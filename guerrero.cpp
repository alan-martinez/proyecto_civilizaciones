#include "guerrero.h"

void Guerrero::setId(int id)
{
    this->id = id;
}

int Guerrero::getId() const
{
    return id;
}

void Guerrero::setSalud(int salud)
{
    this->salud = salud;
}

int Guerrero::getSalud() const
{
    return salud;
}

void Guerrero::setFuerza(float fuerza)
{
    this->fuerza = fuerza;
}

float Guerrero::getFuerza() const
{
    return fuerza;
}

void Guerrero::setEscudo(float escudo)
{
    this->escudo = escudo;
}

float Guerrero::getEscudo() const
{
    return escudo;
}

void Guerrero::setTipo(string &tipo)
{
    this->tipo = tipo;
}

string Guerrero::getTipo()
{
    return tipo;
}
