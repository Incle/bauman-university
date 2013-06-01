#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <ctime>
using namespace std;
#define NumberOfStudents 10
#define NumberOfCourses 5
/**
  	@struct		COURSE
	@brief		Structure for queue
  	@param value	Value of element
	@param *next	Link of next element
*/
struct COURSE
{
	int NumberOfCourse;
	COURSE *next;
};
/**
	@struct		LIST0
	@brief		additional structure
*/
struct LIST0
{
	COURSE* next;
	LIST0* lnext;
};
/**
	@struct		LIST
	@brief		Structure for student
  	@param a	number of student
*/
struct LIST
{
	int a;
	LIST0 *cnext;
	LIST *next;
};
/**
	@fn		CreateList(LIST *Current,int i)
   	@brief		Creat a student
	@param Current->a=i	Number of student
	@return		
*/
void CreateList(LIST *Current,int i)
{
	Current->a=i;
	Current->next=NULL;
}	
/**
	@fn		CreateList(COURSE *Current,int i)
   	@brief		Creat list of Currentses
	@return		
*/
void CreateList(COURSE *Current,int i)
{
	Current->NumberOfCourse=i;
	Current->next=NULL;
}
/**
	@fn		GetCount(COURSE *Current,int n)
   	@brief		Get a Current Currentse
	@return		
*/
COURSE* GetCount(COURSE *Current,int n)
{
	for(int i=0;i<n;++i)
	{
		Current=Current->next;
		if(!Current)
		{
			cout<<"error\n";
			return 0;
		}
	}
	return Current;
}
/**
	@fn		PrintList(LIST *Current)
   	@brief		Print students and Currentses on which they going
	@return		
*/
void PrintList(LIST *Current)
{
	Current=Current->next;
	LIST0* list0;
	while(Current)
	{
		list0=Current->cnext;
		cout<<"Student "<<Current->a<<" ";
		Current=Current->next;
		cout<<"Courses ";
		while(list0->lnext)
		{
			cout<<list0->next->NumberOfCourse<<" ";
			list0=list0->lnext;
		}
		cout<<"\n";
	}
	cout<<"\n";
}
/**
	@fn		PrintList0(LIST *Current,COURSE *Current0,LIST *First)
   	@brief		Print students which go on that Currentse
	@return		
*/
void PrintList0(LIST *Current,COURSE *Current0,LIST *First)
{
	Current0=Current0->next;
	while(Current0)
	{
		Current=First;
		Current=Current->next;
		cout<<"Course "<<Current0->NumberOfCourse<<" ";
		cout<<"Students ";
		while(Current)
		{
			LIST0 *list0;
			list0=Current->cnext;
			while(list0->lnext)
			{
				if(list0->next->NumberOfCourse==Current0->NumberOfCourse)
				{
					cout<<Current->a<<" ";
					break;
				}
				list0=list0->lnext;
			}
			Current=Current->next;
		}
		Current0=Current0->next;
		cout<<"\n";
	}
}
void main()
{
	LIST *Current,*First=new LIST;
	COURSE *cCurrent,*cFirst=new COURSE;
	First->cnext=NULL;
	First->next=NULL;
	cFirst->next=NULL;
	srand(time(NULL));
	for(int i=0;i<NumberOfStudents;++i)
	{
		if(First->next)
		{	
			Current->next=new LIST;
			Current=Current->next;
		}
		else
		{
			Current=new LIST;
			First->next=Current;
		}
		CreateList(Current,i);
		Current->cnext=new LIST0;
	}
	Current=First;
	for(int i=0;i<NumberOfCourses;++i)
	{
		if(cFirst->next)
		{	
			cCurrent->next=new COURSE;
			cCurrent=cCurrent->next;
		}
		else
		{
			cCurrent=new COURSE;
			cFirst->next=cCurrent;
		}
		CreateList(cCurrent,i);
	}
	cCurrent=cFirst;
	LIST0* Current0;
	Current=Current->next;
	while(Current)
	{
		Current0=Current->cnext;
		int k1=rand()%4;
		int k=k1+rand()%(NumberOfCourses-k1)+1;
		for(int i=k1;i<k;++i)
		{
			Current0->next=GetCount(cCurrent,i+1);
			Current0->lnext=new LIST0;
			Current0=Current0->lnext;
			Current0->lnext=NULL;
		}
		Current0->lnext=NULL;
		Current=Current->next;
	}
	cCurrent=cFirst;
	Current=First;
	PrintList(Current);
	cout<<"\n";  
	cCurrent=cFirst;
	Current=First;
	PrintList0(Current,cCurrent,First);
	getch();
}
