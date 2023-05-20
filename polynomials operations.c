#include<stdlib.h>
#include<stdio.h>
struct node
{
  int num;
  int power;
  struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node * insert (struct node *start)
{
  struct node *temp;
  int n, x, y;
  printf ("enter the number of terms \n");
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    {
      struct node *newnode;
      newnode = (struct node *) malloc (sizeof (struct node));
      printf ("enter number and POWER\n");
      scanf ("%d %d", &x, &y);
      newnode->num = x;
      newnode->power = y;
      newnode->next = NULL;
      if (start == NULL)
	{
	  start = newnode;
	}
      else
	{
	  temp = start;
	  while (temp->next != NULL)
	    {
	      temp = temp->next;
	    }
	  temp->next = newnode;
	}
    }
  return start;
}

struct node *add (struct node *temp1, struct node *temp2, struct node *start)
{
  struct node *temp3;
  struct node *newnode;

while (temp1 != NULL && temp2 != NULL)
    {
      newnode = (struct node *) malloc (sizeof (struct node));
      newnode->next = NULL;
      if (temp1->power > temp2->power)
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num;
	  temp1 = temp1->next;
	}
      else if (temp2->power > temp1->power)
	{
	  newnode->power = temp2->power;
	  newnode->num = temp2->num;
	  temp2 = temp2->next;
	}
      else
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num + temp2->num;
	  temp1 = temp1->next;
	  temp2 = temp2->next;
	}
      if (start == NULL)
	{
	  start = newnode;
	}
      else
	{
	  temp3 = start;
	  while (temp3->next != NULL)
	    {
	      temp3 = temp3->next;
	    }
	  temp3->next = newnode;
	}
    }
  while (temp1 != NULL || temp2 != NULL)
    {
      newnode = (struct node *) malloc (sizeof (struct node));
      newnode->next = NULL;
      if (temp1 != NULL)
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num;
	  temp1 = temp1->next;
	}
      if (temp2 != NULL)
	{
	  newnode->power = temp2->power;
	  newnode->num = temp2->num;
	  temp2 = temp2->next;
	}
      if (start == NULL)
	{
	  start = newnode;
	}
      else
	{
	  temp3 = start;
	  while (temp3->next != NULL)
	    {
	      temp3 = temp3->next;
	    }
	  temp3->next = newnode;
	}
    }
  return start;
}

struct node *sub (struct node *temp1, struct node *temp2, struct node *start)
{
  struct node *temp3;
  struct node *newnode;
  while (temp1 != NULL && temp2 != NULL)
    {
      newnode = (struct node *) malloc (sizeof (struct node));
      newnode->next = NULL;
      if (temp1->power > temp2->power)
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num;
	  temp1 = temp1->next;
	}
      else if (temp2->power > temp1->power)
	{
	  newnode->power = temp2->power;
	  newnode->num = -(temp2->num);
	  temp2 = temp2->next;
	}
      else
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num - temp2->num;
	  temp1 = temp1->next;
	  temp2 = temp2->next;
	}
      if (start == NULL)
	{
	  start = newnode;
	}
      else
	{
	  temp3 = start;

while (temp3->next != NULL)
	    {
	      temp3 = temp3->next;
	    }
	  temp3->next = newnode;
	}
    }
  while (temp1 != NULL || temp2 != NULL)
    {
      newnode = (struct node *) malloc (sizeof (struct node));
      newnode->next = NULL;
      if (temp1 != NULL)
	{
	  newnode->power = temp1->power;
	  newnode->num = temp1->num;
	  temp1 = temp1->next;
	}
      if (temp2 != NULL)
	{
	  newnode->power = temp2->power;
	  newnode->num = -(temp2->num);
	  temp2 = temp2->next;
	}
      if (start == NULL)
	{
	  start = newnode;
	}
      else
	{
	  temp3 = start;
	  while (temp3->next != NULL)
	    {
	      temp3 = temp3->next;
	    }
	  temp3->next = newnode;
	}
    }
  return start;
}

void display (struct node *temp)
{
  while (temp->next != NULL)
    {
      printf (" %d^%d \n", temp->num, temp->power);
      temp = temp->next;
    }
  printf (" %d^%d \n", temp->num, temp->power);
  start3 = NULL;

}

void main ()
{
  printf ("enter 1 polynomial \n");
  start1 = insert (start1);
  printf ("enter 2 polynomial \n");
  start2 = insert (start2);
  int choice = 0;
  while (choice != 3)
    {
      printf ("ENTER YOUR CHOICE \n1> ADD\n2> SUBTRACT\n3> EXIT\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  {
	    printf ("----ADD----\n");
	    start3 = add (start1, start2, start3);
	    printf ("print \n");
	    display (start3);
	    break;
	  }
	case 2:
	  {
	    printf ("----SUBTRACT----\n");
	    start3 = sub (start1, start2, start3);
	    printf ("print \n");
	    display (start3);
	    break;
	  }
	case 3:
	  {
	    printf ("EXIT");
	    break;
	  }
	default:
	  printf ("Enter correct choice");
	}
    }
}
