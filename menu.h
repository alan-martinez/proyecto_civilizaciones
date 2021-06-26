#include "civilizacion.h"

Aldeano capturar()
{
    Aldeano a;

    string nombre;
    int edad;
    string genero;
    int salud;

    cout << "Introduzca datos del aldeano" << endl;

    //cin.ignore();

    cout << "Nombre del aldeano: ";
    getline(cin, nombre);
    a.setNombre(nombre);//cin.ignore();

    cout << "Edad aldeano: ";
    cin >> edad;
    a.setEdad(edad);cin.ignore();

    cout << "Genero aldeano: ";
    getline (cin, genero);
    //cin >> genero;
    a.setGenero(genero);

    cout << "Salud aldeano: ";
    cin >> salud;
    a.setSalud(salud);

    return a;
}

void menu (Civilizacion &c)
{
    string op;

    while (true)
    {
        cout << "1.- Agregar" << endl;
        cout << "2.- Mostrar" << endl;
        cout << "3.- Eliminar" << endl;
        cout << "4.- Clasificar" << endl;
        cout << "5.- Buscar" << endl;
        cout << "6.- Modificar" << endl;
        cout << "0.- Salir" << endl;

        getline (cin, op);

        if (op == "1")
        {
            size_t opcion;
            cout << "1.- Agregar al inicio" << endl;
            cout << "2.- Agregar al final" << endl;
            cin >> opcion; cin.ignore();
            switch(opcion)
            {
                case 1:
                    c.agregarInicioAldeano(capturar());
                    break;
                case 2:
                    Aldeano a = capturar();
                    c.agregarFinalAldeano(a);
                    break;
            }
            cout << endl;
            cout << "Se agrego correctamente!";
            cout << endl << endl;
        }
        else if(op == "2")
        {
            c.mostrar();
        }
        else if (op == "3")
        {
            size_t opcion;
            cout << "1.- Eliminar por nombre" << endl;
            cout << "2.- Eliminar por salud" << endl;
            cout << "3.- Eliminar por edad >=60" << endl;
            cin >> opcion; cin.ignore();
            switch(opcion)
            {
                case 1:
                    {
                        string nombre;
                        cout << "Nombre: ";
                        getline (cin, nombre);
                        c.eliminar(nombre);
                    }
                    break;
                case 2:
                    {
                        int salud;
                        cout << "Introduce la salud del aldeano: " << endl;
                        cin >> salud; cin.ignore();
                        c.eliminarSalud(salud);
                    }
                    break;
                case 3:
                    c.eliminarEdad();
                    break;
            }
        }
        else if (op == "4")
        {
            size_t opcion;
            cout << "1.- Ordenar por nombre" << endl;
            cout << "2.- Ordenar por edad (descendente)" << endl;
            cout << "3.- Ordenar por salud (descendente)" << endl;
            cin >> opcion; cin.ignore();
            switch(opcion)
            {
                case 1:
                    c.ordenarNombre();
                    break;
                case 2:
                    c.ordenarEdad();
                    break;
                case 3:
                    c.ordenarSalud();
                    break;
            }
        }
        else if (op == "5")
        {
            Aldeano a;
            string nombre;
            cout << "Ingresa el nombre a buscar: ";
            getline(cin, nombre);
            Aldeano *ptr = c.buscar(nombre);
            if (ptr == nullptr){
                cout << "El aldeano no existe"<< endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if (op == "6")
        {
            //Aldeano *ptr ;
            string nombre;
            cout << "Nombre del aldeano que quieres modificar: ";
            getline(cin, nombre);

            Aldeano *ptr = c.buscar(nombre);
            
                cout << endl;
                cout << "Nombre    Edad    Genero    Salud" << endl;
                cout << *ptr << endl;
                cout << endl;
                c.modificar(ptr);
            //}
        }
        else if (op == "0"){
            break;
        }
    }
}