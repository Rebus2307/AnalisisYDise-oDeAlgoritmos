#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int peso;
    int valor;
} Elemento;

void mochilaEntera(int capacidad, Elemento elementos[], int numElementos) {
    int matriz[numElementos + 1][capacidad + 1];

    for (int i = 0; i <= numElementos; i++) {
        for (int j = 0; j <= capacidad; j++) {
            if (i == 0 || j == 0)
                matriz[i][j] = 0;
            else if (elementos[i - 1].peso <= j)
                matriz[i][j] = (elementos[i - 1].valor + matriz[i - 1][j - elementos[i - 1].peso] > matriz[i - 1][j])
                                   ? elementos[i - 1].valor + matriz[i - 1][j - elementos[i - 1].peso]
                                   : matriz[i - 1][j];
            else
                matriz[i][j] = matriz[i - 1][j];
        }
    }

    // Imprimir la tabla de programacion dinamica
    printf("\n\nTabla de programacion dinamica:\n\n");
    for (int i = 0; i <= numElementos; i++) {
    	int j;
        for (j = 0; j <= capacidad; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Recuperar los objetos seleccionados
    int cargaOptima = matriz[numElementos][capacidad];
    int cargaActual = capacidad;
    printf("\n\nObjetos seleccionados:\n");
    for (int i = numElementos; i > 0 && cargaOptima > 0; i--) {
        if (cargaOptima != matriz[i - 1][cargaActual]) {
            printf("\nObjeto %d \nPeso: %d | Valor: %d\n", i, elementos[i - 1].peso, elementos[i - 1].valor);
            cargaOptima -= elementos[i - 1].valor;
            cargaActual -= elementos[i - 1].peso;
        }
    }

    printf("\nValor maximo obtenido: %d\n", matriz[numElementos][capacidad]);
}

int main() {
    system("cls");
    int capacidad;
    printf("\n\n\t-PRACTICA 7-");
    printf("\n\tMochila Entera / Programacion Dinamica\n");
    printf("\n\tIngrese el peso maximo que soporta la mochila: ");
    scanf("%d", &capacidad);

    int numElementos;
    printf("\n\tIngrese la cantidad de objetos a considerar: ");
    scanf("%d", &numElementos);

    Elemento* elementos = (Elemento*)malloc(numElementos * sizeof(Elemento));

    for (int i = 0; i < numElementos; i++) {
        printf("\nObjeto %d", i+1);
        printf("\nPeso:  ");
        scanf("%d", &(elementos[i].peso));
        printf("Valor: ");
        scanf("%d", &(elementos[i].valor));
    }

    mochilaEntera(capacidad, elementos, numElementos);

    free(elementos);

    return 0;
}
