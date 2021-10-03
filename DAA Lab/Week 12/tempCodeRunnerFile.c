int main()
{
     int p[n] = {5, 10, 6, 3};
     int d[n] = {1, 2, 1, 1};
     job(p, 0, d);
     printf("\nJobs considered are: ");
     int costc = 0, costu = 0;
     for (int i = idx; i >= 0; i--)
     {
          if (v[i] == 0)
               costc += p[i];
     }
     for (int i = 0; i < n; i++)
     {
          if (v[i] == 0)
               costu += p[i];
          printf("%d ", v[i]);
     }
     printf("\nmin cost: c= %d u= %d\n", costc, costu);
     return 0;
}