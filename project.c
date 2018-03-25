#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void Average_Time(int process[], int n, int burst[],int quant,char name)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    int avg_wait , avg_turnaround ;
    WaitingTime(process, n,burst, wt, quant);
    TurnAroundTime(process, n, burst, wt, temp);
    printf("Processes :  Arival_Time:   burst_Time :  Waiting_Time :   Turn_Around_Time : \n");
    int count=0;
    for (i=1; i<=n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
	count+=burst[i];
	if(count>60)
	{
		break;
	}
        printf("%d \t\t  %d \t\t  %d \t \t %d \t\t\t%d\n",i,process[i],burst[i],wt[i],temp[i]);
    }

