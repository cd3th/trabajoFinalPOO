//
// Created by Windows on 5/07/2019.
//

#include "Hotel.h"
#include "Objeto.h"
#include <iostream>
using namespace std;


Hotel::Hotel(const TipoString &nombre, TipoCaracter color, TipoEntero posX, TipoEntero posY,
        TipoEntero Calificacion, TipoEntero _Estrellas,
             const TipoString &_Disponibilidad):Objeto(nombre,color,posX,posY,Calificacion) {
    Disponibilidad=_Disponibilidad;
    Estrellas=_Estrellas;
}

void Hotel::mostrar_Estrellas() {
    cout<<"Estrellas"<<Estrellas<<endl;
}
void Hotel::mostrar_disponibilidad() {
    cout<<"Disponibilidad"<<Disponibilidad<<endl;
}