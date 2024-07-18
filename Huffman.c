/*
	PRACTICA 6
		Integrantes:
		-Cruz Merlin Wilfrido
		-Berrospe Negrete Angela Alessandra 
		
*/

#include "Queue_Nodes.h"

// Función para construir el árbol de Huffman
struct HuffmanNode* Huffman(char characters[], int frequencies[], int size) {
    struct PriorityQueue* queue = buildPriorityQueue(characters, frequencies, size);

	int i;
    for (i = 0; i < size - 1; ++i) {
        struct HuffmanNode* left = extractMin(queue);
        struct HuffmanNode* right = extractMin(queue);

        struct HuffmanNode* top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertNode(queue, top);
    }

    return extractMin(queue);
}

// Función para imprimir el código Huffman óptimo y calcular el costo total del árbol
int printHuffmanCodes(struct HuffmanNode* mainNode, int arr[], unsigned top) {
    int cost = 0;
    if (mainNode->left) {
        arr[top] = 0;
        cost += printHuffmanCodes(mainNode->left, arr, top + 1);
    }

    if (mainNode->right) {
        arr[top] = 1;
        cost += printHuffmanCodes(mainNode->right, arr, top + 1);
    }

    if (isLeaf(mainNode)) {
        printf("%c: ", mainNode->character);
        int i;
        for (i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");

        cost += mainNode->frequency * top;
    }
    return cost;
}

int main() {
    system("cls");

    printf("\n\t-ALGORITMO HUFFMAN-\n\n");

    char input[200];
    printf("\tIngrese el texto: ");
    fgets(input, sizeof(input), stdin);
    strlwr(input);
    input[strcspn(input, "\n")] = '\0';  // Eliminar el salto de línea del final del texto

    int frequencies[256] = {0};

    // Contar las frecuencias de los caracteres en el texto de entrada
    int len = strlen(input);
    int i;
    for (i = 0; i < len; ++i)
        frequencies[(unsigned char)input[i]]++;

    printf("\nFrecuencia de cada letra:\n|");

    int size = 0;
    for (i = 0; i < 256; ++i) {
        if (frequencies[i] > 0) {
            size++;
            printf("%c:%u  |", (char)i, frequencies[i]);
        }
    }


    char characters[size];
    int charFrequencies[size];
    int j = 0;
    for (i = 0; i < 256; ++i) {
        if (frequencies[i] > 0) {
            characters[j] = (char)i;
            charFrequencies[j] = frequencies[i];
            j++;
        }
    }

    struct HuffmanNode* mainNode = Huffman(characters, charFrequencies, size);

    int huffmanCode[100];
    printf("\n\nCodigos de Huffman:\n");
    int totalcost = printHuffmanCodes(mainNode, huffmanCode, 0);
    printf("\nCosto total del arbol: %d\n", totalcost);

    return 0;
}
