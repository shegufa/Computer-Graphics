#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include <stdio.h>

//using direct equation

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    /*
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d %d",a,b);

        putpixel(a,b,10); */

    // putpixel(10,50,10);
    int x1,y1,x2,y2; int color=1;

    int x,y,dy,dx,dT,dS,d;
    double m;
   while(true){
    color++;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x=x1;y=y1;

    dy = y2-y1; dx = x2-x1;
    dT = 2*(dy-dx); dS= 2*dy;
    d = 2*dy - dx;

    m = (dy)/(dx*1.0);
    printf("%lf\n",m);
    putpixel(x,y,color);
    if(-1<=m<=0 || 0<=m<=1) //|m|<=1
    {
        printf("Here\n");
        while(x<=x2){
            x++;
            if(d<0){ //S  point
                d=d+dS;
            }
            else{
                d=d+dT;
                y++;
            }
            putpixel(x,y,color);
        }

    }

    else //|m|>1
    {
        while(y<=y2){
            y++;
            if(d<0){
                d=d+dS;
            }
            else{
                d=d+dT;
                x++;
            }
            putpixel(x,y,color);
        }

    }
   }


    getch();
    closegraph();

    return 0;
}

