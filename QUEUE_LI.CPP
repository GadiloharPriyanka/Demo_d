#include<iostream.h>
#include<conio.h>
class NODE
{
	 public:
	   int data;
	   NODE *next;
};
class QUEUE
{
      private:
	 NODE *front;
	 NODE *rear;
      public:
	 void ADD(int ele);
	 int DEL();
	 void LIST_ALL();
	 QUEUE();
};
QUEUE::QUEUE()
{
   front=NULL;
}
void QUEUE::ADD(int ele)
{
    NODE *NEW=new NODE();
    NEW->data=ele;
    NEW->next=NULL;
    if(front==NULL)
    {
       front=NEW;
       rear=NEW;
    }
    else
    {
       rear->next=NEW;
       rear=NEW;
    }
}
int QUEUE::DEL()
{
    if(front==NULL)
    {
       cout<<"\n Queue LIST is Empty ";
       return NULL;
    }
    else
    {
       int ele=front->data;
       if(front==rear)
       {
	  front=rear=NULL;
       }
       else
       {
	  front=front->next;
       }
       return ele;
    }
}
void QUEUE::LIST_ALL()
{
    if(front==NULL)
    {
	cout<<"\n List is Empty ";
    }
    else
    {
	NODE *ptr;
	ptr=front;
	cout<<endl<<"  ";
	while(ptr!=NULL)
	{
	   cout<<ptr->data<<"  ";
	   ptr=ptr->next;
	}
    }

}
void MENU()
{
      int opt,ele;
      QUEUE obj;
      do
      {
	    cout<<"\n 1.ADD ";
	    cout<<"\n 2.DELETE";
	    cout<<"\n 3.LIST_ALL";
	    cout<<"\n 4.EXIT ";
	    cout<<"\n -------------------------";
	    cout<<"\n Eneter Your Choice =>";
	    cin>>opt;

	      switch(opt)
	      {
		 case 1:
		    cout<<"\n ADD Element to Stack=> ";
		    cin>>ele;
		    obj.ADD(ele);
		    break;
		case 2:
		    ele=obj.DEL();
		    if(ele!=NULL)
		    cout<<endl<<ele<<" is Deleted";
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