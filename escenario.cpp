#include "escenario.h"

Escenario::Escenario()
{
    int i;
    cantEne=1;
    time=0;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, 50);
    for(i=MINN; i< COL; i++)
    {
        gotoxy(i, 0);
        printf("%c", 205);
        gotoxy(i, FIL-4);
        printf("%c", 205);
    }   // lineas bottom and roof
    for(i=MINN; i<FIL-4; i++)
    {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(COL, i);
        printf("%c", 186);
    }   // fin paredes
    gotoxy(MINN,MINN-1);
    printf("%c", 201);
    gotoxy(MINN, FIL-4);
    printf("%c", 200);
    gotoxy(COL, MINN-1);
    printf("%c", 187);
    gotoxy(COL, FIL-4);
    printf("%c", 188);
    e[0].pintar1();
    hr.set_color(RED);
    hb.set_color(BLUE);
    hc.set_color(CIAN);
    hr.set_nuevo();
    hb.set_nuevo();
    hc.set_nuevo();
    if (!fxnuEnem.openFromFile("music/enemy.wav"))
        cerr <<"MUSIC NOT FOUND";
    nextGoal = Hearth::set_nextGoal(RED, BLUE, CIAN);
    switch(nextGoal)
    {
    case RED:
        hr.sayColour();
        break;
    case BLUE:
        hb.sayColour();
        break;
    case CIAN:
        hc.sayColour();
        break;
    }
    hr.pintar_puntos();
}

void Escenario::reset()
{
    int i;
    time=0;
    cantEne =1;
    system("cls");
    hr.reset_ptos();
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, 50);
    for(i=MINN; i< COL; i++)
    {
        gotoxy(i, 0);
        printf("%c", 205);
        gotoxy(i, FIL-4);
        printf("%c", 205);
    }   // lineas bottom and roof
    for(i=MINN; i<FIL-4; i++)
    {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(COL, i);
        printf("%c", 186);
    }   // fin paredes
    e[0].set_x(p.get_x()+15);
    gotoxy(MINN,MINN-1);
    printf("%c", 201);
    gotoxy(MINN, FIL-4);
    printf("%c", 200);
    gotoxy(COL, MINN-1);
    printf("%c", 187);
    gotoxy(COL, FIL-4);
    printf("%c", 188);
    e[0].pintar1();
    hr.set_color(RED);
    hb.set_color(BLUE);
    hc.set_color(CIAN);
    hr.set_nuevo();
    hb.set_nuevo();
    hc.set_nuevo();
    nextGoal = Hearth::set_nextGoal(RED, BLUE, CIAN);
    switch(nextGoal)
    {
    case RED:
        hr.sayColour();
        break;
    case BLUE:
        hb.sayColour();
        break;
    case CIAN:
        hc.sayColour();
        break;
    }
    hr.pintar_puntos();
}


bool Escenario::mostrarElementos()
{
    p.pintar();
    int i;
    time++;
    if(cantEne<CANT_ENE && time%2000 == 0)
    {
        fxnuEnem.play();
        cantEne++;
    }
    if(p.mover())
    {
        if(hr.goal(p.get_x(), p.get_y()))
        {
            if(nextGoal == RED)
            {
                ++hr;
                nextGoal = Hearth::set_nextGoal(RED, BLUE, CIAN);
                hr.set_nuevo();
                hr.pintar_puntos();
                switch(nextGoal)
                {
                case RED:
                    hr.sayColour();
                    break;
                case BLUE:
                    hb.sayColour();
                    break;
                case CIAN:
                    hc.sayColour();
                    break;
                }
            }
            else
            {
                --hr;
                hr.set_nuevo();
                hr.pintar_puntos();
            }
        }
        if(hb.goal(p.get_x(), p.get_y()))
        {
            if(nextGoal == BLUE)
            {
                ++hb;
                hb.set_nuevo();
                hr.pintar_puntos();
                nextGoal = Hearth::set_nextGoal(RED, BLUE, CIAN);
                switch(nextGoal)
                {
                case RED:
                    hr.sayColour();
                    break;
                case BLUE:
                    hb.sayColour();
                    break;
                case CIAN:
                    hc.sayColour();
                    break;
                }
            }
            else
            {
                --hb;
                hb.set_nuevo();
                hb.pintar_puntos();
            }
        }
        if(hc.goal(p.get_x(), p.get_y()))
        {
            if(nextGoal == CIAN)
            {
                ++hc;
                hc.set_nuevo();
                hr.pintar_puntos();
                nextGoal = Hearth::set_nextGoal(RED, BLUE, CIAN);
                switch(nextGoal)
                {
                case RED:
                    hr.sayColour();
                    break;
                case BLUE:
                    hb.sayColour();
                    break;
                case CIAN:
                    hc.sayColour();
                    break;
                }
            }
            else
            {
                --hc;
                hc.set_nuevo();
                hc.pintar_puntos();
            }
        }
        for(i=0; i<cantEne;i++)
            if(p.get_x() == e[i].get_x() && p.get_y() == e[i].get_y())
            return 1;
    }// fin if p.mover

    for(i=0; i<cantEne; i++)
        if(time%(5-i) == 0)
        {
            int e_x = e[i].get_x(),
                e_y = e[i].get_y();
            if(e_x==hr.get_x() && e_y == hr.get_y())
                hr.set_nuevo();
            else if(e_x==hb.get_x() && e_y == hb.get_y())
                hb.set_nuevo();
            else if(e_x==hc.get_x() && e_y == hc.get_y())
                hc.set_nuevo();
            if(e[i].seguir(p.get_x(), p.get_y()))
                return 1;
        }
        return 0;
}   // fin funcion

int Escenario::get_puntos()
{
    return hr.get_puntos();
}
