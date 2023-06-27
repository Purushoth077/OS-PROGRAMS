#include <stdio.h>
#define MAX_PROCESSES 3
void computeFCFS(int burstTimes[], int n, float* avgWaitingTime, float* avgTurnaroundTime) {
    int waitingTimes[MAX_PROCESSES];
    int turnaroundTimes[MAX_PROCESSES];
    waitingTimes[0] = 0;  
    for (int i = 1; i < n; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
    }
    for (int i = 0; i < n; i++) {
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
    }
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }
    *avgWaitingTime = totalWaitingTime / n;
    *avgTurnaroundTime = totalTurnaroundTime / n;
}
int main() {
    int burstTimes[MAX_PROCESSES] = {10, 15, 25};
    int n = sizeof(burstTimes) / sizeof(burstTimes[0]);
    float avgWaitingTime, avgTurnaroundTime;
    computeFCFS(burstTimes, n, &avgWaitingTime, &avgTurnaroundTime);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTimes[i], i > 0 ? (i-1)*burstTimes[i-1] : 0, burstTimes[i] + (i > 0 ? (i-1)*burstTimes[i-1] : 0));
    }
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    return 0;
}
