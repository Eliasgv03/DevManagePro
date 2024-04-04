//
// Created by Administrador on 29/03/2024.
//

#include "Tarea.h"
#include <fstream>
#include <iostream>

Tarea::Tarea(const string &_id, const time_t &_fechaFinalizacion, const string &_estado)
    : id(_id), fechaFinalizacion(_fechaFinalizacion), estado(_estado), asignadoA(nullptr) {}

bool Tarea::operator==(const Tarea &otra) const
{
    return this->id == otra.id; // Aqui debes comparar los campos relevantes para determinar la igualdad
}

string Tarea::getId()const
{
    return id;
}

Desarrollador *Tarea::getAsignadoA() const
{
    return asignadoA;
}

time_t Tarea::getFechaFinalizacion() const
{
    return fechaFinalizacion;
}

string Tarea::getEstado() const
{
    return estado;
}

void Tarea::setAsignadoA(Desarrollador *_asignadoA)
{
    asignadoA = _asignadoA;
}

void Tarea::setFechaFinalizacion(const time_t _fechaFinalizacion)
{
    fechaFinalizacion = _fechaFinalizacion;
}

void Tarea::setEstado(const string _estado) {
    estado = _estado;
}
