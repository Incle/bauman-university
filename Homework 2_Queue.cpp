/** 
	@file	Queue.cpp
    	@brief	Example of queue
*/
#include <iostream>
#include <ctime>
using namespace std;
/** 
	@struct		queue
	@brief		Structure for queue
  	@param value	Value of element
	@param *next	Link of next element
*/
struct queue
{
	int value;
	queue *next;
} *first, *last;								/// first and last elements
/** 
	@fn		void add(int value)
   	@brief		Add element to queue
	@param value	Value of the element
	@return			
*/
void add (int value)
{	
	cout<<"\n Add "<<value;
	queue *ex = new queue;
	ex->value = value;
	ex->next = NULL;
	if(first)
	{
		last->next = ex;
		last = ex;
	}
	else
	{
		first = ex;
		last = first;
	}
}
/**
	@fn		void print()
    	@brief		Print queue
	@return	
*/
void print()
{
    queue *ex;
	ex = first;
	cout<<"\nQueue\n";
	while (ex)
	{
		cout<<" "<<ex->value;
		ex = ex->next;
	}
}
/**
	@fn		void deleteElements()
    	@brief		Delete elements of queue
	@return	
*/
void deleteElements()
{   
	queue *ex;
	while(first)
	{
		ex = first->next;
		delete first;
		first = ex;
	}
	cout<<"\nQueue was deleted\n";
}
void main()
{
	int size, ex;
	srand(time(0));
	cout<<"Input number of elements ";
	cin>>size;
	cout<<"\nCreat";
	while (--size)
	{
		ex = rand()%1000;
		add(ex);
	}
	print();						/// print
	deleteElements();					/// delete
	getchar();
}
