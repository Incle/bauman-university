#include <iostream>
#include <conio.h>
using namespace std;
int array[100];
void qs(int *items, int left, int right) //сама сортировка
{
  int i, j;
  int x, y;
 
  i = left; j = right;
  x = items[(left+right)/2];  		 //опорный элемент
 
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;
 
    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);
 
  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
}
void Out(int elem) 
{
    for (int i=1; i<=elem; i++) 
    { 
		cout << array [i] <<" ";
	}
}
int main()
{
    int elements;
    cout << "Enter length of array1"<< endl;
    cin >> elements;
    for (int i=1; i<=elements; i++) 
    {
		cin >> array[i];
	}
    qs(array,0,elements); 
    cout << "Result :";  
    Out (elements);
    getch();
    return 0;
}
