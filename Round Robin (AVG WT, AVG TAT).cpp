#include <stdio.h>
#define MAX_PROCESSES 3
void computeRoundRobin(int burstTimes[], int n, int quantum, float* avgWaitingTime, float* avgTurnaroundTime) {
    int remainingTimes[MAX_PROCESSES];
    int waitingTimes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remainingTimes[i] = burstTimes[i];
    }
    int currentTime = 0;
    while (1) {
        int allFinished = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTimes[i] > 0) {
                allFinished = 0;
                if (remainingTimes[i] > quantum) {
                    currentTime += quantum;
                    remainingTimes[i] -= quantum;
                } else {
                    currentTime += remainingTimes[i];
                    waitingTimes[i] = currentTime - burstTimes[i];
                    remainingTimes[i] = 0;
                }
            }
        }

        if (allFinished) {
            break;
        }
    }
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += waitingTimes[i] + burstTimes[i];
    }
    *avgWaitingTime = totalWaitingTime / n;
    *avgTurnaroundTime = totalTurnaroundTime / n;
}
int main() {
    int burstTimes[MAX_PROCESSES] = {24, 3, 3};
    int n = sizeof(burstTimes) / sizeof(burstTimes[0]);
    int quantum = 4;
    float avgWaitingTime, avgTurnaroundTime;
    computeRoundRobin(burstTimes, n, quantum, &avgWaitingTime, &avgTurnaroundTime);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTimes[i], burstTimes[i] - quantum, burstTimes[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    return 0;
}
