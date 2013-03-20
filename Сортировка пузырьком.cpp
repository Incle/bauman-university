#include <iostream>
#include <conio.h>
using namespace std;
int array[100];
void Sorting (int elem) 
{ 
    int a=0;  
    for (int i=1; i<=elem; i++)
    {
        for (int j=1; j<=elem-i; j++) 
        {
            if (array [j]>array [j+1]) 
            {
                a=array[j]; 
                array [j]=array [j+1];
                array [j+1]=a;
            }
        }
    }
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
    cout << "Enter length of array"<< endl;
    cin >> elements;
    for (int i=1; i<=elements; i++) 
    {
		cin >> array[i];
	}
    Sorting (elements); 
    cout << "Result :";  
    Out (elements);
    getch();
    return 0;
}
