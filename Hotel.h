//
// Created by Windows on 5/07/2019.
//

#ifndef AGREGACION_HOTEL_H
#define AGREGACION_HOTEL_H
#include "Objeto.h"
#include "Tipos.h"

class Hotel : public Objeto{
    TipoEntero Estrellas;
    TipoString Disponibilidad;
public:
    Hotel(){};
    Hotel(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, TipoEntero Calificacion, TipoEntero _Estrellas, const TipoString& _Disponibilidad);
    void mostrar_disponibilidad();
    void mostrar_Estrellas();
};



#endif //AGREGACION_HOTEL_H
