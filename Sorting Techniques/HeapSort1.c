#include <stdio.h>
void Adjust(int heapArr[], int i)
{
     int j;
     int copy;
     int Number;
     int Reference = 1;
     Number = heapArr[0];
     while (2 * i <= Number && Reference == 1)
     {
          j = 2 * i;
          if (j + 1 <= Number && heapArr[j + 1] > heapArr[j])
               j = j + 1;
          if (heapArr[j] < heapArr[i])
               Reference = 0;
          else
          {
               copy = heapArr[i];
               heapArr[i] = heapArr[j];
               heapArr[j] = copy;
               i = j;
          }
     }
}
void createHeap(int heap[])
{
     int i;
     int noOfElements;
     noOfElements = heap[0];
     for (i = noOfElements / 2; i >= 1; i--)
          Adjust(heap, i);
}
void main()
{
     int heap[] = {6, 3, 8, 4, 1};
     int i;
     int lastElement;
     int copyVariable;
     createHeap(heap);
     while (heap[0] > 1)
     {
          lastElement = heap[0];
          copyVariable = heap[1];
          heap[1] = heap[lastElement];
          heap[lastElement] = copyVariable;
          heap[0]--;
          Adjust(heap, 1);
     }
     for (i = 1; i <= 5; i++)
          printf("%d ", heap[i]);
}