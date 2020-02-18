#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

typedef struct Arreglo{
	float num;
}numero;

void menu(float *ptr,int Max);
void entrada(float *ptr,int Max);
void mostrar(float *ptr,int Max);
void agregar(float *ptr,int Max);
void modificar(float *ptr,int Max);
void insertar(float *ptr,int Max);
void eliminar(float *ptr,int Max);
void buscar(float *ptr,int Max);
void limpiar();


main(){
   int Max;
	float *ptr=NULL;   
	
	menu(ptr, Max);
	
	getch();
}

void menu(float *ptr,int Max){
	int opc,opc2;
	cout<<"----------------------------MENU DE OPCIONES-------------------- "<<endl<<endl;
	cout<<"1)Ingresar Datos del Arreglo\n2)Mostrar Datos del Arreglo\n3)Actualizacion\n4)Buscar\n";
	cin >> opc;
	switch (opc){
		case 1:
	    limpiar(); 
		entrada(ptr, Max); break;
		case 2: 
	    limpiar(); 
		mostrar(ptr, Max); break;
		case 3:
	    limpiar(); 
	    cout<<"------------------------SUBMENU DE OPCIONES------------------- "<<endl<<endl;
    	cout<<"1)Agregar\n2)Modificar\n3)Insertar\n4)Eliminar\n";
	cin >> opc2; 
		    switch (opc2){
		    case 1:
		        limpiar();
		        agregar(ptr, Max);
			    limpiar();
			break;	
			case 2:
				limpiar();
			    modificar(ptr, Max); 
			    limpiar();
			break;
			case 3:
				limpiar();
			    insertar(ptr, Max); 
			    limpiar();
			 break;
			case 4: 
		    	limpiar();
			    eliminar(ptr, Max); 
			    limpiar();
			break; 
			default:system("cls");cout<<"No existe esa opcion, vuelva a intentar: "<<endl;
			 buscar(ptr, Max); 
			break;
		} break; 
		case 4:
	       	limpiar();
		    buscar(ptr, Max); 
		    limpiar();
		 break;
		 default:system("cls");cout<<"No existe esa opcion, vuelva a intentar: "<<endl;
		  buscar(ptr, Max); 
		 break;
	}
}

void entrada(float *ptr,int Max){
	int i;
	
	cout<<"Tamaño del vector: ";
	cin>>Max;
	numero Tarreglo[Max];
	ptr=&Tarreglo[0].num;
	
	for(i=0; i<Max; i++){
		cout<<"Ingresa un elemento en la posicion ["<<i<<"]: ";
		cin>>*(ptr+i);
	}
	limpiar();
	menu(ptr, Max);
}

void mostrar(float *ptr,int Max){
	int i;
	for(i=0; i<Max; i++){
		cout<<*(ptr+i)<<" ";
		cout<<"\n";
	}
	system("pause");
	limpiar();
	menu(ptr,Max);
}

void agregar(float *ptr,int Max){
	int i;
	int elem;
	  for(i=0;i<1;i++){
                    cout<<"Que elemento desea agregar : ";cin>>elem;
                    Max++;
                    *(ptr+Max-1)=elem;
                }
    system("pause");
	limpiar();
	menu(ptr,Max);
}

void modificar(float *ptr,int Max){
	int pos;

	    cout<<"Que posicion desea modificar desde [0] hasta ["<<Max-1<<"]: ";cin>>pos;
	    
	    if(pos<Max){
	    	
	    	cout<<"El nuevo valor en el arreglo es ["<<pos<<"] = ";
	    	cin>>*(ptr+pos);
	    	limpiar();
	    	menu(ptr,Max);
		} 
		else{
			cout<<"Esa posicion no existe!!!!\n";
			modificar(ptr,Max);
		}
}

void insertar(float *ptr,int Max){
	int i,elem,pos;
	
    cout<<"Que elemento desea insertar: ";cin>>elem;
	 
	 do{
	 	cout<<"En que posicion desea insertar de [0] hasta ["<<Max-1<<"]: ";cin>>pos;
	 	
	 	if(pos>(Max-1)||pos<0)
	 	
	 	cout<<"Ingrese una posicion valida!!!"<<endl;
	 	
	 	}while(pos>(Max-1)||pos<0);
	 	
	 	Max++;
	 	
	 	for(i=Max-1;i>=pos;i--){
	 		 
			  *(ptr+i+1)=*(ptr+i);
                    if(pos==i)
                      *(ptr+pos)=elem;
		        }   
	system("pause");
	limpiar();
	menu(ptr,Max);  
}

void eliminar(float *ptr,int Max){
	int i;
	int pos;
	
	do{
	    cout<<"Que posicion desea eliminar de [0] hasta ["<<Max-1<<"]: ";cin>>pos;
	    
	    if(pos>(Max-1)||pos<0)
	    
	    cout<<"Ingrese una posicion valida!!!"<<endl;

	} while(pos>(Max-1)||pos<0);
	for(i=pos;i<Max;i++){
		*(ptr+i)=*(ptr+i+1);
	}
	Max--;
	system("pause");
	limpiar();
	menu(ptr,Max);
}

void buscar(float *ptr,int Max){
	int i;
	int elem;
    cout<<"Que elemento desea buscar: ";cin>>elem;

                for(i=0;i<Max;i++){
                    if(*(ptr+i)==elem){
                        cout<<"El elemento buscado se encuentra en la posicion: ["<<i<<"]"<<endl;
                    }
                    else{
                    	 if(i==Max-1){
                            cout<<"No se encuetra el elemento que busca!!!"<<endl;
                        }
                    }
                }
    system("pause");
	limpiar();
	menu(ptr,Max);				
}

void limpiar(){
	system ("cls");
}

