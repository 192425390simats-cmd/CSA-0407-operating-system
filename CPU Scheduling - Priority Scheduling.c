#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n], p[n];
    float avgWT = 0, avgTAT = 0;

    // Input burst times and priorities
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter priority for P%d (lower number = higher priority): ", i+1);
        scanf("%d", &pr[i]);
        p[i] = i+1; // store process ID
    }

    // Sort processes by priority
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) { // lower number = higher priority
                // swap priority
                int temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // swap process ID
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Calculate turnaround time and averages
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    avgWT /= n;
    avgTAT /= n;

    // Display results
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

