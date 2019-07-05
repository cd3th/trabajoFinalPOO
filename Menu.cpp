//
// Created by ruben on 6/10/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "Museo.h"
#include "Restaurante.h"
#include "Hotel.h"
using namespace std;

enum class Opciones { Agregar=1, Remover, Mostrar, Mejores};


void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
         w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout << "4. Los mejores locales\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    auto tipo=input<TipoCaracter >("Ingrese el tipo(Hotel=H,Restaurante=R,Museo=M):");
    auto nombre = input<TipoString>("Ingrese Nombre : ");
    auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
    auto calificacion = input<TipoEntero >("Ingrese la Calificacion del Establecimiento (1-5): ");

    auto x = input<TipoEntero>("Ingrese posicion X : ");

    while (x < 0 || x >= tierra.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << tierra.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }

    TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
    while (y < 0 || y >= tierra.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << tierra.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }

     if(tipo == 'M'){
        auto exposicion = input<TipoString >("Ingrese la Exposicion que se Exhibe en este momento: ");
        tierra.adicionarObjeto(new Museo(nombre,'M',x,y,calificacion,exposicion));
    }else if(tipo == 'R') {
         auto tipocomida = input<TipoString>("Ingrese el Tipo de Comida que se Sirve: ");
         auto especialidad = input<TipoString>("Ingrese la Especialidad del Restaurant): ");
         tierra.adicionarObjeto(new Restaurante(nombre, 'R', x, y, calificacion,
                                                tipocomida, especialidad));
     } else if(tipo == 'H'){
         auto estrellas = input<TipoEntero >("Ingrese la Cantidad de Estrellas del Hotel (1-7): ");
         auto disponibilidad = input<TipoString >("Ingrese la Disponibilidad del Hotel: ");
         tierra.adicionarObjeto(new Hotel(nombre,'H', x, y,calificacion,estrellas,disponibilidad));}

}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}

void Menu::ejecutar() {
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::MejoresTipos() {
    tierra.UbicarMejoresTipos();
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
      case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
      case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
      case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case  Opciones::Mejores: // Mostrar mejores
            MejoresTipos();
            break;
    }
}
