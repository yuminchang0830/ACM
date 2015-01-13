/* @JUDGE_ID:50418EN 612 C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct s 
{       int serno; 
   char dna[51]; 
   int inversion; 
}a[100]; 
int n,m; 

int getdna(char x) 
{ 
   switch(x) 
   {    case 'A': return 0; 
      case 'C': return 1; 
      case 'G': return 2; 
      case 'T': return 3; 
      default : abort(); 
   } 
} 

int count_sort(char *str) 
{       int i,j,k,invers=0,count[4]={0,0,0,0}; 
   for(i=0; str[i]; i++) 
   { 
      k=getdna(str[i]); 
      count[k]++; 
      for(j=k+1; j<4; j++) 
         invers += count[j]; 
   } 
   return invers; 
} 

int sort_function( const void *a, const void *b) 
{ 
   struct s *p=(struct s *)a, *q=(struct s *)b; 
   if(p->inversion != q->inversion) 
      return p->inversion - q->inversion; 
   else 
      return p->serno - q->serno; 
} 


void main() 
{ 
int testcase,t,i; 

/*freopen("in612.txt","r",stdin);*/ 
scanf("%d",&testcase); 
for(t=1; t<=testcase; t++) 
{   if(t>1) printf("\n"); 
   scanf("%d %d",&n,&m); 
   for(i=0; i<m; i++) 
   { 
      scanf("%s",&a[i].dna); 
      a[i].serno=i; 
      a[i].inversion=count_sort(a[i].dna); 
   } 
   qsort(a,m,sizeof(a[0]),sort_function); 
   for(i=0; i<m; i++) printf("%s\n",a[i].dna); 
} 
} 
