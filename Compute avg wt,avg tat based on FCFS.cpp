#include <stdio.h>

int main()
{
    int processes[3] = {0, 1, 2}; 
    int burst_time[3] = {2, 4, 8}; 
    int arrival_time[3] = {0, 0, 0}; 
    int completion_time[3]; 
    int waiting_time[3]; 
    int turnaround_time[3]; 
    float avg_waiting_time = 0; 
    float avg_turnaround_time = 0; 
    int i, j;
    completion_time[0] = burst_time[0];
    for (i = 1; i < 3; i++) {
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }
    for (i = 0; i < 3; i++) {
        waiting_time[i] = completion_time[i] - burst_time[i] - arrival_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < 3; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }
    avg_waiting_time /= 3;
    avg_turnaround_time /= 3;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
