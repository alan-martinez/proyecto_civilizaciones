#include "aldeano.h"

// Aldeano::Aldeano()
// {

// }

// Aldeano::Aldeano(const string &nombre, size_t edad, const string &genero, size_t salud)
// {
//     this->nombre = nombre;
//     this->edad = edad;
//     this->genero = genero;
//     this-> salud = salud;
// }


void Aldeano::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

string Aldeano::getNombre() const
{
    return nombre;
}

void Aldeano::setEdad(int edad)
{
    this->edad = edad;
}

int Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this->genero = genero;
}

string Aldeano::getGenero() const
{
    return genero;
}

void Aldeano::setSalud(int salud)
{
    this->salud = salud;
}

int Aldeano::getSalud() const
{
    return salud;
}
