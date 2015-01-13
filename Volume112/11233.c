#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 24
#define MAX_DICTIONARY_WORD 21

char Singular[MAX_DICTIONARY_WORD][MAX_WORD_SIZE];
char Plural[MAX_DICTIONARY_WORD][MAX_WORD_SIZE];

int main(void)
{
  int NumIregularWord;
  int NumTestCase;
  int IdxCase;  
  int IdxIrgDict;
  char InputWord[MAX_WORD_SIZE];
  int isWordIregularForm;
  int WordLen;
  
  /*
  freopen("p11233_in.txt", "r", stdin);
  freopen("p11233_out.txt", "w", stdout);
  */
  scanf("%d %d", &NumIregularWord, &NumTestCase);
  
  for ( IdxIrgDict = 0; IdxIrgDict < NumIregularWord; IdxIrgDict++) {
     scanf("%s %s", Singular[IdxIrgDict], Plural[IdxIrgDict]);
  }
  for ( IdxCase = 0; IdxCase < NumTestCase; IdxCase++) {
     /* Check Word is irregular or not*/
	 scanf("%s", InputWord);
	 isWordIregularForm = 0;
	 for ( IdxIrgDict = 0; IdxIrgDict < NumIregularWord; IdxIrgDict++) {
	     if (strcmp(InputWord, Singular[IdxIrgDict]) == 0) {
		    printf("%s\n",Plural[IdxIrgDict]);
			isWordIregularForm = 1;
		    break;
		 }
	 }
	 if ( isWordIregularForm != 1) {
	    WordLen = strlen(InputWord);
		if (WordLen >=2) {
		   if (strncmp(&InputWord[WordLen-2],"ch",2) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-2],"sh",2) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-1],"o",1) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-1],"s",1) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-1],"x",1) == 0) {		   
             strcat(InputWord, "es");		    
		   } else if (strncmp(&InputWord[WordLen-1],"y",1) == 0) {	
             if ( InputWord[WordLen-2] == 'a' || InputWord[WordLen-2] == 'e'  || InputWord[WordLen-2] == 'i' || InputWord[WordLen-2] == 'o' || InputWord[WordLen-2] == 'u') {
                  strcat(InputWord, "s");	
             } else {
                InputWord[WordLen-1] = 'i';		   
                strcat(InputWord, "es");	
             }
		   } else {
             strcat(InputWord, "s");	
		   }
		} else {
		   if (strncmp(&InputWord[WordLen-1],"o",1) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-1],"s",1) == 0) {
		     strcat(InputWord, "es");
		   } else if (strncmp(&InputWord[WordLen-1],"x",1) == 0) {		   
             strcat(InputWord, "es");		    
		   } else {
             strcat(InputWord, "s");	
		   }
		}
		printf("%s\n", InputWord);
	 }
  }

  
  return 0;
}
