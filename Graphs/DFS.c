#include<stdio.h>
#define MAX_VERTICES 20

int i, j, n, adj_mat[MAX_VERTICES][MAX_VERTICES], visited[MAX_VERTICES] = {0};

void DFS(int sourceVertex)
{
    visited[sourceVertex] = 1;
    printf("%d ", sourceVertex);
    for(i = 0 ; i < n ; i++)
    {
        if(adj_mat[sourceVertex][i] && !visited[i])
        {
            visited[i] = 1;
            DFS(i);
        }
    }
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

    DFS(sourceVertex);
}
