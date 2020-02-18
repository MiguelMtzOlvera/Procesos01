#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#define cel 30
using namespace std;
int edadd=0;
int edad2=0;
int r=0;
int r1=0;
int c=0;
typedef struct paciente{
string nombre;
int edad;
bool sexo;
string sintomas;
string diagnostico;
}
paciente;
paciente agendar(paciente a);
paciente actualizar(paciente a);
paciente buscar(paciente a);
paciente promedio(paciente a);
paciente eliminar(paciente b, paciente c);
void Impresion(paciente a);
int edaa();

int main(int argc, char** argv) {
paciente a[10];
int op, b=0, n=0;
while(true){
system("cls");
cout << "Elija alguna de las sig. opciones para paciente: \n    1.Agendar consulta\n    2.Actualizar\n    3.Buscar\n    4.Promedio de edades\n    5.Eliminar registros\n";
cin >> op;

switch(op){
case 1:
system("cls");
a[n] = agendar(a[n]);
n++;
break;

case 2:
system("cls");
cout << "Seleccione un registro para modificar: ";
for(int j=0;j<n;j++){
cout << "\nNo. de paciente: " << j+1;
Impresion(a[j]);}
cout << "\nNo. de paciente: ";
cin >> b;
a[b-1]=actualizar(a[b-1]);
break;

case 3:
system("cls");
cout << "Lista de pacientes: \n";
for(int j=0;j<n;j++){
cout << "\nNo.paciente: " << j+1;
Impresion(a[j]);
}
cout << "\nBuscar no. paciente:";
cin >> b;
n--;
break;

case 4:
system("cls");
edaa();
system("pause");
break;

case 5:
system("cls");
cout << "Lista de pacientes: \n";
for(int j=0;j<n;j++){
cout << "\nNo.Paciente a borrar:  " << j+1;
Impresion(a[j]);
}
cout << "\nNo. Paciente a borrar:";
cin >> b;
for(int o=b;o<n;o++){
a[b-1]=eliminar(a[b],a[b-1]);
}
n--;
break;

     }
  }
}
  
//agendar
paciente agendar(paciente a){
char res;
cout << "Nombre del paciente:   ";
cin >> a.nombre;
cout << "\nEdad:   ";
cin>>edadd;
r=r+edadd;
c++;
a.edad=edadd;
//cin >> a.edad;
cout << "\nSexo M/F:  ";
cin >> res; 
if((res == 'M') || (res == 'm')){
a.sexo=true;
}else{
a.sexo=false;
}
cout << "\nSintomas: \n";
cin >> a.sintomas; 
cout << "\nDiagnostico: \n";
cin >> a.diagnostico;

return a;
}
//actulizar 
paciente actualizar(paciente a){
int op;
char m;
system("cls");
cout << "Elija el campo que desea actualizar de acuerdo a la sig. lista:\n 1.Nombre\n 2.Edad\n 3.Sexo\n 4.Sintomas\n 5.Diagnostico \n ";
cin >> op;
switch(op){
case 1:
cout << "\nNombre: ";
cin >> a.nombre;
break;

case 2:
cout << "\nEdad: ";
cin >> a.edad;
break;

case 3:
cout << "\nSexo M/F: ";
cin >> m;
a.sexo=true;
if((m=='M')||(m=='m')){
}else{
a.sexo=false;
}
break;

case 4:
cout << "\nSintomas: ";
cin >> a.sintomas;
case 5:
cout << "\nDiagnostico: \n";
cin >> a.diagnostico;
break;

}
return a;
}

edaa(){
	
	cout<<"Promedio de las edades de los pacientes registrados el dia de hoy:"<<endl;
	cout<<"La suma de edades da resultado de: "<<r<<"Numero de pacientes: "<<c<<endl;
	int re = r/c;
	cout<<"Operacion: "<<r<<"/"<<c<<":"<<" "<<re;
	
}



//buscar cliente
void Impresion(paciente a){
cout << "\nNombre: " << a.nombre;
cout << "\nEdad: " << a.edad;
cout << "\nSintomas: " << a.sintomas;
cout << "\nDiagnostico: " << a.diagnostico;
cout << "\nSexo: ";
if(a.sexo == true){
cout << "Maculino\n";
}else{
cout << "Femenino\n";
}
}

//eliminar 
paciente eliminar(paciente b, paciente c){
c.nombre=b.nombre;
c.edad=b.edad;
c.sexo=b.sexo;
c.sintomas=b.sintomas;
c.diagnostico=b.diagnostico;
return c;

}
