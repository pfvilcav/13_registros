#ifndef CONTACTO_H
#define CONTACTO_H

#include<iostream>
using namespace std;

#define MAX 10

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

// Declaraciones
void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void agregarContacto(contactoEmail[], contactoEmail, int &);
int menu();
void agregar(contactoEmail[], int &, contactoEmail &);
void mostrarTodos(contactoEmail[], int);
void filtrarPorDominio(contactoEmail[], int);
void confirmarSalida(char &, int &);

#endif