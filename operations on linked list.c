#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node * next;
};
struct node * start1 = NULL;
struct node * start2 = NULL;
struct node * start3 = NULL;
struct node * start4 = NULL;
struct node * start5 = NULL;

struct node * insert(struct node * temp){
    struct node * newnode;
    newnode= (struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(temp == NULL)
    {
        temp = newnode;
    }
    else{
        struct node * temp1 = temp;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next=newnode;
    }
    return temp;
}

void display(struct node * temp){
    if(temp == NULL){
        printf("empty");
    }
    else{
        printf("\ndisplay : ");
        while(temp != NULL){
            printf(" %d ",temp->data);
            temp = temp->next;
        }
    }
}


void displayreverse(struct node * temp){
if(temp == NULL)
return;
displayreverse(temp->next);
printf("%d",temp->data);
}


int count(struct node * temp){
    int count=0;
    while(temp != NULL){
        count++;
        temp= temp->next;
    }
    printf("\ncount is %d \n",count);
    return count;
}

void reverse(struct node * temp){
    struct node * temp1 = temp;
    struct node * prev = NULL;
    struct node * after = NULL;
    while(temp1 != NULL ){
        after = temp1->next;
        temp1->next = prev;
        prev = temp1;
        temp1 = after;
    }
    temp = prev;
    printf("reverse ");
    display(temp);
}

void sort(struct node* temp){
    struct node* temp1 = NULL;
    while(temp!=NULL){
        temp1 = temp->next;
        while(temp1!=NULL){
            if(temp->data > temp1->data){
                int x = temp1->data;
                temp1->data = temp->data;
                temp->data = x;
            }
        temp1 = temp1->next;
        }
    temp = temp->next;
    }
}

void max(struct node * temp){
    int max;
    if(temp  == NULL){
        printf("empty");
    }
    else{
        max = temp->data;
        while(temp!=NULL){
            if(temp->data > max){
            max = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\nmax is %d",max);
}

struct node* concatenate(struct node * temp1,struct node * temp2,struct node * start){
    start=temp1;
    struct node* t=start;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp2;
    return start;
}


void split(struct node * start){
    printf("\nenter data where to split ");
    int val;
    scanf("%d",&val);
    struct node * temp = start;
    while(temp->data != val){
    temp = temp->next;
    }
    start5 = temp;
    temp = start;
    while(temp->next->data != val){
    temp = temp->next;
    }
    temp->next = NULL;
    start4 = start;
}

void main (){
    while(1){
    int n=0;
    printf("\nenter number of terms for 1 ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    start1 = insert(start1);
   // display(start1);
   // printf("\nreverse display ");
   // displayreverse(start1);
   // count(start1);
   // reverse(start1);
   // sort(start1);
   // display(start1);
 //   max(start1);
    printf("\nenter number of terms for 2 ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    start2 = insert(start2);
 //   display(start2);
   // displayreverse(start2);
   // count(start2);
   // reverse(start2);
    printf("\nconcatenate 1 and 2\n");
    start3 = concatenate(start1,start2,start3);
    display(start3);
    split(start3);
    display(start4);
    display(start5);
    }
}
