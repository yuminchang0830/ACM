#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_CHAR 10001


int main(void)
{
 char InputChar; 
 int LenInputLine;
/* int IdxIL; */
 
  
/*
 freopen("p10222_in.txt", "r", stdin);
 freopen("p10222_out.txt", "w", stdout);
*/

  while (scanf("%c",&InputChar) != EOF){
	   switch (InputChar) {
	      case '2':
	      case '@':               
		    printf("%c",'~'); 
		    break;              
	      case '3':
	      case '#':               
		    printf("%c",'1');
            break;   
	      case '4':
	      case '$':               
		    printf("%c",'2');  
		    break;
	      case '5':
	      case '%':               
		    printf("%c",'3');  
            break;
	      case '6':
	      case '^':               
		    printf("%c",'4');
            break;            
	      case '7':
	      case '&':               
		    printf("%c",'5');
            break; 
	      case '8':
	      case '*':               
		    printf("%c",'6');
		    break;             
	      case '9':
	      case '(':               
		    printf("%c",'7');
		    break;  
	      case '0':
	      case ')':               
		    printf("%c",'8');
		    break;     
	      case '-':
	      case '_':               
		    printf("%c",'9');
            break;		    
	      case '+':
          case '=':     
		    printf("%c",'0');
		    break; 
	      case 'q':
	      case 'Q':               
		    printf("%c",'-');		    
		    break;
	      case 'w':
	      case 'W':               
		    printf("%c",'=');		    
		    break;   
	      case 'e':
	      case 'E':               
		    printf("%c",'q');
		    break;  
	      case 'r':
	      case 'R':               
		    printf("%c",'w');
		    break;            
	      case 't':
	      case 'T':               
		    printf("%c",'e');
		    break;            
  	      case 'y':
	      case 'Y':               
		    printf("%c",'r');
		    break;
	      case 'u':
	      case 'U':               
		    printf("%c",'t');
		    break;            
	      case 'i':
	      case 'I':               
		    printf("%c",'y');
		    break;
	      case 'o':
	      case 'O':               
		    printf("%c",'u');
		    break;
	      case 'p':
	      case 'P':               
		    printf("%c",'i');
		    break;
	      case '[':
	      case '{':               
		    printf("%c",'o');
		    break;
	      case ']':
	      case '}':               
		    printf("%c",'p');
		    break;
          case '\\':
          case '|':               
		    printf("%c",'[');
		    break;                                                                                                      	                                                                                 
	      case 'a':
	      case 'A':               
		    printf("%c",']');		    
		    break;              		    
	      case 's':
	      case 'S':               
		    printf("%c",'\\');		    
		    break;
	      case 'd':
	      case 'D':               
		    printf("%c",'a');
		    break;
	      case 'f':
	      case 'F':             
		    printf("%c",'s');
		    break;
	      case 'g':
	      case 'G':               
		    printf("%c",'d');
		    break;
	      case 'h':
	      case 'H':               
		    printf("%c",'f');
		    break;
	      case 'j':
	      case 'J':               
		    printf("%c",'g');
		    break;
	      case 'k':
	      case 'K':               
		    printf("%c",'h');
		    break;
	      case 'l':
	      case 'L':               
		    printf("%c",'j');
		    break;
	      case ':':
	      case ';':               
		    printf("%c",'k');
		    break;                                    		    
	      case '\"':
	      case '\'':               
		    printf("%c",'l');
		    break;
	      case 'z':
	      case 'Z':               
		    printf("%c",';');		    
		    break; 
	      case 'x':
	      case 'X':               
		    printf("%c",'\'');		    
		    break;	
	      case 'c':
	      case 'C':               
		    printf("%c",'z');
		    break;
	      case 'v':
	      case 'V':               
		    printf("%c",'x');
		    break;
	      case 'b':
	      case 'B':               
		    printf("%c",'c');
		    break;		    
	      case 'n':
	      case 'N':               
		    printf("%c",'v');
		    break;
	      case 'm':
	      case 'M':               
		    printf("%c",'b');
		    break;            
	      case ',':
	      case '<':               
		    printf("%c",'n');
		    break;
	      case '.':
	      case '>':               
		    printf("%c",'m');
		    break;                                                		    
	      case '/':
	      case '?':               
		    printf("%c",',');
		    break;
	      case '~':
	      case '`':               
		    printf("%c",'.');
		    break;
	      case '1':
	      case '!':               
		    printf("%c",'/');
		    break;
          case ' ':
            printf("%c",' '); 
		    break;   
          case '\n':     
		    printf("\n");
		    break;               
          default:     
            break;     		  
	   }
 } 

 return 0;
}
