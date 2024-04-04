//
// Created by Administrador on 29/03/2024.
//

#ifndef DEVMANAGE_TAREA_H
#define DEVMANAGE_TAREA_H

#include "Desarrollador.h"
#include <ctime>
using namespace std;

class Tarea
{
private:
    string id ;
    Desarrollador *asignadoA;
    time_t fechaFinalizacion;
    string estado;

public:
    Tarea(const string &_id, const time_t &_fechaFinalizacion, const string &_estado);
    string getId()const;
    Desarrollador *getAsignadoA() const;
    time_t getFechaFinalizacion() const;
    string getEstado() const;

    bool operator==(const Tarea &otra) const;

    bool operator<(const Tarea &otraTarea) const
    {
        // Si una tarea es pendiente y la otra es completada, la tarea pendiente va primero
        if (estado != otraTarea.estado)
        {
            return estado == "Pendiente"; // Si la tarea actual es pendiente, va primero
        }

        // Si ambas tareas son pendientes o completadas, o ambas son completadas,
        // entonces se comparan por fecha de finalizacion
        if (estado == "Pendiente")
        {
            // Si las fechas de finalizacion son diferentes, ordenamos por fecha de finalizacion
            if (fechaFinalizacion != otraTarea.fechaFinalizacion)
            {
                return fechaFinalizacion < otraTarea.fechaFinalizacion;
            }
            // Si las fechas de finalizacion son iguales, no importa el estado
            return false; // No se cambia el orden, ya que son igualmente prioritarias
        }
        else
        {
            // Si ambas tareas son completadas, simplemente se comparan por fecha de finalizacion
            return fechaFinalizacion < otraTarea.fechaFinalizacion;
        }
    }

    void setEstado(const string _estado);
    void setAsignadoA(Desarrollador *_asignadoA);
    void setFechaFinalizacion(const time_t _fechaFinalizacion);
};
#endif // DEVMANAGE_TAREA_H