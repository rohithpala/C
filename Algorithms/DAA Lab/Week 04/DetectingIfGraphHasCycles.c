#include<stdio.h>
#include<stdlib.h>

// Merges the components of k and k1 (Here changes k1 to k)
void Union(int comp[], int n, int k, int k1){
    int i;
    for(i = 0 ; i < n ; i++){
        if(comp[i] == k)
            comp[i] = k1;
    }
}

// Simply returns the component in which k is present
int Find(int comp[], int k){
    return comp[k];
}

int main()
{
    int n, i, j; // n->number of nodes/vertices
    printf("No. Of Nodes: ");
    scanf("%d",&n);
    int adj_mat[n][n], comp[n];

    // Taking the Adjacency Matrix as Input
    printf("Enter the Adjacency Matrix:\n");
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++)
            scanf("%d",&adj_mat[i][j]);
    }

    //Initializing Component Array
    for(i = 0 ; i < n ; i++)
        comp[i] = i;

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            if(i > j && adj_mat[j][i] == 1){ // This condition is imposed because if it was not their the algo checks for i,j and j,i and
                                            // always prints "Graph has Cycles". As i,j and j,i edge is the same, it should not be checked
                                            // twice. This condition takes care of that
                continue;
            }
            else if(adj_mat[i][j]){ //  We use Union-Find Algorithm Idea
                if(Find(comp, i) == Find(comp, j)){ // If 2 nodes are in same component then the graph contains cycles
                    printf("Graph has Cycles\n");
                    exit(0);
                } else { // If not merge the components.
                    Union(comp, n, comp[i], comp[j]);
                }
            }
        }
    }
    if(i == n) // If Graph doesn't contain any cycles the above loop runs till i= n
        printf("Graph has no Cycles\n");
    return 0;
}
