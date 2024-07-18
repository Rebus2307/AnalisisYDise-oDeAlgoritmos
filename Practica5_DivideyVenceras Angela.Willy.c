/*
	PRACTICA 5
		Integrantes:
		-Cruz Merlin Wilfrido
		-Berrospe Negrete Angela Alessandra 
		
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <limits.h>

struct subarray {
    int left;
    int right;
    int sum;
};

struct subarray Find_Max_Crossing_subarray(int A[], int low, int mid, int high){
	
	int left_sum = -100000; 

	int sum = 0;

	int i, max_left;
	for(i = mid; i >= low; i--){
		sum = sum + A[i];

		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}
	 int right_sum = -100000;
    int max_right, j;
    sum = 0;
    for(j = mid+1; j <= high; j++){
        sum = sum + A[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    
}
struct subarray result = {max_left, max_right, left_sum + right_sum};
    return result;
}

struct subarray Find_Maximum_Subarray(int A[], int low, int high){
    if(low == high){
        struct subarray result = {low, high, A[low]};
        return result;
    }
    else{
        int mid = (low + high)/2;
        struct subarray left = Find_Maximum_Subarray(A, low, mid);
        struct subarray right = Find_Maximum_Subarray(A, mid+1, high);
        struct subarray cross = Find_Max_Crossing_subarray(A, low, mid, high);
        if(left.sum >= right.sum && left.sum >= cross.sum){
            return left;
        }
        else if(right.sum >= left.sum && right.sum >= cross.sum){
            return right;
        }
        else{
            return cross;
        }
    }
}

int main(){
	
	system("cls");

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
	struct subarray max_subarray = Find_Maximum_Subarray(dif, 0, w-1);
    printf("\n\nEl subarreglo de diferencia maxima es: [%d, %d]", max_subarray.left+1, max_subarray.right+1);
    printf("\nEl cambio neto durante este periodo es: %d\n", max_subarray.sum);
    
	return 0;
}
