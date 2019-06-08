#include "personaje.h"

Personaje::Personaje(int c)
{
    set_x(COL/2);
    set_y(FIL/2);
    set_fig(1);
    set_color(c);
}

bool Personaje::mover()
{
    if(kbhit())
    {
        char tecla = getch();
        int x = get_x(),
            y = get_y();
        borrar();
        if(tecla==RIGHT)set_x(x+=1);
        if(tecla==LEFT)set_x(x-=1);
        if(tecla==UP)set_y(y-=1);
        if(tecla==DOWN)set_y(y+=1);
        if(tecla==DOWN_RIGHT){set_x(x+=1); set_y(y+=1);}
        if(tecla==DOWN_LEFT){set_x(x-=1); set_y(y+=1);}
        if(tecla==UP_LEFT){set_x(x-=1); set_y(y-=1);}
        if(tecla==UP_RIGHT){set_x(x+=1); set_y(y-=1);}

        pintar();
        return 1;
    }
    return 0;
}
