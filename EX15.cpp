#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void fcfs(int req[], int n, int head)
{
    int i, seek = 0;
    printf("Head movements: ");
    for(i=0;i<n;i++)
    {
        printf("%d->",head);
    seek += abs(head - req[i]);
    head = req[i];
    }
    printf("end\nTotal Seek Time = %d\n",seek);
}

void sstf(int req[], int n, int head)
{
    int i, j, seek = 0, min, pos, temp;
    int visited[20] = {0};
    printf("Head movements: ");
    for(i=0;i<n;i++)
    {
        min = 9999;
        for(j=0;j<n;j++)
        {
            if(!visited[j] && abs(head - req[j]) < min){
            min = abs(head - req[j]);
            pos = j;
        }
    }
    visited[pos] = 1;
    printf("%d->",head);
    seek += abs(head - req[pos]);
    head = req[pos];
    }
    printf("end\nTotal Seek Time = %d\n",seek);
}

void scan(int req[], int n, int head, int disk_size, int direction)
{
    int i, j, seek = 0;
    int temp[20], count = 0;
    for(i=0;i<n;i++) temp[i] = req[i];
        temp[n] = head; n++;

    // Sort requests
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(temp[i] > temp[j])
            {
                int t = temp[i]; temp[i]=temp[j]; temp[j]=t;
            }
        }
    }
    int index;
    for(i=0;i<n;i++) if(temp[i]==head){ index=i; break;}
        printf("Head movements: ");
        if(direction==0){ // left
        for(i=index;i>=0;i--)
        {
            printf("%d->",temp[i]);
            if(i>0) seek += abs(temp[i]-temp[i-1]);
        }
        for(i=index+1;i<n;i++){
            printf("%d->",temp[i]);
            if(i<n-1) seek += abs(temp[i]-temp[i-1]);
        }
} else { // right
    for(i=index;i<n;i++)
    {
        printf("%d->",temp[i]);
        if(i<n-1) seek += abs(temp[i]-temp[i+1]);
    }

    for(i=index-1;i>=0;i--)
    {
        printf("%d->",temp[i]);
        if(i>0) seek += abs(temp[i]-temp[i-1]);
    }
}
    printf("end\nTotal Seek Time = %d\n",seek);
}

int main() {
    int n, i, head, choice, disk_size=200;
    int req[20], direction;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter request sequence: ");
    for(i=0;i<n;i++)scanf("%d",&req[i]);
        printf("Enter initial head position: ");
    scanf("%d",&head);
    do {
        printf("\nDisk Scheduling Algorithms:\n");
        printf("1. FCFS\n2. SSTF\n3. SCAN\n4. C-SCAN\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: fcfs(req,n,head); break;
        case 2: sstf(req,n,head); break;
        case 3:
        printf("Enter direction (0=left,1=right): ");
        scanf("%d",&direction);
        scan(req,n,head,disk_size,direction);
        break;
        case 4:
        printf("C-SCAN currently similar to SCAN (single direction)\n");
        scan(req,n,head,disk_size,1);
        break;
        case 5: exit(0);
        default: printf("Invalid choice\n");
    }
    } while(1);
    return 0;
}