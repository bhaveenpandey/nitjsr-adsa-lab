#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int min(int a, int b) { return (a < b) ? a : b; }

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);
    int result[n];
    int slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i])
            printf("%c ", jobs[result[i]].id);
    }
    printf("\n");
}
/* int main() {
    Job jobs[] = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    
    printf(jobs);
    int n = sizeof(jobs)/sizeof(jobs[0]);
    jobSequencing(jobs, n);
    return 0;
}  */ 

int main() {
    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };
    
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("Given Jobs:\n");
    printf("Job\tDeadline\tProfit\n");
    for (int i = 0; i < n; i++) {
        printf("%c\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    printf("\n");
    jobSequencing(jobs, n);
    return 0;
}