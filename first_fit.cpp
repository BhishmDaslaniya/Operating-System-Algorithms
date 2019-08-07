#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int psize;
    int pflag;
} process;

typedef struct block
{
    int bsize;
    int bflag;
} block;

void accept(process p[], block b[], int *n, int *m)
{

    int i, j;

    printf("\n Enter no. of blocks : ");
    scanf("%d", m);
    for (i = 0; i < *m; i++)
    {
        printf(" Enter size of block[%d] : ", i);
        scanf("%d", &b[i].bsize);
    }

    printf("\n Enter no. of processes : ");
    scanf("%d", n);
    for (i = 0; i < *n; i++)
    {
        printf(" Enter size of block[%d] : ", i);
        scanf("%d", &p[i].psize);
    }
}
void re_init(process p[], block b[], int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
        p[i].pflag = 0;
    for (i = 0; i < m; i++)
        b[i].bflag = 0;
}

void first_fit(process p[], block b[], int n, int m)
{

    int i, j, in_frag = 0, ex_frag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (p[i].psize <= b[j].bsize && b[j].bflag == 0 && p[i].pflag == 0)
            {
                b[j].bflag = p[i].pflag = 1;
                in_frag += b[j].bsize - p[i].psize;
                printf("\n P[%d]\t-\tB[%d]", i, j);
                break;
            }
        }
        if (p[i].pflag == 0){
            printf("\n P[%d]\t-\tUnassigned", i);
            ex_frag+=p[i].psize;
        }
    }
    printf("\n\n Total internal fragmentation : %d", in_frag);
    // for (j = 0; j < m; j++)
    // {
    //     if (b[j].bflag == 0)
    //         ex_frag += b[j].bsize;
    // }
    printf("\n Total external fragmentation : %d", ex_frag);
}

int main()
{

    int ch, n = 0, m = 0;
    process p[10];
    block b[10];
    accept(p, b, &n, &m);
    re_init(p, b, n, m);
    first_fit(p, b, n, m);
    return 0;
}