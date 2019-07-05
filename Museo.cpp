//
// Created by Windows on 5/07/2019.
//

#include "Museo.h"
using namespace std;

Museo::Museo(const TipoString &nombre, TipoCaracter color, TipoEntero posX, TipoEntero posY, TipoEntero calificacion,
             const TipoString &_ExposicionAc):Objeto(nombre,color,posX,posY,calificacion) {
ExposicionActual=_ExposicionAc;
}
void Museo::mostrarExposicionActual(){
cout<<"La exposicion actual es:"<<ExposicionActual<<endl;
}

