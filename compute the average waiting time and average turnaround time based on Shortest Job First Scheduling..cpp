#include <stdio.h>

#define MAX_PROCESSES 3

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateWaitingTime(struct Process processes[], int numProcesses) {
    int remainingTime[MAX_PROCESSES];

    for (int i = 0; i < numProcesses; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    int complete = 0;
    int time = 0;
    int shortestProcess = 0;
    int minRemainingTime = (INT_MAX);
    int finishTime;

    while (complete != numProcesses) {
        for (int j = 0; j < numProcesses; j++) {
            if (processes[j].burstTime <= minRemainingTime && processes[j].burstTime > 0) {
                shortestProcess = j;
                minRemainingTime = processes[j].burstTime;
            }
        }

        remainingTime[shortestProcess]--;

        if (remainingTime[shortestProcess] == 0) {
            complete++;
            finishTime = time + 1;

            processes[shortestProcess].waitingTime = finishTime - processes[shortestProcess].burstTime;

            if (processes[shortestProcess].waitingTime < 0) {
                processes[shortestProcess].waitingTime = 0;
            }

            processes[shortestProcess].turnaroundTime = finishTime;

            minRemainingTime = _INT_MAX_;
        }

        time++;
    }
}

void calculateTurnaroundTime(struct Process processes[], int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void printResults(struct Process processes[], int numProcesses) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    double averageWaitingTime = totalWaitingTime / numProcesses;
    double averageTurnaroundTime = totalTurnaroundTime / numProcesses;

    printf("\nAverage Waiting Time: %.2lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", averageTurnaroundTime);
}

int main() {
    struct Process processes[MAX_PROCESSES] = {
        {0, 2, 0, 0},
        {1, 4, 0, 0},
        {2, 8, 0, 0}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    calculateWaitingTime(processes, numProcesses);
    calculateTurnaroundTime(processes, numProcesses);
    printResults(processes, numProcesses);

    return 0;
}
