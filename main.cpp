#include <iostream>
#include <ctime>
#include "Trabajador.h"
#include "Jefe.h"
#include "Desarrollador.h"
#include "Proyecto.h"
#include <sstream>
#include <iomanip>
#include "Menu.h"
#include <fstream>

void borrarDatosArchivo(const std::string &nombreArchivo)
{
    std::ofstream archivo(nombreArchivo, std::ios::out | std::ios::binary);
    if (archivo.is_open())
    {
        // No se escribe nada en el archivo, lo que efectivamente borra todos los datos.
        archivo.close();
        std::cout << "Datos borrados exitosamente del archivo " << nombreArchivo << std::endl;
    }
    else
    {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << " para escritura" << std::endl;
    }
}
time_t stringToTime(const string &dateString)
{
    struct tm tm = {};
    std::istringstream ss(dateString);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    time_t time = mktime(&tm);
    return time;
}

string timeToString(const time_t &time)
{
    std::stringstream ss;
    ss << std::put_time(localtime(&time), "%Y-%m-%d");
    return ss.str();
}

bool esAnhoBisiesto(int anho)
{
    return (anho % 4 == 0 && anho % 100 != 0) || (anho % 400 == 0);
}

bool esFechaValida(int anho, int mes, int dia)
{
    if (mes < 1 || mes > 12 || dia < 1)
    {
        return false;
    }

    int diasEnMes;
    if (mes == 2)
    {
        diasEnMes = esAnhoBisiesto(anho) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        diasEnMes = 30;
    }
    else
    {
        diasEnMes = 31;
    }

    return dia <= diasEnMes;
}

bool esFechaFutura(time_t fecha)
{
    time_t ahora = time(nullptr);
    return fecha > ahora;
}

bool verificarFecha(const std::string &fechaStr)
{
    struct tm tm = {};
    istringstream ss(fechaStr);
    ss >> get_time(&tm, "%Y-%m-%d");

    if (ss.fail())
    {
        cerr << "Formato de fecha invalido. Utilice el formato AAAA-MM-DD." << endl;
        return false;
    }

    int anho = tm.tm_year + 1900; // tm_year es el numero de años desde 1900
    int mes = tm.tm_mon + 1;      // tm_mon es el numero de meses desde enero (0-11)
    int dia = tm.tm_mday;

    if (!esFechaValida(anho, mes, dia))
    {
        cerr << "La fecha ingresada no es valida." << endl;
        return false;
    }

    time_t fecha = mktime(&tm);
    if (!esFechaFutura(fecha))
    {
        cerr << "La fecha ingresada no es futura." << endl;
        return false;
    }

    return true;
}

using namespace std;

