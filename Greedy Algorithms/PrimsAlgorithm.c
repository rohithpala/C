#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Graph Edges are taken into this structure
typedef struct Edges{
    int v1, v2, wt;
} edges;

// Prim's Minimum Spanning Tree Edges are taken into this structure
typedef struct Kruskal{
    int v1, v2, wt;
} solution;

// Merges the components of k and k1 (Here changes k1 to k)
void Union(int comp[], int n, int k, int k1){
     int i;
     for(i = 0 ; i < n ; i++){
          if(comp[i] == k1)
               comp[i] = k;  
     }
}

// Simply returns the component in which k is present
int Find(int comp[], int k){
     return comp[k];
}

// Swaps 2 variables (Call by Reference)
void swap(int *x, int *y){
     *x = *x + *y;
     *y = *x - *y;
     *x = *x - *y;
}

void main()
{
     int i, j, n, ed, minimumCost = 0; // n->number of nodes/vertices, ed->number of edges
     printf("Number of Nodes and Edges: ");
     scanf("%d%d", &n, &ed);
     int comp[n];
     edges *e = (edges*)malloc(ed*sizeof(edges));
     solution *prim_edges = (solution*)malloc((n-1)*sizeof(solution)); // Spanning Tree Contains only n-1 edges

     int min = INT_MAX, minIndex;
     // Taking Edges as Input and finding minimum edge at the same time (to prevent usage of another loop)
     printf("Enter Edge Weights in [v1 v2 wt] format:\n");
     for(i = 0 ; i < ed ; i++){
          scanf("%d%d%d", &e[i].v1, &e[i].v2, &e[i].wt);

          if(min > e[i].wt){
               min = e[i].wt;
               minIndex = i;
          }
     }
     
     // At first all the nodes are considered to be in different components or disjoint sets which are
     // labeled to be the set elements itself (instead of taking another array for labels)
     // i;e node 0 is in component 0, node 1 is in component 1 and so on
     // Initializing Component Array
     for (i = 0; i < n; i++)
          comp[i] = i;

     int minEdgeVertex1, minEdgeVertex2, minEdgeWeight;
     prim_edges[0].v1 = e[minIndex].v1;
     prim_edges[0].v2 = e[minIndex].v2;
     prim_edges[0].wt = e[minIndex].wt;
     j = 1;
     int iter1, iter2;
     for(i = 0 ; i < ed ; i++){
          minEdgeWeight = INT_MAX;
          for(iter1 = 0 ; iter1 < n ; iter1++){
               
          }
     }
}