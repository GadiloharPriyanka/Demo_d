#include<iostream.h>
#include<conio.h>
class NODE
{
	public:
		int data,pri;
		NODE *next;
};

class QUEUE
{
	NODE  *front,*rear;
	public:
		QUEUE();
		void MENU();
		void Q_INSERT(int,int);
		int Q_DELETE();
		void LIST_ALL();
};
QUEUE::QUEUE()
{
	front=NULL;
	rear=NULL;
}
void QUEUE::MENU()
{
	int ele;
	int opt,pos,pri;
	do
	{
		cout<<"\n------------------------------";
		cout<<"\n 1. Insert node @ into Queue";
		cout<<"\n 2. Delete node @ from Queue";
		cout<<"\n 3.Exit";
		cout<<"\n------------------------------";
		cout<<"\nChoose any option:";
		cin>>opt;
		switch(opt)
		{
			case 1: cout<<"\nEnter element to insert:";
				cin>>ele;
				cout<<"\nEnter the priority:";
				cin>>pri;
				Q_INSERT(ele,pri);
				LIST_ALL();
				break;
			case 2: ele=Q_DELETE();
				if(ele)
				cout<<ele<<"is Deleted\n";
				LIST_ALL();
				break;
			case 3:
				Q_LIST_ALL();
				break;
			case 4:
				return;
			default:cout<<"\nInvalid option:\n";
		}
	}while(1);
}
void QUEUE::Q_INSERT(int ele,int prio)
{
	NODE *New=new NODE();
	NODE *P;
	if(New==NULL)
	{
		cout<<"\nQueue is full";
	}
	else
	{
		New->pri=prio;
		New->data=ele;
		New->next=NULL;
		if(front==NULL)
		{
			rear=New;
			front=New;
		}
		else
		{
			P=front;
			while(P->next!=NULL && P->next->pri<=prio)
			{
				P=P->next;
			}
			if(New->pri<front->pri)
			{
				New->next=front;
				front=New;
			}
			else
			{
				New->next=P->next;
				P->next=New;
				if(New->pri>rear->pri)
					rear=New;
			}
		}
	}
}
int QUEUE::Q_DELETE()
{
	if(front==NULL)
	{
		cout<<"\nQueue is Empty";
		return NULL;
	}
	else
	{
		int ele;
		ele=front->data;
		front=front->next;
		return ele;
	}
}
void QUEUE::LIST_ALL()
{
	NODE *ptr=front;
	while(ptr!=NULL)
	{
		cout<<"\n"<<ptr->data<<"  "<<ptr->pri;
		ptr=ptr->next;
	}
}
void main()
{
	clrscr();
	QUEUE q1;
	q1.MENU();
	getch();
}

