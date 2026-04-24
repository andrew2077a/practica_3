#include "librerias.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


string leer_archivo(char c[]) {
    ifstream archivo("C:\\Users\\gisel\\OneDrive\\Escritorio\\practi_c++\\fina\\practica__3\\mensaje.txt");
    string linea;
    string guardar;

    try {
        if (!archivo.is_open()) {
            // Lanzas un texto directo, sin usar runtime_error
            throw "No se abrio el archivo";
        }

        while (getline(archivo, linea)) {
            guardar += linea;
        }
        archivo.close();
        cambiar_a_char(guardar,c);
        return guardar;
    }
    // Capturas el texto (char*) que lanzaste arriba
    catch (const char* e) {
        cout << "FALLO: " << e << endl;
    }
    return "";

}

void guardar_en_archivo(string contenido) {
    // Definimos la ruta y el nombre del archivo que se va a CREAR
    string ruta = "C:\\Users\\gisel\\OneDrive\\Escritorio\\practi_c++\\fina\\practica__3\\resultado.txt";

    // 'ofstream' sirve para escribir (Output File Stream)
    ofstream archivo(ruta,ios::app);

    try {
        // Verificamos si el archivo se pudo crear/abrir
        if (!archivo.is_open()) {
            throw "Error: No se pudo crear el archivo en la ruta especificada.";
        }

        // Escribimos el contenido en el archivo
        archivo << contenido<<endl;

        // Cerramos el archivo para asegurar que se guarden los cambios
        archivo.close();

    }
    catch (const char* e) {
        // Si algo falló, imprimimos el mensaje que capturó 'e'
        cout << "ALERTA: " << e << endl;
    }
}
