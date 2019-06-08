#include "enemigo.h"

Enemigo::Enemigo(int c)
{
    set_fig(64);
    set_y(FIL/2);
    set_x(COL/3);
    set_color(c);
}

void Enemigo::pintar1()
{
    pintar();
}

int Enemigo::seguir(int x, int y)
{
    int myX = get_x(),
        myY = get_y();
    borrar();
    if(myX > x)
        set_x(--myX);
    else {if(myX < x)
            set_x(++myX);
        if(myY > y)
                set_y(--myY);

        else if(myY < y)
            set_y(++myY);
    }   // fin else
    pintar();

    return (myX==x && myY==y)? 1 : 0;
}

