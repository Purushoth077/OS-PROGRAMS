#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int arrival_times[MAX_PROCESSES] = {0, 1, 2, 4};
    int burst_times[MAX_PROCESSES] = {5, 3, 3, 1};
    int num_processes = 4;
    int remaining_burst_times[MAX_PROCESSES];
    int completion_times[MAX_PROCESSES];
    int waiting_times[MAX_PROCESSES];
    int turnaround_times[MAX_PROCESSES];
    int current_time, shortest_remaining_time, shortest_index, i, j;
    
    for (i = 0; i < num_processes; i++) {
        remaining_burst_times[i] = burst_times[i];
    }

    current_time = 0;
    while (1) {
        shortest_remaining_time = -1;
        shortest_index = -1;
        for (i = 0; i < num_processes; i++) {
            if (arrival_times[i] <= current_time && remaining_burst_times[i] > 0) {
                if (shortest_remaining_time == -1 || remaining_burst_times[i] < shortest_remaining_time) {
                    shortest_remaining_time = remaining_burst_times[i];
                    shortest_index = i;
                }
            }
        }

        if (shortest_index == -1) {
            break;
        }
        remaining_burst_times[shortest_index]--;
        current_time++;
        if (remaining_burst_times[shortest_index] == 0) {
            completion_times[shortest_index] = current_time;
            waiting_times[shortest_index] = completion_times[shortest_index] - arrival_times[shortest_index] - burst_times[shortest_index];
            turnaround_times[shortest_index] = completion_times[shortest_index] - arrival_times[shortest_index];
        }
    }
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < num_processes; i++) {
        total_waiting_time += waiting_times[i];
        total_turnaround_time += turnaround_times[i];
    }
    float avg_waiting_time = total_waiting_time / num_processes;
    float avg_turnaround_time = total_turnaround_time / num_processes;
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_times[i], burst_times[i], completion_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average waiting time: %.2f milliseconds\n", avg_waiting_time);
    printf("Average turnaround time: %.2f milliseconds\n", avg_turnaround_time);

    return 0;
}
