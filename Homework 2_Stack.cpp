/**
  	@file			Stack.cpp
  	@brief			Example of stack
*/
#include <iostream>
#include <ctime>
using namespace std;
/**
	@struct		      	stack
	@brief			Structure for elements of stack
 	@param val	  	Value of element
	@param *next	    	Link on next element of stack
	@param *previous	Link on previousious element of stack
*/
struct stack
{
	int val;
	stack *next, *previous;
};
/**
	@fn			void add(int value, stack **element)
  	@brief			Add new element to stack
	@param value	    	Value of element
  	@param **element  	Link on link first element of stack
	@return			
*/
void add(int value, stack **element)
{
	stack *exv = new stack;
	exv->val = value;
	exv->next = (*element)->previous;
	(*element)->previous = exv;
	cout<<"\nAdd "<<value;
}
/**
	@fn			void print_stack(stack *element)
  	@brief			Print
 	@param *element		Link on first element of stack
	@return			
*/
void print(stack *element)
{
  stack *exv = new stack;
  exv = element->previous;
	cout<<"\nStack\n";
	while (exv)
	{
		cout<<exv->val<<" ";
		exv = exv->next;
	}
}
/**
	@fn			void delete_stack(stack *element)
 	@brief			Delete stack
  	@param *element   	Link on first element of stack
	@return			
*/
void delete_stack(stack *element)
{
	cout<<"\nStack was deleted\n";
	while (element->previous)
	{
		stack *exv=element->previous->next;
		delete element->previous;
		element->previous=exv;
	}
}
void main()
{	
	int size,exVal;
	stack *element;
	element = new stack;
	element->previous = NULL;
	cout<<"Input number of elements: ";		/// size of stack
	cin>>size;
	++size;
	while (--size)					/// create elements
	{
		exVal = rand()%1000;
		add(exVal, &element);			/// add element
	}
  cout<<"\nStack was created\n";  
	print(element);					/// print
	delete_stack(element);			      	/// delete
	getchar();
}






