#include<iostream>
#include "contacto.h"
using namespace std;

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}

void agregarContacto(contactoEmail lista[], contactoEmail cE, int &cant){
    lista[cant] = cE;
    cant++;
}

int menu(){
    int opcion;
    cout<<"Menu de opciones -------------------------"<<endl;
    cout<<"1. Agregar contacto"<<endl;
    cout<<"2. Mostrar contactos"<<endl;
    cout<<"3. Mostrar listado de contactos por dominio"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"Elige una opcion: "; cin>>opcion;
    return opcion;
}

void agregar(contactoEmail lista[], int &n, contactoEmail &cont){
    string nom, user, domain;
    char sex, SN;
    int edad;
    correo email;

    if(n < MAX){
        cout<<"Ingrese los datos de un usuario:"<<endl;
        cin.ignore();
        cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
        cout<<"Ingrese el sexo (M/F): "; cin>>sex;
        cout<<"Ingrese la edad: "; cin>>edad;
        cout<<"Ingrese el correo electronico (usuario@dominio):"<<endl;
        cout<<"\tIngrese el usuario: "; cin>>user;
        cout<<"\tIngrese el dominio: "; cin>>domain;

        leerCorreo(email,user,domain);
        leerContacto(cont,nom,sex,edad,email);

        cout<<"\nHa ingresado la siguiente informacion:"<<endl;
        imprimeContacto(cont);
        cout<<"\nEsta informacion es correcta? (S/N): "; cin>>SN;
        if(SN == 'S' || SN == 's'){
            agregarContacto(lista,cont,n);
            cout<<"Registro exitoso!"<<endl;
        }else{
            cout<<"Se cancelo la operacion"<<endl;
        }
    }else{
        cout<<"Limite de contactos alcanzado"<<endl;
    }
    system("pause");
}

void mostrarTodos(contactoEmail lista[], int n){
    if(n == 0){
        cout<<"Aun no se han registrado contactos"<<endl;
    }else{
        for(int i = 0; i < n; i++){
            cout<<"Contacto #"<<i+1<<endl;
            imprimeContacto(lista[i]);
            cout<<endl;
        }
    }
    system("pause");
}

void filtrarPorDominio(contactoEmail lista[], int n){
    if(n == 0){
        cout<<"Aun no se han registrado contactos"<<endl;
    }else{
        string filtro;
        bool encontrado = false;
        cout<<"Ingrese el dominio a filtrar: "; cin>>filtro;
        for(int i = 0; i < n; i++){
            if(lista[i].email.domain == filtro){
                cout<<"Contacto #"<<i+1<<endl;
                imprimeContacto(lista[i]);
                cout<<endl;
                encontrado = true;
            }
        }
        if(!encontrado){
            cout<<"No hay contactos con ese dominio"<<endl;
        }
    }
    system("pause");
}

void confirmarSalida(char &SN, int &op){
    cout<<"Esta seguro de salir? (S/N): "; cin>>SN;
    if(SN != 'S' && SN != 's'){
        op = -1;
        cout<<"Se cancelo la operacion"<<endl;
    }else{
        cout<<"Hasta la proxima!"<<endl;
    }
    system("pause");
}