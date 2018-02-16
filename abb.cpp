//Arbol Binario. 
#include <iostream>
using namespace std;

class Nodo{
	public:
		int valor, x;
		Nodo* der;
		Nodo* izq;
	public:
		Nodo(int n);
	friend class Arbol;
};
Nodo::Nodo(int v)
{
	valor=v;
	der=NULL;
	izq=NULL;
}

class Arbol{
	public:
		Nodo* raiz;
		Nodo* arbol;
		Nodo* padre;
		Nodo* deleteNodo;
		Nodo* aux;
		bool encontrado;
	public:
		Arbol(){
			raiz=NULL;
			arbol=NULL;
			bool encontrado= false;
		}
		void recorrido(Nodo* arbol, int x);
		void preOrden(Nodo* arbol);
		void postOrden(Nodo* arbol);
		void inOrden(Nodo* arbol);
		void insertar();
		Nodo* buscar(Nodo* arbol, int x);
		void eliminarDosSubarboles();
		void eliminarSubarbol();
		void eliminarHoja();
		void eliminarRaiz();
};

void Arbol::preOrden(Nodo* arbol)
{
	if (arbol != NULL)
	{
		cout<<arbol->valor<<"  ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void Arbol::postOrden(Nodo* arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->valor<<"  ";
	}
}

void Arbol::inOrden(Nodo* arbol)
{
	if (arbol != NULL)
	{
		inOrden(arbol->izq);
		cout<<arbol->valor<<"  ";
		inOrden(arbol->der);
	}
}

void Arbol::recorrido(Nodo* arbol, int x)
{
	if (arbol != NULL)
	{
		if (arbol->valor == x)
		{
			padre=arbol;
			encontrado = true;
		}
		recorrido(arbol->izq, x);
		recorrido(arbol->der, x);
	}
}

void Arbol::insertar()
{
	int o, n;
	cout<<endl<<"Ingresa el numero a insertar: ";
	cin>>n;
	Nodo* nuevo = new Nodo(n);
	if (raiz==NULL)
	{
		raiz=nuevo;
	}
	else
	{
		int x;
		cout<<"Dame el valor del padre: "; cin>>x;
		recorrido(raiz, x);
		if (encontrado)
		{
			if (n > padre->valor)
			{
				padre->der = nuevo;
			}
			else if (n < padre->valor)
			{
				padre->izq = nuevo;
			}
		}
		else
			cout<<"Ese nodo no existe"<<endl;	
		encontrado=false;	
	}
}

void Arbol::eliminarRaiz()
{
	raiz = NULL;
}

void Arbol::eliminarHoja()
{
	if (raiz!=NULL)
	{
		int x;
		cout<<"Nodo a eliminar: "; cin>>x;
		recorrido(raiz, x);
		if (encontrado)
		{
			aux=padre;
			aux = NULL;
		}
		else
			cout<<"Ese nodo no existe"<<endl;
		encontrado = false;
	}
}

void Arbol::eliminarSubarbol()
{
	if (raiz!=NULL)
	{
		int x;
		cout<<"Nodo a eliminar: "; cin>>x;
		recorrido(raiz, x);
		deleteNodo = padre;
		if(deleteNodo->izq!=NULL && deleteNodo->der==NULL)
				*deleteNodo=*deleteNodo->izq;
		else if(deleteNodo->der!=NULL && deleteNodo->izq==NULL)
				*deleteNodo=*deleteNodo->der;
	}
}

void Arbol::eliminarDosSubarboles()
{
	if (raiz!=NULL)
	{
		int x;
		cout<<"Nodo a eliminar: "; cin>>x;
	//	deleteNodo = buscar(raiz, x);
		Nodo* aux=deleteNodo;
		while(aux->izq!=NULL)
			aux=aux->izq;
		deleteNodo->valor=aux->valor;
		//*aux=NULL;
	}
}

int main ()
{
	Arbol* abb = new Arbol();
	int o, op;
	do 
	{
		cout<<endl<<"Teclea la opcion deseada"<<endl<<endl;
		cout<<"1) Insertar nodo"<<endl;
		cout<<"2) Recorrer arbol"<<endl;
		cout<<"3) Eliminar nodo"<<endl;
		cout<<"4) Buscar nodo"<<endl;
		cout<<"5) Salir"<<endl<<"Opcion: ";
		cin>>o;
		switch (o)
		{
			case 1:
				system ("cls");
				abb->insertar();
				break;
			case 2:
				system("cls");
				cout<<"Recorrer arbol:"<<endl;
				cout<<"   1) In-Orden"<<endl;
				cout<<"   2) Pre-Orden"<<endl;
				cout<<"   3) Post-Orden"<<endl<<endl;
				cout<<"Opcion: "; cin>>op;	
				if (op==1)
				{
					//InOrden
					system ("cls");
					if (abb->raiz==NULL)
					{
						cout<<"Arbol vacio"<<endl;
					}
					else
					{
						abb->inOrden(abb->raiz);
					}		
				}
				else if (op==2)
				{
					//PreOrden
					system ("cls");
					if (abb->raiz==NULL)
					{
						cout<<"Arbol vacio"<<endl;
					}
					else
					{
						abb->preOrden(abb->raiz);
					}
				}
				else if (op==3)
				{
					//PostOrden
					system ("cls");
					if (abb->raiz==NULL)
					{
						cout<<"Arbol vacio"<<endl;
					}
					else
					{
						abb->postOrden(abb->raiz);
					}
				}
				else
					cout<<"Opcion no valida"<<endl;
				break;
			case 3:
				system("cls");
				cout<<"Eliminar un nodo:"<<endl;
				cout<<"   1) Nodo raiz"<<endl;
				cout<<"   2) Nodo hoja"<<endl;
				cout<<"   3) Nodo con un subarbol"<<endl;
				cout<<"   4) Nodo con dos subarboles"<<endl;
				cout<<"Opcion: "; cin>>op;
				if (op==1)
					abb->eliminarRaiz();
				else if (op==2)
					abb->eliminarHoja();
				else if (op==3)
					abb->eliminarSubarbol();
				else if (op==4)
					abb->eliminarDosSubarboles();
				else
					cout<<"Opcion no valida"<<endl;
				break;
			case 4:
				int x;
				system("cls");
				cout<<"Ingresa el valor a buscar: "; cin>>x;
				abb->recorrido(abb->raiz, x);
				if (abb->encontrado==true)
					cout<<"Nodo encontrado";
				else
				{
					cout<<"Nodo no encontrado";
				}
				abb->encontrado=false;
				break;
			case 5:
				return 0;
			default:
				cout<<"Opcion no valida"<<endl;	
				break;
		}
	}while (o>0 && o!=5);
}
