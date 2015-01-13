/* @JUGEN:50418EN 299 C++ */

#include <iostream>

using namespace std;

void bubblesort(int *data, int n);
void swap(int *a, int *b);
int stimes;

int main(void)
{ 
 int times,i,k,n;
 int *data;
 cin >> times;
 for (k = 0 ; k < times ; k++) {
  cin >> n;
  data = new int[n];
  for (i = 0 ; i < n ; i++) {
   cin >> data[i];
  }
  stimes = 0;
  bubblesort(data, n);
  cout << "Optimal train swapping takes " << stimes << "swaps." << endl;
  cout << endl;
 } 
}

void bubblesort(int *data, int n)
{
 int i, j;
 for ( i = 0; i < n ; i++ ) {
  for( j = n - 1 ; j < i ; j-- ) {
   if ( data[j-1] > data[j] ) {
    swap(&data[j], &data[j+1]);
    stimes++;
   } 
  }
 } 
}

void swap(int *a, int *b)
{
 int c;
 c = *a;
 *a = *b;
 *b = c;
}
