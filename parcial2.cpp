#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
 using namespace std;
 void menu();
 void cola2();
 int main(){
 	int op;
 	do
 	{
	
 	cout<< endl << "\t CONTINUACION ESCOJA UNA DE LAS DOS OPCIONES ";
 	cout<< endl << endl << "\tA 1. PILA  ";
 	cout<< endl << endl << "\tA 2. COLA  ";
 	cout<< endl << endl << "\tA 3. SALIR ";
 	cin >>op;
 	
 	switch(op){
 		case 1:
 			menu();
 		case 2:
 			cola2();
	 }
	 system("pause");
	 } while(op!=3);
	 
 }
 
 
 
 
 
 
 struct pilas
{
int d;
pilas *a;
}*c,*e;
 


void ingresar (void)
{

 if(!c)
 {
 c=new(pilas);
 cout<<"Ingrese elemento: ";
 cin>>c->d;

 c->a=NULL;
 return;
 }
 
 e=new(pilas);
 cout<<"\nIngrese elemento: ";
 cin>>e->d;
 e->a=c;
 c=e;
}

void ultimo(void)
{
	e = c;
	while(e != NULL)
	{
		if(e->a == NULL)
		{
			cout << "el primer dato ingresado fue: " << e->d;
		}
		e = e->a; //contandor
	}
}

void sacar(void)
{
 if(!c)
 {
 cout<<"\n\nNo hay elementos!!";
 return;
 }
 
 e=new(pilas);
 e=c;
 cout<<"\n\nElemento eliminado: " <<e->d;
 c=e->a;
 delete(e);
 
}


void actualizar_pila(void)
{
 int y=2,i,ca=0;
 e=c;
 while(e)
 {
 ca++;
 e=e->a;
 }
 
for(i=0;i<=ca;i++)
 {
 cout<<" ";
 }
 //muestro lo que tiene la pila!!
 i=0;
 e=c;
 while(e)
 {
 cout<<"\n";
 cout<<++i<<" - "<<e->d;
 e=e->a;
 }
}
 void menu(void)
{
int y,opc;
 for(;;)
 {
 cout<<"\n1. Ingresar datos";
 cout<<"\t2. extraer datos";
 cout<<"\t3. el ultimo salir";
 cout<<"\t4. actualizar pila";
 cout<<"\t0. Terminar";
 cout<<"\n Ingrese opcion: ";
 cin>>opc;
 switch(opc)
 {
 case 1:
 ingresar();
 break;
 case 2: 
 sacar();
 break;
  case 3: 
 ultimo();
 break;
 case 4:
 	actualizar_pila();
 	break;
 case 0: 
return;
 default: cout<<"\n Opcion no valida!!"; break;
 }
 
cout<<"\n\nOprima una tecla para continuar";
getch();
 }
}
 
 
 
 
 
 /*                Estructura de los nodos de la cola      
------------------------------------------------------------------------*/
struct nodo
{
    int nro;
    struct nodo *sgte;
};
 
 
/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
 
 
/*                        Encolar elemento      
------------------------------------------------------------------------*/
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
/*                        Desencolar elemento      
------------------------------------------------------------------------*/
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
 
/*                        Mostrar Cola      
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
 
/*              Eliminar todos los elementos de la Cola      
------------------------------------------------------------------------*/
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
void muestra1( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;


	 
}

 
/*                        Menu de opciones    
------------------------------------------------------------------------*/
void menu2()
{
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. PRIMER NUMERO A DESEMCOLAR            "<<endl;
    cout<<" 6. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
  
}
 
/*                        Funcion Principal        
------------------------------------------------------------------------*/
 void cola2()
{
    struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
   

 
    do
    {
        menu2();  
		cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; 
				 cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
            
            case 5: 
            	cout<< "\n\nEl primer numero a desencolar es ";
            	muestra1 (q);
            	
            	break;
            
            
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=6);
   
   
    return ;
}


