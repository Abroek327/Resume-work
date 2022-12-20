#include<stdio.h>

int main()
{
    //declaration
    int height, length, width,volume,weight;

    //input
    printf("Enter the height of the box: ");
    scanf("%d",&height);

    printf("Enter the length of the box: ");
    scanf("%d",&length);

    printf("Enter the width of the box: ");
    scanf("%d",&width);

    //processing
    volume=height*length*width;
    weight=(volume+165)/166;

    //output
    printf("Volume (cubic inches):%d\n",volume);
    printf("Dimensional weight (pounds):%d\n9",weight);

    return 0;

}
