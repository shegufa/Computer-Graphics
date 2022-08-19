#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
int x,y;

//driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file

    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm,"");

    int x1 = getmaxx()/2;
    int y1= getmaxy()/2;
    int x2 = getmaxx();
    int y2 = getmaxy();
    line(0,y1, x2,y1);
    line(x1,0, x1,y2);
// center = (x,y)
    int color = 5;
    putpixel(x,y,color);



    int r;
    printf("Enter the radius: ");
    scanf("%d",&r);

    x = 0;
    y=r;
    double d = 3-2*r;
    while(x<=y){

        putpixel(x+x1,y+y1,color);
        putpixel(y+x1,x+y1,color);
        putpixel(-x+x1,-y+y1,color);
        putpixel(-y+x1,-x+y1,color);
        putpixel(-x+x1,y+y1,color);
        putpixel(y+x1,-x+y1,color);
        putpixel(x+x1,-y+y1,color);
        putpixel(-y+x1,x+y1,color);

        if(d<0)
            d = d + 4*x +6;
        else{
            d = d + 4*(x-y)+10;
            y--;
        }
        x++;


    }
    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();

    return 0;
}


