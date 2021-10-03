#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

typedef struct Graph{
    int node;
    struct Graph *link;
} graph;
graph *G[MAX_NODES] = {NULL}, *q;

void display(int noOfVertices)
{
    int i;
    for(i = 0 ; i < noOfVertices ; i++){
        if(i == noOfVertices/2 + 1)
            printf("\n");
        printf("[%d] -> ", i);
        if(G[i]){
            q = G[i];
            while(q){
                printf("%d ", q->node);
                q = q->link;
            }
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

void addEdge(int node, int adjNode)
{
    graph *temp = (graph*)malloc(sizeof(graph));
    temp->node = adjNode;
    temp->link = NULL;
    q = G[node];
    if(!q)
        G[node] = temp;
    else{
        while(q->link)
            q = q->link;
        q->link = temp;
    }
}

int Q[MAX_NODES], visited[MAX_NODES] = {0}, front = -1, rear = -1;
void BFS(int sourceVertex)
{
    if(front > rear)
        return;
    visited[sourceVertex] = 1;
    q = G[sourceVertex];
    printf("%d ", sourceVertex);
    while(q){
        if(visited[q->node] == 0){
            visited[q->node] = 1;
            Q[++rear] = q->node;
        }
        q = q->link;
    }
    BFS(Q[++front]);
}

void DFS(int sourceVertex)
{
    visited[sourceVertex] = 1;
    q = G[sourceVertex];
    printf("%d ",sourceVertex);
    while(q){
        if(visited[q->node] == 0){
            DFS(q->node);
        }
        q = q->link;
    }
}

void main()
{
    int noOfVertices, i, node, sourceVertex;
    char ch;
    printf("No. Of Vertices: ");
    scanf("%d",&noOfVertices);
    for(i = 0 ; i < noOfVertices ; i++){
        printf("Adjacent Vertices of Vertex %d: ", i);
        while(1){
            scanf("%d%c",&node,&ch);
            addEdge(i, node);
            if(ch=='\n')
                break;
        }
    }
    printf("Enter the Source Vertex: ");
    scanf("%d",&sourceVertex);
    printf("BFS: ");
    BFS(sourceVertex);
    for(i = 0 ; i < noOfVertices ; i++)
        visited[i] = 0;
    printf("\nDFS: ");
    DFS(sourceVertex);
//    display(noOfVertices);
}
