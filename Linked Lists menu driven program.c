#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* next;
};
struct node *start=NULL;

void Insert_start()
{
    struct node* new_node;
    int item;
    printf("Enter the value: ");
    scanf("%d",&item);

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
        printf("OVERFLOW");
    else
        {
        new_node -> data = item;
        new_node->next = start;
        start = new_node;
    }
}

void Insert_middle()
{
    struct node * temp;
    int item,x;
    printf("Enter the element to be inserted: ");
    scanf("%d" , &item);
    printf("After which element it is to be inserted? : ");
    scanf("%d" , &x);
    struct node * new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = item;
    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while(temp -> data != x)
        {
            temp = temp -> next;
        }
        new_node -> next = temp -> next;
        temp -> next = new_node;
        printf("Successfully inserted!");
    }
}

void Insert_end()
{
    struct node * temp , *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    int item;
    printf("Enter the value: ");
    scanf("%d",&item);
    new_node -> data = item;
    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        temp = start;
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        new_node -> next = NULL;
        temp -> next = new_node;
    }
}

void Display()
{
    struct node* temp;
    if (start == NULL)
        printf("empty\n");
    else{
        printf("The elements in the linked list are \n");
        temp = start;

        // while(temp->next != NULL)
        // {
        //     printf("%d      ", temp->data);
        //     temp= temp->next;
        // }
        // printf("%d   ", temp->data);

        while(temp != NULL)
        {
            printf("%d    ", temp->data);
            temp= temp->next;
        }
    }
}
void Delete_start()
{
    struct node* temp;
    if(start==NULL)
        printf("empty");
    else
    {
        temp = start;
        start = temp->next;
    }
}

void Delete_middle()
{
    struct node* temp1;
    struct node* temp2;
    int item;
    printf("Enter the element to be deleted: ");
    scanf("%d" , &item);
    if(start == NULL)
        printf("Underflow!");
    else
    {
        temp1 = start;
        temp2 = start->next;
        while(temp1->data != item)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
    }
}

void Delete_last()
{
    struct node* temp1;
    struct node* temp2;
    temp1 = start;
    temp2 = start->next;
    if(start == NULL)
        printf("empty");
    else{
        while(temp2->next != NULL)
           {
              temp1 = temp1->next;
              temp2 = temp2->next;
           }
        temp1->next = NULL;
    }
}


int main()
{
    //struct node* start = NULL ;
    int choice;
    while(choice!=8)
    {
        printf("\nOperations performed by singly linked list:");
        printf("\n 1.To insert the element in the beginning\n 2.To insert the element at the end\n 3.TO insert the element in middle\n 4.To Delete first element\n 5. To Delete last element \n ");
        printf("6. To Delete middle element\n 7. To Display the linked list\n 8.Exit the Loop");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: Insert_start();
                        break;
            case 2: Insert_end();
                       break;
            case 3: Insert_middle();
                      break;
            case 4: Delete_start();
                        break;
            case 5: Delete_last();
                        break;
            case 6: Delete_middle();
                        break;
            case 7: Display();
                        break;
            case 8: printf("Exiting the Program\n");
                        break;
            default : printf("\nINVALID CHOICE.");
                        break;
        }
    }
}
