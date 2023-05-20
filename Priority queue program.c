#include <stdio.h>
#define size 50
int priqueue[size][2], front = -1, rear = -1;

void sort(){
    if(front == -1) return;
    if(front == rear ) return;
  for(int j=front;j<rear;j++){
    for(int i=front;i<rear;i++){
        if(priqueue[i][1] < priqueue[i+1][1]){
            int temp = priqueue[i][0];
            priqueue[i][0] = priqueue[i+1][0];
            priqueue[i+1][0] = temp;

            temp = priqueue[i][1];
            priqueue[i][1] = priqueue[i+1][1];
            priqueue[i+1][1] = temp;
        }
    }
  }
}

void enqueue ()
{
  if (rear == size - 1)
    {
      printf ("\nqueue full\n");
    }
  else
    {
      int item,pri;
      printf ("\n enter item and priority : ");
      scanf ("%d %d", &item,&pri);
      if (front == -1)
	{
	  front++;
	  rear++;
	  priqueue[rear][0] = item;
	  priqueue[rear][1] = pri;
	}
      else
	{
	  rear++;
	  priqueue[rear][0] = item;
	  priqueue[rear][1] = pri;
	}
    }
    sort();
}

void dequeue ()
{
  if(front == -1) printf("queue empty\n");
  else if (front == rear)
    {
      front = -1;
      rear = -1;
    }
  else
    {
      front++;
    }
}

void display ()
{
  if(front == -1) printf("queue empty\n");
    for (int i = front; i <= rear; i++)
    {
      printf (" %d %d \n", priqueue[i][0],priqueue[i][1]);
    }
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
