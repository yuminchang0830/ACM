/* @JUDGE_ID:50418EN 711 C */

#include<stdio.h> 
#define SUM 150 

int T[SUM]; 

int main(void) 
{ 
   int i,j,k,l,m,n[6],total,num; 
/*   freopen("data.txt","r",stdin); 
   freopen("da.txt","w",stdout);*/ 
   num=0; 
   while(1){ 
      num++; 
      for(i=0;i<6;i++){ 
         scanf("%d",&n[i]); 
         if(n[i]>6) 
            n[i]=6+n[i]%2; 
      } 
      total=n[0]+n[1]*2+n[2]*3+n[3]*4+n[4]*5+n[5]*6; 
      if(!total) 
         break; 
      if(total%2){ 
         printf("Collection #%d:\nCan't be divided.\n\n",num); 
         continue; 
      } 
      T[0]=1; 
      l=0; 
      for(i=1;i<=SUM;i++) 
         T[i]=0; 
      for(i=0;i<6;i++){ 
         for(j=0;j<n[i];j++){ 
            for(k=0;k<=l;k++) 
               if(T[k]){ 
                  T[k+i+1]=1; 
                  m=k+i+1; 
                  if(T[total/2]) 
                     break; 
               } 
            l=m; 
            if(T[total/2]) 
               break; 
         } 
         if(T[total/2]) 
            break; 
      } 
      if(T[total/2]) 
         printf("Collection #%d:\nCan be divided.\n\n",num); 
      else 
         printf("Collection #%d:\nCan't be divided.\n\n",num); 
   } 
   return 0; 
}