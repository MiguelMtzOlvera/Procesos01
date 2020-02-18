#include <iostream>
#include<string>
#include <bits/stdc++.h>
#include<stdlib.h>
#include<cctype>

using namespace std;

char minusculas(char s);

void vocales1();
void reversa2();
void mayus3();
void encr4();
void palin5();

int main(){
	
	char vocal;
	string cadena;
	int opc;
	do{
		cout<<"--------------MENU DE OPCIONES------------- "<<endl<<endl;
	cout<<"\n1. Dice cuantas vocales tiene tu frase"<<endl;
	cout<<"2. Invertir la frase"<<endl;
	cout<<"3. Contar las mayusculas"<<endl;
	cout<<"4. Decodificar frase"<<endl;
	cout<<"5. Dice si es palandrimo"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"Seleccione el numero de una opcion: "<<endl;
	cin>>opc;
	system("cls");
	switch(opc){
		case 1:{
		vocales1();	
		break;
		}
	case 2:{
		reversa2();
		break;
	}
	case 3:{
		mayus3();
		break;
	}
	case 4:{
		encr4();
		break;
	}
	case 5:{
	    palin5();
		break;
	}
	case 6:{
		
		break;
	}
		default:
		cout<<"opcion incorrecta"<<endl;
	}
	} while (opc!=6);
	return 0;
}

void vocales1(){
		string cadena;
	cout<<"Ingrese la palabra: "<<endl;
	cin>>cadena;
	int contador=0;
			for(int i=0; i<cadena.length();i++){
			if(cadena[i]=='a' || cadena[i]=='e'|| cadena[i]=='i'|| cadena[i]=='o'||cadena[i]=='u')
			{
				contador++;
			}
			}
			cout<<"El total de vocales es: "<<contador<<endl;
}

void reversa2(){
		string cadena;
	cout<<"Ingrese la palabra: "<<endl;
	cin>>cadena;
		for(int i=cadena.length()-1;i>=0;i--)
		{
			cout<<cadena[i];
		}
}

void mayus3(){
		string cadena;
	cout<<"Ingrese la palabra: "<<endl;
	cin>>cadena;
	int contador=0;
		string cadenax;
			for(int i=0; i<cadena.length();i++){
			if(cadena[i]>='A'&& cadena[i]<='Z')
			{
				contador++;
			}
			}
			cout<<"El total de las mayusculas son: "<<contador<<endl;
}

void encr4(){
		string cadena;
	cout<<"Ingrese la palabra: "<<endl;
	cin>>cadena;
            string r;
	        for(int i =0; i<cadena.length();i++){
			int letra=int(cadena[i])+3;
			cout<<char(letra);
		}
}

void palin5(){
		string cadena;
	cout<<"Ingrese la palabra: "<<endl;
	cin>>cadena;
string alreves;
		for (int i=cadena.length()-1;i>=0;i--){
			alreves+=cadena[i];
		}
		if(alreves==cadena){
			cout<<"La palabra es palindromo"<<endl;
		}
		else{
			cout<<"La palabra no es palindromo"<<endl;
		}
}

char minusculas(char s) {
	
		s= tolower(s);
	return s;
}
