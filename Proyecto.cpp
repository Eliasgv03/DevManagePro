//
// Created by Administrador on 29/03/2024.
//
#include "Proyecto.h"
#include <algorithm>
#include <iostream>
#include "Tarea.h"
#include "Desarrollador.h"
#include <sstream>
#include <iomanip>
#include <fstream> // Para trabajar con archivos

Proyecto::Proyecto() : jefe()
{
    // Otros inicializaciones si es necesario
}
Proyecto::Proyecto(const std::string& nombre) : nombre(nombre) {}

// Método para obtener el nombre del proyecto
string Proyecto::getNombre() const {
    return nombre;
}

// Método para establecer el nombre del proyecto
void Proyecto::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}
// Destructor
Proyecto::~Proyecto()
{
    // Cualquier limpieza necesaria
}

void Proyecto::agregarDesarrollador(Desarrollador desarrollador)
{
    desarrolladores.push_back(desarrollador);
    // cout << (desarrollador).datos()<< endl;
}
// Metodo para establecer el jefe

Jefe *Proyecto::getJefe() const
{
    return jefe;
}
void Proyecto::setJefe(Jefe *jefe)
{
    Proyecto::jefe = jefe;
}

void Proyecto::agregarTarea(const Tarea &tarea)
{
    tareas.push_back(tarea);
}

void Proyecto::ordenarTareasPorFecha()
{
    // Ordenar las tareas utilizando el operador de comparacion sobrecargado
    sort(tareas.begin(), tareas.end());
}

void Proyecto::mostrarTareasProyecto()
{
    // Ordenar las tareas por fecha y estado completado
    ordenarTareasPorFecha();

    // Mostrar las tareas ordenadas
    cout << endl ;
    cout << "ID       Desarrollador   Fecha Limite     Estado " << endl;
    cout << "--------------------------------------------------------" << endl;
    for (const auto &tarea : tareas)
    {
        if (tarea.getAsignadoA() == nullptr)
        {
            cout << tarea.getId() << "    "
                 << "NO ASIGNADA"
                 << "         "
                 << timeToString(tarea.getFechaFinalizacion()) << "         " << tarea.getEstado() << endl;
        }
        else
        {
            cout << tarea.getId() << "     " << tarea.getAsignadoA()->getNombre() << "         "
                 << timeToString(tarea.getFechaFinalizacion()) << "         " << tarea.getEstado() << endl;
        }
    }
}
void Proyecto::mostrarTareasPendientes()
{
    /*ordenarTareasPorFecha();
    cout << endl ;
    cout << "ID       Desarrollador   Fecha Limite   " << endl;
    cout << "---------------------------------------------" << endl;
    for (const auto &tarea : tareas)
    {
        if (tarea.getEstado() == "Pendiente" && tarea.getAsignadoA() == nullptr)
        {
            cout << tarea.getId() << "     "
                 << "NO ASIGNADA "
                 << "         "
                 << timeToString(tarea.getFechaFinalizacion()) << endl;
        }
        else if (tarea.getEstado() == "Pendiente")
        {
            cout << tarea.getId() << "     " << tarea.getAsignadoA()->getNombre() << "         "
                 << timeToString(tarea.getFechaFinalizacion()) << endl;
        }
    }*/

        ordenarTareasPorFecha();
        cout << endl ;
        cout << setw(10) << "ID" << setw(20) << "Desarrollador" << setw(15) << "Fecha Limite" << endl;
        cout << "---------------------------------------------" << endl;
        for (const auto &tarea : tareas) {
            if (tarea.getEstado() == "Pendiente" && tarea.getAsignadoA() == nullptr) {
                cout << setw(10) << tarea.getId() << setw(20) << "NO ASIGNADA" << setw(15) << timeToString(tarea.getFechaFinalizacion()) << endl;
            }
            else if (tarea.getEstado() == "Pendiente") {
                cout << setw(10) << tarea.getId() << setw(20) << tarea.getAsignadoA()->getNombre() << setw(15) << timeToString(tarea.getFechaFinalizacion()) << endl;
            }
        }

}

