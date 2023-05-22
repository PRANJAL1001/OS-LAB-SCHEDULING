#include<stdio.h>
void main() {
    int n, i, j;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wait_time[n], turnaround_time[n];
    for(i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }
    wait_time[0] = 0;
    for(i = 1; i < n; i++) {
        wait_time[i] = 0;
        for(j = 0; j < i; j++) {
            wait_time[i] += burst_time[j];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + wait_time[i];
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("Process %d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %0.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
}
