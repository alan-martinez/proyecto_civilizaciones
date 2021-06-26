#include "barco.h"

void Barco::setId(int id)
{  
    this->id = id;
}

int Barco::getId() const
{
    return id;
}

void Barco::setCombustible(float combustible)
{
    this->combustible = combustible;
}

float Barco::getCombustible() const
{
    return combustible;
}

void Barco::setVelocidad(float velocidad)
{
    this->velocidad = velocidad;
}

float Barco::getVelocidad() const
{
    return velocidad;
}

void Barco::setArmadura(float armadura)
{
    this->armadura = armadura;
}

float Barco::getArmadura() const
{
    return armadura;
}

void Barco::setCantidad(int cantidad = 0)
{
    this->cantidad = cantidad;
}

int Barco::getCantidad() const
{
    return cantidad;
}

void Barco::agregarGuerrero(const Guerrero &g)
{
    guerrero.push(g);
    cantidad = cantidad +1;
}

void Barco::eliminarGuerrero(const Guerrero &g)
{
    guerrero.pop();
}

void Barco::topeGuerrero(const Guerrero &g)
{
    auto const &e = guerrero.top();

    cout << "id        salud     fuerza         escudo    tipo" << endl;
    cout << e << endl;
    //cout << guerrero.top();
}

