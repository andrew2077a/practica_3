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
            throw "No se abrio el archivo";
        }

        while (getline(archivo, linea)) {
            guardar += linea;
        }
        archivo.close();
        cambiar_a_char(guardar,c);
        return guardar;
    }
    catch (const char* e) {
        cout << "FALLO: " << e << endl;
    }
    return "";

}

void guardar_en_archivo(string contenido) {
    string ruta = "C:\\Users\\gisel\\OneDrive\\Escritorio\\practi_c++\\fina\\practica__3\\resultado.txt";
    ofstream archivo(ruta,ios::app);

    try {
        if (!archivo.is_open()) {
            throw "Error: No se pudo crear el archivo en la ruta especificada.";
        }
        archivo << contenido<<endl;

        archivo.close();

    }
    catch (const char* e) {
        cout << "ALERTA: " << e << endl;
    }
}
