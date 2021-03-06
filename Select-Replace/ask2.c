
// Ask 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum=0;

typedef char AirportCode[4];
typedef struct NodeTag
{
	AirportCode Airport;
	struct NodeTag *Link;
} NodeType;
typedef NodeType *NodePointer;

/* function prototypes */
void InsertNewSecondNode(NodeType **);
void InsertNewLastNode(char *, NodeType **);
void DeleteLastNode(NodeType **);
NodeType *ListSearch(char *, NodeType *);
void PrintList(NodeType *);

// Askisi 1
void length(NodeType *);

// Askisi 2
NodeType *Select(int, NodeType *);
void Replace(char *, int, NodeType **);


int main(int argc, char *argv[])
{

			int i;
      NodeType *L,*N;

      L=NULL;

      PrintList(L);



      InsertNewLastNode("DUS", &L);
      InsertNewLastNode("ORD", &L);
      InsertNewLastNode("SAN", &L);
      PrintList(L);



      InsertNewSecondNode(&L);

      PrintList(L);



      DeleteLastNode(&L);
      PrintList(L);

			/*
      if (ListSearch("DUS",L) != NULL) {
        printf("DUS is an element of the list\n");
      }
			*/


      // Ask 2
			length(L);
			i = atoi(argv[1]);
			if(i>sum)
				printf("The %d-node does not exist\n",i);
			else
			{
	      	N = Select(i,L);	// To N exei to pointer tou i-ostou stoixeiou
	      /* printf("The i-variable (i=%d) is: %s\n",i,N->Airport);	// Check if N is right */

	      Replace (argv[2], i, &L);
	      PrintList(L);
			}

}

void InsertNewLastNode(char *A, NodeType **L)
{
      NodeType *N, *P;

      N=(NodeType *)malloc(sizeof(NodeType));
      strcpy(N->Airport, A);
      N->Link=NULL;

      if (*L == NULL) {
         *L=N;
      } else {
         P=*L;
         while (P->Link != NULL) P=P->Link;
         P->Link=N;
      }

}



void PrintList(NodeType *L)
{
      NodeType *N;

      printf("(");
      N=L;
      while(N != NULL) {
         printf("%s", N->Airport);
         N=N->Link;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}


void DeleteLastNode(NodeType **L)
{
      NodeType *PreviousNode, *CurrentNode;

      if (*L != NULL) {
         if ((*L)->Link == NULL){
            free(*L);
            *L=NULL;
         } else {
            PreviousNode=*L;
            CurrentNode=(*L)->Link;
            while (CurrentNode->Link != NULL){
               PreviousNode=CurrentNode;
               CurrentNode=CurrentNode->Link;
            }
            PreviousNode->Link=NULL;
            free(CurrentNode);
         }
      }
}


void InsertNewSecondNode (NodeType **L)
{
      NodeType *N;
      N=(NodeType *)malloc(sizeof(NodeType));
      strcpy(N->Airport,"BRU");
      N->Link=(*L)->Link;
      (*L)->Link=N;
}



NodeType *ListSearch(char *A, NodeType *L)
{
      NodeType *N;

      N=L;
      while (N != NULL){
        if (strcmp(N->Airport,A)==0){
           return N;
        } else {
           N=N->Link;
        }
      }
      return N;
}




void length (NodeType *L)
{
	NodeType *N;
	N=L;

	if (N != NULL)
	{
		++sum;
		N=N->Link;
		length(N);
	}
}


NodeType *Select(int i, NodeType *L)
{
	NodeType *N;
	N=L;

	int y;
	for (y=0 ; y<=i-2 ; ++y)
		N=N->Link;

	return N;
}



void Replace (char *A, int i, NodeType **L)
{
	NodeType *N;
	N=*L;

	int y;
	for (y=0 ; y<=i-2 ; ++y)
		N=N->Link;

	strcpy(N->Airport, A);
}
