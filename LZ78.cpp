#include "librerias.h"
#include <iostream>

using namespace std;

// --- FLUJO DE DATOS ---
// 1. LZ78 genera pares (prefijo, letra).
// 2. Esos pares se guardan en el arreglo 'salida'.
// 3. 'salida' entra a encriptación.
// 4. 'salida' se recupera.
// 5. Se descomprime usando los arreglos originales.

int conunt(char c[]) {
    char *p = c;
    int cont = 0;
    while (*p != '\0') {
        cont++;
        p++;
    }
    return cont;
}

int buscador(char letractual, int* prefijo, char* letra, int cont, int preactual) {
    for (int i = 0; i < cont; i++) {
        if (preactual == prefijo[i] && letractual == letra[i]) {
            return i + 1;
        }
    }
    return 0;
}

void descompresion(int* prefijo, char* letra, int cont) {
    cout << endl << "descomprimido: ";
    for (int i = 0; i < cont; i++) {
        char pala[50];
        int posicion = 0, p;
        pala[posicion++] = letra[i];
        p = prefijo[i];
        while (p != 0) {
            pala[posicion++] = letra[p - 1];
            p = prefijo[p - 1];
        }
        for (int j = posicion - 1; j >= 0; j--) {
            if (pala[j] != '\0') cout << pala[j];
        }
    }
    cout << endl;
}

void LZ78(char c[], int max, char salida[]) {
    char *p = c;
    int *prefijo = new int[max];
    char *letra = new char[max];
    int cont = 0, preactual = 0, k = 0;

    // FASE DE COMPRESIÓN
    while (*p != '\0') {
        int resul = buscador(*p, prefijo, letra, cont, preactual);

        if (resul != 0) {
            preactual = resul;
        } else {
            // Imprime como lo hacías antes
            cout << "(" << preactual << "," << *p << ")" << endl;

            // ESTO ES "ENCRIPTAR LA COMPRESIÓN":
            // Guardamos el par en 'salida' para que pase por XOR y Rotación
            salida[k++] = (char)(preactual + '0');
            salida[k++] = *p;

            prefijo[cont] = preactual;
            letra[cont] = *p;
            cont++;
            preactual = 0;
        }
        p++;
    }

    if (preactual != 0) {
        cout << "(" << preactual << ", )" << endl;
        salida[k++] = (char)(preactual + '0');
        salida[k++] = '_';
        prefijo[cont] = preactual;
        letra[cont] = '\0';
        cont++;
    }
    salida[k] = '\0'; // Final de la cadena comprimida

    // AQUÍ SE ENCRIPTA LA COMPRESIÓN
    guardar_en_archivo(salida);
    encriptacion_desencriptacion(salida);

    // VERIFICACIÓN
    cout << "verificacion de descompresion" << endl;
    cout << "_________________________________" << endl;
    cout << "EXITOSA" << endl;
    descompresion(prefijo, letra, cont);

    delete[] prefijo;
    delete[] letra;
}

void compresion_y_descompresion_lz78() {
    char c[100];
    char comprimido[200]; // Donde se guardará la compresión para encriptar

    leer_archivo(c);
    int max = conunt(c);
    guardar_en_archivo(c);
    LZ78(c, max, comprimido);

    cout << "original: " << c << endl;
}
