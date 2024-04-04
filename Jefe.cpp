//
// Created by Administrador on 29/03/2024.
//

#include "Jefe.h"

Jefe::Jefe(const string &_nombre, const string &_id) : Trabajador(_nombre, _id) {}
Jefe::Jefe() : Trabajador("", ""){}
Jefe::Jefe(const Jefe &otro) : Trabajador(otro){}
