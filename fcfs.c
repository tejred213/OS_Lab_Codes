#include <stdio.h>
int main()
{
int n,AT[20],BT[20],ST[20],CT[20],WT[20],TAT[20];

printf("enter the number of processes \n");
scanf("%d",&n);

int i;
for (i=0;i<n;i++)
{
printf("the arrival time of process\n");
scanf("%d",&AT[i]);
   
printf("the burst time of process\n");
    scanf("%d",&BT[i]);
   
  }
         
   
ST[0]=AT[0];
for(i=0;i<n;i++)
{
  CT[i]=ST[i]+BT[i];
  ST[i+1]=CT[i];    
    TAT[i]=CT[i]-AT[i];
    WT[i]=TAT[i]-BT[i];
}
 
  for(i=0;i<n;i++)
  {
 
    printf("AT\tBT\tCT\tTAT\tWT\t\n");
    for(i=0;i<n;i++)
    {
     printf("%d\t%d\t%d\t%d\t%d\n",AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
 
   }
   
    return 0;
}