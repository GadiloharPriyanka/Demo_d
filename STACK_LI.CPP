#include<iostream.h>
#include<conio.h>
class NODE
{
	 public:
	 int data;
	 NODE *next;
};
class STACK
{
      private:
	 NODE *top;
      public:
	 void PUSH(int ele);
	 int POP();
	 void LIST_ALL();
	 STACK();
};
STACK::STACK()
{
   top=NULL;
}
void STACK::PUSH(int ele)
{
    NODE *NEW=new NODE();
    NEW->data=ele;
    NEW->next=NULL;
    NEW->next=top;
    top=NEW;
}
int STACK::POP()
{
    if(top==NULL)
    {
       cout<<"\n LIST is Empty ";
       return NULL;
    }
    else
    {
       int ele=top->data;
       NODE *TEMP=top;
       top=top->next;
       delete TEMP;
       return ele;
    }
}
void STACK::LIST_ALL()
{
    if(top==NULL)
    {
	cout<<"\n List is Empty ";
    }
    else
    {
	NODE *ptr;
	ptr=top;
	while(ptr!=NULL)
	{
	   cout<<ptr->data<<" ";
	   ptr=ptr->next;
	}
    }

}
void MENU()
{
      int opt,ele;
      STACK obj;
      do
      {
	    cout<<"\n PUSH ";
	    cout<<"\n POP";
	    cout<<"\n LIST_ALL";
	    cout<<"\n EXIT ";
	    cout<<"\n -------------------------";
	    cout<<"\n Eneter Your Choice =>";
	    cin>>opt;

	      switch(opt)
	      {
		 case 1:
		    cout<<"\n ADD Element to Stack=> ";
		    cin>>ele;
		    obj.PUSH(ele);
		    break;
		case 2:
		    ele=obj.POP();
		    if(ele!=NULL)
		    cout<<endl<<ele<<" Deleted";
		    break;
		case 3:
		    obj.LIST_ALL();
		    break;
		case 4:
		      return;
		default:
		    cout<<"\n Invalid choice";
		    break;
	       }
	}while(1);
}
void main()
{
      clrscr();
      MENU();
      getch();
}