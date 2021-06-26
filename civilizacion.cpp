#include "civilizacion.h"
#include <fstream>
#include <iostream>
//#include <stack>

using namespace std;

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion)
{
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &nombre)
{
    this->nombre=nombre;
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicacion_x(int ubicacion_x)
{
    this->ubicacion_x = ubicacion_x;
}

int Civilizacion::getUbicacion_x()
{
    return ubicacion_x;
}

void Civilizacion::setUbicacion_y(int ubicacion_y)
{
    this->ubicacion_y = ubicacion_y;
}

int Civilizacion::getUbicacion_y()
{
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(int puntuacion)
{
    this->puntuacion = puntuacion;
}

int Civilizacion::getPuntuacion() const
{
    return puntuacion;
}


void Civilizacion::agregarFinalAldeano(const Aldeano &a)
{
    aldeano.push_back(a);
    puntuacion = puntuacion + 100;
}

void Civilizacion::agregarInicioAldeano(const Aldeano &a)
{
    aldeano.push_front(a);
    puntuacion = puntuacion + 100;
}

void Civilizacion::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(12) << "Edad";
    cout << setw(12) << "Genero";
    cout << setw(10) << "Salud";
    cout << endl;

    for (auto it = aldeano.begin(); it!= aldeano.end(); it++)
    {
        cout << *it << endl;

    }
}

void Civilizacion::eliminar(const string &nombre)
{
    for (auto it = aldeano.begin(); it != aldeano.end(); it++){
        Aldeano &a = *it;

        if (nombre == a.getNombre()){
            aldeano.erase(it);
            break;
        }
    }
}

// bool comparador(const Aldeano &a)
// {
//     size_t salud;
//     cout << "Introduce la salud del aldeano: " << endl;
//     cin >> salud; cin.ignore();
//     cout << "Se eliminara los aldeanos de salud menor a: " + salud << endl;

//     return a.getSalud() < salud;
// }

void Civilizacion::eliminarSalud(int salud)
{
    //aldeano.remove_if(comparador);
    aldeano.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

bool comparadorEdad(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeano.remove_if(comparadorEdad);
}

void Civilizacion::ordenarNombre()
{
    aldeano.sort();
}

bool comparadoraEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad()
{
    aldeano.sort(comparadoraEdad);
}

void Civilizacion::ordenarSalud()
{
    aldeano.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscar(string nombre)
{
    for (auto it = aldeano.begin(); it != aldeano.end(); it++){
        Aldeano &a = *it;
        if (nombre == a.getNombre())
        {
            return &(*it);
        }
    }
    return nullptr;
}

void Civilizacion::modificar(Aldeano *ptr)
{
    size_t i;
    size_t pos = 0;
    size_t op;

    string nombreNuevo;
    int edadNueva;
    string generoNuevo;
    int saludNueva;

    // for (i = 0; i < aldeano.size(); i++)
    // {
    //     for (auto it = aldeano.begin(); it != aldeano.end(); it++)
    //     {
            Aldeano &a = *ptr;
            if (ptr->getNombre() == a.getNombre())
            {
                pos = 1;
                cout << endl;
                cout << "Datos del aldeano: " << endl;
                cout << "Nombre: " << a.getNombre() << endl; 
                cout << "Edad: " << a.getEdad() << endl; 
                cout << "Genero: " << a.getGenero() << endl; 
                cout << "Salud: " << a.getSalud() << endl;
                cout << endl;

                cout << "¿Que quieres modificar?: " << endl;
                cout << "1.- Nombre" << endl; 
                cout << "2.- Edad" << endl; 
                cout << "3.- Genero" << endl; 
                cout << "4.- Salud" << endl;

                cin >> (op);
                switch(op)
                {
                    case 1:
                        cout << "Nombre nuevo: ";
                        cin.ignore();
                        getline(cin, nombreNuevo);
                        a.setNombre(nombreNuevo);
                        break;
                    case 2:
                        cout << "Edad nueva: ";
                        cin.ignore();
                        cin >> edadNueva;
                        a.setEdad(edadNueva);
                        break;
                    case 3:
                        cout << "Genero nuevo: ";
                        cin.ignore();
                        getline(cin, generoNuevo);
                        a.setGenero(generoNuevo);
                        break;
                    case 4:
                        cout << "Salud nueva: ";
                        cin.ignore();
                        cin >> saludNueva;
                        a.setSalud(saludNueva);
                        break;
                }

                cout << "Modificacion exitosa!" << endl;
                cout << endl;
            }
    //     }
    // }

}

void Civilizacion::respaldarAldeano()
{
    ofstream aldeanos (getNombre()+".txt", ios::out);
    
    for (auto it = aldeano.begin(); it != aldeano.end(); it++) 
    {
        Aldeano& aldeano = *it; 
        aldeanos << aldeano.getNombre() << endl;
        aldeanos << aldeano.getEdad()   << endl;
        aldeanos << aldeano.getGenero() << endl;
        aldeanos << aldeano.getSalud()  << endl;
    }
    aldeanos.close();
}

void Civilizacion::recuperarAldeano()
{
    ifstream archivo(getNombre()+ ".txt");

        if (archivo.is_open()){
            //size_t t;
            Civilizacion c;
            //t = stoi(temp);
                    int edad;
                    int salud;
                    string temp;
                    Aldeano a;

            while (true)
            {

                getline (archivo, temp);
                //t = stoi(temp);
                if (archivo.eof()){
                    break;
                }
                a.setNombre(temp);

                getline(archivo, temp);
                edad = stoi(temp);
                a.setEdad(edad);

                getline(archivo, temp);
                //t = stoi(temp);
                a.setGenero(temp);

                getline(archivo, temp);
                salud = stoi(temp);
                a.setSalud(salud);

                agregarFinalAldeano(a);
            }
        }
        archivo.close();
}

//TODO ACT 14
// void Civilizacion::agregarBarco(Barco *b)
// {
//     puerto.push_back(b);
// }

void Civilizacion::capturarBarco( Civilizacion &c)
{
    int id;
    double combustible;
    float velocidad, armadura;

    Barco *b = new Barco();

    // b->setVelocidad(0);
    // b->setArmadura(100);

    cout << "Id: ";
    cin >> id;
    b->setId(id);

    cout << "Combustible: (0-100) ";
    cin >> combustible;
    b->setCombustible(combustible);
    cin.ignore();

    cout << "Velocidad: (0.0 - 14.0) ";
    cin >> velocidad;
    b->setVelocidad(velocidad);

    cout << "Armadura: (0.0 - 100.0) ";
    cin >> armadura;
    b->setArmadura(armadura);
    //Agregar el barco a la civilizacion
    c.agregarBarco(b);
}

void Civilizacion::mostrarBarcos(Civilizacion &c)
{
  
    if (puerto.empty())
    {
        cout << "No hay barcos registrados" << endl;
    }
    else{

        cout <<"Barcos de " << c.getNombre() << endl;
        cout << left;
        cout << setw(10) << "Id";
        cout << setw(15) << "Combustible";
        cout << setw(12) << "Velocidad";
        cout << setw(15) << "Armadura";
        cout << setw(10) << "Cant. Guerreros";
        cout << endl;

        // for (auto const &e: puerto){
        //    cout << *e << endl;
        //}
        //}


        for (auto it = puerto.begin(); it != puerto.end(); it++)
        {
            auto &e = *it;
            //cout << "barco" << endl;
            cout << *e << endl;
        }
    }
}

void Civilizacion::buscarBarcos(Civilizacion &c)
{
    Guerrero guerrero;

    int id;

        cout << "Ingresa el id a buscar: " << endl;
        cin >> id; cin.ignore();

    for (auto it = puerto.begin(); it != puerto.end(); it++){

        Barco *b = *it;

        if (id == b->getId())
        {
            auto &e = *it;
            //cout << "barco" << endl;
            cout << endl;
            cout << "Barco encontrado!" << endl << endl;
            cout << left;
            cout << setw(10) << "Id";
            cout << setw(15) << "Combustible";
            cout << setw(12) << "Velocidad";
            cout << setw(15) << "Armadura";
            cout << setw(10) << "Cant. Guerreros";
            cout << endl;
            cout << *e << endl;
            //return *it;

            size_t opcion;
            cout << "Menu de Guerreros" << endl;
            cout << "1.- Agregar guerrero" << endl;
            cout << "2.- Eliminar guerrero" << endl;
            cout << "3.- Mostrar ultimo guerrero" << endl;
            cout << "4.- Mostrar todos los guerrero" << endl;
            cout << "0.- Salir" << endl;

            cin >> opcion; cin.ignore();


            switch (opcion)
            {
            case 1:
                    {
                        Guerrero guerrero;
                        int id, salud;
                        float fuerza, escudo;
                        //string tipo;
                        string tipo;

                        cout << "Id guerrero: " << endl;
                        cin >> id; cin.ignore();
                        guerrero.setId(id);

                        cout << "Salud: (0-100) "<< endl;
                        cin >> salud;
                        guerrero.setSalud(salud);

                        cout << "Fuerza: (0.0 - 60.0) " << endl;
                        cin >> fuerza;
                        guerrero.setFuerza(fuerza);

                        cout << "Escudo: (0.0 - 30.0) " << endl;
                        cin >> escudo;
                        guerrero.setEscudo(escudo);

                        // cout << "Tipo: (lancero, arquero, paladin, etc) " << endl;
                        // getline (cin, tipo); cin.ignore();
                        // //cin >> tipo;
                        // guerrero.setTipo(tipo);
                        

                        b->agregarGuerrero(guerrero);
                    }
                break;
            case 2:
                    {
                        Guerrero guerrero;
                        b->eliminarGuerrero(guerrero);
                    }
            case 3:
                    {
                        Guerrero guerrero;
                        b->topeGuerrero(guerrero);

                        //cout << &b;
                        cout << endl;
                        //cout << &guerrero;
                    }
            case 4:
                    {
                        // Guerrero copia(guerrero);
                        // Guerrero guerrero;
                        // while (! guerrero.empty())
                        // {
                        // //     auto const &e = copia.top();

                        // //     cout << e << endl;

                        // //     copia.pop();
                        // }
                        //stack <Guerrero> copia (guerrero);
                    }
            case 0:
                break;
            }


            /* TODO La opción *Buscar barcos* pedirá el id, si no existe el barco con tal id, mostrar mensaje.
                Si existe el barco, mostrar el siguiente menú de opciones:

             - Agregar Guerrero (captura y agrega *-apilar-* un guerrero al *stack* de guerreros del barco).
             - Eliminar Guerrero (manda llamar al método para eliminar *-desapilar-* guerrero).
             - Mostrar último guerrero (manda llamar al método de tope).
             - Mostrar todos los Guerreros (hace una copia del *stack* de guerreros y usa la copia 
             para desapilar y mostrar). */
        }
    }

}

void Civilizacion::eliminarCombustible(Civilizacion &c )
{
    float combustible;
    cout << "Intoduce barco con combustible menor a eliminar: "<< endl;
    cin >> combustible; cin.ignore();

        puerto.remove_if([combustible](Barco* b){
            if (b->getCombustible() < combustible){
                cout << "Se elimino correctamente" << endl;
                delete b;
                return true;
            }
            else{
                return false;
            }
            });
}


// bool comparador(const Barco *b)
// {
//     int id;
//     cout << "Introduce el ID del barco: " << endl;
//     cin >> id; cin.ignore();
//     //cout << "Se eliminara los aldeanos de salud menor a: " + salud << endl;

//     return b->getId()  == id;

//     //return a.getSalud() < salud;
// }

void Civilizacion::eliminarId(Civilizacion &c)
{
    int id;
    cout << "Intoduce barco con ID a eliminar: "<< endl;
    cin >> id; cin.ignore();

    puerto.remove_if([id](Barco* b){ 
        if (b->getId() == id)
        {
            cout << "Se elimino correctamente" << endl;
            delete b;
            return true;
        }
        else {
            return false;
        }
        });

}

