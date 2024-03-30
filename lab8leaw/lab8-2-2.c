//66070503448 Phattharapong Duangkham

#include <string.h>
#include <stdio.h>
int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1) return;
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void delete(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
    int tree[100];
    char ch[100];
    int key,temp,cnt=0;
    while (1) {
        scanf("%s", ch);
        if (strcmp(ch, "INSERT") == 0) {
            while (scanf("%d", &key) == 1) {
                insert(tree,key);
            }
        } else if (strcmp(ch, "DELETE") == 0) {
            while (scanf("%d", &key) == 1){
                delete(tree,key);
            }
        } else if (strcmp(ch, "PRINT") == 0) {
            printArray(tree,size);
        } else if (strcmp(ch, "EXIT") == 0) {
            break;
        }
    }
}