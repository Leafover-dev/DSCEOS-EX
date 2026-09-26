#include <stdio.h>
int main()
{
    int pages[50], frames[10];

    int n, f, i, j, k, flag, faults = 0, index = 0;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("Enter page reference string:\n");

    for(i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frames[i] = -1;

    // FIFO Algorithm
    for(i=0;i<n;i++)
    {
        flag = 0;
        for(j=0;j<f;j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }

        printf("Frames: ");
        for(j=0;j<f;j++)
            printf("%d ",frames[j]);
        printf("\n");
    }
    printf("Total Page Faults (FIFO) = %d\n",faults);

    return 0;
}
