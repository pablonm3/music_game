#include "funciones.h"

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(hCon, Pos);
}

void ocultar_cursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cursor);
}

void random_music(char *music, int mod, int Max)
{
    int n = rand()%Max+1;
    switch(mod)
    {
    case 1: sprintf(music, "music/background/b%d.wav", n);
            break;
    case 2: sprintf(music, "music/goal/g%d.wav", n);
            break;
    }
}

void muestra_record(FILE *F, int puntos)
{
    t_reg reg;
    fseek(F, 0, 0);
    fread(&reg,sizeof(t_reg), 1, F);
    sf::Music song;

    if(puntos > reg.puntos)
    {
        if (!song.openFromFile("music/record.wav"))
            {
            cerr <<"MUSIC NOT FOUND";
            }
        else
            song.play();
        cout << "NUEVO RECORD INGRESE SU NOMBRE: ";
        cin.getline(reg.nombre, sizeof(reg.nombre));
        reg.puntos = puntos;
        fseek(F, 0, 0);
        fwrite(&reg, sizeof(t_reg), 1, F);
    }
    else
    {
        cout << "MEJOR PUNTUACION :  "<< reg.nombre<<",  puntos: "<<reg.puntos<<endl;
    }
}


