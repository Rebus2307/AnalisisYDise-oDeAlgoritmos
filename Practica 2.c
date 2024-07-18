/*
	PRACTICA 2
 	Integrantes:
	-Cruz Merlin Wilfrido
 	-Berrospe Negrete Angela Alessandra 
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];  //se crean arreglos temporales

	//copia datos a los arreglos temporales
    for (i = 0; i < n1; i++) {  
        L[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

	//fusiona los arreglos temporales en el arreglo original
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

	//Copia los elementos restantes de L y R , Si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Funcion recursiva que divide el arreglo en subarreglos y los fusiona
void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;

        mergeSort(arr, p, q);	//ordena los subarreglos
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);	//fusiona los subarreglos ordenados
    }
}

int main() {
    int n,i;
    printf("Ingrese la cantidad de numeros a ordenar: ");
    scanf("%d", &n);

    int arr[n]; 	//Crea un arreglo de tama�o n

    srand(time(NULL));
    printf("\nDatos desordenados:\n ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 99 + 1;  	//Llena el arreglo con numeros aleatorios del 1 al 99
        //printf("%d ", arr[i]);
    }

    clock_t begin = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("\n\nDatos ordenados:\n ");
    for (i = 0; i < n; i++) {
    	printf("%d ", arr[i]);
    }

    printf("\n\nTiempo de ejecucion: %f segundos\n\n", ((double)(end - begin)) / CLOCKS_PER_SEC);

    return 0;
}


