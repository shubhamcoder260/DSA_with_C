#include<stdio.h>

//for malloc function
#include<stdlib.h>



struct node{//creating node as struct because it stores two parts:
    //one part is data and;
    int data;
    //another is a pointer which stores address to another node 
    struct node *link;
};
int main(){
    //creation of head pointer which stores address of the first node
    //malloc is used for assigning memory address
    struct node *head=malloc(sizeof(struct node));
    //->is used to point that head is a pointer pointing at first node which has two parts:
    //data for storing the data and;
    head->data=45;
    //link for storing the address of another node
    //at first we have to keep the link value to null because there is only one node and it is linked with none
    head->link=NULL;

    //here is another node and we create another pointer called current which stores the address of the node
    struct node *current=malloc(sizeof(struct node));
    //here same as before we are assigning the data into data and link to NULL because we have two nodes only
    current->data=23;
    current->link=NULL;

    //here we change the address in the first node i.e null to the address of second node which has been stored into current pointer 
    head->link=current;//we can keep the code as it is ; here in the first node  there is link = NULL;but we change it to current so it works

    current=malloc(sizeof(struct node));
    current->data=56;
    current->link=NULL;
    //head->link->link=current directs current to 3rd node
    head->link->link=current;




    current=malloc(sizeof(struct node));
    current->data=54;
    current->link=NULL;
    head->link->link->link=current;

    current=malloc(sizeof(struct node));
    current->data=90;
    current->link=NULL;
    head->link->link->link->link=current;

        print_data(head);


}
//this block of code is for transversing or printing the list
//we simply create a function
void print_data(struct node *head){
    //here we check if list is empty:
      if(head==NULL){
        printf("linked list is empty");  
      }
      //here we create a pointer ptr which has value NULL;
      struct node *ptr=NULL;
      //here we point the ptr to head;
      ptr=head;
      while(ptr!=NULL){//while ptr is not empty:
        //here it will print the value of data in head ,first node;
          printf("%d  ",ptr->data);
          //here we direct ptr to second link, address of second node;
          //now ptr will again go in loop and everytime there is some value in head it will run and print;
          ptr=ptr->link;
      }
      
  }
