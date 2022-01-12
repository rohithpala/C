#include<stdio.h>
#include<limits.h>
#define min(a,b) a < b ? a : b

void SingleSourceShortestPath(int n, int adj_mat[n][n], int sourceVertex){
    int i, j, shortestPath[n], wt = 0, temp;

    for(i = 0 ; i < n ; i++){
        if(adj_mat[sourceVertex][i] != 0)
            shortestPath[i] = adj_mat[sourceVertex][i];
        else
            shortestPath[i] = INT_MAX;
    }
    shortestPath[sourceVertex] = 0;

    for(i = 0 ; i < n ; i++){
        if(adj_mat[sourceVertex][i]){
            temp = adj_mat[sourceVertex][i];
            for(j = 0 ; j < n ; j++){
                if(j != sourceVertex && adj_mat[i][j] != 0){
                    wt = temp;
                    wt += adj_mat[i][j];
                    shortestPath[j] = min(shortestPath[j], wt);
                }
            }
        }
    }

    printf("Shortest Paths from the Source Vertex %d:\n", sourceVertex);
    for(i = 0; i < n; i++){
        printf("%d -> %d: %d\n", sourceVertex, i, shortestPath[i]);
    }
}

int main()
{
    int n, i, j, sourceVertex;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &n);
    int adj_mat[n][n];
    //Taking Edges Matrix as Input
    printf("Enter the Edges Matrix:\n");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d", &adj_mat[i][j]);
        }
    }

    printf("Enter the Source Vertex: ");
    scanf("%d",&sourceVertex);
    SingleSourceShortestPath(n, adj_mat, sourceVertex);
    return 0;
}