void Proyecto::mostrarTareasDesarrollador(Desarrollador *desarrollador)
{
    cout << endl;

    if (desarrollador == nullptr)
    {
        cout << "Error: Desarrollador no encontrado." << endl;
        return;
    }

    cout << "Tareas pendientes de " << desarrollador->getNombre() << ":" << endl;
    cout << setw(7) << "ID" << setw(28) << "Fecha Limite " << endl;
    cout << "-----------------------------------------" << endl;

    bool tareasEncontradas = false;

    for (const auto &tarea : tareas)
    {
        if (tarea.getAsignadoA() != nullptr && tarea.getAsignadoA()->getId() == desarrollador->getId() && tarea.getEstado() == "Pendiente")
        {
            cout << setw(10) << tarea.getId() << setw(20) << timeToString(tarea.getFechaFinalizacion()) << endl;
            tareasEncontradas = true;
        }
    }

    if (!tareasEncontradas)
    {
        cout << "No hay tareas asignadas a " << desarrollador->getNombre() << "." << endl;
    }
}

/*
void Proyecto::mostrarTareasDesarrollador(Desarrollador *desarrollador)
{
    cout << endl ;
    if (desarrollador == nullptr)
    {
        cout << "Error: Desarrollador no encontrado." << endl;
        return;
    }

    cout << "Tareas asignadas a " << desarrollador->getNombre() << ":" << endl;
    cout << setw(7) << "ID" << setw(28) << "Fecha Limite " << endl;
    cout << "-----------------------------------------" << endl;

    bool tareasEncontradas = false;

    for (const auto &tarea : tareas)
    {
        if (tarea.getAsignadoA()->getId() == desarrollador->getId())
        {
            cout << setw(10) << tarea.getId() << setw(20) << timeToString(tarea.getFechaFinalizacion()) << endl;
            tareasEncontradas = true;
        }
    }

    if (!tareasEncontradas)
    {
        cout << "No hay tareas asignadas a " << desarrollador->getNombre() << "." << endl;
    }
}

void Proyecto::realizarTarea(const string &idTarea, const string &idDesa)
{
    Desarrollador *d = buscarDesarrollador(idDesa);
    Tarea *t = buscarTarea(idTarea);

    if (d != nullptr && t != nullptr && t->getAsignadoA()->getId() == idDesa && t->getEstado() == "Pendiente")
    {
        t->setEstado("Completada");
        cout << "Tarea realizada con exito." << endl;
    }
    else
    {
        cout << "Error: La tarea ya esta completada o no tienes acceso a ella." << endl;
    }
}*/
void Proyecto::realizarTarea(const string &idTarea, const string &idDesa)
{
    // Buscar el desarrollador y la tarea
    Desarrollador *d = buscarDesarrollador(idDesa);
    Tarea *t = buscarTarea(idTarea);

    // Verificar si se encontraron el desarrollador y la tarea, y si la tarea está asignada al desarrollador
    if (d != nullptr && t != nullptr && t->getAsignadoA() != nullptr && t->getAsignadoA()->getId() == idDesa)
    {
        // Verificar si la tarea está pendiente
        if (t->getEstado() == "Pendiente")
        {
            // Marcar la tarea como completada
            t->setEstado("Completada");
            cout << "Tarea realizada con exito." << endl;
        }
        else
        {
            cout << "Error: La tarea ya esta completada." << endl;
        }
    }
    else
    {
        cout << "Error: La tarea no se encontro o no esta asignada a usted." << endl;
    }
}
Desarrollador *Proyecto::buscarDesarrollador(const string &id)
{
    for (auto &desa : desarrolladores)
    {
        if (desa.getId() == id)
        {
            return &desa;
        }
    }
    cout << "Desarrollador no encontrado." << endl;
    return nullptr;
}

Tarea *Proyecto::buscarTarea(const string &id)
{
    for (auto &tarea : tareas)
    {
        if (tarea.getId() == id)
        {
            return &tarea;
        }
    }
    cout << "Tarea no encontrada." << endl;
    return nullptr;
}

