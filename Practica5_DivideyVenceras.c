#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int encontrarMaximoCruce(int arreglo[], int bajo, int medio, int alto, int *inicio, int *fin) {
    int suma_izquierda = -100000;
    int suma_derecha = -100000;
    int suma = 0;

    int i;
    for (i = medio; i >= bajo; i--) {
        suma += arreglo[i];
        if (suma > suma_izquierda) {
            suma_izquierda = suma;
            *inicio = i;
        }
    }

    suma = 0;

    int j;
    for (j = medio + 1; j <= alto; j++) {
        suma += arreglo[j];
        if (suma > suma_derecha) {
            suma_derecha = suma;
            *fin = j;
        }
    }

    return suma_izquierda + suma_derecha;
}

int encontrarMaximoSubarreglo(int arreglo[], int bajo, int alto, int *inicio, int *fin) {
    if (bajo == alto) {
        *inicio = *fin = bajo;
        return arreglo[bajo];
    }

    int medio = (bajo + alto) / 2;
    int inicio_izquierda, fin_izquierda; 
	int inicio_derecha, fin_derecha; 
	int inicio_cruce, fin_cruce;

    int suma_izquierda = encontrarMaximoSubarreglo(arreglo, bajo, medio, &inicio_izquierda, &fin_izquierda);

    int suma_derecha = encontrarMaximoSubarreglo(arreglo, medio + 1, alto, &inicio_derecha, &fin_derecha);

    int suma_cruce = encontrarMaximoCruce(arreglo, bajo, medio, alto, &inicio_cruce, &fin_cruce);

    if (suma_izquierda >= suma_derecha && suma_izquierda >= suma_cruce) {
        *inicio = inicio_izquierda;
        *fin = fin_izquierda;
        return suma_izquierda;
    } else if (suma_derecha >= suma_izquierda && suma_derecha >= suma_cruce) {
        *inicio = inicio_derecha;
        *fin = fin_derecha;
        return suma_derecha;
    } else {
        *inicio = inicio_cruce;
        *fin = fin_cruce;
        return suma_cruce;
    }
}

int main() {
	system("cls");

    int inicio, fin;
	int n; 

	printf("\n-MAXIMO SUBARREGLO-\n");
	printf("\nIngrese el tamanio del arreglo: ");
	scanf("%d", &n);

	int *Array;
    
    Array = calloc(n, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"
	srand(time(NULL));

	printf("\nDias:		");					//Imprimimos dias
	int i;
	for(i= 0; i<n; i++){
		printf("%d	", i);
	}

	printf("\nPrecio: 	");
	for (i = 0; i < n; i++) {
    	Array[i] = rand() % 99 + 1;  	//Llena el arreglo con numeros aleatorios del 1 al 99
        printf("%d	", Array[i]);
    }

	printf("\nDiferencia:		");
	
    int w = n-1;
	int *dif;

    dif = calloc(w, sizeof(int)); //Asignacion de memoria dinamica de tipo "entero"

	for(i = 0; i < w; i++){
    	dif[i] = Array[i+1] - Array[i];
    	printf("%d	", dif[i]);			//Imprimimos la diferencia entre los elementos
    }

	printf("\n");

    int suma_maxima = encontrarMaximoSubarreglo(dif, 0, w - 1, &inicio, &fin);

	printf("\n");
    printf("El subarreglo con la suma maxima es: ");
    for (i = inicio; i <= fin; i++) {
        printf("%d ", dif[i]);
    }
    printf("\n");
    printf("La suma maxima del subarreglo es: %d\n", suma_maxima);

    free(Array);
    free(dif);

    return 0;
}
