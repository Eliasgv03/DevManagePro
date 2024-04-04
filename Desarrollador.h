//
// Created by Administrador on 29/03/2024.
//

#ifndef DEVMANAGE_DESARROLLADOR_H
#define DEVMANAGE_DESARROLLADOR_H

#include "Trabajador.h"
#include <vector>
using namespace std;

class Desarrollador : public Trabajador
{
private:
    string rol;

public:
    Desarrollador(const string &nombre_, const string &id_, const string &rol_);
    Desarrollador(const Desarrollador &otro);
    ~Desarrollador();

    void copyFrom(const Desarrollador &otro);

    // Metodo para obtener el valor del atributo rol (getter)
    string getRol() const;

    string datos();
};
#endif // DEVMANAGE_DESARROLLADOR_H