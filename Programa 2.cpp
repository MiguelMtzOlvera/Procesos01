#include <iostream>

using namespace std;

int LimiteFila ();

int LimiteColumna ();

void Menu_P ();

void Menu_A ();

char Reset_MP ();

char Reset_MA ();

struct Matriz
{
	int x;
	Matriz *ptr;
};

int Agregar ();

float Modificar();

float Insercion ();

void Leer (int x);

void Eliminar (Matriz *&ptr, int &x);

bool Busqueda (int x, int temp, int y1, int y2);

int main ()
{
	Matriz *ptr = new Matriz ();
	bool B;
	int M /*Columna*/, N/*Fila*/, V_x, temp, Busqueda_M, Busqueda_N;
	char Op_MP=NULL, Op_MA=NULL, re;
	M=LimiteColumna ();
	N=LimiteFila ();
	Matriz Tabla [M][N];
	do
	{
		if ((Op_MP>='1' & Op_MP<='4') | Op_MP == NULL)
		{
			Menu_P ();
		}
		cin>>Op_MP;
		switch (Op_MP)
		{
			case '1':
				for (int i=0; i<M; i++)
				{
					for (int j=0; j<N; j++)
					{
						if (i==0)
						{
							cout<<"Ingrese el valor de la primera columna y";
						}
						else if (i==M-1)
						{
							cout<<"Ingrese el valor de la ultima columna y";
						}
						else
						{
							cout<<"Ingrese el valor de la columna "<<i+1<<" y";
						}
						if (j==0)
						{
							cout<<" el valor de la primera flia: ";
						}
						else if (j==N-1)
						{
							cout<<" el valor de la ultima fila: ";
						}
						else
						{
							cout<<" el valor de la fila "<<j+1<<": ";
						}
						Tabla[i][j].x = Agregar();
					}
				}
				re = Reset_MP (); //Reinicia el menu pricipal en caso de que se desee
				break;
			case '2':
				cout<<"Leyendo elementos...\n";
				for (int i=0; i<M; i++)
				{
					for (int j=0; j<N; j++)
					{
						V_x=Tabla[i][j].x;
						Leer (V_x);
					}
					cout<<"\n";
				}
				re = Reset_MP (); //Reinicia el menu pricipal en caso de que se desee
				break;
			case '3':
				system ("cls");
				do
				{
					if ((Op_MA>='1' & Op_MA<='3') | Op_MA == NULL)
					{
						Menu_A ();
					}
					cin>>Op_MA;
					switch (Op_MA)
					{
						case '1':
							cout<<"Seleccione la columna del registro que desea modificar: ";
							cin>>Busqueda_M;
							cout<<"Seleccione la fila del registro que desea modificar: ";
							cin>>Busqueda_N;
							Tabla[Busqueda_M-1][Busqueda_N-1].x=Modificar ();
							re = Reset_MA ();
							break;
						case '2':
							cout<<"Seleccione la columna del registro que desea insertar: ";
							cin>>Busqueda_M;
							cout<<"Seleccione la fila del registro que desea insertar: ";
							cin>>Busqueda_N;
							if (Tabla[Busqueda_M-1][N].x!=NULL)
							{
								N++;
							}
							for (int i=M; i>Busqueda_M-1; i--)
							{
								Tabla[i][Busqueda_N-1].x=Tabla[i-1][Busqueda_N-1].x;
							}
							Tabla[Busqueda_M-1][Busqueda_N-1].x=Insercion ();
							re = Reset_MA ();
							break;
						case '3':
							cout<<"Seleccione la columna del registro que desea eliminar: ";
							cin>>Busqueda_M;
							cout<<"Seleccione la fila del registro que desea eliminar: ";
							cin>>Busqueda_N;
							Eliminar (ptr, Tabla[Busqueda_M-1][Busqueda_N-1].x);
							for (int i=Busqueda_M; i<M; i++)
							{
								Tabla[i][Busqueda_N-1].x=Tabla[i+1][Busqueda_N-1].x;
							}
							N--;
							re = Reset_MA ();
							break;
						default:
							cout<<"Introducir una opcion valida: ";
							break;
					}
				} while ((Op_MA>='1' | Op_MA<='3') & (re=='s' | re=='S'));
				re = Reset_MP (); //Reinicia el menu pricipal en caso de que se desee
				break;
			case '4':
				cout<<"Ingrese el numero que desea buscar: ";
				cin>>V_x;
				for (int i=0; i<M; i++)
				{
					for (int j=0; j<N; j++)
					{
						temp=Tabla[i][j].x;
						B=Busqueda (V_x, temp, i, j);
					}
				}
				if(B==false)
				{
					cout<<"El numero no fue encontrado\n";
				}
				cout<<"Proceso finalizado\n";
				re = Reset_MP ();
				break;
			default:
				cout<<"Introducir una opcion valida: ";
				break;
		}
	} while ((Op_MP>='1' | Op_MP<='4') & (re=='s' | re=='S'));
}

int LimiteFila ()
{
	int lim;
	cout<<"Introducir el maximo numero de registros de la fila: "; //Introduce el limite de datos ingresados por el usuario
	cin>>lim;
	system("cls");
	return lim;
}

int LimiteColumna ()
{
	int lim;
	cout<<"Introducir el maximo numero de registros de la columna: "; //Introduce el limite de datos ingresados por el usuario
	cin>>lim;
	return lim;
}

void Menu_P ()
{
	cout<<"---------------------------------------------------MENU DE OPCIONES------------------------------------------------------ "<<endl<<endl;
	cout<<"1. Agregar registros\n2. Lectura de registros\n3. Actualizacion de registros\n4. Busqueda secuencial\nIntroducir una opcion: ";
}

void Menu_A ()
{
	cout<<"---------------------------------------------------MENU DE OPCIONES------------------------------------------------------ "<<endl<<endl;
	cout<<"1. Modificar registros\n2. Insercion de registros\n3. Eliminacion de registros\nIntroducir una opcion: ";
}

char Reset_MP ()
{
	char re;
	cout<<"Desea regresar al menu principal? (S/N): ";
	do
	{
		cin>>re;
		if ((re!='s' & re!='S') & (re!='n' & re!='N'))
		{
			cout<<"Introducir una opcion valida: ";
		}
	} while ((re!='s' & re!='S') & (re!='n' & re!='N'));
	system ("cls");
	return re;
}

char Reset_MA ()
{
	char re;
	cout<<"Desea regresar al menu de actualizacion? (S/N): ";
	do
	{
		cin>>re;
		if ((re!='s' & re!='S') & (re!='n' & re!='N'))
		{
			cout<<"Introducir una opcion valida: ";
		}
	} while ((re!='s' & re!='S') & (re!='n' & re!='N'));
	system ("cls");
	return re;
}

int Agregar ()
{
	int x;
	cin>>x;
	return x;
};

void Leer (int x)
{
	cout<<x<<"\t";
}

float Modificar ()
{
	float x;
	cout<<"Ingrese el nuevo valor: ";
	cin>>x;
	return x;
}

float Insercion ()
{
	float x;
	cout<<"Ingrese el nuevo valor: ";
	cin>>x;
	return x;
}

void Eliminar (Matriz *&ptr, int &x)
{
	Matriz *aux = new Matriz ();
	x=aux->x;
	ptr=aux->ptr;
	delete aux;
}

bool Busqueda (int x, int temp, int y1, int y2)
{
	bool B;
	if (temp==x)
	{
		cout<<"El numero se encontro en el registro ("<<y1+1<<", "<<y2+1<<")\n";
		B=true;
	}
	return B;
}
