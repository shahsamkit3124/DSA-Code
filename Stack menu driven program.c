#include<stdio.h>
#define size 50
// push pop peek display exit // insert
int top = -1, stack[size];
void push ()
{
  if (top == size - 1)
    {
      printf ("Stack full\n");
    }
  else
    {
      int item;
      printf ("Enter an element\n");
      scanf ("%d", &item);
      top++;
      stack[top] = item;
}}
void pop ()
{
  if (top == -1)
    {
      printf ("empty\n");
    }
  else top--;
}

void peek ()
{
  if (top == -1)
    printf ("empty\n");
  else printf ("The top element is %d\n", stack[top]);
}

void display ()
{
  if (top == -1)
    {
      printf ("empty\n");
    }
  else
    {
      for (int i = 0; i <= top; i++)
	{
	  printf ("%d\n", stack[i]);
    }
    }
}
void main ()
{
int choice = 0;
printf ("Enter your choice  1.push 2.pop 3.peek 4.display 5.Exit\n");
scanf ("%d", &choice);
while (choice != 5){
switch (choice)
	{
case 1:{
push ();
break;
}
case 2:{
pop ();
break;
}
case 3:{
peek ();
break;
}
case 4:{
display ();
break;
}
case 5:{
break;
}
default:
printf ("enter correct choice\n");
break;
}
printf ("Enter your choice  1.push 2.pop 3.peek 4.display 5.Exit\n");
scanf ("%d", &choice);
}
}
