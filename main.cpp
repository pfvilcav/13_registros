#include<iostream>
#include "contacto.h"
using namespace std;

int main(){
    int n = 0, op;
    char SN;
    contactoEmail cont, lista[100];
    do{
        system("cls");
        op = menu();
        switch(op){
            case 1: agregar(lista,n,cont); break;
            case 2: mostrarTodos(lista,n); break;
            case 3: filtrarPorDominio(lista,n); break;
            case 0: confirmarSalida(SN,op); break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}