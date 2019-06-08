#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED
#include "funciones.h"
#include "personaje.h"
#include "hearth.h"
#include "enemigo.h"

class Escenario{
public:
    Escenario();    //PINTA ESCENARIO
    void reset();
    bool mostrarElementos();
    int get_puntos();

private:
    Personaje p;
    int nextGoal,
        cantEne,
        time;
    sf::Music fxnuEnem;
    Enemigo e[CANT_ENE];
    Hearth hr,
           hb,
           hc;
};


#endif // ESCENARIO_H_INCLUDED
