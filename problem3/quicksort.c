#include<stdio.h>


void main(){
  int n;
  printf("Enter size of Array: ");
  scanf("%d",&n);
  int A[n];
  printf("Enter elements: ");
  for(int i = 0;i<n;i++){
    scanf("%d",&A[i]);

  }

  printf("Unsorted Array: ");
  display(A,n);
 
  quicksort(A,0,n-1);
  printf("Sorted Array: ");
  display(A,n);
  printf("\n");
  


}
void display(int arr[],int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


void quicksort(int arr[],int left,int right){
  if(left<right){
    int q = partition(arr,left,right);
    quicksort(arr,left,q-1);
    quicksort(arr,q+1,right);
  }
}

int partition(int arr[], int left,int right){
  int i = left,j = right;
  int pivot = arr[i];
  while(i<=j){
    while(i<=right && arr[i]<=pivot){
      i++;
    }
    while(arr[j]>pivot){
      j--;
    }
    if(i<j){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    
    

  }
  arr[left] = arr[j];
  arr[j] = pivot;
  return j;
}