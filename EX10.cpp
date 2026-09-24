#include <stdio.h>
int main()
{
    int pages, frames, i;
    int pageTable[20];
    int pageNumber, offset;
    int frameNumber, physicalAddress, frameSize;
    printf("Enter number of pages: ");
    scanf("%d",&pages);
    printf("Enter number of frames: ");
    scanf("%d",&frames);

    printf("Enter frame size: ");
    scanf("%d",&frameSize);

    printf("Enter page table (frame number for each page):\n");
    for(i=0;i<pages;i++)
    {
        printf("Page %d -> Frame: ",i);
        scanf("%d",&pageTable[i]);
    }

    printf("Enter page number: ");
    scanf("%d",&pageNumber);
    printf("Enter offset: ");
    scanf("%d",&offset);
    if(pageNumber >= pages)
    {
        printf("Invalid Page Number\n");
    }
    else
    {
        frameNumber = pageTable[pageNumber];
        physicalAddress = (frameNumber * frameSize) + offset;
        printf("Frame Number: %d\n",frameNumber);
        printf("Physical Address: %d\n",physicalAddress);
    }
    return 0;
}
