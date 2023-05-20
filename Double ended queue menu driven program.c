#include<stdio.h>
#define size 5
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1, queue[size];
void enqueue ()
{
  if (size == rear1 + size - 1 - rear2 + 2)
    {
      printf ("Queue full\n");
    }
  else
    {

int item, qno;
      printf ("Enter queue no and item  ");
      scanf ("%d %d", &qno, &item);
      if (qno == 1)
	{
	  if (front1 == -1 && rear1 == -1)
	    {
	      front1++;
	      rear1++;
	      queue[rear1] = item;
	    }
	  else
	    {
	      rear1++;
	      queue[rear1] = item;
	    }
	}
      if (qno == 2)
	{
	  if (front2 == -1 && rear2 == -1)
	    {
	      front2 = size - 1;
	      rear2 = size - 1;
	      queue[rear2] = item;
	    }
	  else
	    {
	      rear2--;
	      queue[rear2] = item;
	    }
	}
    }
}

void dequeue ()
{
  if (front1 == -1 && front2 == -1)
    {
      printf ("Queue Empty\n");
    }
  else
    {
      int qno;
      printf ("Enter queue no  ");
      scanf ("%d", &qno);
      if (qno == 1)
	{
	  if (front1 == -1 && rear1 == -1)
	    {
	      printf ("Queue 1 Empty\n");
	    }
	  else
	    {

    if (front1 == rear1)
		{
		  rear1 = -1;
		  front1 = -1;
		}
	      else
		{
		  queue[front1] = 0;
		  front1++;
		}
	    }
	}
      if (qno == 2)
	{
	  if (front2 == -1 && rear2 == -1)
	    {
	      printf ("Queue 2 Empty\n");
	    }
	  else
	    {
	      if (front2 == rear2)
		{
		  rear2 = -1;
		  front2 = -1;
		}
	      else
		{
		  queue[front2] = 0;
		  front2--;
		}
	    }
	}
    }
}

void display ()
{
  if (front1 == -1 && front2 == -1)
    {
      printf ("empty\n");
    }
  else
    {
      for (int i = 0; i < size; i++)
	{
	  printf ("%d\t", queue[i]);
    }} printf ("\n");
}

void main ()
{
  int choice = 0;

  printf ("\nEnter your choice  1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
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
	default:
	  printf ("enter correct choice\n");
	  break;
	}
      printf ("\nEnter your choice  1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
      scanf ("%d", &choice);
    }
}

