#include <stdio.h>
#define MAX 10

int main() {
int quantum, counter = 0, burstTime[MAX], i, n, arrivalTime = 0, turnAroundTime[MAX], waitTime[MAX], sum = 0, completionTime[MAX], oldBurstTime[MAX];
float avgWT = 0, avgTAT = 0;
// quantum, no of processes are taken as an input
printf("Enter no. of processes: ");
scanf("%d", &n);
printf("Enter time quantum: ");
scanf("%d", &quantum);

for(i = 0; i < n; i ++) {
printf("Enter burst time for PS[%d]: ", i);
scanf("%d", &burstTime[i]);
}
// oldBurstTime is a backup of burstTime as we will be manipulating burstTime
// while calculating its wait Time/turnaround time
for(i = 0; i < n; i ++) {
oldBurstTime[i] = burstTime[i];
}

while(1) {
// will execute till p[n] doesn't reach zero or is less than quantum
if(burstTime[i] > quantum) {
burstTime[i] -= quantum;
sum += quantum;
} else if (burstTime[i] <= quantum && burstTime[i] > 0) {
sum += burstTime[i];
burstTime[i] = 0;
completionTime[i] = sum;
// This is unnecessary but I am doing this for myself \
this is unnecessary because arrival time is 0 for all instances
turnAroundTime[i] = completionTime[i] - arrivalTime;
++counter;

}
if (i == n) {
i = 0;
} else {
++i;
}
if (counter == n) {
break;
}
}

// will take a summation of avg TAT
for(i = 0; i < n; i ++) {
avgTAT += (float)turnAroundTime[i];
}
// will calculate waitTime first and sum it
for(i = 0; i < n; i ++) {
waitTime[i] = turnAroundTime[i] - oldBurstTime[i];
avgWT += (float)waitTime[i];
}
// prints the info in tabular format
printf("PS\tTAT\tWT\tCT\tBT\n");
printf("-----\n");
for(i = 0; i < n; i ++) {
printf("%d\t%d\t%d\t%d\t%d\n", i, turnAroundTime[i], waitTime[i], completionTime[i], oldBurstTime[i]);
}

avgWT /= 4;
avgTAT /= 4;

printf("\nAvg TAT:%.2f\nAvg WT: %.2f\n", avgTAT, avgWT);

return 0;
}
