#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include "funciones.h"

class Punto
{
public:
    Punto();
    void pintar()const;
    int get_x()const;
    int get_y()const;
    void set_color(int);
    int get_color();
    void set_x(int);
    void set_y(int);
protected:
    void borrar()const;
    void set_fig(int);
private:
    int x,
        y,
        color;
    static const HANDLE hCon;
    char fig;

};


#endif // PUNTO_H_INCLUDED
