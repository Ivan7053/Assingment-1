#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int angka;
	Node *next;
}*head , *tail , *curr;

// Create NULL
Node *createNode(int angka){
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->angka = angka;
	newNode->next  = NULL;
	return newNode;
}

// Insert
void pushHead(int angka){
  Node *temp = createNode(angka);

  if(!head){
    head=tail=temp;
  } else{
    temp->next = head;
    head=temp;
  }
}

void pushTail(int angka){
	Node *temp = createNode(angka);
	if(!head){
		head = tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
}

// Print
void printLinkedList(){
  
  Node *curr = head;
  while(curr !=NULL){
  printf("%d ", curr-> angka);
    curr= curr-> next;
  }
}

// Delete
void popTail() {
  if(!head) {
    return; 
  } else if(head == tail) {
    head = tail = NULL;
    free(head);
  } else {
    Node *temp = head;
    while(temp->next != tail) {
      temp = temp->next;
    }
    temp->next = NULL;
    free(tail);
    tail = temp;
  }
}

int cek=1;
void deleteDuplicateLinkedList(){
  int temp;
  Node *curr;
  Node *ptr = head;
  while(ptr!= NULL){
    curr = ptr-> next;
    while(curr!= NULL){
      if(ptr->angka == curr->angka){
          Node *temp , *curr1;
          curr1 = curr;
          temp = curr -> next;
          while(temp != NULL){
            curr1->angka = temp->angka;
            temp = temp ->next;
            curr1 = curr1->next;
          }
          cek=0;
          popTail();
      }
      if(cek==1)
      curr = curr->next;
      else if(cek==0)
      cek=1;
    }
    ptr = ptr->next;
  }
}

// Driver code
int main(){
  int n , m , a , b;

  printf("Banyaknya Data : "); scanf("%d" , &n);
  printf("Masukan Data :\n");
  for(int i=0 ; i<n ; i++){
    scanf(" %d" , &a);
    pushTail(a);
  }

  deleteDuplicateLinkedList();
  printf("List setelah duplicate dihapus :\n");
  printLinkedList();
printf("\n");
return 0;
}
