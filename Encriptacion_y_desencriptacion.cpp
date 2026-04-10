#include "librerias.h"
#include <iostream>
using namespace std;

// --- LOGICA DE BITS (MOTOR) ---

// Realiza una rotacion circular a la izquierda
// Los bits que salen por la izquierda se reinsertan por la derecha usando el OR (|)
unsigned char rotarIzquierda(unsigned char byte, int n) {
    // (byte << n): desplaza bits a la izquierda
    // (byte >> (8 - n)): recupera los bits que se salieron y los pone al final
    return (byte << n) | (byte >> (8 - n));
}

// Proceso inverso: rotacion circular a la derecha
unsigned char rotarDerecha(unsigned char byte, int n) {
    // (byte >> n): desplaza hacia la derecha
    // (byte << (8 - n)): recupera los bits del final y los pone al inicio
    return (byte >> n) | (byte << (8 - n));
}

// Aplica la formula del punto 5.3: 1. Rotar -> 2. XOR
void aplicarEncriptacion(char* datos, int tam, int n, unsigned char K) {
    for (int i = 0; i < tam; i++) {
        unsigned char b = (unsigned char)datos[i]; // Convertimos a unsigned para evitar problemas de signo
        unsigned char rotado = rotarIzquierda(b, n); // Primero rotamos n posiciones
        datos[i] = (char)(rotado ^ K); // Luego aplicamos XOR con la clave K
    }
}

// Aplica el proceso inverso: 1. XOR -> 2. Rotar al lado contrario
void aplicarDesencriptacion(char* datos, int tam, int n, unsigned char K) {
    for (int i = 0; i < tam; i++) {
        // El XOR es reversible, asi que aplicarlo de nuevo con la misma K lo elimina
        unsigned char b = (unsigned char)datos[i] ^ K;
        // Finalmente rotamos a la derecha para devolver los bits a su posicion original
        datos[i] = (char)rotarDerecha(b, n);
    }
}

// --- INTERFAZ (PREGUNTAS) ---

void modulo_preguntar_encriptacion(char* datos, int tam) {
    int n, k_int, op;
    unsigned char K;

    // Pedimos el valor de rotacion (debe ser entre 1 y 7 segun el PDF)
    cout << "Ingrese n (rotacion 1-7): ";
    cin >> n;

    // Pedimos la clave XOR (un byte va de 0 a 255)
    cout << "Ingrese K (clave 0-255): ";
    cin >> k_int;
    K = (unsigned char)k_int; // Casting para asegurar que sea un byte

    // Llamamos a la funcion que transforma el arreglo
    aplicarEncriptacion(datos, tam, n, K);
    cout << "Datos encriptados correctamente." << endl;

    // Preguntamos si queremos ver el proceso inverso
    cout << "Desencriptar para verificar? (1:Si / 0:No): ";
    cin >> op;

    if (op == 1) {
        aplicarDesencriptacion(datos, tam, n, K);
        cout << "Datos recuperados exitosamente." << endl;
    }
}
