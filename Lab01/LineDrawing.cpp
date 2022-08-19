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
   while(true){

    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    double m,b;
    color++;
    //finding m
    m = (y2-y1)/double(x2-x1);
    // finding b
    b = y1 - m*x1;

    int x,y,x_,y_;
    if(x1<=x2)
    {
        x=x1;y=y1;x_=x2;y_=y2;
    }
    else
    {
        x=x2;y =y2;x_=x1;y_=y1;
    }

    putpixel(x,y,color);


    if(-1<=m<=0 || 0<=m<=1) //|m|<=1
    {
        while(x<=x_)
        {
            x++;
            y=m*x+b;
            putpixel(x,y,color);
        }
    }

    else //|m|>1
    {
        while(y<=y_)
        {
            y++;
            x = (y-b)/m;
            putpixel(x,y,color);
        }

    }
   }


    getch();
    closegraph();

    return 0;
}
