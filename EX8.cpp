#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    int allocation[10][10],
    request[10][10];
    int available[10], finish[10];
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);
    printf("Enter Allocation Matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&allocation[i][j]);

    printf("Enter Request Matrix:\n"); for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&request[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&available[i]);

    for(i=0;i<n;i++)
        finish[i] = 0;

    int found;
    do
    {
        found = 0;

        for(i=0;i<n;i++)
        {
            if(finish[i] == 0)
            {
                for(j=0;j<m;j++)
                {
                    if(request[i][j] > available[j]) break;
                }
                if(j == m)
                {
                    for(k=0;k<m;k++)
                        available[k] += allocation[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while(found);

    int deadlock = 0;
    for(i=0;i<n;i++)
    {
        if(finish[i] == 0)
        {
            printf("Process P%d is in deadlock\n",i); deadlock = 1;
        }
    }
    if(deadlock == 0)
        printf("No Deadlock detected\n");
    return 0;
}
