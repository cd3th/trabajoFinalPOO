//
// Created by Windows on 5/07/2019.
//

#ifndef AGREGACION_RESTAURANTE_H
#define AGREGACION_RESTAURANTE_H
#include "Objeto.h"
#include "Tipos.h"

class Restaurante: public Objeto{

    TipoString TipodeComida;
    TipoString Especialidad;
public:
    Restaurante(){};
    Restaurante(const TipoString& nombre,TipoCaracter color,TipoEntero posX,TipoEntero posY,TipoEntero Calificacion,
               const TipoString& _TipoComida, const TipoString& _Especialidad);
    void Mostrar_Especialidad();
    void Mostrar_TipodeComida();


};


#endif //AGREGACION_RESTAURANTE_H
