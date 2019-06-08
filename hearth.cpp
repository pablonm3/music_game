#include "hearth.h"
int Hearth::puntos = 0;

Hearth::Hearth(int c)
{
    set_color(c);
    set_y(FIL-10);
    set_x(COL/3);
    set_fig(3);
    pintar();
}
void Hearth::pintar_puntos()const
{
    gotoxy(COL-11, FIL-3);
    printf("puntos:    ");
    gotoxy(COL-3, FIL-3);
    printf("%d", puntos);
}

void Hearth::set_nuevo()
{
    borrar();
    set_x(rand()%COL);
    set_y(rand()%FIL);
    pintar();
}

bool Hearth::goal(int _x, int _y)
{
    return (get_x()==_x && get_y()==_y);
}

void Hearth::sayColour()
{
    switch (get_color())
    {
        case BLUE: if (!soundColour.openFromFile("music/nextGoal/Blue.wav"))
                    {
                        cerr << "NO ENCONTRADO";
                        return;
                    }
                    break;
        case RED:   if (!soundColour.openFromFile("music/nextGoal/Red.wav"))
                    {
                        cerr << "NO ENCONTRADO";
                        return;
                    }
                break;
        case CIAN: if (!soundColour.openFromFile("music/nextGoal/Cian.wav"))
                    {
                        cerr << "NO ENCONTRADO";
                        return;
                    }
                break;
        default: return;
    }
    soundColour.play();
}

void Hearth::reset_ptos()
{
    puntos = 0;
}

int Hearth::set_nextGoal(int color1, int color2, int color3)
{
    int n = rand()%3;
    switch(n)
    {
        case 0:  return color1;
        case 1:  return color2;
        case 2:  return color3;
    }
    return 0;
}

Hearth& Hearth::operator++()
{
    random_music(fx, 2, MAXGOAL);
    if (!sound.openFromFile(fx))
    {
        cerr << "NO ENCONTRADO";
        return *this;
    }
    sound.play();
    puntos+=5;
    return *this;
}

int Hearth::get_puntos()
{
    return puntos;
}

Hearth& Hearth::operator--()
{
    if (!sound.openFromFile("music/nextGoal/error.wav"))
    {
        cerr << "NO ENCONTRADO";
        return *this;
    }
    sound.play();
    puntos-=15;
    return *this;
}
