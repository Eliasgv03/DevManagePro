//
// Created by Administrador on 29/03/2024.
//

#include "Trabajador.h"

Trabajador::Trabajador() : id(""), nombre("") {}

Trabajador::Trabajador(const string &nombre_, const string &id_) : nombre(nombre_), id(id_) {}

Trabajador::Trabajador(const Trabajador &otro) : id(otro.id), nombre(otro.nombre){};

Trabajador::~Trabajador(){};

void Trabajador::copyFrom(const Trabajador &otro)
{
    nombre = otro.nombre;
    id = otro.id;
}

string Trabajador::getNombre() const
{
    return nombre;
}

string Trabajador::getId() const
{
    return id;
}
