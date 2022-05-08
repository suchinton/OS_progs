#include <stdio.h>
#define max 30

int main()
{
  int n,i,j,b=0,k=1,temp,min,bt[max],at[max],priority[max],wt[max],tat[max],arr[max];
  float awt=0,atat=0;
  printf("Enter number of processes: ");
  scanf("%d",&n);
  printf("Enter burst time, arrival time and priority:\n");
  for(i=0;i<n;i++){
    scanf("%d %d %d",&bt[i],&at[i],&priority[i]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(at[i]<at[j]){
        temp=at[j];
        at[j]=at[i];
        at[i]=temp;

        temp=bt[j];
        bt[j]=bt[i];
        bt[i]=temp;
      }
    }
  }
  for(j=0;j<n;j++){
    b=b+bt[j];
    min=bt[k];
    for(i=k;i<n;i++){
      min=priority[k];
      if(b>=at[i]){
        if(priority[i]<min){
          temp=at[k];
          at[k]=at[i];
          at[i]=temp;

          temp=bt[k];
          bt[k]=bt[i];
          bt[i]=temp;

          temp=priority[k];
          priority[k]=priority[i];
          priority[i]=temp;
        }
      }
    }
    k++;
  }
  arr[0]=0;
  printf("Process\t Burst Time\t Arrival Time\t Priority\t Waiting Time\t Turnaround Time\n");
  for(i=0;i<n;i++){
    wt[i]=0, tat[i]=0;
    arr[i+1]=arr[i]+bt[i];
    wt[i]=arr[i]-at[i];
    tat[i]=wt[i]+bt[i];
    awt=awt+wt[i];
    atat=atat+tat[i];
    printf("%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i+1,bt[i],at[i],priority[i],wt[i],tat[i]);
  }
  awt=awt/n; atat=atat/n;
  printf("Average waiting time: %f",awt);
  printf("\nAverage turnaround time: %f",atat);
}