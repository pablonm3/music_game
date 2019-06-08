#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
#define MAXBACK 6
#define MAXGOAL 4
#define FIL 35
#define COL 100
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define DOWN_RIGHT 'd'
#define DOWN_LEFT 'a'
#define UP_LEFT 'q'
#define UP_RIGHT 'e'
#define MINN 1
#define RED 4
#define BLUE 9
#define CIAN 3
#define ENEMY_COLOR 5
#define PER_COLOR 2
#define CANT_ENE 3
typedef struct{
    char nombre[100];
    int puntos;
}t_reg;

void gotoxy(int , int);
void ocultar_cursor();
void random_music(char *music, int mod, int Max);
void muestra_record(FILE *F, int);
/* MODO 1 : BACKGROUD
   MODO 2 : GOAL
   MODO 3 : BAD GOAL
   MODO 4 : DEAD
   MODO 5 : SUPER POWER
*/

#endif // FUNCIONES_H_INCLUDED
