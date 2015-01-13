/* @JUDGE_ID:50418EN 623 C++ */
#include <iostream.h> 
using namespace std;

void solve(int [],int); 
void out(int []); 

void solve(int N[],int A) 
{ 
int intT; 
int intIF=0; 
int intS=0; 

for (intT=2999 ;intT>=0 ;intT--) 
{ 
N[intT]*=A; 

if (intIF!=0) 
intS=intIF; 
else 
intS=0; 

if (N[intT]>=10000) 
{ 
intIF=(N[intT]/10000); 
N[intT]%=10000; 
} 
else 
intIF=0; 

N[intT]+=intS; 
} 
} 

void out (int N[]) 
{ 
int intOK=0; 
int intT; 

for (intT=0 ;intT<3000 ;intT++) 
{ 
if (intOK==0 && intT==2999) 
cout << N[intT]; 
else if (intOK==0 && N[intT]==0) 
continue; 
else if (intOK==0 && N[intT]!=0) 
{ 
intOK=1; 
cout << N[intT]; 
} 
else 
{ 
if (N[intT]<10) 
cout << "000" << N[intT]; 
else if (N[intT]<100) 
cout << "00" << N[intT]; 
else if (N[intT]<1000) 
cout << "0" << N[intT]; 
else 
cout << N[intT]; 
} 
} 
} 

int main() 
{ 
int intN,i; 
int intNumber[3000]; 
int intT; 
int TABLE[1001][3000];

for (intT=0 ;intT<2999 ;intT++) {
  intNumber[intT]=0; 
  TABLE[0][intT] = 0;
  TABLE[1][intT] = 0;
}
intNumber[2999] = 1; 
TABLE[0][2999] = 1;
TABLE[1][2999] = 1;

for (intT=1 ;intT <=1000 ;intT++)  {	
 solve(intNumber,intT);
 for ( i = 0; i < 3000; i++ ) {
  TABLE[intT][i] = intNumber[i]; 	
 }
}

while (cin >> intN) 
{
cout << intN << "!" << endl; 
out(TABLE[intN]); 
cout << endl; 
}


return 0; 


}