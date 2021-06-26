#include "videogame.h"
#include <fstream>
#include <algorithm>
#include "menu.h"

//TODO implementacion ACT 15
#include "menuBarcos.h"

VideoGame::VideoGame()
{
}

VideoGame::VideoGame(const string &nombreV)
{
    this->nombreV = nombreV;
}

void VideoGame::setNombreVideoGame(const string &n)
{
    nombreV = n;
}

string VideoGame::getNombreVideoGame()
{
    return nombreV;
}

void VideoGame::agregarNombreUsuario(const VideoGame &v)
{
    nombreVideoGame.push_back(v);
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizacion.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizacion.insert(civilizacion.begin() + pos, c);
}

size_t VideoGame::size()
{
    return civilizacion.size();
}

void VideoGame::inicializa(const Civilizacion &c, size_t n)
{
    civilizacion = vector<Civilizacion>(n, c);
}

void VideoGame::primeraCivilizacion(const Civilizacion &c)
{
    if (civilizacion.empty())
    {
        cout << "Vector vacio" << endl;
    }
    else
    {
        cout << civilizacion.front() << endl;
    }
}

void VideoGame::ultimaCivilizacion(const Civilizacion &c)
{
    if (civilizacion.empty())
    {
        cout << "Vector vacio" << endl;
    }
    else
    {
        cout << civilizacion.back() << endl;
    }
}

void VideoGame::ordenarNombre()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion n1, Civilizacion n2)
         { return n1.getNombre() < n2.getNombre(); });
}

void VideoGame::ordenarUbicacionX()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion x1, Civilizacion x2)
         { return x1.getUbicacion_x() < x2.getUbicacion_x(); });
}

void VideoGame::ordenarUbicacionY()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion y1, Civilizacion y2)
         { return y1.getUbicacion_y() < y2.getUbicacion_y(); });
}

void VideoGame::ordenarPuntuacion()
{
    sort(civilizacion.begin(), civilizacion.end(), [](Civilizacion p1, Civilizacion p2)
         { return p1.getPuntuacion() > p2.getPuntuacion(); });
}

void VideoGame::eliminar(const string &nombre)
{

    size_t pos = 0;

    for (auto it = civilizacion.begin(); it != civilizacion.end(); it++)
    {
        Civilizacion &c = *it;

        if (nombre == c.getNombre())
        {
            pos = 1;
            civilizacion.erase(it);
            break;
        }
    }
}

Civilizacion *VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizacion.begin(), civilizacion.end(), c);

    if (it == civilizacion.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}
void VideoGame::total()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(12) << "Ubicacion X";
    cout << setw(12) << "Ubicacion Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;

    for (size_t i = 0; i < civilizacion.size(); i++)
    {
        Civilizacion &c = civilizacion[i];

        cout << c;
        cout << endl;
    }
}

void VideoGame::modificar(Civilizacion &c)
{
    //Civilizacion c;

    size_t i;
    size_t pos = 0;
    size_t op;
    int nuevaX, nuevaY;
    int nuevaPuntuacion;
    string nombre;

    for (i = 0; i < civilizacion.size(); i++)
    {
        if (civilizacion[i].getNombre() == c.getNombre())
        {
            pos = 1;
            cout << endl;
            cout << "Datos de la civilizacion: " << endl;
            cout << "Nombre: " << civilizacion[i].getNombre() << endl;
            cout << "Ubicacion X: " << civilizacion[i].getUbicacion_x() << endl;
            cout << "Ubicacion Y: " << civilizacion[i].getUbicacion_y() << endl;
            cout << "Puntuacion: " << civilizacion[i].getPuntuacion() << endl;
            cout << endl;

            cout << "Que quieres modificar?: " << endl;
            cout << "1.- Nombre" << endl;
            cout << "2.- Ubicacion X" << endl;
            cout << "3.- Ubicacion Y" << endl;
            cout << "4.- Puntuacion" << endl;

            cin >> op;

            switch (op)
            {
            case 1:
                cout << "Nuevo nombre: ";
                cin.ignore();
                getline(cin, nombre);
                civilizacion[i].setNombre(nombre);
                break;
            case 2:
                cout << "Nueva posicion X: ";
                cin.ignore();
                cin >> nuevaX;
                //getline(cin, nuevaX);
                civilizacion[i].setUbicacion_x(nuevaX);
                break;
            case 3:
                cout << "Nueva posicion Y: ";
                cin.ignore();
                cin >> nuevaY;
                //getline(cin, nuevaY);
                civilizacion[i].setUbicacion_y(nuevaY);
                break;
            case 4:
                cout << "Nueva puntuacion: ";
                cin.ignore();
                cin >> nuevaPuntuacion;
                civilizacion[i].setPuntuacion(nuevaPuntuacion);
                break;
            }

            cout << "Modificado con exito! " << endl;
            cout << endl;
        }
    }
}

