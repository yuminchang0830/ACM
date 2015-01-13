/* @JUDGE_ID:50418EN 338 C++ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
using namespace std;
#define max_l 150



char DATA[11][80];

int h;

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
 h = 0;
 n1 = strlen( (*this).data );
 n2 = strlen( multiend.data ); 
 
 
 
 for ( i = n2 - 1, z = 0, h = 0; i >= 0 ; i--, z++ ,h++) {
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
   
   sprintf(DATA[h], "%s", temp.data);
   DATA[h][j] = '\0';
   
   for (s = 0 ; s < z ; s++ ) {
      temp.data[j + s] = '0';
   }      
   temp.data[j + s ] = '\0';   
   
   product = product + temp;
   } else {
     sprintf(DATA[h], "%d", 0);   	
   }
 } 
 return product;
}

int main(void) 
{ 
 int i,j,flag = 0;
 int n1, n2, n3,max,max2; 
 BIG_INT a,b,c;

     
/*
	freopen("p338_in.txt", "r", stdin);
	freopen("p338_out.txt", "w", stdout);
*/

 while (cin >> a.data  >> b.data ) {
 	
 n1 = strlen(a.data);
 n2 = strlen(b.data);	
 	
 for ( i = 0 ; a.data[i] == '0' && i < (n1-1) ; i++ ) {
 }
 for ( j = 0 ; j < (n1 - i + 1) ; j++ ) {
    a.data[j] = a.data[j+i];	
 }
 
 for ( i = 0 ; b.data[i] == '0' && i < (n2-1) ; i++ ) {
 }
 for ( j = 0 ; j < (n2 - i + 1) ; j++ ) {
    b.data[j] = b.data[j+i];	
 }
 
 n1 = strlen(a.data);
 n2 = strlen(b.data);

 c = a * b;
 
 n3 = strlen(c.data);
 
 flag = 0;
 for ( i = 0 ; i < n2 ; i++ ) {
    if (b.data[i] > '0' ) {
      flag++;
    }
 }
 
 /*
 
 for ( i = 0 ; i < n1 ; i++ ) {
    if (a.data[i] > '0' ) {
       flag++;
    }	
 }
 if ( flag > 1 ) {
    flag = 0;
   	
 } 
 */
 
 if (n1 >= n2 ) {
  max = n1;
 } else {
  max = n2;
 }
 
 if ( strcmp(a.data, "0") == 0 || strcmp(b.data, "0") == 0) { 
    max2 = max;
 } else {
    max2 = n3;
 } 
 cout.width(max2);
 cout <<  a.data << endl; 
 cout.width(max2);
 cout <<  b.data << endl; 
 
 
 cout.width(n3-max+1);
 cout << "-";
 
 for(i = 1 ; i < max ; i++ ) {
  cout << "-";
 } 
 
 cout << endl;
 
 if (flag > 1 && !( strcmp(a.data, "0") == 0 || strcmp(b.data, "0") == 0)) {
  for(i = 0 ; i < h ; i++ ) {
   cout.width(n3 - i);
   if ( strcmp(DATA[i], "0" ) != 0 ) {
    cout <<  DATA[i] << endl;
   }
  }
   for(i = 0 ; i < n3 ; i++ ) {
   cout << "-";
  }
  cout << endl;
 }
 
 if ( strcmp(a.data, "0") == 0 || strcmp(b.data, "0") == 0) {    
    cout.width(max);
    cout << "0" << endl;
 } else {       	 
    cout << c.data << endl;    	
 }
 
 cout << endl;
 
 }
 return 0;
} 
