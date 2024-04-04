//
// Created by Administrador on 29/03/2024.
//

#include "Desarrollador.h"
#include <fstream>

Desarrollador::Desarrollador(const string &nombre_, const string &id_, const string &rol_)
    : Trabajador(nombre_, id_), rol(rol_) {}

Desarrollador::Desarrollador(const Desarrollador &otro) : Trabajador(otro), rol(otro.rol){};

Desarrollador::~Desarrollador() {}

void Desarrollador::copyFrom(const Desarrollador &otro)
{
    Trabajador::copyFrom(otro); // Copiar miembros de la clase base
    rol = otro.rol;
}

string Desarrollador::getRol() const
{
    return rol;
}

string Desarrollador::datos()
{
    return nombre + " " + id ;
}
