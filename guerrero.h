#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>

using namespace std;


class Guerrero
{
    int id; // - id
    int salud; //- salud (0 - 100) 
    float fuerza; //- salud (0.0 - 60.0)
    float escudo; // - escudo (0.0 - 30.0)
    string tipo; // - tipo de Guerrero (lancero, arquero, paladín, etc)

public:
    Guerrero(){}
    Guerrero(int id, int salud, float fuerza, float escudo, string &tipo)
    :id(id), salud(salud), fuerza(fuerza), escudo(escudo), tipo(tipo){}


    void setId(int id);
    int getId() const;

    void setSalud(int salud);
    int getSalud() const;

    void setFuerza(float fuerza);
    float getFuerza() const;

    void setEscudo(float escudo);
    float getEscudo() const;

    void setTipo(string &tipo);
    string getTipo();

    friend ostream& operator<<(ostream &out, const Guerrero &g)
    {
        out << left;
        out << setw(10) << g.id;
        out << setw(10) << g.salud;
        out << setw(15) << g.fuerza;
        out << setw(12) << g.escudo;
        out << setw(15) << g.tipo;

        return out;
    }
};

#endif 