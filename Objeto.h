//
// Created by ruben on 6/10/19.
//

#ifndef AGREGACION_OBJETO_H
#define AGREGACION_OBJETO_H


#include <iostream>
#include "Tipos.h"

using namespace std;

class Objeto {
private:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoEntero    calificacion;
public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY,TipoEntero calificacion);

    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getColor();
    TipoEntero getcalificacion();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();


};


#endif //AGREGACION_OBJETO_H
