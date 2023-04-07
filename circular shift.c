#include<stdio.h>

int x,y,z;


int crsh(int a,int b,int c){
    b=x
    c=y
    a=z
    return a,b,c;
}

int main(){

    printf("enter the first digit: ")
    scanf("%d",x)

    printf("enter the second digit: ")
    scanf("%d",y)

    printf("enter the third digit: ")
    scanf("%d",z)

    printf("pre shifted values are: x= %d, y= %d, z=%d", x, y, z)

    crsh(x,y,z)

    printf("post shifting values are: x= %d, y= %d, z=%d", x, y, z)

}