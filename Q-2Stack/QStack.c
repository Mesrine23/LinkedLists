#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "mods.h"
#include "item.h"

int main(int argc, char *argv[])
{
    int *N;
    int i;

    N = malloc(argc-1);

    for(i=0 ; i<argc-1 ; ++i)
    {
      N[i] = atoi(argv[i+1]);
      printf("%d ",N[i]);
    }
    printf("\n");

    printf("The popped value is: %d\n",fQueue(N,argc-1));
}
