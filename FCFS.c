#include<stdio.h>
int main(){
int n,sum,i,j;
printf("Enter the total no. of Processes:");
scanf("%d",&n);
int at[n],bt[n],wt[n],tat[n],ct[n];
float totalwt=0,totaltat=0;
printf("\nEnter the process arrival time and Burst Time:\n");
for (i=0;i<n;i++){
printf("Enter arrival time of Process[%d]: ", i + 1);
scanf("%d",&at[i]);
printf("Enter burst time of Process[%d]: ", i + 1);
scanf("%d",&bt[i]);
}
sum=at[0];
for(j=0;j<n;j++){
sum+=bt[j];
ct[j]=sum;
tat[j]=ct[j]-at[j];
wt[j]=tat[j]-bt[j];
totaltat+=tat[j];
totalwt+=wt[j];
}
printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0;i<n;i++){
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\nAverage Turn Around Time = %.1f", totaltat/n);
printf("\nAverage Waiting Time = %.1f", totalwt/n);
}