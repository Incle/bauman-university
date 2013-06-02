/**
  @brief Realisation of Dijkstra's algorithm... find the shortest ways in graph from one top... and show distance of the shortest way 
*/
#include <stdint.h>
#include <iostream>

using namespace std;
#define NUMBER 6 ///number of tops of graph


int main() {
    int root[NUMBER], top = 0, D[NUMBER],i,k,j,mindistance;
    bool point[NUMBER];
    int A[NUMBER][NUMBER] =									///Example of graph
	{		
        {0, 7, 9, 14, INT16_MAX, INT16_MAX},
        {7, 0, 10, INT16_MAX, INT16_MAX, 15},
        {9, 10, 0, 2, INT16_MAX, 11},
        {14, INT16_MAX, 2, 0, 9, INT16_MAX},
        {INT16_MAX, INT16_MAX, INT16_MAX, 9, 0, 6},
        {INT16_MAX, 15, 11, INT16_MAX, 6, 0}
    };
    for (int i = 0; i < NUMBER; ++i) 
	{ 
		D[i] = A[top][i];
        root[i] = top;
        point[i] = false;
    }
    point[top] = true;				///distance from 0 to 0
    root[top] = 0;
    for (i = 0; i < NUMBER - 1; ++i) 
	{
        k = 0;
		mindistance = INT16_MAX;
										
        for (int j = 0; j < NUMBER; j++)		///Find the shortest way
		{
            if ( (mindistance > D[j])&&(!point[j]))
			{	
				k = j;
                mindistance = D[j];
            }
        }
        point[k] = true;						/// Point top k
		for (j = 0; j < NUMBER; ++j)			/// use distance for top j if way on root A[k][j] shorter then was found before
		{
            if ((D[j] > D[k] + A[k][j])&&(!point[j]) ) 
			{
				root[j] = k;
                D[j] = D[k] + A[k][j];
            }
        }
    }
    cout<<"Way\n";		///print way in back order
    for (i = NUMBER; i > top + 1; --i) 
	{
        cout<<"From "<<i - 1<<" to "<< top<<" = ";
        for (j = i - 1; j > top;) 
		{
            cout<<j<<" ";
            j = root[j];
        }
        cout<<top<<"\n";
    }
	cout<<"Distance\n";				///print distance
    for (i = 0; i < NUMBER; i++) 
	{
        cout<<"From "<<top<<" to "<<i<<" = "<< D[i]<<"\n";
    }
    return (0);
}
