#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int roll;
    char name[20];
    float marks;
};
int main()

{
    FILE *fp;
    struct student s;
    int n, i;

    // Writing records sequentially
    fp = fopen("students.dat", "wb");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter number ofstudents: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter Roll No, Name, Marks:\n");
        scanf("%d %s %f",&s.roll,s.name,&s.marks);
        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);

    // Reading records sequentially
    fp = fopen("students.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;

    }
    printf("\nSequential File Records:\n");
    printf("Roll\tName\tMarks\n");
    while(fread(&s, sizeof(s), 1, fp) == 1) {
        printf("%d\t%s\t%.2f\n",s.roll, s.name, s.marks);
    }
    fclose(fp);
    return 0;
}