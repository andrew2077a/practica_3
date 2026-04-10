#include "librerias.h"
#include <iostream>
#include <string>
using namespace std;
string Run_Length_Encoding(string c ){
    char *p=&c[0];
    char a;
    int cont=0;
    string compresion="";
    a=*p;
    while (*p !='\0'){
        if (a==*p){
            cont++;
            p++;
        }
        else{
            p--;
            compresion += to_string(cont)+*p;
            p++;
            cont =0;
            a=*p;
        }
        if (*p =='\0'){
            p--;
            compresion += to_string(cont)+*p;
            p++;
        }

    }
    return compresion;

}

string descompresion(string res ){
    char *p=&res[0];
    string a;
    string cont ="";
    string descompresion="";
    a=*p;
    while (*p !='\0'){
        if (*p>=48 && *p<=57){
            cont += *p;
        }
        else{
            for(int i=1;i<=stoi(cont);i++){
                descompresion +=*p;

            }
            cont= "";
        }
        p++;

    }
    return descompresion;



}

void compresion_y_descompresion_rle(){
    string c,res;
    cout <<"Ingrese una cadena de caracteres para la compresion: "<<endl;
    cin.ignore();
    getline(cin, c);
    res=Run_Length_Encoding(c);
    cout<<"compresion: " << res<<endl;
    res =descompresion(res);
    cout<<"descompresion: " << res <<endl;
    cout <<"verificacion de descomprecion exitosa"<<endl<<"_________________________________"<<endl;
    cout<<"original: "<< c<<endl;
    cout<<"descompresion: "<<res<<endl;


}
