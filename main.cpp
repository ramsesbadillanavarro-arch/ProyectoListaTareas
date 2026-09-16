#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
    string prioridad;
};

// Prototipos
void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    while (opcion != 4) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                completarTarea(tareas);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// Agregar una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nuevaTarea;
    cout << "Ingrese la tarea: ";
    getline(cin, nuevaTarea.descripcion);
    
    cout << "Ingrese la prioridad Alta, Media, Baja: ";
    getline(cin, nuevaTarea.prioridad);
    
    nuevaTarea.completada = false; 
    tareas.push_back(nuevaTarea);
    
    cout << "Tarea agregada correctamente.\n";
}

// Muestra todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {
    cout << "\nTAREAS\n";
    
    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }

    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << i + 1 << ". ";
        
        if (tareas[i].completada) {
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }
        
        // Se agrega la prioridad
        cout << "[" << tareas[i].prioridad << "] ";
        cout << tareas[i].descripcion << "\n";
    }
}

// Marcar una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas registradas\n";
        return;
    }

    mostrarTareas(tareas);
    
    int numero;
    cout << "Seleccione la tarea: ";
    cin >> numero;
    cin.ignore();

    if (numero > 0 && numero <= tareas.size()) {
        tareas[numero - 1].completada = true;
        cout << "Tarea marcada como completada.\n";
    } else {
        cout << "Opción no es válida.\n"; // Mensaje de error
    }
}
