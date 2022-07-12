
#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data;
		NODE *next;
		NODE *prev;
};
class C_LINK
{
	NODE *start;
	public:
		C_LINK();
		void MENU();
		void INSERT_FIRST(int);
		void INSERT_LAST(int);
		int DELETE_FIRST();
		int DELETE_LAST();
		void LIST_ALL();
};
C_LINK::C_LINK()
{
	start=NULL;
}
void C_LINK::MENU()
{
	int opt,ele;
	do
	{
		cout<<"\n_________________________________________";
		cout<<"\n 1.Insert the element at First position:";
		cout<<"\n 2.Insert the element at Last position:";
		cout<<"\n 3.DELETE the element at first position:";
		cout<<"\n 4.DELETE the element at Last position:";
		cout<<"\n 5.EXIT";
		cout<<"\n_________________________________________";
		cout<<"\nchoose the option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\n Enter the Element to insert:";
				cin>>ele;
				INSERT_FIRST(ele);
				LIST_ALL();
				break;
			case 2: cout<<"\n Enter the Element to insert:";
				cin>>ele;
				INSERT_LAST(ele);
				LIST_ALL();
				break;
			case 3:	ele=DELETE_FIRST();
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				LIST_ALL();
				break;
			case 4:	ele=DELETE_LAST();
				if(ele)
				{
					cout<<ele<<"is deleted\n";
				}
				LIST_ALL();
				break;
			case 5: return;
			default: cout<<"\nInvalid Option";
				 break;


		}

	}while(1);
}
void C_LINK::INSERT_FIRST(int ele)
{
	NODE *New=new NODE();
	if(New==NULL)
	{
		cout<<"\nList is full";
	}
	New->data=ele;
	if(start==NULL)
	{
		start=New;
		New->next=start;
		New->prev=start;
	}
	else
	{
		NODE *ptr=new NODE();
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		New->next=start;
		New->prev=ptr;
		start->prev=New;
		ptr->next=New;
	}
}
void C_LINK::INSERT_LAST(int ele)
{
	NODE *New=new NODE();
	if(New==NULL)
	{
		cout<<"\nList is full";
	}
	New->data=ele;
	if(start==NULL)
	{
		start=New;
		New->next=start;
		New->prev=start;
	}
	else
	{
		NODE *ptr=start;
		while(ptr->next!=start)
			ptr=ptr->next;
		New->next=start;
		New->prev=ptr;
		start->prev=New;
		start=New;
		ptr->next=New;
	}
}
int C_LINK::DELETE_FIRST()
{
	if(start==NULL)
	{
		cout<<"\nList is Empty";
		return NULL;
	}
	NODE *ptr=start;
	NODE *prev=NULL;
	while(ptr->next!=start)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	int ele=ptr->data;
	if(ptr==start)
	{
		start=NULL;
	}
	else
	{
		prev->next=start;
		start->prev=prev;
	}
	delete ptr;
	return ele;
}
int C_LINK::DELETE_LAST()
{
	if(start==NULL)
	{
		cout<<"\nList is Empty";
		return NULL;

	}
	int ele=start->data;
	NODE *ptr=new NODE();
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	NODE *temp=start;
	if(ptr==start)
		start=NULL;
	else
	{
		ptr->next=start->next;
		start=start->next;
		start->prev=ptr;
	}
	delete temp;
	return ele;
}
void C_LINK::LIST_ALL()
{
	/*NODE *ptr=new NODE();
	if(start==NULL)
	{
		cout<<"\nList is empty";
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" | ";
			ptr=ptr->next;
		}
	}       */
	NODE *ptr=new NODE();
	NODE *last=new NODE();
	ptr=start;
	if(ptr!=NULL)
	{
		cout<<"\nElements of the List are:";
		while(ptr->next!=start)
			ptr=ptr->next;
		last=ptr;
		do
		{
			cout<<ptr->data<<" | ";
			ptr=ptr->prev;
		}while(ptr!=last);
	}
	else
		cout<<"\nList is Empty";
}
void main()
{
	clrscr();
	C_LINK c1;
	c1.MENU();
	getch();
}