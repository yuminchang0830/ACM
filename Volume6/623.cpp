/* @JUDGE_ID:50418EN 623 C++ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define max_l 4000

class BIG_INT {
public:
 char data[max_l];
 BIG_INT operator+(BIG_INT &augend);   
 BIG_INT operator*(BIG_INT &multiend);
 BIG_INT();
};

BIG_INT::BIG_INT()
{ 
 data[0] = '0';
 data[1] = '\0';
 
}

BIG_INT BIG_INT::operator+(BIG_INT &augend)
{
 int n1, n2;
 int i,j,k,temp;
 int carry=0; 
 BIG_INT sum;
 n1 = strlen((*this).data);
 n2 = strlen(augend.data);  
   
 if ( n1 >= n2 ) {    
    for ( i = n1 - 1, j = n2 - 1, k = n1 ; j >= 0 ; i--, j--,k-- ) {	       
       sum.data[k] = ( ((*this).data[i] + augend.data[j] - 96 + carry) % 10 ) + 48 ;
       carry = ((*this).data[i] + augend.data[j] - 96 + carry) / 10;    
     
    }    
    for (; i >= 0 ; i--,k-- ) {
       sum.data[k] = ( ((*this).data[i] - 48 + carry) % 10 ) + 48 ;       
       carry = ((*this).data[i] - 48 + carry) / 10;
     
    } 
    if ( carry == 1 ) {
       sum.data[0] = '1';    
       sum.data[n1+1] = '\0';
    } else {
       for ( i = 0 ; i < n1 ; i++ ) {
         sum.data[i] = sum.data[i+1];
       }
       sum.data[i] = '\0';
    }     
 } else {
    temp = n1;
    n1 = n2;
    n2 = temp;
    for ( i = n1 - 1, j = n2 - 1, k = n1 ; j >= 0 ; i--, j--,k-- ) {	       
       sum.data[k] = ( (augend.data[i] + (*this).data[j] - 96 + carry) % 10 ) + 48 ;
       carry = (augend.data[i] + (*this).data[j] - 96 + carry) / 10;    
      
    }    
    for (; i >= 0 ; i--,k-- ) {
       sum.data[k] = ( (augend.data[i] - 48 + carry) % 10 ) + 48 ;       
       carry = (augend.data[i] - 48 + carry) / 10;
     
    } 
    if ( carry == 1 ) {
       sum.data[0] = '1'; 
       sum.data[n1+1] = '\0';   
    } else {
       for ( i = 0 ; i < n1 ; i++ ) {
         sum.data[i] = sum.data[i+1];
       }
       sum.data[i] = '\0';
    }    
   
 } 
 return sum; 
}

BIG_INT BIG_INT::operator*(BIG_INT &multiend)
{
 BIG_INT product, temp;
 int n1, n2;
 int carry = 0;
 int i, j ,k, s, z;
 n1 = strlen( (*this).data );
 n2 = strlen( multiend.data ); 
 
 for ( i = n2 - 1, z = 0 ; i >= 0 ; i--, z++ ) {
   carry = 0;
   if ( multiend.data[i] != '0' ) {
   for(j = n1 - 1, k = n1 ; j >= 0 ; j--, k-- ) {      
      temp.data[k] =  (( ( (*this).data[j] - 48) * (multiend.data[i] - 48) + carry) % 10) + 48; 
      carry = (( ( (*this).data[j] - 48 ) * (multiend.data[i] - 48)  +  carry )  / 10)  ; 
   }
   if ( carry == 0 ) {
      for ( j = 0 ; j < n1 ; j++ ) {
         temp.data[j] = temp.data[j+1];
      }      
   } else {
      temp.data[0] = carry + 48;
      j = n1 + 1;   
   }
   
   for (s = 0 ; s < z ; s++ ) {
      temp.data[j + s] = '0';
   }      
   temp.data[j + s ] = '\0';   
   product = product + temp;
   }
 } 
 return product;
}

int main(void) 
{ 
 int n,i,number;
	 
 BIG_INT b; 
 BIG_INT TABLE[1001];
   
 sprintf(TABLE[0].data, "%d", 1 );
 
 for ( i = 1 ; i < 1001; i++ ) {
    sprintf(b.data, "%d", i);
    TABLE[i] = TABLE[i- 1] * b;	
 }
 
 
 while ( cin >> n ) {    
       
    cout << n << "!" << endl;   
    cout << TABLE[n].data << endl;    
 }
 return 0;

} 
