#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int diGraph = 0;
struct Vertex {
    char label;
    int visited;
};
typedef struct Vertex vertex;
int queue[MAX];
int rear = -1, front = 0;
int queueItemCount = 0;
struct Vertex *lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;
void enqueue(int data) {
    queue[++rear] = data;
    queueItemCount++;
}
int dequeue() {
    queueItemCount--;
    return queue[front++];
}
int isQueueEmpty() {
    return queueItemCount == 0;
}
void addVertex(char label) {
    vertex *v = (vertex *) malloc(sizeof(vertex));
    v->label = label;
    v->visited = 0;
    lstVertices[vertexCount++] = v;
}
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    if (!diGraph)
        adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices[vertexIndex]->label);
}
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for (i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == 0)
            return i;
    }
    return -1;
}
void breadthFirstSearch(int startVertexIndex) {
    int i, unvisitedVertex;
    lstVertices[startVertexIndex]->visited = 1;
    displayVertex(startVertexIndex);
    enqueue(startVertexIndex);
    while (!isQueueEmpty()) {
        int tempVertex = dequeue();
        while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
            lstVertices[unvisitedVertex]->visited = 1;
            displayVertex(unvisitedVertex);
            enqueue(unvisitedVertex);
        }
    }
    for (i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = 0;
    }
}
int main() {
    int i, j, startVertexIndex;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    diGraph = 0;
    addVertex('A');   
    addVertex('B');   
    addVertex('C');   
    addVertex('D');   
    addVertex('E');   
    startVertexIndex = 0; 
    addEdge(0, 1);    
    addEdge(0, 2);    
    addEdge(0, 3);    
    addEdge(1, 4);    
    addEdge(2, 4);    
    addEdge(3, 4);    
    printf("Breadth First Search: ");
    breadthFirstSearch(startVertexIndex);
    return 0;
}