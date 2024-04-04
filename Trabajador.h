//
// Created by Administrador on 29/03/2024.
//

#ifndef DEVMANAGE_TRABAJADOR_H
#define DEVMANAGE_TRABAJADOR_H

#include <string>

using namespace std;

class Trabajador
{
protected:
     string nombre;
     string id;

public:
    Trabajador();
    Trabajador(const string &nombre_, const string &id_);
    Trabajador(const Trabajador &otro);

    //   bool operator==(const Trabajador& otro) const;
    //  Trabajador& operator=(const Trabajador& otro);
    ~Trabajador();

    void copyFrom(const Trabajador &otro);
    string getNombre() const;
    string getId() const;

    bool operator<(const Trabajador &otroTrabajador) const
    {
        return nombre<otroTrabajador.getNombre();

    }
};
#endif // DEVMANAGE_TRABAJADOR_H