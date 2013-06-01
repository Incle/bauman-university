/**
 	 @file	List.cpp
 	 @brief	Example of list
*/
#include <iostream>
#include <ctime>
using namespace std;
/**
	@struct	list
	@brief			Struct for list
    	@param value		Value of element
	@param *next		Pointer to next element of list
*/
struct list
{
	int value;
	list *next;
};
/** 
	@fn			void print(list *Element)
    	@brief			Print list
    	@param *Element		Link on first element of list
	@return		
*/
void print(list *Element)
{
	cout<<"\nList \n";
	while (Element)
	{
		cout<<Element->value<<" ";
		Element = Element->next;
	}
}
/** 
	@fn			void deleteList(list *linkOfElement, list *Element)
    	@brief			Delete list
    	@param *linkOfElement	Link on link of first element of list
   	@param *Element	Link on first element of list
	@return			
*/
void deleteList(list *linkOfElement, list *Element)
{
	while (linkOfElement)
	{
		Element = linkOfElement;
		linkOfElement = linkOfElement->next;
		delete Element;
	}
	cout<<"\nList was deleted\n";
}
void main()
{	
	srand(time(0));
	int size;					/// number of elements
	list *Element,*linkOfElement = NULL;
	cout<<"Input number of elements ";
	cin>>size;
	++size;
	while (--size)					/// create elements of list
	{
		Element = new list;
		Element->value = rand()%1000;
		Element->next = linkOfElement;
		linkOfElement = Element;
	}
	cout<<"List was created \n";
	print(Element);					/// print list
	deleteList(linkOfElement, Element);		/// delete list
	getchar();
}


