#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void push(struct node **,int); 
int findmiddle(struct node *head){
	struct node *fast=head;
	while(head!=NULL && fast->next!=NULL && fast->next->next!=NULL){
		fast=fast->next->next;		
		head=head->next;
	}	
	return head->data;
}
void printList(struct node *head){
	while(head!=NULL){
	printf("->%d",head->data);
	head=head->next;
	}
}
void insertNth(struct node **head_ref,int data,int index){
	struct node *head=(*head_ref);
	if ( index == 0 ) {
		push(&head,data);
		return ;
	}
	while(head != NULL ) {
		head=head->next;
		index--;
		if ( index == 0 ) break;
	}
	
		printf("%d\n",head->data);
	if ( head == NULL && index  ) {
		printf("index out of the list");
		return;
	}
	struct node *newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=head->next;
	head->next=newnode;	
			
}

void removeDup(struct node **head_ref){
	struct node *head=*head_ref;
	while(head->next!=NULL){
		if ( head->next != NULL ) {
			if(head->data==head->next->data){
				struct node *temp=head->next->next;
				free(head->next);
				head->next=temp;
			} else {
			head=head->next;
			}
		}
	}
	return;
}

int pop(struct node **head_ref){
	struct node *head=(*head_ref);
	int result;
	result=head->data;
	head=head->next;
	*(head_ref)=head;
	return result;
	
}
/* Given a reference (pointer to pointer) to the head
    of a list and an int, push a new node on the front
    of the list. */
void push(struct node** head_ref, int new_data)
{

printf("\nINSIDE PUSH HEAD VALUE %p\n",head_ref);
printf("HEAD VALUE %p",*head_ref);
    /* allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
   
    /* link the old list off the new node */
    new_node->next = (*head_ref);
   
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Takes head pointer of the linked list and index
    as arguments and return data at index*/
int GetNth(struct node* head, int index)
{
		struct node* current = head;
		int count = 0; /* the index of the node we're currently
						  looking at */
		while (current != NULL)
		{
				if (count == index)
						return(current->data);
				count++;
				current = current->next;
		}

		/* if we get to this line, the caller was asking
		   for a non-existent element so we assert fail */
		assert(0);              
		while(0){

				while(index>=1 && head!=NULL){
						printf("%d",index);
						printf(" %d",head->data);
						printf("\n");
						head=head->next;	
						index--;
				}
				if ( index != 0 ) return head->data;	
				return -1;
		}
}




int findnth(struct node *head,int index){

	struct node *temp=head;
	int count=0;
	while(head!=NULL){
			head=head->next;
			if(count>=index){
					temp=temp->next;
			}
			count++;
	}
	return temp->data;
} 



void reverseListRecursive(struct node **head){

	if(head->next==NULL){
		printf("END %d",(*head)->next);
		return	;
	}
	printf("one %d",*(head)->next);
	reverseListRecursive(&(*(head)->next));
}

void reverseList(struct node **head){

	struct node *prev;
	struct node *togo;
	struct node *current=*head;
	prev=NULL;
	while(current != NULL){
			togo=current->next;
			current->next=prev;
			prev=current;
			current=togo;	
	}
	*head=prev;
}


int detechLoop(struct node *head){
	struct node *fast=head;
	while(head != NULL && fast->next!=NULL){
	head=head->next;
	fast=fast->next->next;
	if ( fast == head ) {
		return 1;
	}
	}
	return 0;

}


