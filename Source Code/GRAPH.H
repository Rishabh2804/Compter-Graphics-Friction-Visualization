// Created By :- Gaurav Gupta, Rishabh Gupta with the knowledge of basic graphics algorithms
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void lineBres(int x0, int y0, int x1, int y1, int COLOR)
{
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x < x1)
    {
        if (p >= 0)
        {
            putpixel(x, y, COLOR);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, COLOR);
            p = p + 2 * dy;
            x = x + 1;
	}
    }
}

void lineDDA(int x0, int y0, int x1, int y1, int COLOR)
{
    float x, y, dx, dy, steps;
    int i = 1;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    if (dx >= dy)
    {
	steps = dx;
    }
    else
    {
	steps = dy;
    }

    dx = dx / steps;
    dy = dy / steps;
    x = x0;
    y = y0;

    while (i <= steps)
    {
        putpixel(x, y, COLOR);
        x += dx;
        y += dy;
        i = i + 1;
    }
}
void rec(int left, int top, int right, int bottom, int COLOR)
{
	lineDDA(left, top, right, top, COLOR);
	lineDDA(left, bottom, right, bottom, COLOR);
	lineDDA(left, top, left, bottom, COLOR);
	lineDDA(right, top, right, bottom, COLOR);
}

void circleMid(int xc, int yc, int r, int COLOR)
{
    int x, y, d;
    d = 1 - r;
    x = 0;
    y = r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, COLOR);
        putpixel(xc - x, yc + y, COLOR);
        putpixel(xc + x, yc - y, COLOR);
        putpixel(xc - x, yc - y, COLOR);
        putpixel(xc + y, yc + x, COLOR);
        putpixel(xc + y, yc - x, COLOR);
        putpixel(xc - y, yc - x, COLOR);
        putpixel(xc - y, yc + x, COLOR);

        if (d <= 0)
        {
            d = d + 2 * x + 1;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            y = y - 1;
        }
        x = x + 1;
    }
}

void helper(int xc, int yc, int x, int y, int COLOR)
{
    putpixel(x + xc, y + yc, COLOR);
    putpixel(x + xc, -y + yc, COLOR);
    putpixel(-x + xc, -y + yc, COLOR);
    putpixel(-x + xc, y + yc, COLOR);
    putpixel(y + xc, x + yc, COLOR);
    putpixel(y + xc, -x + yc, COLOR);
    putpixel(-y + xc, -x + yc, COLOR);
    putpixel(-y + xc, x + yc, COLOR);
}

void circleBres(int xc, int yc, int r, int COLOR)
{
    int x = 0, y = r, d = 3 - (2 * r);
    helper(xc, yc, x, y, COLOR);

    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        helper(xc, yc, x, y, COLOR);
    }
}
