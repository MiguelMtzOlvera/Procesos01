#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#define cel 30

using namespace std;

typedef struct TCliente{
int id_cliente;
string Nombre;
string telefono;
float saldo;
bool moroso;
string calle;
string colonia;
int cp;
}cliente;

cliente Alta(cliente x);
cliente Baja(cliente w, cliente z);
void Impresion(cliente x);
cliente Modificar(cliente x);

int main(int argc, char** argv) {
cliente a[10];
int op, b=0, n=0;
while(true){
system("cls");
cout << "\t\tRegistro Cliente\t\n" << "1.Alta\n2.Baja\n3.Mostrar\n4.Modificar\n5.Salir\n: HOLAAA ";
cin >> op;
switch(op){
case 1:
system("cls");
a[n] = Alta(a[n]);
n++;
break;
case 2:
system("cls");
cout << "?ue cliente desea borrar?\n";
for(int j=0;j<n;j++){
cout << "\nNo.Cliente: " << j+1;
Impresion(a[j]);
}
cout <<"\nNo. Cliente a borrar:";
cin >> b;
for(int o=b;o<n;o++){
a[b-1]=Baja(a[b],a[b-1]);
}
n--;
break;
case 3:
system("cls");
for(int j=0;j<n;j++){
Impresion(a[j]);
}
system("pause");
break;
case 4:
system("cls");
cout << "Que registro desea modificar?";
for(int j=0;j<n;j++){
cout << "\nNo.Cliente: \n" << j+1;
Impresion(a[j]);
}
cout << "No. de cliente: ";
cin >> b;
a[b-1]=Modificar(a[b-1]);
break;
case 5:
exit(EXIT_FAILURE);
default:
exit(0);
}
}
}
//***********************************************************--ALTA--******************************************************************************
cliente Alta(cliente x){
char resp;
cout << "Ingrese ID Cliente:\n";
cin >> x.id_cliente;
cout << "Ingrese Nombre:\n";
cin >> x.Nombre;
cout << "Ingrese Telefono:\n";
cin >> x.telefono;
cout << "Ingrese Saldo:\n";
cin >> x.saldo;
cout << "?s moroso? Y/N";
cin >> resp; 
if((resp == 'y') || (resp == 'Y')){
x.moroso=true;
}else{
x.moroso=false;
}
cout << "Ingrese Direccion \n\n";
cout << "Ingrese Colonia:\n";
cin >> x.colonia;
cout << "Ingrese Calle:\n";
cin >> x.calle;
cout << "Ingrese Codigo Postal:\n";
cin >> x.cp;
return x;
}
//***********************************************************--MOATRAR--******************************************************************************
void Impresion(cliente x){
	cout<<endl;
cout << "\nID Cliente: " << x.id_cliente;
cout << "\nNombre: " << x.Nombre;
cout << "\nSaldo: " << x.saldo;
cout << "\nTelefono: " << x.telefono;
cout << "\nMoroso: ";
if(x.moroso == true){
cout << "Es moroso\n";
}else{
cout << "No es moroso\n";
}
cout << "Direccion ";
cout << "\nColonia: " << x.colonia;
cout << "\nCalle: " << x.calle;
cout << "\nCodigo Postal: " << x.cp<<endl;
}
//***********************************************************--BAJA--******************************************************************************
cliente Baja(cliente w, cliente z){
z.id_cliente=w.id_cliente;
z.Nombre=w.Nombre;
z.telefono=w.telefono;
z.saldo=w.saldo;
z.moroso=w.moroso;
z.colonia=w.colonia;
z.calle=w.calle;
z.cp=w.cp;
return z;
}
//********************************************************--MODIFICAR--******************************************************************************
cliente Modificar(cliente x){
int op;
char m;
system("cls");
cout << "Que campo desea modificar?\n1.ID Cliente\n2.Nombre\n3.Saldo\n4.Telefono\n5.Moroso\n6.Direccion\n";
cin >> op;
switch(op){
case 1:
cout << "\nID Cliente:";
cin >> x.id_cliente;
break;
case 2:
cout << "\nNombre:";
cin >> x.Nombre;
break;
case 3:
cout << "\nSaldo:";
cin >> x.saldo;
break;
case 4:
cout << "\nTelefono:";
cin >> x.telefono;
break;
case 5:
cout << "\nMoroso y/n:";
cin >> m;
if((m=='Y')||(m=='y')){
x.moroso=true;
}else{
x.moroso=false;
}
break;
case 6:
cout << "\nColonia:";
cin >> x.colonia;
cout << "\nCalle:";
cin >> x.calle;
cout << "\nCodigo Postal:";
cin >> x.cp;
break;
}
return x;
}
