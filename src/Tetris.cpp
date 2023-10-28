#include <iostream>
#include <fstream>
#include <unistd.h>  // Para usleep
using namespace std;

void imprimirArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        cout << "\033[2J"; // Limpia la pantalla
        cout << "\033[H";  // Coloca el cursor en la esquina superior izquierda
        cout << "Contenido de " << nombreArchivo << ":\n";
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << "." << endl;
    }
}

int main() {
    string archivos[] = {"data/I.txt", "data/J.txt", "data/O.txt", "data/Z.txt", "data/S.txt", "data/L.txt", "data/Z.txt"};

    for (const string& archivo : archivos) {
        imprimirArchivo(archivo);
        usleep(500000);  // Espera medio segundo (500,000 microsegundos)
    }

    return 0;
}
