#include<iostream.h>
#include<conio.h>
class QUEUE
{
	private:
		int *A,s,front,rear,ele;
	public:
		QUEUE(int);
		void ADD(int ele);
		int DEL();
		void LIST_ALL();
};
QUEUE::QUEUE(int par)
{
	s=par;
	front=rear=0;
	A=new int[s+1];
}
void QUEUE::ADD(int ele)
{
	if(rear==s)
	{
		cout<<"\n QUEUE is FULL";
		return;
	}
	else
	{
		if(front==0)
		{
			front=1;
		}
		rear=rear+1;
		A[rear]=ele;
	}
}
int QUEUE::DEL()
{
	if(front==0)
	{
		cout<<"\n Queue is EMPTY";
		return(NULL);
	}
	int ele=A[front];
	if(front==rear)
	{
		front=rear=0;
	}
	else
	{
		front=front+1;
	}
	cout<<"\n element is deleted";
	return(ele);
}
void QUEUE::LIST_ALL()
{
	if(front==0)
	{
		cout<<"\n Queue is empty";
		return;
	}
	else
	{
		cout<<"\n element in queue are";
		for(int i=front;i<=rear;i++)
		{
			cout<<A[i]<<" ";
		}
	}
}
void MENU()
{
	int opt,ele,size;
	cout<<"\n size of Queue:";
	cin>>size;
	QUEUE obj(size);
	do
	{       cout<<"\n\n...........................";
		cout<<"\n1: ADD";
		cout<<"\n2: DELETE";
		cout<<"\n3: LIST";
		cout<<"\n4: exit";
		cout<<"\n Enter your choice: ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n enter element to add:";
				cin>>ele;
				obj.ADD(ele);
				obj.LIST_ALL();
				break;
			case 2:
				int ele=obj.DEL();
				cout<<endl<<ele<<"\n is deleted:";
				obj.LIST_ALL();
				break;
			case 3:
				obj.LIST_ALL();
				break;
			case 4:
				return;
			default:
				cout<<"\n INVALID OPTION:";
		}
	}while(1);
}
void main()
{
	int ele;
	clrscr();
	MENU();
	getch();
}
