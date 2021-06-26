#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

#include "aldeano.h"
#include "barco.h"
#include <list>

//implentacion act: 14
//#include "guerrero.h"

class Civilizacion
{
    list <Aldeano> aldeano;

    //act 14:
    list <Barco *> puerto;


    string nombre;
    int ubicacion_x;
    int ubicacion_y;
    int puntuacion;


public:
    Civilizacion();
    Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion);

    void setNombre(const string &nombre);
    string getNombre();

    void setUbicacion_x(int ubicacion_x);
    int getUbicacion_x();

    void setUbicacion_y(int ubicacion_y);
    int getUbicacion_y();

    void setPuntuacion(int puntuacion);
    int getPuntuacion() const;

    //Implementacion Actividad 13


    void agregarFinalAldeano (const Aldeano &a);
    void agregarInicioAldeano (const Aldeano &a);

    //Eliminar
    void eliminar(const string &nombre);
    // 2. Eliminar aldeanos donde su salud sea menor a `x` (pedir la salud al usuario).
    void eliminarSalud(int salud);
    //Eliminar aldeanos donde su edad sea mayor igual a 60.
    void eliminarEdad();

    //  1. Clasificar la lista de aldeanos por nombre (ascendente).
    void ordenarNombre();
    // 2. Clasificar la lista de aldeanos por edad (descendente).
    void ordenarEdad();
    // 3. Ordenar la lista de aldeanos por salud (descendente).
    void ordenarSalud();

    // La opción Buscar aldeano pide el nombre del aldeano, 
    // la busca en el list<Aldeano> y si la encuentra muestra la información del aldeano.
    Aldeano *buscar(string nombre);

    // La opción Modificar aldeano pide el nombre del aldeano, lo busca en la list<Aldeano> 
    // y si la encuentra hacer lo siguiente: mostrar la información del aldeano y un pequeño 
    // menú para modificar los atributos -nombre, edad, género, salud-  del aldeano).
    void modificar(Aldeano *ptr);
    //Aldeano *modificar(string nombre);

    //Actividad 14
    void respaldarAldeano();
    void recuperarAldeano();

    void mostrar();

    //act 14:
    void agregarBarco (Barco *b)
    {
       puerto.push_back(b);
    }

    void capturarBarco (Civilizacion &c);

    void mostrarBarcos(Civilizacion &c);

    void buscarBarcos (Civilizacion &c);

    //void eliminarCombustible (float combustible);
    void eliminarCombustible (Civilizacion &c);
    
    void eliminarId (Civilizacion &c);

    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(10) << c.nombre;
        out << setw(12) << c.ubicacion_x;
        out << setw(12) << c.ubicacion_y;
        out << setw(10) << c.puntuacion;

        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        string temp;

        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion X: ";
        cin >> c.ubicacion_x;
        //getline(cin, c.ubicacion_x);

        cout << "Ubicacion Y: ";
        cin >> c.ubicacion_y;
        //getline (cin, c.ubicacion_y);

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion&c)
    {
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion&c) const
    {
        return nombre < c.nombre;
    }

};


#endif