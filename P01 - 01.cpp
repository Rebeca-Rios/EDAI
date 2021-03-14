/*
	Programadores:
		Castillo V. Luisa
		Galván M. Carlos
		Gómez I. Tania
		Ríos C. Rebeca
		
	Fecha: 04 - Marzo - 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int p1(); //Prototipo para el ejercicio 1
int p2(); //Prototipo para el ejercicio 2
int p3(); //Prototipo para el ejercicio 3
int p4(); //Prototipo para el ejercicio 4

void crearMensaje(); //Parte del programa Escítala Espartana
void descifrarMensaje(); //Parte del programa Escítala Espartana

int main(){
	setlocale(LC_CTYPE, "Spanish"); //Permite imprimir con acentos y carácteres especiales. Pertenece a la librería <locale.h>
	int n;
	while(1){
		printf("\n\tIngresa el número del programa: ");
		scanf("%d", &n);
		switch(n){ //Menú para llamar a los programas
			case 1:
				p1();
			break;
			case 2:
				p2();
			break;
			case 3:
				p3();
			break;
			case 4:
				p4();
			break;
			case 5:
				return 0;
			break;
		}
	}
}

int p1(){
	int a[10]; //Arreglo tipo entero de 10 elementos unidimensionales
	printf("\n\tDirección del arreglo: %p\n", &a); //Imprime la dirección del arreglo
	for(int i = 0; i < 10; i++)
		printf("\n\tDirección elemento %d: %p", i+1, &a[i]); //Imprime la dirección de cada elemento del arreglo
	printf("\n\n");
}

int p2(){
	double b[3][3]; //Arreglo tipo doble de 9 elementos ordenados en dos dimensiones
	printf("\n\tDirección del arreglo: %p\n", &b); //Imprime la dirección del arreglo
	for(int i = 0; i < 3; i++){
		printf("\n");
		for(int j = 0; j < 3; j++)
			printf("\n\tDirección elemento [%d, %d]: %p", i+1, j+1, &b[i][j]); //Imprime la dirección de cada elemento del arreglo
	}
	printf("\n\n");
}

int p3(){
	char c[3][2][4]; //Arreglo tipo doble de 24 elementos oredenados en tres dimensiones
	printf("\n\tDirección del arreglo: %p\n", &c); //Imprime la dirección del arreglo
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			for(int e = 0; e < 4; e++)
				printf("\n\tDirección elemento [%d, %d, %d]: %p", i+1, j+1, e+1, &c[i][j][e]); //Imprime la dirección de cada elemento del arreglo
		}
		printf("\n");
	}
	printf("\n\n");
}

int p4(){
	short opcion = 0;
	
	while(1){
		printf("\n\n\t*** ESCÍTALA ESPARTANA ***\n");
		printf("\n\t¿Qué desea realizar?\n");
		printf("\t\t1) Crear mensaje cifrado.\n");
		printf("\t\t2) Descifrar mensaje.\n");
		printf("\t\t3) Salir.\n\t");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				crearMensaje();
			break;
			case 2:
				descifrarMensaje();
			break;
			case 3:
				return 0;
			default:
				printf("Opción no válida.\n");
			}
	}
	printf("\n\n");
	return 0;
}

void crearMensaje(){
	int ren, col, i, j, k=0;
	printf("\n\tIngresar el tamaño de la escítala:\n");
	printf("\n\t\tRenglones: ");
	scanf("%i",&ren);
	printf("\t\tColumnas: ");
	scanf("%i",&col);
	
	char escitala[ren][col]; //Arreglo donde se cifrará el mensaje. El tamaño es de acuerdo a los datos ingresador por el usuario.
	char texto[ren*col]; //Arreglo donde se guardará el mensaje. El tamaño es de acuerdo a los datos ingresador por el usuario.
	
	printf("\n\n\tEscriba el texto a cifrar:\n\n\t");
	scanf("%s", texto); //Lee el mensaje a cifrar. SIN ESPACIOS. 
	
	for (i=0 ; i<ren ; i++)
		for (j=0 ; j<col ; j++)
			escitala[i][j] = texto[k++]; //Se guarda el mensaje por renglones (de derecha a izquierda).
			
	printf("\n\tEl texto en la tira queda de la siguiente manera:\n\n\t\t");
	for (i=0 ; i<col ; i++)
		for (j=0 ; j<ren ; j++)
			printf("%c", escitala[j][i]); //Se imprime el mensaje por columnas (de arriba a abajo).
			
	printf("\n");
}
	
void descifrarMensaje(){
	int ren, col, i, j, k=0;
	printf("\n\tIngresar el tamaño de la escítala:\n");
	printf("\n\t\tRenglones: ");
	scanf("%i",&ren);
	printf("\t\tColumnas: ");
	scanf("%i",&col);
	
	char escitala[ren][col]; //Arreglo donde se cifrará el mensaje. El tamaño es de acuerdo a los datos ingresador por el usuario.
	char texto[ren*col]; //Arreglo donde se guardará el mensaje. El tamaño es de acuerdo a los datos ingresador por el usuario.
	
	printf("\n\tEscriba el texto a cifrar:\n\n\t");
	scanf("%s", texto); //Lee el mensaje a descifrar. SIN ESPACIOS.
	
	for (i=0 ; i<col ; i++)
		for (j=0 ; j<ren ; j++)
			escitala[j][i] = texto[k++];  //Se guarda el mensaje por columnas (de arriba a abajo).
			
	printf("\n\tEl texto descifrado es:\n\n\t");
	for (i=0 ; i<ren ; i++)
		for (j=0 ; j<col ; j++)
			printf("%c", escitala[i][j]); //Se imprime el mensaje por renglones (de derecha a izquierda).
}
