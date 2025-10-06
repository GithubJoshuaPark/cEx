#include <stdio.h>
#include <stdlib.h>
#include "graphs_data_structureEx.h"
#include "hello.h" // For printLine

// A node in an adjacency list
// 간선으로 연결된 목적지 정점을 저장하는 연결 리스트의 노드
typedef struct AdjListNode {
    int dest; // 목적지 정점 번호
    struct AdjListNode* next;
} AdjListNode;

// An adjacency list
// 각 정점에 대한 인접 리스트 (연결 리스트의 시작점을 가리킴)
typedef struct AdjList {
    AdjListNode *head;
} AdjList;

// The graph structure: an array of adjacency lists
// 그래프 전체를 나타내는 구조체
typedef struct Graph {
    int num_vertices; // 전체 정점의 개수
    AdjList* array;   // 각 정점의 인접 리스트를 담을 배열
} Graph;

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Adds an edge to an undirected graph
// 무방향 그래프에 간선을 추가하는 함수
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->num_vertices; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// --- Enhanced Graph Printing (Adjacency Matrix) ---

/**
 * @brief Prints a 2D map-like diagram of the graph using an adjacency matrix.
 * @param graph The graph to print.
 */
void printGraphMatrix(Graph* graph) {
    if (graph == NULL) {
        printf("Graph is NULL.\n");
        return;
    }

    int V = graph->num_vertices;
    // Create a temporary 2D array for the matrix representation.
    // A '1' indicates an edge exists between the row and column vertex.
    int* adjMatrix = (int*)calloc(V * V, sizeof(int));
    if (adjMatrix == NULL) {
        printf("Failed to allocate memory for adjacency matrix.\n");
        return;
    }

    // Populate the matrix based on the adjacency lists
    for (int i = 0; i < V; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            // adjMatrix[i][current->dest] = 1;
            adjMatrix[i * V + current->dest] = 1;
            current = current->next;
        }
    }

    // Print the matrix diagram
    printf("\n\nGraph Adjacency Matrix (2D Diagram):\n");
    printf("   ");
    for (int i = 0; i < V; i++) printf(" %d ", i);
    printf("\n---");
    for (int i = 0; i < V; i++) printf("---");
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%d |", i);
        for (int j = 0; j < V; j++) {
            printf(" %d ", adjMatrix[i * V + j]);
        }
        printf("\n");
    }

    free(adjMatrix); // Free the temporary matrix
}

// Function to free the graph and all its nodes
void freeGraph(Graph* graph) {
    if (graph == NULL) return;

    for (int v = 0; v < graph->num_vertices; ++v) {
        AdjListNode* current = graph->array[v].head;
        while (current != NULL) {
            AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

void graphs_data_structureEx(void) {
    printLine("Demonstrating Graph Data Structure (Adjacency List)");

    // Create a graph with 5 vertices
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    //         0
    //       /   \
    //      1-----4
    //     / \   |
    //    2-----3

    // Print the adjacency list representation of the above graph
    printGraph(graph);

    // Print the 2D matrix representation of the graph
    printGraphMatrix(graph);

    freeGraph(graph);
    printf("\n\nGraph memory has been freed.\n");
}