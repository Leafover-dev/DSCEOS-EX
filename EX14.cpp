#include <stdio.h>
#include <stdlib.h>
void sequential_allocation() {
    int start, size, i;
    printf("Enterstarting block: ");
    scanf("%d",&start);
    printf("Enter file size (number of blocks): ");
    scanf("%d",&size);
    printf("Allocated blocks: ");
    for(i=start;i<start+size;i++)
        printf("%d ",i);
    printf("\n");
}
void linked_allocation() {
    int start, size, i, block;
    printf("Enterstarting block: ");
    scanf("%d",&start);
    printf("Enter file size (number of blocks): ");
    scanf("%d",&size);
    printf("Allocated blocks and next pointers:\n");
    block = start;
    for(i=0;i<size;i++) {
        int next;
        printf("Block %d -> ",block);
        if(i != size-1) {
            next = block + 1 + rand()%5; // random next block
            printf("%d\n", next);
            block = next;
        } else {
            printf("NULL\n");
        }
    }
}
void indexed_allocation() {
    int indexBlock, size, i, block;
    printf("Enter index block number: ");
    scanf("%d",&indexBlock);
    printf("Enter file size (number of blocks): ");
    scanf("%d",&size);
    printf("Index Block %d points to blocks: ", indexBlock);
    for(i=0;i<size;i++) {
        block = rand()%100; // random block number
        printf("%d ", block);
    }
    printf("\n");
}
int main() {
    int choice;
    do {
        printf("\nFile Allocation Strategies:\n");
        printf("1. Sequential Allocation\n");
        printf("2. Linked Allocation\n");
        printf("3. Indexed Allocation\n"); 
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:sequential_allocation(); break;
            case 2: linked_allocation(); break;
            case 3: indexed_allocation(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    } while(1);
    return 0;
}