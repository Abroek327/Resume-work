#include<stdio.h>

int main()
{
    //declaration
    float radius, diameter, area, circum;

    //input
    printf("Enter the radius ");
    scanf("%f",&radius);


    //processing
    diameter=2*radius;
    area=3.14159*radius*radius;
    circum=3.14159*diameter;

    //output
    printf("The radius of the circle is %f\n",radius);
    printf("The diameter of the circle is: %f\n",diameter);
    printf("The area of the circle is: %f\n",area);
    printf("The circumference of the circle is: %f\n",circum);

    return 0;
}
