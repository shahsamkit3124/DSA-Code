#include <stdio.h>
#define size 5
int cqueue[size], front = -1, rear = -1;
void enqueue ()
{
  if (rear == front - 1)
    {
      printf ("\ncqueue full\n");
    }
  else if (front == 0 && rear == size - 1)
    {
      printf ("\ncqueue full\n");
    }
  else
    {
      int item;
      printf ("\n enter item : ");
      scanf ("%d", &item);
      if (front == -1)
	{
	  front++;
	  rear++;
	  cqueue[rear] = item;
	}
      else
	{
	  rear = (rear + 1) % size;
	  cqueue[rear] = item;
	}
    }
}

void dequeue ()
{
  if (front == rear)
    {
      cqueue[front] = 0;
      front = -1;
      rear = -1;
    }
  else
    {
      cqueue[front] = 0;
      front = (front + 1) % size;
    }
}

void display ()
{

for (int i = 0; i < size; i++)
    {
      printf (" %d ", cqueue[i]);
    } printf ("\n");
}
int main ()
{
  printf
    ("Enter your choice!\n1. enqueue \n2. dequeue\n3. display\n4. exit\n");
  int choice;
  scanf ("%d", &choice);
  while (choice != 4)
    {
      switch (choice)
	{
	case 1:
	  enqueue ();
	  break;
	case 2:
	  dequeue ();
	  break;
	case 3:
	  display ();
	  break;
	case 4:
	  break;
	}
      printf
	("Enter your choice!\n1. enqueue \n2. dequeue\n3. display\n4. exit\n");
      scanf ("%d", &choice);
    }
  return 0;
}
