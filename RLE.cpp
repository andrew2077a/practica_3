#include "librerias.h"
#include <iostream>
#include <string>
using namespace std;
string Run_Length_Encoding(string c ){
    guardar_en_archivo(c);
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
    guardar_en_archivo(compresion);
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
    guardar_en_archivo(descompresion);
    return descompresion;

}

bool verificar (string c,string res){
    if (c==res){
        return true;

    }
    else{
        return false;
    }
}
void cambiar_a_char(string texto, char tex[]){
    size_t i=0;
    while(i<texto.length()&&i<99){
        tex[i]=texto[i];
        i++;
    }
    tex[i]='\0';
}
void cambiar_a_string(string texto, char tex[]){
    int i=0;
    while(tex[i]!='\0'){
        texto[i]=tex[i];
        i++;
    }
    tex[i]='\0';
}

void compresion_y_descompresion_rle(){
    char tex[100];
    string c,res,rus;
    c=  leer_archivo();
    res=Run_Length_Encoding(c);
    cout<<"compresion: " << res<<endl;
    cambiar_a_char(res ,tex);
    encriptacion_desencriptacion(tex);
    cambiar_a_string(res,tex);
    rus =descompresion(res);
    cout<<"descompresion: " << rus <<endl;
    if (verificar(c,rus)){
        cout <<"verificacion de descompresion"<<endl<<"_________________________________"<<endl<<"EXITOSA"<<endl;
    }
    cout<<"original: "<< c<<endl;
    cout<<"descompresion: "<<rus<<endl;
    guardar_en_archivo(res);


}
