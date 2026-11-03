#include <stdio.h>
int main(){
int n, sum, i, j, temp;
float totaltat = 0, totalwt = 0;
printf("Enter total No of processes:");
scanf("%d", &n);
int bt[n], ct[n], wt[n], tat[n], p[n];
printf("\nEnter process number:\n");
for(i = 0; i < n; i++)
scanf("%d", &p[i]);
printf("\nEnter Process Burst Time\n");
for(i = 0; i < n; i++){
// p[i] = i + 1;
printf("Enter Burst time of process[%d]:", i + 1);
scanf("%d", &bt[i]);
}
/* Apply Bubble sort to sort */
for(i = 0; i < n; i++){
for(j = 0; j < n - 1 - i; j++){
if(bt[j] > bt[j + 1]){
temp = bt[j];
bt[j] = bt[j + 1];
bt[j + 1] = temp;
temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
sum = 0;
for(j = 0; j < n; j++){
sum = sum + bt[j];
ct[j] = sum;
tat[j] = ct[j];
totaltat = totaltat + tat[j];
wt[j] = tat[j] - bt[j];
totalwt = totalwt + wt[j];
}
printf("\nProcess\tBT\tTAT\tWT\n\n");
for(i = 0; i < n; i++){
printf("\nP%d\t %d\t %d\t %d\t\n",i+1, bt[i], tat[i], wt[i]);
}
printf("\nAvg Turnaround Time:%f\n",totaltat/n);
printf("\nAvg Waiting Time:%f",totalwt/n);
return 0;
}