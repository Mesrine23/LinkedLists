#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int main()
{
  char ch,maze[6][6];
  int i=0,j=-1;

// DATA SAVING

  while((ch=getchar())!=EOF)
  {
    if(ch!='\n')
    {
      if((j+1)==6)
      {
        j=0;
        ++i;
      }
      else
        ++j;
      maze[i][j] = ch;
    }
  }

  mazeSOLVE(maze);

}
