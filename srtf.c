#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
};
void print_process_table(struct Process *processes, int n)
{
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWait Time\n");
    for (int i = 0; i < n; i++)
    {
        int turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        int wait_time = turnaround_time - processes[i].burst_time;
        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, turnaround_time, wait_time);
    }
    printf("Average Wait Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    int current_time = 0;
    int completed = 0;
    while (completed < n)
    {
        int shortest_index = -1;
        int shortest_time = 999999;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0)
            {
                shortest_index = i;
                shortest_time = processes[i].remaining_time;
            }
        }
        if (shortest_index == -1)
        {
            current_time++;
        }
        else
        {
            processes[shortest_index].remaining_time--;
            current_time++;
            if (processes[shortest_index].remaining_time == 0)
            {
                completed++;
                processes[shortest_index].completion_time = current_time;
            }
        }
    }
    print_process_table(processes, n);
    return 0;
}
