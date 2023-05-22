#include <stdio.h>
struct Process {
    int pid;    // process ID
    int burst;  // burst time
    int arrival;    // arrival time
    int start;  // start time
    int finish; // finish time
    int waiting;    // waiting time
    int turnaround; // turnaround time
    int remaining;  // remaining time
};
void print_table(struct Process p[], int n) {
    printf("PID\tBurst\tArrival\tStart\tFinish\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].arrival,
            p[i].start, p[i].finish, p[i].waiting, p[i].turnaround);
    }
}
void srtf(struct Process p[], int n) {
    int time = 0, done = 0, min_burst, min_pid;
    while (done < n) {
        min_burst = __INT_MAX__;
        min_pid = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].remaining < min_burst && p[i].remaining > 0) {
                min_burst = p[i].remaining;
                min_pid = i;
            }
        }
        if (min_pid == -1) {
            time++;
            continue;
        }
        p[min_pid].remaining--;
        if (p[min_pid].remaining == 0) {
            done++;
            p[min_pid].finish = time + 1;
            p[min_pid].turnaround = p[min_pid].finish - p[min_pid].arrival;
            p[min_pid].waiting = p[min_pid].turnaround - p[min_pid].burst;
        }

        if (p[min_pid].remaining == p[min_pid].burst) {
            p[min_pid].start = time;
        }
        time++;
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time of process %d: ", i+1);
        scanf("%d %d", &p[i].burst, &p[i].arrival);
        p[i].pid = i+1;
        p[i].remaining = p[i].burst;
    }
    srtf(p, n);
    print_table(p, n);

    float avg_waiting = 0, avg_turnaround = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting += p[i].waiting;
        avg_turnaround += p[i].turnaround;
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    printf("Average Waiting Time: %f\n", avg_waiting);
    printf("Average Turnaround Time: %f\n", avg_turnaround);
    return 0;
}