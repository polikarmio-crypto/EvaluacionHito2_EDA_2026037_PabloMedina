#include <iostream>
using namespace std;

// Nodo de la lista enlazada
struct Estudiante 
{
    string nombre;
    string codigo;
    Estudiante* siguiente;
};

// Clase para manejar la lista de estudiantes
class ListaEstudiantes {
private:
    Estudiante* inicio;
    Estudiante* fin;

public:
    ListaEstudiantes() {
        inicio = nullptr;
        fin = nullptr;
    }

    // Registrar estudiante (inserción al final)
    void registrar(string nombre, string codigo) {
        Estudiante* nuevo = new Estudiante();
        nuevo->nombre = nombre;
        nuevo->codigo = codigo;
        nuevo->siguiente = nullptr;

        if (inicio == nullptr) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        cout << "Estudiante registrado correctamente." << endl;
    }

    // Atender estudiante (eliminar primero en la lista)
    void atender() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera." << endl;
            return;
        }
        Estudiante* atendido = inicio;
        cout << "Atendiendo estudiante:" << endl;
        cout << "Nombre: " << atendido->nombre << endl;
        cout << "Codigo: " << atendido->codigo << endl;

        inicio = inicio->siguiente;
        delete atendido;

        if (inicio == nullptr) {
            fin = nullptr;
        }
    }

    // Mostrar estudiantes en espera
    void mostrar() {
        if (inicio == nullptr) {
            cout << "No hay estudiantes en espera." << endl;
            return;
        }
        cout << "Lista de estudiantes en espera:" << endl;
        Estudiante* actual = inicio;
        int pos = 1;
        while (actual != nullptr) {
            cout << pos << ". Nombre: " << actual->nombre << " | Codigo: " << actual->codigo << endl;
            actual = actual->siguiente;
            pos++;
        }
    }

    // Buscar estudiante por nombre
    void buscar(string nombre) {
        if (inicio == nullptr) {
            cout << "No hay estudiantes registrados." << endl;
            return;
        }
        Estudiante* actual = inicio;
        int pos = 1;
        while (actual != nullptr) {
            if (actual->nombre == nombre) {
                cout << "Estudiante encontrado en posicion " << pos << ":" << endl;
                cout << "Nombre: " << actual->nombre << " | Codigo: " << actual->codigo << endl;
                return;
            }
            actual = actual->siguiente;
            pos++;
        }
        cout << "Estudiante no encontrado." << endl;
    }
};

// Programa principal
int main() {
    ListaEstudiantes lista;
    int opcion;
    string nombre, codigo;

    do {
        cout << endl << "--- Menu de Gestion de Turnos ---" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Atender estudiante" << endl;
        cout << "3. Mostrar estudiantes en espera" << endl;
        cout << "4. Buscar estudiante por nombre" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese codigo: ";
                getline(cin, codigo);
                lista.registrar(nombre, codigo);
                break;
            case 2:
                lista.atender();
                break;
            case 3:
                lista.mostrar();
                break;
            case 4:
                cout << "Ingrese nombre a buscar: ";
                getline(cin, nombre);
                lista.buscar(nombre);
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
