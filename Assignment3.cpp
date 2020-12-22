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
int count=0 , cek=0;
int condition = 0;
float total = 0;
void printLinkedList(){
  Node *curr = head;
  while(curr !=NULL){
    count++;
    curr= curr-> next;
  }
  Node *ptr = head;
  while(ptr != NULL){
    cek++;
    if(count == 1){
      printf("Middle : %d" , ptr -> angka);
      break;
    }
    else if(count%2 == 1){
      if(count/2+1 == cek){
      printf("Middle : %d" , ptr -> angka);
      break;
      }
    }
    else if(count%2 == 0){
      if(count/2 == cek){
          condition++;
          total = total + ptr->angka;
      }
      if(count/2+1 == cek){
          condition++;
          total = total + ptr->angka;
      }
      if(condition ==2){
          printf("Middle : %.2f" , total/2);
          break;
      }
    }
    ptr = ptr-> next;
  }
}

// Sort
void sortLinkedList(){
  int temp;
  Node *curr;
  Node *ptr = head;
  while(ptr!= NULL){
    curr = ptr-> next;
    while(curr!= NULL){
      if(ptr->angka > curr->angka){
        temp = ptr->angka;
        ptr->angka = curr->angka;
        curr->angka = temp;
      }
      curr = curr->next;
    }
    ptr = ptr->next;
  }
}

// Driver code
int main(){
  int n , a;

  printf("Banyaknya List : "); scanf("%d" , &n);
  printf("Masukan data :\n");
  for(int i=0 ; i<n ; i++){
    scanf(" %d" , &a);
    pushTail(a);
  }

  sortLinkedList();
  printLinkedList();
printf("\n");
return 0;
}
