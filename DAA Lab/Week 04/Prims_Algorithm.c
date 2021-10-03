#include<stdio.h>
#include<stdlib.h>

// Graph Edges are taken into this structure
typedef struct Edges{
    int v1, v2, wt;
} edges;

// Prim's Minimum Spanning Tree Edges are taken into this structure
typedef struct Prim{
    int v1, v2, wt;
} solution;

// Merges the components of k and k1 (Here changes k1 to k)
//void Union(int comp[], int n, int k, int k1){
//    int i;
//    for(i = 0 ; i < n ; i++){
//        if(comp[i] == k1)
//            comp[i] = k;
//    }
//}
//
//// Simply returns the component in which k is present
//int Find(int comp[], int k){
//    return comp[k];
//}

int main()
{
    int n, ed, i, j, k = 0, l, ret, temp = 0, min, vert, sourceVertex, minimumCost = 0; // n->number of nodes/vertices, ed->number of edges
    printf("No. Of Nodes and Edges: ");
    scanf("%d%d",&n, &ed);
    int /*comp[n],*/ adj_mat[n][n], visited[n];
    edges *e = (edges*)malloc(n*sizeof(edges));
    solution *prim = (solution*)malloc((n-1)*sizeof(solution)); // Spanning Tree Contains only n-1 edges

    printf("Enter the Adjacency Matrix:\n");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++)
            scanf("%d",&adj_mat[i][j]);
    }

    // Taking Edges as Input
    printf("Enter Edge Weights in [v1 v2 wt] format:\n");
    for(i = 0 ; i < ed ; i++)
        scanf("%d%d%d", &e[i].v1, &e[i].v2, &e[i].wt);

    // At first all the nodes are considered to be in different components or disjoint sets which are
    // labeled to be the set elements itself (instead of taking another array for labels)
    // i;e node 0 is in component 0, node 1 is in component 1 and so on
    // Initializing Component Array
    for(i = 0 ; i < n ; i++){
        visited[i] = 0;
//        comp[i] = i;
    }

    for(i = 0 ; i < n ; i++){
        temp += e[i].wt;
    } temp += 1;

    printf("Enter the vertex from which Prim's Algorithm is to be Considered: ");
    scanf("%d",&sourceVertex);
    visited[sourceVertex] = 1;
    for(i = 0 ; i < n-1 ; i++){
        min = temp;
        for(j = 0 ; j < n ; j++){
            if(adj_mat[sourceVertex][j] == 1 && visited[j] == 0){
//                for(k = 0 ; k < n ; k++){
//                    if(e[k].v1 == sourceVertex && e[k].v2 == j)
//                        ret = e[k].wt;
//                } Problem here
                if(ret < min){
                    min = ret;
                    vert = j;
                }
            }
        }
//        if(Find(comp, sourceVertex) != Find(comp, vert)){
            prim[l].v1 = sourceVertex;
            prim[l].v2 = vert;
            prim[l].wt = ret;
            l++;
            minimumCost += ret;
//            Union(comp, n, comp[sourceVertex], comp[vert]);
            visited[vert] = 1;
//        }
        sourceVertex = vert;
    }

    // Printing Minimum Cost Spanning Tree Edges
    printf("Minimum Cost Spanning Tree's Edges are:\n");
    for(i = 0 ; i < n-1 ; i++)
        printf("[%d, %d] Weight: %d\n", prim[i].v1, prim[i].v2, prim[i].wt);
    printf("Minimum Cost: %d", minimumCost);
    return 0;
}
