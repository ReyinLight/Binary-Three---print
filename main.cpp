#include<stdio.h>
#include<stdlib.h>


struct Nodo{
	int valor;
	Nodo *der;
	Nodo *izq;
};


bool vacio(Nodo *n);
Nodo* crearNodo(int valor);
void insertar(Nodo *&arbol, int valor);
bool eliminar(Nodo *&arbol, int valor);

void mostrar(Nodo *arbol);
void mostrar(Nodo *arbol, int nivel);

void preOrden(Nodo *arbol, int nivel, int caracteres[]);

int main(){
	
	Nodo *arbol = NULL;
	int opc;
	int aux;
	
	insertar(arbol, 5);
	
	insertar(arbol, 2);
	insertar(arbol, 8);
	
	insertar(arbol, 1);
	insertar(arbol, 4);
	
	insertar(arbol, 7);
	insertar(arbol, 10);
	
	insertar(arbol, 3);
	
	
	insertar(arbol, 15);
	insertar(arbol, 13);
	insertar(arbol, 17);
	insertar(arbol, 11);
	insertar(arbol, 6);
	
	
	
	int caracteres[10] = {0};
	
	do{
		system("cls");
		mostrar(arbol);
		printf("\nMenu\n");
		printf("1 - Insertar\n");
		printf("2 - Eliminar\n");
		printf("3 - PreOrden\n");
		printf("4 - Mostrar\n");
		printf("5 - Salir\n");
		scanf("%i",&opc);
		
		
		switch(opc){
			case 1:
				printf("Escribe el valor entero a insertar\n");
				scanf("%i", &aux);
				insertar(arbol, aux);
				break;
			case 2:
				printf("Escribe el valor a eliminar\n");
				scanf("%i", &aux);
				if(eliminar(arbol, aux))
					printf("Se eliminó");
				else
					printf("El valor no se ecuentra en el arbol");
				break;
			case 3:
				system("cls");
				preOrden(arbol, 0, caracteres);
				break;
			case 4:
				mostrar(arbol);
				break;
			
		}
		
		printf("\n");
		system("pause");
		
	}while(opc != 5);
	
	return 0;
}


// Funcion vacio
bool vacio(Nodo *n){
	
	if(n == NULL){
		return true;
	}
	
	return false;
}

// Funcion crear
Nodo* crearNodo(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->der = NULL;
	n->izq = NULL;
	
	return n;
}

// Funcion insertar
void insertar(Nodo *&arbol, int valor){
	if(vacio(arbol)){
		arbol = crearNodo(valor);
	}
	else{
		if(arbol->valor > valor)
			insertar(arbol->izq, valor);
		else
			insertar(arbol->der, valor);
	}
}

// Funcion eliminar
bool eliminar(Nodo *&arbol, int valor){
	if(arbol == NULL)
		return false;
	
	if(valor < arbol->valor)
		eliminar(arbol->izq, valor);
	else if(valor > arbol->valor)
		eliminar(arbol->der, valor);
	
		
	
}

// Funcion mostrar
void mostrar(Nodo *arbol){
	printf(".::Arbol::.\n");
	if(vacio(arbol))
		printf("Arbol vacio");
	else
		mostrar(arbol, 0);
		
	return;
}

// Fucion mostrar recursiva
void mostrar(Nodo *arbol, int nivel){
	if(arbol == NULL){
		return;
	}
	else{
		mostrar(arbol->izq, nivel + 1);
		printf("%i " , arbol->valor);
		mostrar(arbol->der, nivel + 1);
	}
}

void preOrden(Nodo *arbol, int nivel, int caracteres[10]){
	
	// 3 - pipe de 2 caracteres
	// 2 - pipe de continuidad
	// 1 - pipe de un hijo
	// 0 - Sin pipe
	
	if(arbol == NULL)
		return;
	else{
		
		if(nivel > 0)
		{
			// Primero caracteres[]
			for(int i = 0; i < nivel; i++){
				if(caracteres[i] == 3){
					printf("%c",195); // Caracter de 2 nodos
					caracteres[i]--; // Al insertarlo el caracter cambia
				}else if(caracteres[i] == 2){
					printf("%c",179); // Caracter de continuidad
				}else if(caracteres[i] == 1){
					printf("%c",192); // Caracter de 1 nodo
					caracteres[i]--; // Al insertarlo el caracter cambia
				}else if(caracteres[i] == 0){
					printf("%c",255); //Caracter vacio
				}
				
				// espacios vacios
				if(i < nivel - 1){
					printf("%c",255);
					printf("%c",255);
					printf("%c",255);
				}
				
			}
			
			// Lineas horizontales
			printf("%c",196);
			printf("%c",196);
			printf("%c",196);
		}
		
		printf("%i\n", arbol->valor);
		
		
		if(arbol->der != NULL && arbol->izq != NULL){
			caracteres[nivel] = 3;
		}else if(arbol->der != NULL || arbol->izq != NULL){
			caracteres[nivel] = 1; 
		}else
			caracteres[nivel] = 0;
			
		preOrden(arbol->der, nivel + 1, caracteres);
		if(caracteres[nivel] == 2)
			caracteres[nivel]--;
		preOrden(arbol->izq, nivel + 1, caracteres);
		
	}
	
}





