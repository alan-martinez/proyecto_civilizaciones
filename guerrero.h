#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>

using namespace std;

// enum class GuerreroTipo {LANCERO = 1,
//                          ARQUERO,
//                          PALADIN,
//                          };

class Guerrero
{
    string id; // - id
    int salud; //- salud (0 - 100) 
    float fuerza; //- salud (0.0 - 60.0)
    float escudo; // - escudo (0.0 - 30.0)
    string tipo; // - tipo de Guerrero (lancero, arquero, paladín, etc)
    //GuerreroTipo tipos;

public:
    Guerrero(){}
    Guerrero( const string  &id, int salud, float fuerza, float escudo, const string  &tipo)
    :id(id), salud(salud), fuerza(fuerza), escudo(escudo), tipo(tipo){}


    void setId(const string  &id);
    string getId() const;

    void setSalud(int salud);
    int getSalud() const;

    void setFuerza(float fuerza);
    float getFuerza() const;

    void setEscudo(float escudo);
    float getEscudo() const;

    void setTipo(const string &tipo);
    string getTipo() const;

    // void sGuerrero (const string &tipo);
    // GuerreroTipo getGuerreroTipo() const;

    friend ostream& operator<<(ostream &out, const Guerrero &g)
    {
        out << left;
        out << setw(10) << g.id;
        out << setw(10) << g.salud;
        out << setw(15) << g.fuerza;
        out << setw(12) << g.escudo;
        out << setw(15) << g.tipo;

        // out <<  setw(20) << right;
        // GuerreroTipo tipo = g.getGuerreroTipo();
        // if (tipo == GuerreroTipo::LANCERO) {
        //     out <<  "Lancero";
        // }
        // else if (tipo == GuerreroTipo::ARQUERO) {
        //     out << "Arquero";
        // }
        // else if (tipo == GuerreroTipo::PALADIN) {
        //     out << "Paladín";
        // }

        return out;
    }

    // friend istream& operator>>(istream &in, Guerrero &g)
    // {
    //     string temp;

    //     cout << "Id: ";
    //     //getline(cin, g.id);
    //     cin >> g.id;

    //     cout << "Salud: ";
    //     cin >> g.salud;
    //     //getline(cin, c.ubicacion_x);

    //     cout << "Fuerza: ";
    //     cin >> g.fuerza;
    //     //getline (cin, c.ubicacion_y);

    //     cout << "Escudo: ";
    //     cin >> g.escudo;

    //     cout << "Tipo: ";
    //     getline (cin, g.tipo);

    //     return in;
    // }
};

#endif 