#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{
    string nombre;
    int edad;
    string genero;
    int salud;

public:
    Aldeano(){}
    Aldeano(const string &nombre, int edad, const string &genero, int salud)
    :nombre(nombre), edad(edad), genero(genero), salud(salud){}

    void setNombre(const string &nombre);
    string getNombre() const;

    void setEdad(int edad);
    int getEdad() const;

    void setGenero(const string &genero);
    string getGenero() const;

    void setSalud(int salud);
    int getSalud() const;


    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(10) << a.nombre;
        out << setw(12) << a.edad;
        out << setw(12) << a.genero;
        out << setw(10) << a.salud;

        return out;
    }

    // friend istream& operator>>(istream &in, Aldeano &a)
    // {
    //     string temp;

    //     cout << "Nombre: ";
    //     getline(cin, a.nombre);

    //     cout << "Edad: ";
    //     cin >> a.edad;

    //     cout << "Genero: ";
    //     getline (cin, a.genero);

    //     cout << "Salud: ";
    //     cin >> a.salud;

    //     return in;
    // }

    bool operator==(const Aldeano& a)
    {
        return nombre == a.nombre;
    }
    bool operator==(const Aldeano& a) const
    {
        return nombre == a.nombre;
    }

    bool operator<(const Aldeano&a)
    {
        return nombre < a.getNombre();
    }

    bool operator<(const Aldeano&a) const
    {
        return nombre < a.getNombre();
    }

};

#endif