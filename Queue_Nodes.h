#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un nodo del árbol de Huffman
struct HuffmanNode {
    char character;
    unsigned frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Estructura para representar una cola de prioridad de nodos del árbol de Huffman
struct PriorityQueue {
    unsigned size;
    unsigned capacity;
    struct HuffmanNode** nodes;
};

// Función para crear un nuevo nodo del árbol de Huffman
struct HuffmanNode* createNode(char character, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Función para crear una nueva cola de prioridad vacía
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->nodes = (struct HuffmanNode**)malloc(capacity * sizeof(struct HuffmanNode*));
    return queue;
}

// Función para intercambiar dos nodos del árbol de Huffman
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Función para ajustar hacia abajo el nodo más pequeño en una cola de prioridad
void minHeapify(struct PriorityQueue* queue, unsigned index) {
    unsigned smallest = index;
    unsigned left = 2 * index + 1;
    unsigned right = 2 * index + 2;

    if (left < queue->size && queue->nodes[left]->frequency < queue->nodes[smallest]->frequency)
        smallest = left;

    if (right < queue->size && queue->nodes[right]->frequency < queue->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&queue->nodes[index], &queue->nodes[smallest]);
        minHeapify(queue, smallest);
    }
}

// Función para verificar si una cola de prioridad tiene solo un nodo
int isQueueSizeOne(struct PriorityQueue* queue) {
    return queue->size == 1;
}

// Función para verificar si un nodo es un nodo padre en el árbol de Huffman
int isLeaf(struct HuffmanNode* mainNode) {
    return !(mainNode->left) && !(mainNode->right);
}

// Función para crear y construir una cola de prioridad
struct PriorityQueue* buildPriorityQueue(char characters[], int frequencies[], unsigned size) {
    struct PriorityQueue* queue = createPriorityQueue(size);

	int i;
    for (i = 0; i < size; ++i)
        queue->nodes[i] = createNode(characters[i], frequencies[i]);

    queue->size = size;

    int n = queue->size - 1;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(queue, i);

    return queue;
}

// Función para extraer el nodo de menor frecuencia de la cola de prioridad
struct HuffmanNode* extractMin(struct PriorityQueue* queue) {
    struct HuffmanNode* minNode = queue->nodes[0];
    queue->nodes[0] = queue->nodes[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return minNode;
}

// Función para insertar un nodo en la cola de prioridad
void insertNode(struct PriorityQueue* queue, struct HuffmanNode* node) {
    ++queue->size;
    unsigned i = queue->size - 1;

    while (i && node->frequency < queue->nodes[(i - 1) / 2]->frequency) {
        queue->nodes[i] = queue->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    queue->nodes[i] = node;
}
