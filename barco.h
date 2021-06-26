#ifndef BARCO_H
#define BARCO_H

#include "guerrero.h"
#include <stack>

#include <iostream>
#include <iomanip>

class Barco
{
    //Agregar a la clase Barco un stack de la clase Guerrero
    stack <Guerrero> guerrero;

    //stack <Guerrero> copia(Guerrero);
    //vector <Guerrero> copia;
    // Implementar la clase Barco, la cual tendrá los siguientes atributos³:

    int id; // - id
    float combustible; // - combustible (0.0 - 100.0)
    float velocidad; // - velocidad (0.0 - 14.0)
    float armadura; // - armadura (0.0 - 100.0)
    int cantidad = 0;

public:
    Barco(){}
    Barco (int id, float combustible, float velocidad, float armadura, int cantidad = 0)
    : id(id), combustible(combustible), velocidad(velocidad), armadura(armadura), cantidad(cantidad){}

    void setId(int id);
    int getId() const;

    void setCombustible (float combustible);
    float getCombustible () const;

    void setVelocidad (float velocidad);
    float getVelocidad () const;

    void setArmadura (float armadura);
    float getArmadura () const;

    void setCantidad (int cantidad);
    int getCantidad () const;

    // - Agregar Guerrero *push()*.
    void agregarGuerrero(const Guerrero &g);
    // - Eliminar Guerrero *pop()*.
    void eliminarGuerrero (const Guerrero &g);
    // - Tope *top()*.
    void topeGuerrero (const Guerrero &g);

    friend ostream& operator<<(ostream &out, const Barco &b)
    {
        out << left;
        out << setw(10) << b.id;
        out << setw(15) << b.combustible;
        out << setw(12) << b.velocidad;
        out << setw(15) << b.armadura;
        out << setw(10) << b.cantidad;

        return out;
    }


    //probar
    bool operator==(const Barco& b)
    {
        return id == b.id;
    }
    bool operator==(const Barco& b) const
    {
        return id == b.id;
    }

    bool operator<(const Barco &b)
    {
        return id < b.id;
    }

    bool operator<(const Barco&b) const
    {
        return id < b.id;
    }

};


#endif