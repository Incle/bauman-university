#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <ctime>
using namespace std;

#define Number 16
/** 
  	@struct		queue
	@brief		Structure for queue
  	@param value	Value of element
	@param *next	Link of next element
*/
struct Element
{
	int value;
	int priority;
	bool create;

};
/** 
	@class		queue
  	@param	element[Number]	array of 
	@param level	Namber of layer of element
*/
class Queue
{
	Element element[Number];
	int level;
public:
	Queue()
	{
		for(int i=0;i<Number;++i)
		{
			element[i].create=0;
		}
		level=0;
	}
	/** 
		@fn		int GetValue(int i)
   		@brief		Get value of element
		@return	int		
	*/
	int GetValue(int i)
	{
		return element[i].value;
	}
	/** 
		@fn		void add(int c,int c1)
   		@brief		Add element to queue
		@return			
	*/
	void add(int c,int c1)
	{
		int g=1,k=0;
		while(1)
		{
			if(k*g>Number)
			{
				if(level<3)
				{
					++level;
					g=1;
				}
				else
				{
					cout<<"tree is full\n";
					return;
				}
			}
			k=(Number+1)/pow(2.,level+1);
			if(element[k*g].create)
			{
				++g;
			}
			else
			{
				element[k*g].value=c;
				element[k*g].create=1;
				element[k*g].priority=c1;
				queue(k*g);
				return;
			}
		}

	}
	/** 
		@fn		int Checklevel(int k,int g)
   		@brief		check layer of element
		@return int			
	*/
	int Checklevel(int k,int g)
	{

		int i=level;
		for(int x=1;x<10;++x)
		{
			if(Number-k*g==x*pow(2.,4-i))
			{
				return 1;
			}
		}

		return 0;
	}
	/** 
		@fn		DeleteElem()
   		@brief		delete element from queue
		@return			
	*/
	void DeleteElem()
	{
		int g=1,k=0;

		if((!level)&&(!element[(Number+1)/2].create))
		{
			cout<<"tree is empty\n";
			return;
		}


		while(1)
		{
			k=(Number+1)/pow(2.,level+1);
			if((element[Number-k*g].create)&&(!Checklevel(k,g)))
			{
				element[Number-k*g].create=0;
				if(Number-k*(g+1)<1)
				{
					--level;
				}
				return;
			}
			else
			{
				++g;
				if(k*g>=Number)
				{
					element[k*(g-1)].create=0;
				}
			}

		}
	}
	/** 
		@fn		PrintTree()
   		@brief		print tree
		@return			
	*/
	void PrintTree()
	{
		for(int i=0;i<Number;++i)
		{
			if(element[i].create)
			{
				cout<<" "<<element[i].value;
			}
		}
		cout<<"\n";
	}
	/** 
		@fn		void queue(int n1)
   		@brief		Add element to queue
		@return			
	*/
	void queue(int n1)
	{
		int l1=level-1,g=1,k=0,m=n1,m1;
		while(l1>=0)
		{
			if(k*g>Number-1)
			{
				return;
			}
			k=(Number+1)/pow(2.,l1+1);
			if(k*(g-0.5)==m)
			{
				m1=k*g;
				if(element[m1].priority<element[m].priority)
				{
					Element dl;
					dl=element[m1];
					element[m1]=element[m];
					element[m]=dl;
					--l1;
					g=1;
					m=m1;
					continue;
				}
			}
			else
			{
				if(k*(g+0.5)==m)
				{
					m1=k*g;
					if(element[m1].priority<element[m].priority)
					{
						Element dl;
						dl=element[m1];
						element[m1]=element[m];
						element[m]=dl;
						--l1;
						g=1;
						m=m1;
						continue;
					}
				}
			}
			++g;
		}
	}

};
void main()
{
	srand(time(0));
	Queue queue1;
	int n;
	while(1)
	{
		cout<<"1 - add elem\n2 - print tree\n3- delete elem\n";
		cin>>n;
		switch(n)
		{
		case 1:
			int number,priority;
			cout<<"New elem\n";
			cin>>number;
			cout<<"Priority\n";
			cin>>priority;
			queue1.add(number,priority);
			break;
		case 2:
			queue1.DeleteElem();
			break;
		case 3:
			queue1.PrintTree();
			break;
		}
	}
}
	
