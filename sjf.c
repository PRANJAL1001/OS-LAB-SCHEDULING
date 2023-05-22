
#include <stdio.h>

// process structure
typedef struct {
    int pid;    // process ID
    int burst;  // burst time
    int wait;   // waiting time
    int turn;   // turnaround time
} Process;

int main() {
    int n;  // number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // create process array
    Process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;
        p[i].wait = 0;
        p[i].turn = 0;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].burst > p[j].burst) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            p[i].wait += p[j].burst;
        }
        p[i].turn = p[i].wait + p[i].burst;
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
