#include<stdio.h>
#define MAX_VERTICES 20

int i, j, n, adj_mat[MAX_VERTICES][MAX_VERTICES], Q[MAX_VERTICES], front = -1, rear = -1, visited[MAX_VERTICES] = {0};

void BFS(int sourceVertex)
{
    if(front > rear)
        return;

    visited[sourceVertex] = 1;

    for(i = 0 ; i < n ; i++){
        if(adj_mat[sourceVertex][i] == 1 && visited[i] == 0){
            Q[++rear] = i;
            visited[i] = 1;
        }
    }

    printf("%d ", sourceVertex);
    BFS(Q[++front]);
}

void main()
{
    int sourceVertex;

    printf("Enter the Number of Vertices: ");
    scanf("%d",&n);

    printf("Enter The Adjacency Matrix:\n");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d",&adj_mat[i][j]);
        }
    }

    printf("Enter the Source Vertex: ");
    scanf("%d",&sourceVertex);

    BFS(sourceVertex);
}
