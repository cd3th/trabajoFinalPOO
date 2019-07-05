//
// Created by Windows on 5/07/2019.
//

#ifndef AGREGACION_MUSEO_H
#define AGREGACION_MUSEO_H


#include "Tipos.h"
#include "Objeto.h"

class Museo: public Objeto {
private:
    TipoString ExposicionActual;
public:
    Museo(){};
    Museo(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, TipoEntero calificacion,const TipoString& _Exposicion);
void mostrarExposicionActual();
};


#endif //AGREGACION_MUSEO_H
