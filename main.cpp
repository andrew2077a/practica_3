#include <iostream>
#include "librerias.h"

using namespace std;

int main(){
    int x;
    cout << "Seleccione:" <<endl<<"1) RLE" <<endl <<"2) LZ78"<<endl<< "3) Encriptacion"<<endl;
    cin>>x;
    switch (x) {
    case 1:
        compresion_y_descompresion_rle();
        break;
    case 2:
        compresion_y_descompresion_lz78();
        break;
    default:
        break;
    }
}
