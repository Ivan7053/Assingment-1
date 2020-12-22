#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    for ( ; i < n1 && j < n2 ; ) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    for ( ; i < n1 ; ) {
        arr[k] = L[i];
        i++;
        k++;
    }

    for ( ; j < n2 ; ) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
  int n , m , a[1000];
  printf("Banyaknya List ke-1 : "); scanf("%d" , &m);
  
  printf("Masukan list ke 1 :\n");
  for(int i=0 ; i<m ; i++)
    scanf(" %d" , &a[i]);
  
  printf("Banyaknya List ke-2 : "); scanf("%d" , &n);
  
  printf("Masukan list ke 1 :\n");
  for(int i=m ; i<n+m ; i++)
    scanf(" %d" , &a[i]);
  
  mergeSort(a , 0 , n+m-1);

  printf("List Akhir :\n");
  
  for(int i=0 ; i<n+m ; i++)
    printf("%d " , a[i]);
  printf("\n");
return 0;
}