#include <stdio.h>
typedef struct {
    int pid;    // process ID
    int burst;  // burst time
    int rem;    // remaining time
    int wait;   // waiting time
    int turn;   // turnaround time
} Process;
int main() {
    int n, quantum;  
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;
        p[i].rem = p[i].burst;
        p[i].wait = 0;
        p[i].turn = 0;
    }
    int t = 0, done = 0;
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].rem > 0) {
                if (p[i].rem <= quantum) {
                    t += p[i].rem;
                    p[i].rem = 0;
                    p[i].wait = t - p[i].burst;
                    p[i].turn = t;
                    done++;
                } else {
                    t += quantum;
                    p[i].rem -= quantum;
                }
            }
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].wait, p[i].turn);
    }
    float avg_wait = 0, avg_turn = 0;
    for (int i = 0; i < n; i++) {
        avg_wait += p[i].wait;
        avg_turn += p[i].turn;
    }
    avg_wait /= n;
    avg_turn /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turn);
    return 0;
}
