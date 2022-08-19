


#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include <stdio.h>


using namespace std;
double mult[3][5];
double tmat[3][3],input[5][5];

void matMul(int c2)
{
    int i,j,k;

    int r1=3,c1=3;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += tmat[i][k] * input[k][j];
            }

}
void draw(int opt)
{

    line(input[0][0],input[1][0],input[0][1],input[1][1]);
    if(opt==2)
    {

        line(input[0][0],input[1][0],input[0][2],input[1][2]);
        line(input[0][1],input[1][1],input[0][2],input[1][2]);
    }
}

void drawR(int opt)
{

    line(mult[0][0],mult[1][0],mult[0][1],mult[1][1]);
    if(opt==2)
    {

        line(mult[0][0],mult[1][0],mult[0][2],mult[1][2]);
        line(mult[0][1],mult[1][1],mult[0][2],mult[1][2]);
    }
}
//driver code
int main()
{

    //input matrix
    int opt;
    printf("What do you want to draw?:\n1. Line\n2.Triangle\n3.Rectangle\n");
    scanf("%d",&opt);

    printf("Enter the coordinates:\n");

    switch(opt)
    {
    case 1:
        printf("First point: ");
        scanf("%lf%lf",&input[0][0],&input[1][0]);
        input[2][0] = 1;

        printf("Second point: ");
        scanf("%lf%lf",&input[0][1],&input[1][1]);
        input[2][1] = 1;

        break;

    case 2:
        printf("First point: ");
        scanf("%lf%lf",&input[0][0],&input[1][0]);
        input[2][0] = 1;

        printf("Second point: ");
        scanf("%lf%lf",&input[0][1],&input[1][1]);
        input[2][1] = 1;

        printf("Third point: ");
        scanf("%lf%lf",&input[0][2],&input[1][2]);
        input[2][2] = 1;
        break;

    case 3:
        break;
    default:
        break;

    }


    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int x = getmaxx()/2;
    int y = getmaxy()/2;

    setcolor(8);

    draw(opt);

    //transformation matrix

    while(true){
        printf("Enter the scaling values sx and sy: ");
    double sx,sy;
    scanf("%lf%lf",&sx,&sy);
    tmat[0][2]=sx;
    tmat[1][2]=sy;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j) {
                if(i==0) tmat[i][j] = sx;
                else if(i==1) tmat[i][j] = sy;
                else tmat[i][j] = 1;
            }
            else  tmat[i][j] = 0;
        }
    }




    //result
    switch(opt)
    {
        case 1: matMul(2); break;
        case 2: matMul(3); break;
        default: break;
    }


    drawR(opt);

    }


    getch();
    closegraph();

    return 0;
}
