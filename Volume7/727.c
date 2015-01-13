#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

char OpStack[STACK_SIZE];
int StackTopPtr = -1;

void StackPush(char Op) {
   StackTopPtr++;
   OpStack[StackTopPtr] =  Op;
}

char StackPop(void) {
   return OpStack[StackTopPtr--];
}

int OpPriority(char Op)
{
    switch (Op)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '(':
        return 0;
    }
}


void StackPopUntilEmptyOrLparel(void) {
   char OpOut;  
   while (1) {
      if (StackTopPtr == -1) {
         break;
      }
      OpOut = StackPop();
      if (  OpOut == '(') {
         break;
       } else {              
	     printf("%c", OpOut);
       }
   }     
}

void StackPushUntilLowPriority(char OpIn) {
   while ( (StackTopPtr >= 0) && (OpPriority(OpStack[StackTopPtr])>= OpPriority(OpIn))) {
      printf("%c", StackPop()); 
   }
   StackPush(OpIn);     
}


int main(void)
{
   int NumCase;
   int IdxCase;
   char OpIn;
   char Line[10];
   char OpOut;  
   int LenLine;

/*
   freopen("p727_in.txt", "r", stdin);
   freopen("p727_out.txt", "w", stdout);
*/
   scanf("%d", &NumCase);   
   getchar();  
   getchar(); 
   
   for ( IdxCase = 0; IdxCase < NumCase; IdxCase++) {
      StackTopPtr = -1;   
      while (1) {           
       if ( gets(Line) == NULL) {
          StackPopUntilEmptyOrLparel();
          printf("\n");   
	      break;             
       }
       LenLine = strlen(Line);
       if (LenLine == 0) {
          StackPopUntilEmptyOrLparel();
          printf("\n\n");   
	      break;          
       }      
       OpIn = Line[0];
       switch (OpIn) 
 	   {
	    case '(':
		         StackPush(OpIn);
		         break;
	    case ')':
                 StackPopUntilEmptyOrLparel();
		         break;
		case '*':
        case '/':   
  	    case '+':     
		case '-':                                        
                 StackPushUntilLowPriority(OpIn);
                 break;			       							 
		default:			        
                 printf("%c",OpIn);
	             break;
	   }     
      }         
	}
    return 0;
}
