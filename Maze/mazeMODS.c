#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "maze.h"

typedef struct STACKnode* link;

struct STACKnode
{
  Item item;
  link next;
};

static link head;


link NEW(Item item, link next)
{
  link x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}


void STACKinit()
  { head = NULL; }


int STACKempty()
  { return head == NULL; }


void STACKpush(Item item)
  { head = NEW(item, head); }


Item STACKpop()
{ Item item = head->item;
  link t = head->next;
  free(head);
  head = t;
  return item;
}



void mazeSOLVE(char maze[6][6])
{
  int flag=0,move,a,b;
  Item i,j,p;
  Item startI,startJ;

  STACKinit();

  i=0;
  j=0;
  while(1)  // finding position of 'S'
  {
    if(maze[i][j]=='S')
      break;
    else
    {
      if( (j+1)<=5 )
        ++j;
      else
      {
        j=0;
        ++i;
      }
    }
  }

  p = i*6 + j;
  STACKpush(p);
  startI = i;
  startJ = j;
  //maze[i][j]='+';
  //In this case we will always have a path to G
  //so there is no need to change "S" to "+"


  //i,j = current position

  while(flag==0)
  {
    move=0;

    // NORTH - UP
    if( (i-1)>=0 )  //in maze?
    {
      if( maze[i-1][j]=='G' )
      {
        flag=1;
        --i;
        break;
      }
      else if( maze[i-1][j]=='.' )
      {
        --i;
        maze[i][j]='+';
        p = i*6 + j;
        STACKpush(p);
        move=1;
      }
    }

    // EAST - RIGHT
    if(move==0)
    {
      if( (j+1)<=5 )  //in maze?
      {
        if( maze[i][j+1]=='G' )
        {
          flag=1;
          ++j;
          break;
        }
        else if( maze[i][j+1]=='.' )
        {
          ++j;
          maze[i][j]='+';
          p = i*6 + j;
          STACKpush(p);
          move=1;
        }
      }
    }

    // SOUTH - DOWN
    if(move==0)
    {
      if( (i+1)<=5 )  //in maze?
      {
        if( maze[i+1][j]=='G' )
        {
          flag=1;
          ++i;
          break;
        }
        else if( maze[i+1][j]=='.' )
        {
          ++i;
          maze[i][j]='+';
          p = i*6 + j;
          STACKpush(p);
          move=1;
        }
      }
    }

    // WEST - LEFT
    if(move==0)
    {
      if( (j-1)>=0 )  //in maze?
      {
        if( maze[i][j-1]=='G' )
        {
          flag=1;
          --j;
          break;
        }
        else if( maze[i][j-1]=='.' )
        {
          --j;
          maze[i][j]='+';
          p = i*6 + j;
          STACKpush(p);
          move=1;
        }
      }
    }

    // CAN'T move
    if(move==0)
    {
      maze[i][j]='x';
      p = STACKpop();
      i = p/6;
      j = p%6;
    }

  }

  printf("\n");
  for(a=0 ; a<=5 ; ++a)
  {
    for(b=0 ; b<=5 ; ++b)
    {
      if(maze[a][b]=='x')
        maze[a][b]='.';
      printf("%c ",maze[a][b]);
    }
    printf("\n");
  }


  printf("\n");
  printf("G is in position: [%d,%d]\n\n",i+1,j+1);

}

/* -----ΝΟΤΕ---- */
/*
  In order to know the position i moved or removed,
  i define "position" as:
  position = i*6 + j;
  so, i STACKpush(position).
  When i POP my position [p=STACKpop()],
  i need to translate it in "i" , "j" so:
  i = p/6;
  j = p%6;
*/
