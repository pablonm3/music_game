#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "funciones.h"
#include "punto.h"

class Enemigo : public Punto{
 public:
    Enemigo(int= ENEMY_COLOR);
    int seguir(int , int);
    void pintar1();
};


#endif // ENEMIGO_H_INCLUDED
