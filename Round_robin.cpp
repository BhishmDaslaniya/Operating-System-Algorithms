#include <bits/stdc++.h>
using namespace std;

typedef struct process
{
    char name[5];
    int bt;
    int at;
    int wt, ta;
    int flag;
    int prt;
} processes;

void b_sort(processes temp[], int n)
{
    processes t;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (temp[j].at > temp[j + 1].at)
            {
                t = temp[j];
                t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
}

int accept(processes P[])
{
    int i, n;
    printf("\n Enter total no. of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n PROCESS [%d]", i + 1);
        printf(" Enter process name : ");
        scanf("%s", &P[i].name);
        printf(" Enter burst time : ");
        scanf("%d", &P[i].bt);
        printf(" Enter arrival time : ");
        scanf("%d", &P[i].at);
        printf(" Enter priority : ");
        scanf("%d", &P[i].prt);
    }
    printf("\n PROC.\tB.T.\tA.T.\tPRIORITY");
    for (i = 0; i < n; i++)
        printf("\n %s\t%d\t%d\t%d", P[i].name, P[i].bt, P[i].at, P[i].prt);
    return n;
}

void RR(processes P[], int n)
{
    int pflag = 0, t, tcurr = 0, k, i, Q = 0;
    int sumw = 0, sumt = 0;
    float avgwt = 0.0, avgta = 0.0;
    processes temp1[10], temp2[10];

    for (i = 0; i < n; i++)
        temp1[i] = P[i];

    b_sort(temp1, n);

    for (i = 0; i < n; i++)
        temp2[i] = temp1[i];

    printf("\n Enter quantum time : ");
    scanf("%d", &Q);

    for (k = 0;; k++)
    {
        if (k > n - 1)
            k = 0;
        if (temp1[k].bt > 0)
            printf("  %d  %s", tcurr, temp1[k].name);
        t = 0;
        while (t < Q && temp1[k].bt > 0)
        {
            t++;
            tcurr++;
            temp1[k].bt--;
        }
        if (temp1[k].bt <= 0 && temp1[k].flag != 1)
        {
            temp1[k].wt = tcurr - temp2[k].bt - temp1[k].at;
            temp1[k].ta = tcurr - temp1[k].at;
            pflag++;
            temp1[k].flag = 1;
            sumw += temp1[k].wt;
            sumt += temp1[k].ta;
        }
        if (pflag == n)
            break;
    }
    printf("  %d", tcurr);
    avgwt = (float)sumw / n;
    avgta = (float)sumt / n;
    printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.", avgwt, avgta);
}

int main()
{
    processes p[10];
    int n;
    n = accept(p);
    RR(p, n);
    return 0;
}