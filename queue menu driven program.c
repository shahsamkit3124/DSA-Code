#include <stdio.h>
#define size 50
int front = -1, rear = -1, queue[size];
void insert ()
{
  if (rear == size - 1)
    {
      printf ("Queue is full\n");
    }
  else if (front == -1 && rear == -1)
    {
      int num;
      printf ("Enter the number you want to push into the stack:\n");
      front++;
      rear++;
      scanf ("%d", &num);
      queue[0] = num;
    }
  else
    {
      int num;
      printf ("Enter the number you want to push into the stack:\n");
      scanf ("%d", &num);
      rear++;
      queue[rear] = num;
    }
}
void deletion ()
{
  if (front == -1 && rear == -1)
    {
      printf ("\nQueue is empty");
    }
  else if (front == rear)
    {
      front = rear = -1;
    }
  else
    {
      front++;
    }
}

void display ()
{
  if (front == -1 && rear == -1)
    {
      printf ("\nQueue is empty");
    }
  else
    {
      printf ("\nThe elements  present in the queue are:\n");
      for (int i = front; i <= rear; i++)
	{
	  printf ("%d\n", queue[i]);

    }
    }
}
void main ()
{
  int choice = 0;
  while (choice != 4)
    {
      printf ("\nPress 1 -> Insert 2 -> Delete 3 -> Display 4 -> Exit\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  insert ();
	  break;
	case 2:
	  deletion ();
	  break;
	case 3:
	  display ();
	  break;
	case 4:
	  break;
	default:
	  printf ("Please enter correct number.\n");
	}
    }
}
