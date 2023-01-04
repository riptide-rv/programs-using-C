#include<stdio.h>
int MAXSIZE = 20;
int length;


void heapsort(int arr[]){
  buildHeap(arr);
  for(int i = length-1;i>=0;i--){
    swap(arr,0,i);
    heapify(arr,0,i);

  }
}


void buildHeap(int arr[]){
  for(int i =(length/2)-1;i>=0;i--){
    heapify(arr,i,length);
  }
}

void heapify(int arr[],int i,int n){
  int largest = i;
  int l = (2*i)+1;
  int r =(2*i)+2;
  if(l<n && arr[l]>arr[largest])largest = l;
  if(r<n && arr[r]>arr[largest]) largest = r;
  if(largest!=i){
    swap(arr,i,largest);
    heapify(arr,largest,n);

  }
}

void swap(int arr[], int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}


void main(){
  do{
    printf("Enter size of array(maxsize is 20): ");
    scanf("%d",&length);
    if(length>MAXSIZE)printf("Enter valid size less than 20\n");

  }while(length>MAXSIZE);


  int A[length];
  printf("Enetr elements\n");
  for(int i = 0;i<length;i++){
      scanf("%d",&A[i]);
  }
  printf("Unsorted array: ");
  display(A);
  printf("\n");
  heapsort(A);
  printf("Sorted array: ");
  display(A);
  printf("\n");




}

void display(int arr[]){
  for(int i = 0;i<length;i++){
    printf("%d ",arr[i]);

  }
  printf("\n");
}

