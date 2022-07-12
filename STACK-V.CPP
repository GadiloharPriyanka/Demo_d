#include<iostream.h>
#include<conio.h>
class stack
{
	private:
		int *a,s,top;
	public:
		stack(int);
		void PUSH(int ele);
		int POP();
		void LIST_ALL();
};
stack::stack(int n)
{
	s=n;
	top=0;
	a=new int[s+1];
}
void stack::PUSH(int ele)
{
	if(top==s)
	{
		cout<<"\n stack is OVERFLOW";
		return;
	}
	top=top+1;
	a[top]=ele;
}
int stack::POP()
{
	if(top==0)
	{
		cout<<"\nstack is Empty ";
		return(NULL);
	}
	int ele=a[top];
	top=top-1;
	return(ele);
}
void stack::LIST_ALL()
{
	if(top==0)
	{
		cout<<"\n Stack is empty";
	}
	else
	{
		cout<<"\Element in stack are ";
		for(int i=top;i>=1;i--)
		{
			cout<<a[i]<<" ";
		}
	}
}
void MENU()
{
	int opt,ele,size;
	cout<<"\n size of stack:";
	cin>>size;
	stack obj(size);
	do
	{
		cout<<"\n1: PUSH";
		cout<<"\n2: POP";
		cout<<"\n3: LIST";
		cout<<"\n4: exit";
		cout<<"\n enter your choice:";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n enter element to add:";
				cin>>ele;
				obj.PUSH(ele);
				break;
			case 2:
				ele=obj.POP();
				cout<<endl<<ele<<"\n is deleted:";
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
	clrscr();
	MENU();
	getch();
}
