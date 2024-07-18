#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Insertion_Sort(int *array, int num){

    int i; 

    for(i=1; i<num; i++){            //Recorremos el arreglo empezando desde el segundo elemento
        int key = array[i]; 
        int j = i-1;

        while(j>=0 && array[j]>key){ //Movemos los elementos mayores que el elemento actual a la derecha
            array[j+1] = array[j];
            j = j-1; 
        }
        array[j+1] = key;            //Colocamos el elemento actual en si poosicion correcta
    }
}

void Selection_Sort(int *array, int num){
    int i, j;

    for(i=0; i<num-1; i++){             //Recorremos el arreglo
        int min = i;

        for(j=i+1; j<num; j++){         //Buscamos el elemento mas pequeño
            if(array[j] < array[min]){  //Si encontramos el mas pequeño
                min = j;                //Cambiamos el indice del mas pequeño
            }
        }
        int aux = array[i];             //Intercambiamos el elemento actual con el minimo encontrado
        array[i] = array[min];
        array[min] = aux;
    }
}

void merge(int *array, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];  //se crean arreglos temporales

	//copia datos a los arreglos temporales
    for (i = 0; i < n1; i++) {  
        L[i] = array[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[q + 1 + j];
    }

	//fusiona los arreglos temporales en el arreglo original
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

	//Copia los elementos restantes de L y R , Si hay alguno
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
//Funcion recursiva que divide el arreglo en subarreglos y los fusiona
void mergeSort(int *array, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;

        mergeSort(array, p, q);	//ordena los subarreglos
        mergeSort(array, q + 1, r);

        merge(array, p, q, r);	//fusiona los subarreglos ordenados
    }
}


void bubble_sort(int *array, int lenght){
    int i, j, ban;

    for(i=1; i<(lenght-1); i++){        //Recorremos el arreglo
        ban = 0; 
        for(j=0; j<(lenght-1); j++){    //Comparamos elementos
            if(array[j] > array[j+1]){  //Si es mayor
                int aux = array[j];     //Cambiamos de posicion
                array[j] = array[j+1];
                array[j+1] = aux;
                ban = 1;                //Marcamos la bandera como 1 para indicar que hubo intercambios
            }
        }
        if(ban == 0){                   //Si no hubo intercambios en la ultima iteracion, el arreglo esta ordenado
        break;                          //Salimos del ciclo
        }
    }
}
