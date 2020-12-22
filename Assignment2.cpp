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



// Detect Loop
int cek=0;
void detectLoopLinkedList(){
  int temp;
  Node *curr;
  Node *ptr = head;
  curr = ptr ->next;
  curr = curr->next;
  ptr = ptr->next;
  while(ptr!= NULL){
  	// printf("%d %d\n" , ptr->angka , curr->angka);
    if(ptr == curr){
      printf("Terdapat Loop\n");
      cek=1;
      break;
    }
    curr = curr->next;
    if(curr == NULL){
      curr = ptr; //reset
    }
    curr = curr->next;
    if(curr == NULL){
      curr = ptr; //reset
    }
    ptr = ptr->next;
  }
  // printf("%d\n" ,cek);
  if(cek==0){
    printf("Tidak ada loop\n");
  }
}
// 1 2 3 4 5
// 1 1
// 2 3
// 3 5
// 4 2
// 5 4
// No loop
// Driver code
int main(){
  int n , m , a , b;

  printf("Banyaknya List : "); scanf("%d" , &n);
  printf("Masukan list :\n");
  for(int i=0 ; i<n ; i++){
    scanf(" %d" , &a);
    pushTail(a);
  }

  detectLoopLinkedList();

return 0;
}