#include <stdio.h>
#include <string.h>
#define size 20
int stack[size], top = -1;
void push (int x)
{
  top++;
  stack[top] = x;
}

int isop (char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 1;
  else
    return 0;
}

int pop ()
{
  int x = stack[top];
  top--;
  return x;
}

void postfixEval(char s[size]){
  for (int i = 0;s[i] != '\0'; i++)
    {
      if (isop (s[i]))
	{
	  char op = s[i];
	  int a = pop ();
	  int b = pop ();
	  switch (op)
	    {
	    case '+':
	      push (a + b);
	      break;
	    case '-':
	      push (b - a);
	      break;
	    case '*':
	      push (a * b);
	      break;
	    case '/':
	      push (b / a);
	      break;
	    }

	}
      else
	{
	  push (s[i] - '0');
	}

    }
}

int main ()
{
  char s[size] = "";
  gets(s);
  postfixEval(s);
  for (int i = 0; s[i] != '\0'; i++)
    printf ("%c", s[i]);
  printf (" =  %d", stack[top]);
  return 0;
}
