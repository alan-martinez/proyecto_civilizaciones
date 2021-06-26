#include "civilizacion.h"

// Barco capturarBarcos()
// {

// }

void menuBarcos (Civilizacion &c)
{
    string op;

    while (true)
    {
        cout << "1.- Agregar barcos" << endl;
        cout << "2.- Mostrar" << endl;
        cout << "3.- Buscar barcos" << endl;
        cout << "4.- Eliminar" << endl;
        cout << "0.- Salir" << endl;

        getline (cin, op);

        if (op == "1")
        {
            Barco *b;
            c.capturarBarco(c);
        }
        else if (op == "2")
        {
            //Civilizacion c;
            c.mostrarBarcos(c);
        }
        else if (op == "3")
        {
            // int id;
            // cout << "Ingresa el id a buscar: " << endl;
            // cin >> id; cin.ignore();

            c.buscarBarcos(c);

        }
        else if (op == "4")
        {
            size_t opcion;

            cout << "1.- Eliminar por ID" << endl;
            cout << "2.- Eliminar por combustible" << endl;
            cin >> opcion; cin.ignore();

            switch(opcion)
            {
                case 1:
                    {
                        // int id;
                        // cout << "Introduce el ID a eliminar: " << endl;
                        // cin >> id; cin.ignore();
                        c.eliminarId(c);
                    }
                break;

                case 2:
                    {
                        // float combustible;
                        // cout << "Introduce el combustible del barco a eliminar" << endl;
                        // cin >> combustible; cin.ignore();
                        c.eliminarCombustible(c);
                    }
            }
        }
        else if (op == "0")
        {
            break;
        }
    }
}