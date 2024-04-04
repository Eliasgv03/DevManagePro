//
// Created by Administrador on 29/03/2024.
//
#ifndef DEVMANAGE_PROYETO_H
#define DEVMANAGE_PROYETO_H

#include "Desarrollador.h"
#include "Jefe.h"
#include "Tarea.h"
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Proyecto
{
private:
    string nombre;
  vector<Desarrollador> desarrolladores;
  Jefe *jefe;
  vector<Tarea> tareas;

  void ordenarTareasPorFecha();
    void ordenarDesarrolladoresPorNombre();

public:
  // Constructor

    Proyecto();

    Proyecto(const string& nombre);

    // Método para obtener el nombre del proyecto
    string getNombre() const;

    // Método para establecer el nombre del proyecto
    void setNombre(const std::string& nombre);

  // Destructor
  ~Proyecto();

  void agregarDesarrollador(Desarrollador desarrollador);
  void despedirDesarrollador(const Desarrollador &desarrollador);
  // Setter para el jefe

  void setJefe(Jefe *jefe);

  Jefe *getJefe() const;

  // Metodos de busqueda
  Desarrollador *buscarDesarrollador(const string &id);
  Tarea *buscarTarea(const string &id);

  // Metodos para agregar y eliminar tareas
  void agregarTarea(const Tarea &tarea);
  void eliminarTarea(const Tarea &tarea);
  void actualizarTarea(Tarea *tarea, string nuevaFecha);
  // Metodo para asignar una tarea a un desarrollador
  void asignarTarea(const string &id, Desarrollador *desarrollador);

  // Metodo para realizar una tarea
  void realizarTarea(const string &idTarea, const string &idDesa);

  // Metodos para obtener la cantidad de tareas pendientes
  int cantTareasPen(string id);
  int cantTotalTareasPen();

  // Metodo para mostrar todas las tareas del proyecto
  void mostrarTareasProyecto();

  // Metodo para mostrar las tareas pendientes
  void mostrarTareasPendientes();

  // Metodo para mostrar las tareas de un desarrollador
  void mostrarTareasDesarrollador(Desarrollador *desarrollador);

  // Metodo para mostrar la lista de desarrolladores
  void mostrarDesarrolladores();

  // Funciones para convertir entre string y time_t
  string timeToString(const time_t &time) const;
  time_t stringToTime(const string &dateString);
};


#endif // DEVMANAGE_PROYETO_H