string Proyecto::timeToString(const time_t &time) const
{
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d");
    return ss.str();
}
void Proyecto::despedirDesarrollador(const Desarrollador &desarrollador)
{
/*
    for (Tarea &tarea : tareas)
    {
        if (tarea.getAsignadoA() == &desarrollador)
        {
            tarea.setAsignadoA(nullptr);
            return;
        }
    }

    for (int i = 0; i < desarrolladores.size(); i++)
    {
        if (desarrolladores[i].getId() == (desarrollador).getId())
        {
            for (int j = i; j < desarrolladores.size() - 1; i++)
            {
                desarrolladores[j].copyFrom(desarrolladores[j + 1]);
            }
        }
    }

    desarrolladores.pop_back();
    cout << "Despido realizado" << endl  ;*/

        // Buscar la tarea asignada al desarrollador y desasignarla
        for (auto &tarea : tareas)
        {
            if (tarea.getAsignadoA() == &desarrollador)
            {
                tarea.setAsignadoA(nullptr);
            }
        }


        // Eliminar al desarrollador del vector de desarrolladores
        auto it = remove_if(desarrolladores.begin(), desarrolladores.end(), [&desarrollador](const Desarrollador &des) {
            return des.getId() == desarrollador.getId();
        });

        if (it != desarrolladores.end())
        {
            desarrolladores.erase(it, desarrolladores.end());
            cout << "Desarrollador despedido exitosamente." << endl;
        }
        else
        {
            cout << "Error: No se encontró al desarrollador." << endl;
        }

}

void Proyecto::eliminarTarea(const Tarea &tarea)
{
    auto it = tareas.begin();
    while (it != tareas.end())
    {
        if (*it == tarea)
        {
            it = tareas.erase(it);
            cout << "Tarea eliminada exitosamente." << endl;
            return;
        }
        else
        {
            ++it;
        }
    }
    cout << "Error: No se encontró la tarea." << endl;
  /*  for (const auto &tarea1 : tareas){
        if (tarea1 == tarea){}
        {
            tareas.erase(tarea1);
        }
    }*/
    /*auto it = find(tareas.begin(), tareas.end(), tarea);
    if (it != tareas.end())
    {
        tareas.erase(it);
        cout << "Tarea eliminada exitosamente." << endl;
    }
    else
    {
        cout << "Error: No se encontro la tarea." << endl;
    }*/
}

void Proyecto::asignarTarea(const string &id, Desarrollador *desarrollador){

   for (auto &tarea : tareas)
    {
        if (tarea.getId() == id)
        {
            tarea.setAsignadoA(desarrollador);
            cout << "Tarea asignada exitosamente a " << desarrollador->getNombre() << "." << endl;
            return;
        }
    }
    cout << "Error: No se encontro la tarea con el ID especificado." << endl;



}

time_t Proyecto::stringToTime(const string &dateString)
{
    struct tm tm = {};
    std::istringstream ss(dateString);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    time_t time = mktime(&tm);
    return time;
}
void Proyecto::actualizarTarea(Tarea *tarea, string nuevaFecha)
{
    if (tarea != nullptr)
    {
        tarea->setFechaFinalizacion(stringToTime(nuevaFecha));
        cout << "Fecha de la tarea actualizada exitosamente." << endl;
    }
    else
    {
        cout << "Error: La tarea proporcionada no es valida." << endl;
    }
}

int Proyecto::cantTareasPen(string id){
        int cant = 0;
        for (const auto &tarea : tareas)
        {
            Desarrollador *asignadoA = tarea.getAsignadoA();
            if (asignadoA != nullptr && asignadoA->getId() == id && tarea.getEstado() == "Pendiente")
            {
                cant++;
            }
        }
        return cant;
}

int Proyecto::cantTotalTareasPen()
{
    int cant = 0;
    for (const auto &tarea : tareas)
    {
        if (tarea.getEstado() == "Pendiente")
        {
            cant++;
        }
    }
    return cant;
}
void Proyecto::ordenarDesarrolladoresPorNombre()
{
     sort(desarrolladores.begin(), desarrolladores.end());
}
void Proyecto::mostrarDesarrolladores()
{

    ordenarDesarrolladoresPorNombre();
    cout << "Nombre "
         << "  "
         << " ID "
         << "   "
         << " Rol "
         << "  "
         << " #Tareas " << endl;
    for (const auto &d : desarrolladores)
    {
        int a = cantTareasPen(d.getId()) ;

        cout << d.getNombre() << "  " << d.getId() << "   " << d.getRol() << "  " << a << endl;
    }
}
