#include<stdio.h>
#include<stdlib.h>

// Graph Edges are taken into this structure
typedef struct Edges{
    int v1, v2, wt;
} edges;

// Kruskal Minimum Spanning Tree Edges are taken into this structure
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
     solution *kruskal_edges = (solution*)malloc((n-1)*sizeof(solution)); // Spanning Tree Contains only n-1 edges

     // Taking Edges as Input
     printf("Enter Edge Weights in [v1 v2 wt] format:\n");
     for(i = 0 ; i < ed ; i++)
          scanf("%d%d%d", &e[i].v1, &e[i].v2, &e[i].wt);
     
     // At first all the nodes are considered to be in different components or disjoint sets which are
     // labeled to be the set elements itself (instead of taking another array for labels)
     // i;e node 0 is in component 0, node 1 is in component 1 and so on
     // Initializing Component Array
     for (i = 0; i < n; i++)
          comp[i] = i;

     // Sorting edges in increasing order of weights
     for(i = 0 ; i < ed ; i++){
          for(j = i ; j < ed ; j++){
               if(e[i].wt > e[j].wt){
                    swap(&e[i].v1, &e[j].v1);
                    swap(&e[i].v2, &e[j].v2);
                    swap(&e[i].wt, &e[j].wt);
               }
          }
     }
     
     // If 2 Nodes are not in the same component then we add it to the solution array and merge them
     j = 0;
     for(i = 0 ; i < ed ; i++){
          if(Find(comp, e[i].v1) != Find(comp, e[i].v2)){ // Find(x) != Find(y) tells that x and y are not in the same component,
                                                        // so they doesn't form a cycle
                                                        // and can be added to the solution array
               // Adding the edge to the solution array/vector/structure
               kruskal_edges[j].v1 = e[i].v1;
               kruskal_edges[j].v2 = e[i].v2;
               kruskal_edges[j].wt = e[i].wt;
               Union(comp, n, comp[e[i].v1], comp[e[i].v2]);
               minimumCost += e[i].wt; // Calculating the Minimum Cost
               j++;
          }
     }

     // Printing Minimum Cost Spanning Tree Edges
     printf("Minimum Cost Spanning Tree's Edges are:\n");
     for(i = 0 ; i < n-1 ; i++)
          printf("[%d, %d] Weight: %d\n", kruskal_edges[i].v1, kruskal_edges[i].v2, kruskal_edges[i].wt);
     printf("Minimum Cost: %d", minimumCost);
}
