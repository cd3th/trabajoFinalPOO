//
// Created by Windows on 5/07/2019.
//

#include "Restaurante.h"
#include <iostream>
using namespace std;
Restaurante::Restaurante(const TipoString& nombre,TipoCaracter color,TipoEntero posX,TipoEntero posY,TipoEntero Calificacion,
                       const TipoString& _TipodeComida, const TipoString& _Especialidad):Objeto(nombre,color,posX,posY,Calificacion) {

    TipodeComida = _TipodeComida;
    Especialidad = _Especialidad;
}

void Restaurante::Mostrar_Especialidad(){
    cout<<"Especialidad"<<Especialidad<<endl;

}
void Restaurante::Mostrar_TipodeComida() {
    cout<<"Tipo de comida"<<TipodeComida<<endl;
}


