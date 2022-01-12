#include<stdio.h>
#define MAX_SIZE 10

int noOfVertices, i, j, Q[MAX_SIZE], visited[MAX_SIZE] = {0}, front = -1, rear = -1, adj_mat[MAX_SIZE][MAX_SIZE];
void BFS(int sourceVertex)
{
    if(front <= rear){
        printf("%d ",sourceVertex);
        visited[sourceVertex] = 1;
        for(i = 0 ; i < noOfVertices ; i++){
            if(adj_mat[sourceVertex][i] && !visited[i]){
                Q[++rear] = i;
                visited[i] = 1;
            }
        }
        BFS(Q[++front]);
    }
}

void DFS(int sourceVertex)
{
    printf("%d ", sourceVertex);
    visited[sourceVertex] = 1;
    for(i = 0 ; i < noOfVertices ; i++){
        if(adj_mat[sourceVertex][i] && !visited[i]){
            DFS(i);
        }
    }
}

void main()
{
    int sourceVertex;
    printf("Enter Number of Vertices: ");
    scanf("%d",&noOfVertices);
    printf("Enter the Adjacency matrix representation of graph:\n");
    for(i = 0 ; i < noOfVertices ; i++){
        for(j = 0 ; j < noOfVertices ; j++)
            scanf("%d",&adj_mat[i][j]);
    }
    printf("Enter the Source Vertex: ");
    scanf("%d",&sourceVertex);
    printf("BFS: ");
    BFS(sourceVertex);
    for(i = 0 ; i < noOfVertices ; i++)
        visited[i] = 0;
    printf("\nDFS: ");
    DFS(sourceVertex);
}
