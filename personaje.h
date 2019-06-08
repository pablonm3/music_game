#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include "funciones.h"
#include "punto.h"


class Personaje : public Punto{
  public:
    Personaje(int=PER_COLOR);
    bool mover();
};


#endif // PERSONAJE_H_INCLUDED
