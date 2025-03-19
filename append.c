#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(int argc, char *argv[])
{
  node *list = NULL;

  // append each num entered
  for (int i = 1; i < argc; i++)
  {
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->number = number;
    n->next = list;

    if (list == NULL)
    {
      list = n;
    }
    else
    {
      for (node *ptr = list; ptr != NULL; ptr = ptr->next)
      {
        if (ptr->next == NULL)
        {
          // append
          ptr->next = n;
          break;
        }
      }
    }
  }
}
