#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *pre;
};
struct node *head;
void insert();
void delete();
void display();
void search();
int c = 0, b = 0;
void main()
{
  int a, ch;
  head = NULL;
  while (1)
  {
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert();
      break;
    case 2:
      delete ();
      break;
    case 3:
      display();
      break;
    case 4:
      search();
      break;
    case 5:
      exit(0);
    default:
      printf("invalid choice");
    }
  }
}

void insert()
{
  int n, p, i;
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  struct node *temp2, *x;
  scanf("%d%d", &n, &p);
  if (p <= 0 || p > c + 1)
    printf("Enter a valid position");
  else
  {
    c++;
    temp->data = n;
    temp->next = NULL;
    temp->pre = NULL;
    if (head == NULL)
      head = temp;
    else if (p == 1)
    {
      x = head;
      x->pre = temp;
      temp->next = x;
      head = temp;
    }
    else
    {
      temp2 = head;
      for (i = 1; i < p - 1; i++)
      {
        temp2 = temp2->next;
      }
      temp->next = temp2->next;
      temp2->next = temp;
      temp->pre = temp2;
      if (p != c)
      {
        temp2 = temp->next;
        temp2->pre = temp;
      }
    }
  }
}

void delete()
{
  int p, i;
  struct node *temp1 = head, *temp2;
  scanf("%d", &p);
  if (p <= 0 || p > c)
    printf("Enter a valid position");
  else
  {
    c--;
    if (p == 1)
    {
      head = temp1->next;
      if (c != 0)
      {
        temp2 = temp1->next;
        temp2->pre = temp1->pre;
      }
      free(temp1);
    }
    else
    {
      for (i = 1; i < p - 1; i++)
      {
        temp1 = temp1->next;
      }
      temp2 = temp1->next;
      temp1->next = temp2->next;
      if (p != c + 1)
      {
        temp1 = temp2->next;
        temp1->pre = temp2->pre;
      }
      free(temp2);
    }
  }
}

void search()
{
  int n, p = 0;
  struct node *x;
  scanf("%d", &n);
  if (head == NULL)
  {
    printf("DLL is empty");
    return;
  }
  x = head;
  while (x != NULL)
  {
    p++;
    if (x->data == n)
    {
      b = 1;
      break;
    }
    x = x->next;
  }
  if (b == 1)
    printf("%d found at position %d", x->data, p);
  else
    printf("element not found");
}

void display()
{
  int i;
  struct node *x, *y;
  if (head == NULL)
  {
    printf("DLL is empty");
    return;
  }
  x = head;
  y = head;
  printf("\nFORWARD Traversal: ");
  while (x != NULL)
  {
    printf("%d ", x->data);
    x = x->next;
  }
  printf("\nBACKWARD Traversal: ");
  for (i = 0; i < c - 1; i++)
  {
    y = y->next;
  }
  while (y != NULL)
  {
    printf("%d ", y->data);
    y = y->pre;
  }
}