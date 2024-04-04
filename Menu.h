//
// Created by Administrador on 29/03/2024.
//

#ifndef DEVMANAGE_MENU_H
#define DEVMANAGE_MENU_H

#include <string>
using namespace std;
class Menu
{
public:
    static int mostrarMenuInicial();
    static int mostrarMenuPrincipal();
    static int mostrarMenuProgramador();
    static int mostrarMenuJefe();
    static string verificacion();
};

#endif // DEVMANAGE_MENU_H