int main()
{
/*ESTE ES UN EJEMPLO PARA PROBAR EL CODIGO CON EL CUAL SE PUEDE PROBAR TODAS LAS FUNCIONABILIDADES DEL PROGRAMA
  DE IGUAL FORMA SE RECOMIENDA CREAR UN NUEVO PROYECTO
  PROXIMAMENTE SE IMPLEMENTARA EL SISTEMA DE PERMANENCIA DE DATOS
*/
    Proyecto proyecto("C++");

    Jefe jefe("Saborit", "000");
    proyecto.setJefe(&jefe);

    Desarrollador desarrollador1("Pedro", "001", "Frontend");
    Desarrollador desarrollador2("Carlos", "002", "Backend");
    Desarrollador desarrollador3("Rene" , "003" ,"Movil" );
    proyecto.agregarDesarrollador(desarrollador1);
    proyecto.agregarDesarrollador(desarrollador2);
    proyecto.agregarDesarrollador(desarrollador3);

    Tarea t1("Tarea1", stringToTime("2024-04-15"), "Pendiente");
    Tarea t2("Tarea2", stringToTime("2024-03-30"), "Completada");
    Tarea t3("Tarea3", stringToTime("2024-04-25"), "Pendiente");
    Tarea t4("Tarea4" ,stringToTime("2024-04-17") , "Pendiente"  );
    Tarea t5("Tarea5" ,stringToTime("2024-04-12") , "Pendiente" );
    proyecto.agregarTarea(t1);
    proyecto.agregarTarea(t2);
    proyecto.agregarTarea(t3);
    proyecto.agregarTarea(t4);
    proyecto.agregarTarea(t5);

    proyecto.asignarTarea(t1.getId(), &desarrollador2);
    proyecto.asignarTarea(t2.getId(), &desarrollador3);
    proyecto.asignarTarea(t4.getId(), &desarrollador1);

    // 2  cout << t1.getAsignadoA()->getNombre() << endl ;
    /*     cout << "Tareas del proyecto " << endl;
         proyecto.mostrarTareasProyecto();
         proyecto.mostrarTareasPendientes();
         proyecto.realizarTarea("Tarea1", "789012");
         proyecto.mostrarTareasDesarrollador("789012");
   */
    //  string nombreArchivo = "datos_proyecto.bin";

    /*   // Verificar si el archivo existe
       ifstream archivo(nombreArchivo, ios::binary);
       if (!archivo) {
           // Si el archivo no existe, crearlo y cerrarlo
           ofstream crearArchivo(nombreArchivo, ios::binary);
           crearArchivo.close();
           cout << "Archivo creado exitosamente." << endl;
       } else {
           // Si el archivo existe, cerrarlo
           archivo.close();
       }*/
    while (true)
    {
        int opcionInicial = Menu::mostrarMenuInicial();
        switch (opcionInicial)
        {
        case 1:
        {
            //    borrarDatosArchivo(nombreArchivo);
            cout << "Crear un nuevo proyecto" << endl;
            cout << "Nombre de proyecto : " ;
            string nomp ;
            cin >> nomp ;
            Proyecto proyecto(nomp);
            string nombre, id;
            cout << "Ingrese sus datos personales " << endl;
            cout << "Nombre : ";
            cin >> nombre;
            cout << "ID : ";
            cin >> id;
            Jefe jefe1(nombre, id);
            proyecto.setJefe(&jefe1);
            cout << "Listo ya puede comenzar a gestionar su proyecto" << endl;
            cout << endl ;
            while (true)
            {
                cout << "Bienvenido " << jefe1.getNombre() << " a DEVMANAGEPRO" << endl ;
                cout << "Proyecto : " << proyecto.getNombre() << endl;
                cout << "Hay " << proyecto.cantTotalTareasPen() << " tareas pendientes " << endl;
                int opcionJefe = Menu::mostrarMenuJefe();
                switch (opcionJefe)
                {
                case 1:
                {
                    cout << "Contratar desarrollador" << endl;
                    string nombre1, id1, r1;
                    cout << "Ingrese los datos del Desarrollador " << endl;
                    cout << "Nombre : ";
                    cin >> nombre1;
                    cout << "ID : ";
                    cin >> id1;
                    cout << "Rol : ";
                    cin >> r1;
                    Desarrollador desarrollador1(nombre1, id1, r1);
                    if (proyecto.buscarDesarrollador(id1) != nullptr)
                    {
                        cout << "Datos ingresados incorrectos. Intentelo nuevamente\n";
                        break;
                    }
                    else
                    {
                        proyecto.agregarDesarrollador(desarrollador1);
                        cout << "Desarrollador agregado exitosamente\n";
                    }
                    cout << endl ;
                    break;
                }
                case 2:
                {
                    cout << "Despedir desarrollador" << endl;
                    string id2;
                    cout << "Ingrese el ID del desarrollador que desea despedir: ";
                    cin >> id2;
                    Desarrollador *desarrollador2 = proyecto.buscarDesarrollador(id2);
                    if (desarrollador2 != nullptr)
                    {
                        proyecto.despedirDesarrollador(*desarrollador2);
                    }
                    else
                    {
                        cout << "El ID ingresado no corresponde a ningun desarrollador." << endl;
                        break ;
                    }
                    cout << endl ;
                    break;
                }
                case 3:
                {
                    while (true)
                    {
                        cout << "Agregar tarea" << endl;
                        string idTarea1, fecha1;
                        cout << "Inserte los datos y especificaciones de la nueva tarea" << endl;
                        cout << "Id : ";
                        cin >> idTarea1;

                        cout << "Fecha limite (FORMATO AAAA-MM-DD ) : ";
                        cin >> fecha1;

                        if (!verificarFecha(fecha1))
                        {
                            //  cout << "La fecha ingresada no es valida o no es futura. Intente nuevamente."<< endl;
                            continue; // Volver al inicio del bucle y pedir nuevamente la fecha
                        }
                        if (proyecto.buscarTarea(idTarea1) == nullptr)
                        {
                            Tarea tarea1(idTarea1, stringToTime(fecha1), "Pendiente");
                            proyecto.agregarTarea(tarea1);
                            cout << "Tarea agregada con exito " << endl;

                            cout << "Desea asignarle la Tarea a algun trabajador ? " << endl;
                            cout << "1. SI" << endl;
                            cout << "2. NO" << endl;
                            int op;
                            cin >> op;
                            if (op == 1)
                            {
                                cout << "Ingrese el Id del desarrollador " << endl;
                                cout << "ID : ";
                                string id3;
                                cin >> id3;
                                Desarrollador *desarrollador3 = proyecto.buscarDesarrollador(id3);
                                if (desarrollador3 == nullptr)
                                {

                                    cout << "Id de desarrollador incorrecto , intentelo nuevamente " << endl;
                                    cout << endl ;
                                    break;
                                }
                                else
                                {
                                    proyecto.asignarTarea(idTarea1, desarrollador3);
                                    cout << "Tarea Asignada con exito " << endl;
                                    cout << endl ;
                                }
                            }
                        }
                        else
                        {
                            cout << "Esta tarea ya existe " << endl;
                        }
                        cout << endl ;
                        break;
                    }

                    break;
                }
                case 4:
                {
                    cout << "Eliminar tarea" << endl;
                    string idTarea2;
                    cout << "Ingrese el ID de la tarea que desea eliminar: ";
                    cin >> idTarea2;
                    Tarea *tarea2 = proyecto.buscarTarea(idTarea2);
                    if (tarea2 != nullptr)
                    {
                        proyecto.eliminarTarea(*tarea2);
                    }
                    else
                    {
                        cout << "El ID ingresado no corresponde a ninguna tarea." << endl;
                    }
                    cout << endl ;
                    break;
                }
                case 5:
                {
                    cout << "Asignar Tarea" << endl;
                    while (true)
                    {
                        string idTarea3, id4;
                        cout << "Ingrese el ID de la tarea que desea asignar: ";
                        cin >> idTarea3;
                        cout << "Ingrese el ID del desarrollador al que desea asignar la tarea: ";
                        cin >> id4;
                        Tarea *tarea3 = proyecto.buscarTarea(idTarea3);
                        Desarrollador *desarrollador4 = proyecto.buscarDesarrollador(id4);
                        //   cout << (*desarrollador4).datos() << endl ;
                        if (tarea3 == nullptr || desarrollador4 == nullptr)
                        {
                            cout << "Datos incorrectos. Intente nuevamente." << endl;
                            cout << endl ;
                            continue;
                        }
                        else if (tarea3->getAsignadoA() != nullptr)
                        {
                            cout << "Esta tarea ya ha sido asignada. Desea reasignarla ?" << endl;
                            cout << "1. SI" << endl;
                            cout << "2. NO" << endl;
                            int op2;
                            cin >> op2;
                            if (op2 == 1)
                            {
                                proyecto.asignarTarea(idTarea3, desarrollador4);
                                cout << endl ;
                            }
                            break;
                        }
                        else
                        {
                            proyecto.asignarTarea(idTarea3, desarrollador4);
                            cout << endl ;
                            break;
                        }
                    }
                    break;
                }
                case 6:
                {
                    cout << "Actualizar fecha limite de tarea " << endl;
                    string idTarea, nuevaFecha;
                    cout << "Ingrese el ID de la tarea que desea actualizar su fecha limite: ";
                    cin >> idTarea;
                    cout << "Ingrese la nueva fecha limite para la tarea (FORMATO AAAA-MM-DD): ";
                    cin >> nuevaFecha;
                    if (verificarFecha(nuevaFecha))
                    {
                        Tarea *tarea = proyecto.buscarTarea(idTarea);
                        if (tarea != nullptr)
                        {
                            proyecto.actualizarTarea(tarea, nuevaFecha);
                        }
                        else
                        {
                            cout << "El ID ingresado no corresponde a ninguna tarea." << endl;
                            cout << endl ;
                        }
                    }
                    else
                    {
                        cout << "La fecha ingresada no es valida o no es futura. Intente nuevamente."
                             << endl;
                        cout << endl ;
                    }
                    break;
                }
                case 7:
                {
                    cout << "Lista de Tareas" << endl;
                    proyecto.mostrarTareasProyecto();
                    cout << endl ;
                    break;
                }
                case 8:
                {
                    cout << "Lista de Tareas Pendientes" << endl;
                    proyecto.mostrarTareasPendientes();
                    cout << endl ;
                    break;
                }
                case 9:
                    cout << "Lista de Desarrolladores " << endl;
                    proyecto.mostrarDesarrolladores();
                        cout << endl ;
                    break;
                case 0:
                {

                    cout << "Desea guardar los cambios ? " << endl;
                    cout << "1. SI" << endl;
                    cout << "2. NO" << endl;
                    int op;
                    cin >> op;
                    if (op == 1)
                    {
                        //            proyecto.guardarDatosEnArchivo("datos_proyecto.bin");
                    }

                    cout << "Saliendo del programa " << endl;
                    break;
                }
                default:
                {
                    cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                    break;
                }
                }

                if (opcionJefe == 0)
                {
                    break; // Salir del bucle si se selecciona la opcion 0 (Regresar)
                }
            }
            break;
        }
        case 2:
        {
            // Logica para cargar datos
            cout << "Cargando Datos..." << endl;
            //     proyecto.cargarDatosDesdeArchivo("datos_proyecto.bin");
            cout << "Proyecto : " << proyecto.getNombre() << endl;
            // Mostrar menu para seleccionar si eres Jefe o Desarrollador
            int opcionRol = Menu::mostrarMenuPrincipal();
            switch (opcionRol) {
                case 1: {


                    Jefe *j = proyecto.getJefe();
                    string id;
                    id = Menu::verificacion();
                    string s = j->getId();
                    if (s == id) {
                        cout << "Usted se ha logueado con exito " << endl;
                        cout << endl;
                        while (true) {
                            cout << "Bienvenido " << j->getNombre() << " a DEVMANAGEPRO" << endl ;
                            cout << "Proyecto : " << proyecto.getNombre() << endl;
                            cout << "Hay " << proyecto.cantTotalTareasPen() << " tareas pendientes " << endl;
                            int opcionJefe = Menu::mostrarMenuJefe();
                            switch (opcionJefe) {
                                case 1: {
                                    cout << "Contratar desarrollador" << endl;
                                    string nombre1, id1, r1;
                                    cout << "Ingrese los datos del Desarrollador " << endl;
                                    cout << "Nombre : ";
                                    cin >> nombre1;
                                    cout << "ID : ";
                                    cin >> id1;
                                    cout << "Rol : ";
                                    cin >> r1;
                                    Desarrollador desarrollador1(nombre1, id1, r1);
                                    if (proyecto.buscarDesarrollador(id1) != nullptr) {
                                        cout << "Datos ingresados incorrectos. Intentelo nuevamente\n";
                                        cout << endl;
                                        break;
                                    } else {
                                        proyecto.agregarDesarrollador(desarrollador1);
                                        cout << "Desarrollador agregado exitosamente\n";
                                        cout << endl;
                                    }
                                    break;
                                }
                                case 2: {
                                    cout << "Despedir desarrollador" << endl;
                                    string id2;
                                    cout << "Ingrese el ID del desarrollador que desea despedir: ";
                                    cin >> id2;
                                    Desarrollador *desarrollador2 = proyecto.buscarDesarrollador(id2);
                                    if (desarrollador2 != nullptr) {
                                        proyecto.despedirDesarrollador(*desarrollador2);
                                    } else {
                                        cout << "El ID ingresado no corresponde a ningun desarrollador." << endl;
                                        break;

                                    }
                                    cout << endl;
                                    break;

                                }
                                case 3: {
                                    while (true) {
                                        cout << "Agregar tarea" << endl;
                                        string idTarea1, fecha1;
                                        cout << "Inserte los datos y especificaciones de la nueva tarea" << endl;
                                        cout << "Id : ";
                                        cin >> idTarea1;

                                        cout << "Fecha limite (FORMATO AAAA-MM-DD ) : ";
                                        cin >> fecha1;

                                        if (!verificarFecha(fecha1)) {
                                            //  cout << "La fecha ingresada no es valida o no es futura. Intente nuevamente."<< endl;
                                            continue; // Volver al inicio del bucle y pedir nuevamente la fecha
                                        }
                                        if (proyecto.buscarTarea(idTarea1) == nullptr) {
                                            Tarea tarea1(idTarea1, stringToTime(fecha1), "Pendiente");
                                            proyecto.agregarTarea(tarea1);
                                            cout << "Tarea agregada con exito " << endl;

                                            cout << "Desea asignarle la Tarea a algun trabajador ? " << endl;
                                            cout << "1. SI" << endl;
                                            cout << "2. NO" << endl;
                                            int op;
                                            cin >> op;
                                            if (op == 1) {
                                                cout << "Ingrese el Id del desarrollador " << endl;
                                                cout << "ID : ";
                                                string id3;
                                                cin >> id3;
                                                Desarrollador *desarrollador3 = proyecto.buscarDesarrollador(id3);
                                                if (desarrollador3 == nullptr) {

                                                    cout << "Id de desarrollador incorrecto , intentelo nuevamente "
                                                         << endl;
                                                    cout << endl;
                                                    break;
                                                } else {
                                                    proyecto.asignarTarea(idTarea1, desarrollador3);
                                                    cout << "Tarea Asignada con exito " << endl;
                                                    cout << endl;
                                                }
                                            }
                                        } else {
                                            cout << "Esta tarea ya existe " << endl;
                                        }
                                        cout << endl;
                                        break;
                                    }

                                    break;
                                }
                                case 4: {
                                    cout << "Eliminar tarea" << endl;
                                    string idTarea2;
                                    cout << "Ingrese el ID de la tarea que desea eliminar: ";
                                    cin >> idTarea2;
                                    Tarea *tarea2 = proyecto.buscarTarea(idTarea2);
                                    if (tarea2 != nullptr) {
                                        proyecto.eliminarTarea(*tarea2);
                                        cout << endl;
                                    } else {
                                        cout << "El ID ingresado no corresponde a ninguna tarea." << endl;
                                        cout << endl;
                                    }
                                    break;
                                }
                                case 5: {
                                    cout << "Asignar Tarea" << endl;
                                    while (true) {
                                        string idTarea3, id4;
                                        cout << "Ingrese el ID de la tarea que desea asignar: ";
                                        cin >> idTarea3;
                                        cout << "Ingrese el ID del desarrollador al que desea asignar la tarea: ";
                                        cin >> id4;
                                        Tarea *tarea3 = proyecto.buscarTarea(idTarea3);
                                        Desarrollador *desarrollador4 = proyecto.buscarDesarrollador(id4);
                                        //   cout << (*desarrollador4).datos() << endl ;
                                        if (tarea3 == nullptr || desarrollador4 == nullptr) {
                                            cout << "Datos incorrectos. Intente nuevamente." << endl;
                                            cout << endl;
                                            continue;
                                        } else if (tarea3->getAsignadoA() != nullptr) {
                                            cout << "Esta tarea ya ha sido asignada. Desea reasignarla ?" << endl;
                                            cout << "1. SI" << endl;
                                            cout << "2. NO" << endl;
                                            int op2;
                                            cin >> op2;
                                            if (op2 == 1) {
                                                proyecto.asignarTarea(idTarea3, desarrollador4);
                                                cout << endl;
                                            }
                                            break;
                                        } else {
                                            proyecto.asignarTarea(idTarea3, desarrollador4);
                                            cout << endl;
                                            break;
                                        }
                                    }
                                    break;
                                }
                                case 6: {
                                    cout << "Actualizar fecha limite de Tarea..." << endl;
                                    string idTarea, nuevaFecha;
                                    cout << "Ingrese el ID de la tarea que desea actualizar su fecha limite: ";
                                    cin >> idTarea;
                                    cout << "Ingrese la nueva fecha limite para la tarea (FORMATO AAAA-MM-DD): ";
                                    cin >> nuevaFecha;
                                    if (verificarFecha(nuevaFecha)) {
                                        Tarea *tarea = proyecto.buscarTarea(idTarea);
                                        if (tarea != nullptr) {
                                            proyecto.actualizarTarea(tarea, nuevaFecha);
                                        } else {
                                            cout << "El ID ingresado no corresponde a ninguna tarea." << endl;
                                            cout << endl;
                                        }
                                    } else {
                                        cout
                                                << "La fecha ingresada no es valida o no es futura. Intente nuevamente."
                                                << endl;
                                        cout << endl;
                                    }
                                    break;
                                }
                                case 7: {
                                    cout << "Lista de Tareas" << endl;
                                    proyecto.mostrarTareasProyecto();
                                    cout << endl;
                                    break;
                                }
                                case 8: {
                                    cout << "Lista de Tareas Pendientes" << endl;
                                    proyecto.mostrarTareasPendientes();
                                    cout << endl;
                                    break;
                                }
                                case 9:
                                    cout << "Lista de Desarrolladores " << endl;
                                    proyecto.mostrarDesarrolladores();
                                    cout << endl;
                                    break;
                                case 0: {

                                    cout << "Desea guardar los cambios ? " << endl;
                                    cout << "1. SI" << endl;
                                    cout << "2. NO" << endl;
                                    int op;
                                    cin >> op;
                                    if (op == 1) {
                                        //            proyecto.guardarDatosEnArchivo("datos_proyecto.bin");
                                    }

                                    cout << "Saliendo del programa " << endl;
                                    break;
                                }
                                default: {
                                    cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                                    break;
                                }
                            }
                            if (opcionJefe == 0) {
                                break; // Salir del bucle si se selecciona la opcion 0 (Regresar)
                            }
                        }
                    }
                    break;
                }
                case 2: {


                    Desarrollador *d3;
                    string id;
                    id = Menu::verificacion();
                    d3 = proyecto.buscarDesarrollador(id);
                    if (d3 != nullptr) {
                        while (true) {
                            cout << "Usted se ha logeado con exito" << endl;
                            cout << endl;
                            cout << "Bienvenido " << d3->getNombre()  << " a DEVMANAGEPRO" << endl ;
                            cout << "Proyecto : " << proyecto.getNombre() << endl;
                            cout << "Tiene " << proyecto.cantTareasPen(id) << " tareas pendientes " << endl;
                       //     cout << "Mostrando menu del Desarrollador..." << endl;
                            int opcionDesarrollador = Menu::mostrarMenuProgramador();
                            switch (opcionDesarrollador) {
                                case 1:
                                    cout << "Mis Tareas pendientes : " << endl;
                                    proyecto.mostrarTareasDesarrollador(d3);
                                    cout << endl;
                                    break;
                                case 2: {
                                    string idTarea ;

                                    cout << "Ingrese el ID de la tarea: ";
                                    cin >> idTarea;
                                    proyecto.realizarTarea(idTarea, id);
                                    break;
                                }
                                case 3: {
                                    cout << "Lista total de tareas del proyecto" << endl;
                                    proyecto.mostrarTareasProyecto();
                                    cout << endl;
                                    break;
                                }
                                case 4:
                                    cout << "Lista total de las Tareas Pendientes del proyecto " << endl;
                                    proyecto.mostrarTareasPendientes();
                                    cout << endl;
                                    break;
                                case 0:

                                    cout << "Desea guardar los cambios ? " << endl;
                                    cout << "1. SI" << endl;
                                    cout << "2. NO" << endl;
                                    int op;
                                    cin >> op;
                                    if (op == 1) {
                                        //        proyecto.guardarDatosEnArchivo("datos_proyecto.bin");
                                    }
                                    cout << "Saliendo del programa " << endl;

                                    break;
                                default:
                                    cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                            }
                            if (opcionDesarrollador == 0) {
                                break; // Salir del bucle si se selecciona la opcion 0 (Regresar)
                            }
                        }
                    } else {
                        cout << "ID de desarrollador incorrecto, intente nuevamente." << endl;
                    }
                    break;
                }
                case 0: {
                    cout << "Regresando ..." << endl;
                    break;
                }
                default: {
                    cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                    break;
                }


            }
            if ( opcionInicial == 0)
            {
                break; // Salir del bucle si se selecciona la opcion 0 (Regresar)
            }

            break;
        }
        case 3:
        {
            cout << "Esta seguro de eliminar todos los datos ?" << endl;
            cout << "1.SI" << endl;
            cout << "2.NO" << endl;
            int op;
            cin >> op;
            if (op == 1)
            {
                //            borrarDatosArchivo(nombreArchivo);
            }
            break;
        }
        case 0:
        {
            cout << "Saliendo del programa..." << endl;
            return 0 ;
        }
        default:
        {
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
        }
    }
}
