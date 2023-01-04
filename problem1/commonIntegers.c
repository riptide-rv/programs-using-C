// Implement a C program to
//  a)  Create 2 singly linked lists with integer elements  
//  b)  Print those elements which are common in both the list
// 	c)  Print average of elements of first linked list.

#include<stdio.h>
#include<stdlib.h>
struct Node{
  int number;
  struct Node *next;

}*list1head,*list2head,*ptr,*prev,*new,*newnode,*ptr1;

int firstlistlength = 0;
int secondlistlength = 0;
int item;


//function to allocate memory for new node
struct Node* getNode(){
  newnode = (struct Node*)malloc(sizeof(struct Node));
  
  return newnode;
  
}


//function to get end node
struct Node* endnode(struct Node *header){
  ptr = header;
  prev = header;
  while(ptr ->next!=NULL){
    ptr = ptr->next;
  }

  return ptr;
}

//function to insert new node
void insert(struct Node *choice){
  
    new = getNode();
    if(new==NULL)printf("No Memory Available\n");
    else{
      printf("Enter number: ");
      scanf("%d",&item);
      new->number=item;
      new->next=NULL;
      ptr = endnode(choice);
      ptr->next = new;
      if(choice==list1head)firstlistlength++;
      else secondlistlength++;      
      
      
    }
  
  
}

void commonelements(){
  
  if(firstlistlength==0||secondlistlength==0){
    printf("No common elements\n");
    return;
  }
  printf("common elements are: ");
  ptr = list1head;
  ptr1 = list2head;
  ptr = ptr->next;
  do{
      item = ptr->number;
      ptr1 = ptr1->next;
      do{
        
        if(ptr1->number==item){
          printf("%d ",item);

        }
        ptr1 = ptr1 -> next;
      }while(ptr1!=NULL);
      ptr1 = list2head;
      ptr = ptr->next;
  }while(ptr!=NULL);
  printf("\n");


}

void average(struct Node *choice){
  int length;
  if(choice==list1head)length = firstlistlength;
  else length = secondlistlength;
  if(length==0){
    printf("Cannot find avaerage because list length is empty");
    return;
  }
  float sum =0;
  ptr = choice ->next;
  do{
    sum = sum+ ptr->number;
    ptr = ptr->next;
  }while (ptr!=NULL);
  printf("average = %.2f",sum/length);
  
  
}

void display(struct Node *choice){
  ptr = choice;
  if(ptr->next==NULL){
    printf("List is empty\n");
    return;
  }
  ptr= ptr->next;
  do{
    printf("%d -> ",ptr->number);
    ptr = ptr->next;
  }while(ptr!=NULL);
  printf("\n");

}
void main(){
  list1head = getNode();
  list1head->number = NULL;
  list1head ->next = NULL;
  list2head = getNode();
  list2head ->number = NULL;
  list2head->next=NULL;
  int a;
  int b;
  printf("Enter length of fisrt linked list: ");
  scanf("%d",&a);
  for(int i = 0;i<a;i++){
    insert(list1head);
  }
  printf("Enter length of second linked list: ");
  scanf("%d", &b);
  for (int i = 0; i < b; i++)
  {
    insert(list2head);
  }
  display(list1head);
  display(list2head);
  commonelements();
  average(list1head);

}


