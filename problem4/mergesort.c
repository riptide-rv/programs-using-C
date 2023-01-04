#include<stdio.h>


int n;
void main(){
  
  printf("Enter size of arrat: ");
  scanf("%d",&n);
  int A[n];
  printf("Enter elements: \n");
  for(int i =0;i<n;i++){
    scanf("%d",A+i);
  }


  printf("Unsorted Array: ");
  display(A,n);
  mergesort(A,0,n-1);
  printf("Sorted Array: ");
  display(A,n);

}

void mergesort(int arr[],int left,int right){
  if(left<right){
    int mid = (left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);

  }
}
void merge(int arr[],int left,int mid,int right ){
  int  i= left;
  int j = mid+1;
  int temp[n];
  int k =0;
  while(i<=mid&& j<=right){
    if(arr[i]<=arr[j]){
      temp[k] = arr[i];
      i++;
      k++;
    }
    else{
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j<=right){
    temp[k] = arr[j];
    j++;
    k++;
  }
  for(i = left,j =0;j<k;j++){
    arr[i] = temp[j];
   // printf("%d",temp[j]);
    i++;
  }
  printf("\n");  
}

void display(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
