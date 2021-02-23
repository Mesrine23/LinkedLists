#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "palmods.h"
#include "item.h"

int main()
{
  printf("\n\n");
  char str[60],prestack[60];
  int x,i;

  STACKinit();

  while (fgets(str, 60, stdin)!=NULL) //read line per line
  {
    for(i=0;i<60;++i)
      prestack[i]=0;

    x=0;
    i=0;

    //saving data in a proper way
    while(1)
    {
      if(str[i]>='A' && str[i]<='Z')
      {
        prestack[x]=str[i];
        ++x;
      }
      else if(str[i]>='a' && str[i]<='z')
      {
        prestack[x]=str[i] - ('a'-'A');
        ++x;
      }
      else if(str[i]=='\n' || str[i]=='\0')
      {
        break;
      }
      ++i;
    }


    //calling the proper function
    if((x%2)==0)
    {
      if(palEVEN(prestack,x)==0)
        printf("PALINDROME : %s",str);
      else
        printf("NON-PALINDROME : %s",str);
    }
    else
    {
      if(palODD(prestack,x)==0)
        printf("PALINDROME : %s",str);
      else
        printf("NON-PALINDROME : %s",str);
    }
  }
  printf("\n\n");
}
