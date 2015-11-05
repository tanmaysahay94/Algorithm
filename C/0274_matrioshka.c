#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data, sum;
  struct node *link;
} node;
int
main ()
{
  int testCases, i, numberOfInputs, matrioshka, num, pop, dollSum;
  scanf ("%d", &testCases);
  while (testCases--)
    {
      dollSum = 0;
      scanf ("%d", &numberOfInputs);
      int a[numberOfInputs];
      matrioshka = 1;
      node *stack = NULL, *temp;
      for (i = 0; i < numberOfInputs; i++)
	{
	  scanf ("%d", &a[i]);
	  dollSum += a[i];
	}
      if (a[0] == -a[numberOfInputs - 1] && !dollSum)
	{
	  for (i = 0; i < numberOfInputs; i++)
	    {
	      num = a[i];
	      if (!stack)
		{
		  temp = (node *) malloc (sizeof (node));
		  temp->data = num;
		  temp->sum = 0;
		  temp->link = NULL;
		  stack = temp;
		}
	      else
		{
		  if (num < 0)
		    {
		      if (num <= stack->data)
			{
			  matrioshka = 0;
			  break;
			}
		      else
			{
			  temp = (node *) malloc (sizeof (node));
			  temp->data = num;
			  temp->sum = 0;
			  temp->link = stack;
			  stack = temp;
			}
		    }
		  else
		    {
		      if (num == -stack->data)
			{
			  pop = stack->data;
			  stack = stack->link;
			  if (stack)
			    {
			      stack->sum += pop;
			      if (stack->sum <= stack->data)
				{
				  matrioshka = 0;
				  break;
				}
			    }
			}
		      else
			{
			  matrioshka = 0;
			  break;
			}
		    }
		}
	    }
	}
      else
	matrioshka = 0;
      if (matrioshka)
	printf (":-) Matrioshka!\n");
      else
	printf (":-( Try again.\n");
    }
  return 0;
}
