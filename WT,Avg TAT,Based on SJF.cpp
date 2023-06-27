#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int burst_times[MAX_PROCESSES] = {6, 8, 7, 3};
    int num_processes = 4;
    int completion_times[MAX_PROCESSES];
    int waiting_times[MAX_PROCESSES];
    int turnaround_times[MAX_PROCESSES];
    int i, j, shortest_job_index, total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < num_processes; i++) {
        shortest_job_index = i;
        for (j = i + 1; j < num_processes; j++) {
            if (burst_times[j] < burst_times[shortest_job_index]) {
                shortest_job_index = j;
            }
        }
        int temp = burst_times[i];
        burst_times[i] = burst_times[shortest_job_index];
        burst_times[shortest_job_index] = temp;
        if (i == 0) {
            completion_times[i] = burst_times[i];
        } else {
            completion_times[i] = completion_times[i-1] + burst_times[i];
        }
    }
    for (i = 0; i < num_processes; i++) {
        waiting_times[i] = completion_times[i] - burst_times[i];
        turnaround_times[i] = completion_times[i];
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], completion_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / num_processes);

    return 0;
}
