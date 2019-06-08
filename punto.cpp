#include "punto.h"

const HANDLE Punto::hCon = GetStdHandle(STD_OUTPUT_HANDLE);

Punto::Punto()
:fig(33){
    set_x(1);
    set_y(1);
    color = 255;
}

int Punto::get_color()
{
    return color;
}

void Punto::set_color(int c)
{
    color = (c>=0 && c<256)? c : 2;
}

void Punto::pintar()const
{
    SetConsoleTextAttribute(hCon, color);
    gotoxy(x,y);
    printf("%c", fig);
}

void Punto::borrar()const
{
    gotoxy(x,y);
    SetConsoleTextAttribute(hCon, 0);
    printf(" ");
}

void Punto::set_x(int n)
{
    x = (n<=MINN)? COL-1 : (n>=COL)? MINN+1 : n;
}

void Punto::set_y(int n)
{
    y = (n<=MINN-1)? FIL-5 : (n>FIL-5)? MINN : n;
}

void Punto::set_fig(int f)
{
    fig = f;
}

int Punto::get_x()const
{
    return x;
}

int Punto::get_y()const
{
    return y;
}
