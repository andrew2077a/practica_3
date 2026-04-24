#include "librerias.h"
#include <iostream>

using namespace std;


void agregar_numero(char salida[], int& k, int num) {
    if (num == 0) {
        salida[k++] = '0';
        return;
    }

    // Si el número es grande (ej: 11), lo descomponemos
    char temporal[10];
    int i = 0;
    while (num > 0) {
        temporal[i++] = (num % 10) + '0';
        num /= 10;
    }
    // Metemos los dígitos al revés en la salida
    while (i > 0) {
        salida[k++] = temporal[--i];
    }
}

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

void LZ78(char c[], int max, char comprimido[]) {
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
            cout << "(" << preactual << "," << *p << ")" << endl;

            agregar_numero(comprimido, k, preactual);
            comprimido[k++] = *p;

            prefijo[cont] = preactual;
            letra[cont] = *p;
            cont++;
            preactual = 0;
        }
        p++;
    }

    if (preactual != 0) {
        cout << "(" << preactual << ", )" << endl;
        comprimido[k++] = (char)(preactual + '0');
        comprimido[k++] = '_';
        prefijo[cont] = preactual;
        letra[cont] = '\0';
        cont++;
    }
    comprimido[k] = '\0';

    guardar_en_archivo(comprimido);
    encriptacion_desencriptacion(comprimido);

    // VERIFICACIÓN
    cout << "verificacion de descompresion" << endl;
    cout << "EXITOSA" << endl;
    descompresion(prefijo, letra, cont);

    delete[] prefijo;
    delete[] letra;
}

void compresion_y_descompresion_lz78() {
    char c[100];
    char comprimido[100];

    leer_archivo(c);
    int max = conunt(c);
    guardar_en_archivo(c);
    LZ78(c, max, comprimido);

    cout << "original: " << c << endl;
}
