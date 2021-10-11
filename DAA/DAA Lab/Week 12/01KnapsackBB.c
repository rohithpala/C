#include <stdio.h>
struct Item
{
     int weight;
     int value;
};
struct Node
{
     int level, profit, bound;
     int weight;
};
struct Node Q[20];
int f = -1, r = -1;
void push(struct Node u)
{
     if (f == -1)
          f = 0;
     r = r + 1;
     Q[r] = u;
}
struct Node pop()
{
     int x = f;
     if (f == r)
          f = r = -1;
     else
          f += 1;
     return Q[x];
}
int empty()
{
     if (f == -1 && r == -1)
          return 1;
     return 0;
}
struct Node front()
{
     return Q[f];
}
int cmp(struct Item a, struct Item b)
{
     double r1 = (double)a.value / a.weight;
     double r2 = (double)b.value / b.weight;
     if (r1 > r2)
          return 1;
     if (r1 < r2)
          return -1;
     return 0;
}
int bound(struct Node u, int n, int W, struct Item arr[])
{
     if (u.weight >= W)
          return 0;
     int profit_bound = u.profit;
     int j = u.level + 1;
     int totweight = u.weight;
     while ((j < n) && (totweight + arr[j].weight <= W))
     {
          totweight += arr[j].weight;
          profit_bound += arr[j].value;
          j++;
     }
     if (j < n)
          profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
     return profit_bound;
}
int knapsack(int W, struct Item arr[], int n)
{
     struct Node u, v;
     u.level = -1;
     u.profit = u.weight = 0;
     push(u);
     int maxProfit = 0;
     while (!empty())
     {
          u = front();
          pop();
          if (u.level == -1)
               v.level = 0;
          if (u.level == n - 1)
               continue;
          v.level = u.level + 1;
          v.weight = u.weight + arr[v.level].weight;
          v.profit = u.profit + arr[v.level].value;
          if (v.weight <= W && v.profit > maxProfit)
               maxProfit = v.profit;
          v.bound = bound(v, n, W, arr);
          if (v.bound > maxProfit)
               push(v);
          v.weight = u.weight;
          v.profit = u.profit;
          v.bound = bound(v, n, W, arr);
          if (v.bound > maxProfit)
               push(v);
     }
     return maxProfit;
}
int main()
{
     int W; //6
     printf("Enter maximum capacity of bag: ");
     scanf("%d", &W);
     int n; //3
     printf("Enter no of items: ");
     scanf("%d", &n);
     printf("Enter weight and profit of each item:\n");
     struct Item arr[n]; //{{2,1}, {3, 2}, {4,5}};
     for (int i = 0; i < n; i++)
          scanf("%d %d", &arr[i].weight, &arr[i].value);
     printf("Maximum possible profit: %d\n", knapsack(W, arr, n));
     return 0;
}