//TODO Esta bien
void VideoGame::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizacion.size(); i++)
    {
        Civilizacion &c = civilizacion[i];
        archivo << c.getNombre() << endl;
        archivo << c.getUbicacion_x() << endl;
        archivo << c.getUbicacion_y() << endl;
        archivo << c.getPuntuacion() << endl;

        c.respaldarAldeano();
    }
    archivo.close();
}

void VideoGame::recuperar()
{
    ifstream archivo("civilizaciones.txt");

    if (archivo.is_open())
    {
        //Civilizacion c;

        string temp;
        int ubicacionX;
        int t;
        while (true)
        {
            //Civilizacion c;
            // string temp;
            // int ubicacionX;
            // int t;
            Civilizacion c;

            getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            c.setNombre(temp);

            getline(archivo, temp);
            t = stoi(temp);
            c.setUbicacion_x(t);

            getline(archivo, temp);
            t = stoi(temp);
            c.setUbicacion_y(t);

            getline(archivo, temp);
            t = stoi(temp);
            c.setPuntuacion(t);

            c.recuperarAldeano();
            agregarCivilizacion(c);
        }
    }
    archivo.close();
}

void VideoGame::elegirCivi()
{
    if (civilizacion.empty())
    {
        cout << "No hay civilizaciones" << endl;
    }

    //prueba

    else
    {
        size_t o;

        cout << "Menu de aldeanos y barcos" << endl;
        cout << "1.- Menu aldeanos" << endl;
        cout << "2.- Menu barcos" << endl;

        cout << "Digite opcion: ";
        cin >> o;
        cin.ignore();

        if (o == 1)
        {
            for (size_t i = 0; i < civilizacion.size(); i++)
            {
                Civilizacion &c = civilizacion[i];

                cout << "" << i + 1 << ") " << c.getNombre() << endl;
            }

            cout << "0)Salir" << endl
                 << endl;

            int x;

            cout << "Digite opcion: ";
            cin >> x;
            cin.ignore();

            cout << endl
                 << endl;

            if (x > civilizacion.size())
            {
                cout << "Digite una opcion valida" << endl;
            }
            else
            {
                if (x != 0)
                {
                    Civilizacion &aldea = civilizacion[x - 1];

                    menu(aldea);
                }
            }
        }
        else if (o == 2)
        {
            for (size_t i = 0; i < civilizacion.size(); i++)
            {
                Civilizacion &c = civilizacion[i];

                cout << "" << i + 1 << ") " << c.getNombre() << endl;
            }

            cout << "0)Salir" << endl
                 << endl;

            int x;

            cout << "Digite opcion: ";
            cin >> x;
            cin.ignore();

            cout << endl
                 << endl;

            if (x > civilizacion.size())
            {
                cout << "Digite una opcion valida" << endl;
            }
            else if (x != 0)
            {
                Civilizacion &barquitos = civilizacion[x - 1];

                menuBarcos(barquitos);
            }
        }
        else 
        {
            cout << "Opcion no valida" << endl;
        }

        // else
        // {
        //     for (size_t i = 0; i < civilizacion.size(); i++)
        //     {
        //         Civilizacion &c = civilizacion[i];

        //         cout << "" << i + 1 << ") " << c.getNombre() << endl;
        //     }

        //     cout << "0)Salir" << endl
        //          << endl;

        //     int x;

        //     cout << "MENU DE ALDEANO Y BARCOS" << endl
        //          << endl;

        //     cout << "1.- Menu aldeanos" << endl;
        //     cout << "2.- Menu barcos" << endl;

        //     cout << "Digite opcion: ";
        //     cin >> x;
        //     cin.ignore();

        //     cout << endl
        //          << endl;

        //     if (x > civilizacion.size())
        //     {
        //         cout << "Digite una opcion valida" << endl;
        //     }
        //     else
        //     {
        //         if (x == 1)
        //         {
        //             Civilizacion &aldea = civilizacion[x - 1];

        //             menu(aldea);
        //         }
        //         else if (x == 2)
        //         {
        //             Civilizacion &barquitos = civilizacion[x - 1];

        //             menuBarcos(barquitos);
        //         }
        //     }
        //     //     else if (x == 1){
        //     //         Civilizacion &aldea = civilizacion[x-1];

        //     //         menu(aldea);
        //     //     }
        //     //     else if (x == 2){
        //     //         Civilizacion &barquitos = civilizacion[x-1];

        //     //         menuBarcos(barquitos);
        //     //     }
        //     // }
        // }
    }
}