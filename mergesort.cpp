#define Size 100
#define lineLenght 5 ///number of numbers in output line
#include <iostream>
#include <ctime>
using namespace std;
void swop(int *a, int *b)
{
  *a+=*b;
	*b=*a-*b;
	*a-=*b;
}
/**
@function merge_sort 
divides an array on two and recursively sort them
@param massiv[] source array
@param left left limit of sort array
@param right right limit of sort array
*/
void merge_sort(int massiv[], int left, int right)
{
	int middle = (left+right)/2; 
	int sizeofanswer = right-left+1;; 
	int i = left-left, j = middle+1-left, k = left;
	if (sizeofanswer > 2)
	{
		merge_sort(massiv,left,middle);
		merge_sort(massiv,middle+1,right);
		int *temp = new int[sizeofanswer];
		for (int t = 0, y = left; t < sizeofanswer; t++, y++)
		{
			temp[t] = massiv[y];
		}
		for (; (i <= middle-left)&&(j <= (right-left)); k++)
		{
			if (temp[i]<=temp[j])
			{
				massiv[k] = temp[i];
				i++;
			}
			else
			{
				massiv[k] = temp[j];
				j++;
			}
		}
		if (i == middle+1)
		{
			for (;(j <= right-left); j++, k++)
				{
          massiv[k] = temp[j];
        }
		}
		else
		{
			for (; (i <= middle-left); i++, k++)
				{
          massiv[k] = temp[i];
        }
		}

		delete temp;

	}
	else
	{
		if (sizeofanswer == 2)
		{
			if(massiv[left] > massiv[right])
				{
          swop(&massiv[left],&massiv[right]);
        }
		}
	}
}
/**
@function print
print array on screen
@param *a array
@param size size of array
@param lenght number of numbers in output line
*/
void print(int *massiv, int size, int lenght)
{
	lenght++;
	for (int i = 0; i < size; i++)
	{
		cout << massiv[i];
		if ((massiv[i]>=0)&&(massiv[i]<1000)) ///for equalent space for different numbers on screen
		{
			cout <<" ";
		}
		if ((massiv[i]>=0)&&(massiv[i]<100))
		{
			cout <<" ";
		}
		if ((massiv[i]>=0)&&(massiv[i]<10))
		{
			cout <<" ";
		}
		if (!((i+1) % lenght))
			{
        cout << "\n";
      }
	}
	cout << "\n\n";
}
void main()
{
	int *massiv = new int[Size];
	srand(time(NULL));
	for (int i = 0; i < Size; i++)
	{
		massiv[i] = rand() % 1000; ///for small numbers
	}
	print(massiv, Size, lineLenght);
	merge_sort(massiv, 0, Size-1);
	print(massiv, Size, lineLenght);
	delete massiv;
}
