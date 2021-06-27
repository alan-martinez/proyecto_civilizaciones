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

void Barco::topeGuerrero()
{
    // auto const &e = guerrero.top();

    cout << "ID        Salud     Fuerza         Escudo      Tipo" << endl;
    // cout << e << endl;
    cout << guerrero.top() << endl;
}

void Barco::mostrar()
{
    stack <Guerrero> copia(guerrero);

    // cout << setw(10) << "ID";
    // cout << setw(15) << "Salud";
    // cout << setw(10) << "Fuerza";
    // cout << setw(15) << "Escudo";
    // cout << setw(15) << "Tipo";
    cout << "ID        Salud     Fuerza         Escudo      Tipo" << endl;
    while (! copia.empty())
    {
        auto const &g = copia.top();
        cout << g << endl;

        copia.pop();
    }
}

