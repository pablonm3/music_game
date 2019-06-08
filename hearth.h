#ifndef HEARTH_H_INCLUDED
#define HEARTH_H_INCLUDED
#include "funciones.h"
#include "punto.h"

class Hearth : public Punto{
 public:
    Hearth(int=1);
    void pintar_puntos()const;
    void reset_ptos();
    void set_nuevo();
    int get_puntos();
    bool goal(int , int );
    Hearth& operator++();
    Hearth& operator--();
    void sayColour();
    static int set_nextGoal(int, int, int);
 private:
    static int puntos;
    sf::Music sound,// fx sound
              soundColour;
    char fx[30];
};



#endif // HEARTH_H_INCLUDED
