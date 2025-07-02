#include<iostream>
#define MAX 10
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void agregarContacto(contactoEmail[], contactoEmail, int &);

int main(){
    int n, op;
    string nom, user, domain, filtro;
    char sex, SN;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Mostrar listado de contactos por dominio"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
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
                break;
            case 2:
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
                break;
            case 3:
                if(n == 0){
                    cout<<"Aun no se han registrado contactos"<<endl;
                }else{
                    cout<<"Ingrese el dominio a filtrar: "; cin>>filtro;
                    bool encontrado = false;
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
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): "; cin>>SN;
                if(SN != 'S' && SN != 's'){
                    op = -1;
                    cout<<"Se cancelo la operacion"<<endl;
                }else{
                    cout<<"Hasta la proxima!"<<endl;
                }
                system("pause");
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
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