#include <iostream>
#include "librerias.h"

using namespace std;

int main(){
    int x;
    cout<<"ingrese algo"<<endl;
    cin>>x;
    switch (x) {
    case 1:
        compresion_y_descompresion();
        break;
    default:
        break;
    }
}
