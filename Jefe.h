//
// Created by Administrador on 29/03/2024.
//

#ifndef DEVMANAGE_JEFE_H
#define DEVMANAGE_JEFE_H

#include "Trabajador.h"
using namespace std;

class Jefe : public Trabajador
{
public:
    Jefe();
    Jefe(const Jefe &otro);
    Jefe(const string &_nombre, const string &_id);
};
#endif // DEVMANAGE_JEFE_H