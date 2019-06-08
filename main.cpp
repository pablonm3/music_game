#include "funciones.h"
#include "escenario.h"

int main()
{
    char song[30],
         tecla;
    FILE *F;
    F = fopen("record.dat", "rb+");
    if(!F)
        return -1;
    Escenario s;
    bool game_over = false;
    srand (time(NULL));
    random_music(song, 1, MAXBACK);
    sf::Music music;
    if (!music.openFromFile(song))
    {
        cerr <<"MUSIC NOT FOUND";
        return -1;
    }

    do{
        music.setLoop(true);
        tecla = 'a';
        music.play();
        ocultar_cursor();
        while(!game_over)
        {
            game_over = s.mostrarElementos();
            Sleep(30);
        }   // fin while: fin juego
        music.stop();
        music.openFromFile("music/nextGoal/error.wav");
        music.play();
        system("cls");
        gotoxy(COL/2-20, FIL/2);
        cout << "JUEGO TERMINADO, SU PUNTAJE: " << s.get_puntos()<<endl;
        gotoxy(COL/2-20, FIL/2+1);
        Sleep(1000);
        music.stop();
        muestra_record(F, s.get_puntos());
        gotoxy(COL/2-20, FIL/2+3);
        cout<<"ingrese S para jugar de nuevo: ";
        fflush(stdin);
        tecla = getchar();
    if(tecla == 's')
    {
        music.stop();
        random_music(song, 1, MAXBACK);
        game_over = false;
        music.openFromFile(song);
        s.reset();
    }
    }while(tecla == 's');
    fclose(F);
    return 0;
}

