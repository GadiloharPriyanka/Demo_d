#include<iostream.h>
#include<conio.h>
class NODE
{
	 public:
	   int data,ele;
	   NODE *next;
};
class LIST_39
{
      private:
	 NODE *start;
	 NODE *ptr1;
	 NODE *ptr2;
      public:
	 void ADD_FIRST_39(int ele);
	 int DEL_FIRST_39();
	 void ADD_END_39(int ele);
	 int DEL_END_39();
	 void ADD_POS_39(int ele,int pos);
	 int DEL_POS_39(int pos);
	 void LIST_ALL_39();
	 LIST_39();
};
LIST_39::LIST_39()
{
   start=NULL;
}
void LIST_39::ADD_FIRST_39(int ele)
{
    NODE *NEW=new NODE();
    if(NEW==NULL)
    {
	cout<<"\n List is Full ";
    }
    else
    {
	NEW->data=ele;
	NEW->next=NULL;
	NEW->next=start;
	start=NEW;
     }

}
int LIST_39::DEL_FIRST_39()
{
    if(start==NULL)
    {
	cout<<"\n List is Empty";
	return NULL;
    }
    else
    {
	int ele=start->data;
	NODE *TEMP=start;
	start=start->next;
	delete TEMP;
	return ele;
    }
}
void LIST_39::ADD_END_39(int ele)
{
    NODE *NEW=new NODE();
    NEW->data=ele;
    NEW->next=NULL;
    if(NEW==NULL)
    {
	cout<<"\n List is Full ";
	return;
    }
    if(start==NULL)
    {
	 start=NEW;
    }
    else
    {
	 NODE *ptr=start;
	 while(ptr->next!=NULL)
	 {
	       ptr=ptr->next;
	 }
	 ptr->next=NEW;
    }
}
int LIST_39::DEL_END_39()
{
    if(start==NULL)
    {
       cout<<"\n List is Empty";
       return NULL;
    }
    else
    {
       NODE *ptr1=start;
       NODE *ptr2=NULL;
       while(ptr1->next!=NULL)
       {
	   ptr2=ptr1;
	   ptr1=ptr1->next;
       }
      int ele=ptr1->data;
       NODE *TEMP=ptr1;
       if(ptr2!=NULL)
	  ptr2->next=NULL;
       else
	  start=NULL;

      delete TEMP;
      return ele;
    }
}
void LIST_39::ADD_POS_39(int ele,int pos)
{
    NODE *NEW=new NODE();
    NEW->data=ele;
    NEW->next=NULL;
    if(pos==1)
    {
       NEW->next=start;
       start=NEW;
    }
    else
    {
       NODE *ptr1=start;
       NODE *ptr2=NULL;
       int count=1;
       while(count<pos)
       {
	  ptr2=ptr1;
	  ptr1=ptr1->next;
	  count=count+1;
       }
       NEW->next=ptr1;
       ptr2->next=NEW;
    }
}
int LIST_39::DEL_POS_39(int pos)
{
    int ele;
    NODE *TEMP;
    if(start==NULL)
    {
       cout<<"\n List is Empty";
       return NULL;
    }
    else
    {
       if(pos==1)
       {
	  ele=start->data;
	  TEMP=start;
	  start=start->next;
       }
       else
       {
	  NODE *ptr1=start;
	  NODE *ptr2=NULL;
	  int count=1;
	  while(count<pos)
	  {
	    ptr2=ptr1;
	    ptr1=ptr1->next;
	    count=count+1;
	  }
	 ele=ptr1->data;
	 TEMP=ptr1;
	 ptr2->next=ptr1->next;
      }
      delete TEMP;
      return ele;
   }
}
void LIST_39::LIST_ALL_39()
{
    if(start==NULL)
    {
	cout<<"\n List is Empty";
    }
    else
    {
	NODE *ptr;
	ptr=start;
	cout<<endl<<" ";
	while(ptr!=NULL)
	{
	    cout<<ptr->data<<" ";
	    ptr=ptr->next;
	}
    }
}
void MENU()
{
      int opt,ele,pos;
      LIST_39 obj;
      do
      {
	    cout<<"\n 1.ADD_FIRST ";
	    cout<<"\n 2.DEL_FIRST";
	    cout<<"\n 3.ADD_END";
	    cout<<"\n 4.DEL_END";
	    cout<<"\n 5.ADD_POS";
	    cout<<"\n 6.DEL_POS";
	    cout<<"\n 7.LIST_ALL";
	    cout<<"\n 8.EXIT ";
	    cout<<"\n -------------------------";
	    cout<<"\n Eneter Your Choice =>";
	    cin>>opt;

	      switch(opt)
	      {
		 case 1:
		    cout<<"\n ADD Element to List at First => ";
		    cin>>ele;
		    obj.ADD_FIRST_39(ele);
		    break;
		case 2:
		    ele=obj.DEL_FIRST_39();
		    if(ele!=NULL)
		    cout<<endl<<ele<<" is Deleted at First ";
		    break;
		case 3:
		    cout<<"\n Add Element to list at Last=> ";
		    cin>>ele;
		    obj.ADD_END_39(ele);
		    break;
		case 4:
		    ele=obj.DEL_END_39();
		    if(ele!=NULL)
		    cout<<endl<<ele<<"is Deleted at End ";
		    break;
		case 5:
		    cout<<"\n Enter Element=>";
		    cin>>ele;
		    cout<<"\n Enter Position=>";
		    cin>>pos;
		    obj.ADD_POS_39(ele,pos);
		    break;
		case 6:
		    cout<<"\n Enter Position for deletion ";
		    cin>>pos;
		    ele=obj.DEL_POS_39(pos);
		    if(ele!=NULL)
		    cout<<endl<<ele<<"is Deleted at Position";
		    break;
		case 7:
		    obj.LIST_ALL_39();
		    break;
		case 8:
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