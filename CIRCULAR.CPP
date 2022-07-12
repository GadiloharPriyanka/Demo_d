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
	if((front==1 && rear==s)||(rear+1==front))
	{
		cout<<"\n QUEUE is FULL";
		return;
	}
	if(front==0)
		front=front+1;
	if(rear==s)
		rear=0;
	rear=rear+1;
	A[rear]=ele;
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
	{       if(front==s)
			front=0;
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
	cout<<"\n element in queue are";
	if(front<=rear)
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<A[i]<<" ";
		}
	}
	else
	{
		for(int i=front;i<=s;i++)
		{
			cout<<A[i]<<" ";
		}
		for(i=1;i<=rear;i++)
		{
			cout<<A[i]<<" " ;
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
