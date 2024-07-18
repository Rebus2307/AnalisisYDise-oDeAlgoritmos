#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ordenamientos.c"

int Randomized_Partition();
void Randomized_QuickSort();
int Partition();
int Random();

int Random (int p, int r){
    srand(time(NULL));
    return p + rand() % (r - p);
}
int Randomized_Partition(int *array, int p, int r){
    int i = Random(p,r);
    int aux = array[i];
    array[i] = array[r];
    array[r] = aux;

    return Partition(array, p, r);
}
void Randomized_QuickSort(int *array, int p, int r){
    if(p<r){
        int q = Randomized_Partition(array, p, r);
        Randomized_QuickSort(array, p, q-1);
        Randomized_QuickSort(array, q+1, r);
    }
}
int Partition(int *array, int p, int r){ 
    int x = array[r];
    int i = p-1;

    int j;
    for(j=p; j<r; j++){
        if(array[j] <= x){
            i++;
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    int aux = array[i+1];
    array[i+1] = array[r];
    array[r] = aux;

    return i+1;
}


int main(){

    int num, *array;
    double time_spent = 0.0; 

    printf("\n\n\t-Randomized_QuickSort-");
    printf("\n\n\tIngrese el numero de variables a trabajar: ");
    scanf("%d", &num);

    array = calloc(num, sizeof(int));   //Asignacion de memoria dinamica de tipo "entero"
    srand(time(NULL));                  //Generación de numeros aleatorios

    int i;
    for(i=0; i<num; i++){   
        array[i] = rand()%99 +1;   
        //printf("%d ", array[i]);
    }
    
    mergeSort(array, 0, num - 1); 		//Los ordenamos con Merge

    printf("\n\n\tEl arreglo ordenado queda asi: \n\n");

    clock_t begin = clock();
    Randomized_QuickSort(array, 0, num-1); //Llamamos a la funcion Quick_Sort
    clock_t end = clock();

    //Mostramos el arreglo ya ordenado
    for(i=0; i<num; i++){
       // printf("%d ", array[i]);
    }

    free(array);    //Liberamos el arreglo

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\n\n\tEl tiempo transcurrido es de: %f segundos\n\n", time_spent);

    return 0;
}
