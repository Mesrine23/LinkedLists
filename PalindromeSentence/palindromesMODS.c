/* FUNCTIONS USED BY MAIN */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "palmods.h"
#include "item.h"


typedef struct STACKnode* link;

struct STACKnode
{
  Item item;
  link next;
};

static link head;


int palODD(char *ch,int x)
{
  int i,f=0;
  Item top;

  for(i=0 ; i<((x-1)/2) ; ++i)
    STACKpush(ch[i]);

  for(i=(((x-1)/2)+1) ; i<x ; ++i)
  {
    top=STACKpop();
    if((top-ch[i])!=0)
    {
      f=1;
      break;
    }
  }
  return f;
}


int palEVEN(char *ch,int x)
{
  int i,f=0;
  Item top;

  for(i=0 ; i<(x/2) ; ++i)
    STACKpush(ch[i]);

  for(i=(x/2) ; i<x ; ++i)
  {
    top=STACKpop();
    if((top-ch[i])!=0)
    {
      f=1;
      break;
    }
  }
  return f;
}



link NEW(Item item, link next)
  {
    link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
  }


void STACKinit()
  { head = NULL; }


int STACKempty()
  { return head == NULL; }


void STACKpush(Item item)
  { head = NEW(item, head); }


Item STACKpop()
  {
    Item item = head->item;
    link t = head->next;
    free(head); head = t;
    return item;
  }
