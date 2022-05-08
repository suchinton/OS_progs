#include <stdio.h>
int main() 
{
  int arr[10], burr[10], temp[10];
  int i, smallest, count = 0, time, nop;
  double wt= 0, tat = 0, end;
  float awt, atat;
  printf("Enter the Number of Processes: ");
  scanf("%d", &nop); 
  printf("\nEnter Details of those %d Processes:\n", nop);
  for(i = 0; i < nop; i++){
    printf("\nEnter the Arrival Time: ");
    scanf("%d", &arr[i]);
    printf("Enter Burst the Time: ");
    scanf("%d", &burr[i]); 
    temp[i] = burr[i];
  }
  burr[9] = 9999;  
  for(time = 0; count != nop; time++){
    smallest = 9;
    for(i = 0; i < nop; i++){
      if(arr[i] <= time && burr[i] < burr[smallest] && burr[i] > 0){
            smallest = i;}
    }
    burr[smallest]--;
    if(burr[smallest] == 0){
      count++;
      end = time + 1;
      wt = wt + end - arr[smallest] - temp[smallest];
      tat = tat + end - arr[smallest];}
  }
  awt = wt / nop; 
  atat = tat / nop;
  printf("\n\nAverage Waiting Time:->>\t%f\n", awt);
  printf("\nAverage Turnaround Time:->>\t%f\n", atat);
  return 0;
}