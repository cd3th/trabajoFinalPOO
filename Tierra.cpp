//
// Created by ruben on 6/10/19.
//

#include "Tierra.h"
#include "Objeto.h"
#include "Restaurante.h"
#include "Hotel.h"
#include "Museo.h"
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

Tierra::Tierra() {
    plano.resize(ALTURA);
    for (auto& item: plano)
        item.resize(ANCHO);
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {
    plano.resize(altura);
    for (auto& item: plano)
        item.resize(ancho);
}

Tierra::~Tierra() {}

void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
}

Objeto* Tierra::removerObjeto(string& nombre) {
    // Buscando objeto
    if (objetos.size() == 0)
      return nullptr;

    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
      return nullptr;
    // Eliminando objeto
    objetos.erase(iter);
    //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
    return *iter;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto& item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             <<"Direccion(coordenadas):"
             << item->mostrarPosicion()
             << " Tipo = " << item->getColor() << '\n';
        i++;

    }
}

void Tierra::actualizarTierra() {
    for (auto &row: plano)
        for (auto &cell: row)
            cell = COLOR;

    for (auto& item: objetos)
        plano[item->getPosX()][item->getPosY()]
                = item->getColor();
}

void Tierra::dibujarTierra() {
    cout << '\n';
    cout << setw(3) << ' ';
    for (auto j = 0; j < getAncho(); ++j)
        cout << setw(3) << j;
    cout << '\n';

    for (auto i = 0; i < getAltura(); ++i) {
        cout << setw(3) << i;
        for (auto j = 0; j < getAncho(); ++j) {
            cout << setw(3) << plano[i][j];
        }
        cout << '\n';
    }
}

TipoEntero Tierra::getAltura() {
    return plano.size();
}

TipoEntero Tierra::getAncho(){
    return plano[0].size();
}

void Tierra::UbicarMejoresTipos() {
    TipoEntero calfH=0,calfR=0,calfM=0;
    TipoString nomH,nomR,nomM;
    for (Objeto *tipo:objetos) {
        if (tipo->getColor() == 'H'){
            if(calfH<tipo->getcalificacion()) {
                calfH = tipo->getcalificacion();
                nomH=tipo->getNombre();
            }
        }
        else if(tipo->getColor() == 'R'){
            if(calfR<tipo->getcalificacion()) {
                calfR = tipo->getcalificacion();
                nomR=tipo->getNombre();
            }
        }
        else if(tipo->getColor() == 'M'){
            if(calfM<tipo->getcalificacion()) {
                calfM = tipo->getcalificacion();
                nomM=tipo->getNombre();
            }
        }
    }
    cout<<"Los mejores establecimiento del Lima son: "<<endl;
    if(calfH==0) cout<<"No hay evalacion aun para hoteles\n";
    else cout<<"Hotel: "<<nomH<<endl;
    if(calfR==0) cout<<"No hay evalacion aun para restaurantes\n";
    else cout<<"Restaurant: "<<nomR<<endl;
    if(calfM==0) cout<<"No hay evalacion aun para museos\n";
    else cout<<"Museo: "<<nomM<<endl;
}