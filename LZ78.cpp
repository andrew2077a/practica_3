#include "librerias.h"
#include <iostream>
using namespace std;

int conunt(char c[]){
    char *p = c;
    int cont = 0;
    while (*p != '\0'){
        cont++;
        p++;
    }
    return cont;
}

int buscador(char letractual, int* prefijo, char* letra, int cont, int preactual){
    for (int i = 0; i < cont; i++){
        if (preactual == prefijo[i] && letractual == letra[i]){
            return i + 1;
        }
    }
    return 0;
}

void descompresion(int* prefijo, char* letra, int cont) {
    cout <<endl<< "descomprimido: ";

    for (int i = 0; i < cont; i++) {
        char pala[50];
        int posicion = 0;


        pala[posicion++] = letra[i];


        int p = prefijo[i];
        while (p != 0) {
            pala[posicion++] = letra[p - 1];
            p = prefijo[p - 1];
        }


        for (int j = posicion - 1; j >= 0; j--) {
            cout << pala[j];
        }
    }
    cout<<endl;
}

void LZ78(char c[], int max){
    char *p = c;
    int *prefijo = new int[max];
    char *letra = new char[max];
    int cont = 0, preactual = 0;

    while (*p != '\0'){
        int resul = buscador(*p, prefijo, letra, cont, preactual);

        if (resul != 0){
            preactual = resul;
        }
        else {
            cout << "(" << preactual << "," << *p << ")" << endl;

            prefijo[cont] = preactual;
            letra[cont] = *p;

            cont++;
            preactual = 0;
        }
        p++;
    }
    if (preactual != 0) {
        cout << "(" << preactual << ", )" << endl;
        prefijo[cont] = preactual;
        letra[cont] = '\0';
        cont++;
    }

    descompresion (prefijo,letra,cont );

    delete[] prefijo;

    delete[] letra;

}

void compresion_y_descompresion_lz78(){
    char c[50];
    int max;
    cout <<"Ingrese una cadena de caracteres para la compresion: "<<endl;
    cin>> c;
    max =conunt(c);
    LZ78(c,max);
    cout<< "comparacion con el original: "<<c<<endl;
    //cout<<"compresion: " << res<<endl;
    // =descompresion(res);
    //cout<<"descompresion: " << res <<endl;
    //cout <<"verificacion de descomprecion exitosa"<<endl<<"_________________________________"<<endl;
    //cout<<"original: "<< c<<endl;
    //cout<<"descompresion: "<<res<<endl;

}
