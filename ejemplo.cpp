#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};

int main () {
    EMP EMPLEADOS[100];
    int n;
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Numero de empleado: ";
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        cout<<"Nombre del empleado: ";
        getline(cin, EMPLEADOS[i].nom);
        for (int j=0; j<12; j++) {
            cout<<"Venta del mes "<<j+1<<": ";
            cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Salario base: ";
        cin>>EMPLEADOS[i].sal;
    }

    int max=0;
    float ventasmax=0;
    
    cout<<"===============================================";
    cout<<"\nINFORMACION DE EMPLEADOS:\n";
    for (int i=0; i<n; i++) {
        float totalVentas = 0;
        for (int j=0; j<12; j++) {
            totalVentas += EMPLEADOS[i].ven[j];
        }
        if (totalVentas>ventasmax) {
            ventasmax=totalVentas;
            max=i;
        }
        if (totalVentas>100) {
            EMPLEADOS[i].sal*=1.10;
        }
        cout<<"===============================================\n";
        cout<<"Empleado: "<<EMPLEADOS[i].nom<<endl;
        cout<<"Ventas mensuales: ";
        for (int j=0; j<12; j++) {
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<"\nTotal ventas: "<<totalVentas<<endl;
        cout<<"Salario recibido: "<<EMPLEADOS[i].sal<<endl;
    }
    cout<<"===============================================";
    cout<<"\nEmpleado con mas ventas\n";
    cout<<"Numero: "<<EMPLEADOS[max].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[max].nom<<endl;

    return 0;
}