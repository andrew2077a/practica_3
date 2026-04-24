#include "librerias.h"
#include <iostream>
using namespace std;

unsigned char rotar_izquierda(unsigned char byte, int n) {
    return (byte << n) | (byte >> (8 - n));
}

unsigned char rotar_derecha(unsigned char byte, int n) {
    return (byte >> n) | (byte << (8 - n));
}

unsigned char operacionXOR(unsigned char byte, unsigned char K) {
    return byte ^ K;
}


void encriptacion_desencriptacion(char texto[]){
    int n, k_int;

    cout << "Ingrese n (rotacion 1-7): ";
    cin >> n;

    cout << "Ingrese K (clave 0-255): ";
    cin >> k_int;

    unsigned char K = (unsigned char)k_int;

    int tam = 0;
    while (texto[tam] != '\0') {
        tam++;
    }

    for (int i = 0; i < tam; i++) {

        unsigned char byte_puro = (unsigned char)texto[i];


        unsigned char rotado = rotar_izquierda(byte_puro, n);

        texto[i] = (char)operacionXOR(rotado, K);
    }

    cout << "Texto encriptado exitosamente: " << texto << endl;
    guardar_en_archivo(texto);

    for (int i = 0; i < tam; i++) {

        unsigned char byte_enc = (unsigned char)texto[i];


        unsigned char sin_xor = operacionXOR(byte_enc, K);

        texto[i] = (char)rotar_derecha(sin_xor, n);
    }
    cout << "Texto recuperado: " << texto << endl;

}
