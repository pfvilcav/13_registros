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
    cout<<"META N;";
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>EMPLEADOS[i].num;
        cin.ignore(1000, '\n');
        getline (cin, EMPLEADOS[i].nom);
        for (int j=0; j<12; j++) {
            cin>>EMPLEADOS[i].ven[j];
        }
        cin>>EMPLEADOS[i].sal;
    }
    return 0;
}