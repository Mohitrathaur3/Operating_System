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
// average query time and average waiting time
    avg_wait=total_wt/(i-1);
    avg_turnaround=total_time/(i-1);
    if(name=='s')
    {
	printf("\n Time he spend on handling of students query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
    else
    {
	printf("\n Time he spend on handling of faculty query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
}

//waiting time frome here

void WaitingTime(int process[], int n,int burst[], int wt[], int quan)
{
    int i,t,rem[n];
    t=0;
    for (i = 1 ; i <= n ; i++)
        {
            rem[i] =  burst[i];
        }
    while(1)
    {
        bool flag= true;
        for(i = 1; i <= n; i++)
        {
            if (rem[i]>0)
            {
                flag=false; 
 
                if (rem[i]>quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
	            wt[i] = t - process[i];
                    t = t + rem[i];
                    //wt[i] = t - burst[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}
