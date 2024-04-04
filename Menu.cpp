//
// Created by Administrador on 29/03/2024.
//

#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::mostrarMenuInicial()
{
    int opcion;
    cout << "Bienvenido a DevManagePRO" << endl;
    cout << "=== Menu Inicial===" << endl;

    cout << "1. Crear un nuevo proyecto" << endl;
    cout << "2. Cargar datos" << endl;
    cout << "3. Borrar datos" << endl;
    cout << "0. Salir del programa" << endl;
    cout << "Seleccione una opcion : ";
    cin >> opcion;
    return opcion;
}
int Menu::mostrarMenuPrincipal()
{
    int opcion;
    cout << "=== Menu Principal ===" << endl;

    cout << "1. Jefe" << endl;
    cout << "2. Desarrollador" << endl;
    cout << "0. Regresar" << endl;
    cout << "Seleccione su rol: ";
    cin >> opcion;
    return opcion;
}

int Menu::mostrarMenuProgramador()
{
    int opcion;
    cout << "=== Menu del Programador ===" << endl;

    cout << "1. Ver mis tareas pendientes" << endl;
    cout << "2. Realizar tarea " << endl;
    cout << "3. Ver todas las tareas del Proyecto" << endl;
    cout << "4. Ver todas las tareas pendientes del proyecto " << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

int Menu::mostrarMenuJefe()
{
    int opcion;
    cout << "=== Menu del Jefe ===" << endl;
    cout << "1. Contratar programador " << endl;
    cout << "2. Despedir Programador" << endl;
    cout << "3. Agregar nueva tarea" << endl;
    cout << "4. Eliminar tarea" << endl;
    cout << "5. Asignar tarea a programador" << endl;
    cout << "6. Actualizar fecha limite de tarea" << endl;
    cout << "7. Ver todas las tareas del Proyecto " << endl;
    cout << "8. Ver tareas pendientes" << endl;
    cout << "9. Ver lista de trabajadores" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

string Menu::verificacion()
{
    string id;
    cout << "Por favor ingrese su ID " << endl;
    cout << "ID : ";
    cin >> id;
    return id;
}
