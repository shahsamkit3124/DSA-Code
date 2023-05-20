#include<stdio.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;

};

int main()
{
    int n,i,data;
    struct node *newnode;
    struct node*head;
    struct node *temp;
    printf("Enter the NUmber of Node");
    scanf("%d",&n);
    newnode=(struct node *) malloc(sizeof(struct node));
    head=newnode;
    printf("Enter the 1 element");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp=head;


    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof (struct node));
        printf("Enter the %d Element for node",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    temp=head;

    printf("\n\t\tLINKED_LIST\nPosition=\t");
    for(i=1;i<=5;i++)
    {
        printf("%d\t",i);
    }
    printf("\nData=\t\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

