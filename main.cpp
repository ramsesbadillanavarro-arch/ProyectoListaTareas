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
void eliminarTarea(vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Eliminar tarea\n";
        cout << "4. Marcar tarea como completada\n";
        cout << "5. Salir\n\n";
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
                eliminarTarea(tareas);
                break;
            case 4:
                completarTarea(tareas);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// 1. Agrega una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nueva;
    
    cout << "Ingrese la tarea: ";
    getline(cin, nueva.descripcion);
    
    if (nueva.descripcion == "") {
        cout << "La tarea no puede estar vacía\n";
        return;
    }

    int opcionPrioridad;
    cout << "Seleccione la prioridad (1. Alta, 2. Media, 3. Baja): ";
    cin >> opcionPrioridad;
    cin.ignore();

    if (opcionPrioridad == 1) {
        nueva.prioridad = "Alta";
    } else if (opcionPrioridad == 2) {
        nueva.prioridad = "Media";
    } else {
        nueva.prioridad = "Baja"; 
    }
    
    nueva.completada = false;
    
    tareas.push_back(nueva);
    cout << "Tarea agregada correctamente.\n";
}

// 2. Muestra todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {
    cout << "\nTAREAS\n\n";
    
    for (int i = 0; i < tareas.size(); i++) {
        cout << i + 1 << ". ";
        
        if (tareas[i].completada == true) {
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }
        
        cout << "[" << tareas[i].prioridad << "] " << tareas[i].descripcion << endl;
    }
}

// 3. Elimina una tarea
void eliminarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    
    if (tareas.empty()) {
        return;
    }
    
    int numeroTarea;
    cout << "Seleccione la tarea a eliminar: ";
    cin >> numeroTarea;
    cin.ignore();
    
    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "Opción no válida.\n";
        return;
    }
    
    tareas.erase(tareas.begin() + numeroTarea - 1);
    cout << "Tarea eliminada correctamente.\n";
}

// 4. Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    
    if (tareas.empty()) {
        return;
    }
    
    int numeroTarea;
    cout << "Seleccione la tarea: ";
    cin >> numeroTarea;
    cin.ignore();
    
    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "Opción no válida.\n";
        return;
    }
    
    tareas[numeroTarea - 1].completada = true;
    cout << "Tarea marcada como completada.\n";
}
