/* FUNCTIONS USED BY MAIN */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "mods.h"
#include "item.h"


typedef struct STACKnode* link;

struct STACKnode
{
  Item item;
  link next;
};

/*
struct Queue
{
  STACKnode MAIN;
  STACKnode TEMP;
};
*/



static link headM;
static link headT;


void Qinit()
{
  headM = NULL;
  headT = NULL;
}


link NEW(Item item, link next)
  {
    link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
  }


void STACKpushM(Item item)
  { headM = NEW(item, headM); }

void STACKpushT(Item item)
  { headT = NEW(item, headT); }


Item STACKpopM()
  {
    Item item = headM->item;
    link t = headM->next;
    free(headM); headM = t;
    return item;
  }

Item STACKpopT()
  {
    Item item = headT->item;
    link t = headT->next;
    free(headT); headT = t;
    return item;
  }



int fQueue(int *N,int x)
{
  //Queue q;
  Item top;
  int i;

  Qinit();

  for(i=0 ; i<x ; ++i)
    STACKpushM(N[i]);

  for(i=0 ; i<x ; ++i)
  {
    top=STACKpopM();
    STACKpushT(top);
  }

  return STACKpopT();
}
