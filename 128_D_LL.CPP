
#include<iostream.h>
#include<conio.h>
class NODE_128
{
	public:
		int data;
		NODE_128 *next;
		NODE_128 *prev;
};
class LIST_128
{
		private:
			NODE_128 *start;
		public:
			LIST_128();
			void ADD_FIRST_128(int ele);
			int DEL_FIRST_128();
			void ADD_END_128(int ele);
			int DEL_END_128();
			void ADD_POS_128(int ele,int pos);
			int DEL_POS_128(int pos);
			void LIST_ALL_128();

};
void LIST_128::LIST_128()
{
		start=NULL;
}
void LIST_128::ADD_FIRST_128(int ele)
{
		//create a node
		NODE_128 *NEW =new NODE_128();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		NEW->prev=NULL;
		//set the link
		NEW->next=start;
		if(start!=NULL)
		{
			start->prev=NEW;
		}
		start=NEW;

}
int LIST_128::DEL_FIRST_128()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	int ele=start->data;
	NODE_128 *TEMP=start;
	start=start->next;
	if(start!=NULL)
	{
		start->prev=NULL;
	}
	delete TEMP;
	return ele;

}
void LIST_128::ADD_END_128(int ele)
{
		//create a node
		NODE_128 *NEW =new NODE_128();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		NEW->prev=NULL;
		//set the link
		NODE_128 *ptr;
		if(start==NULL)
		{
			start=NEW;
		}
		else
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=NEW;
			NEW->prev=ptr;

}
int LIST_128::DEL_END_128()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	NODE_128 *ptr1=start;
	NODE_128 *ptr2=NULL;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	int ele=ptr1->data;
	NODE_128 *Temp=ptr1;
	if(ptr2==NULL)
		start=NULL;
	else
	{
		ptr2->next=NULL;
	}
	delete Temp;
	return ele;
}
void LIST_128::ADD_POS_128(int ele,int pos)
{
		//create a node
		NODE_128 *NEW =new NODE_128();
		if(NEW==NULL)
		{
			cout<<"LIST is full";
			return;
		}
		//fill up the data
		NEW->data= ele;
		NEW->next=NULL;
		if(start==NULL)
			start=NEW;
		//Assuming given 'pos' in valid
		int count;
		if(pos==1)
		{
			NEW ->next=start;
			start->prev=NEW;
			start=NEW;
		}
		else
		{
			NODE_128 *ptr1=start;
			NODE_128 *ptr2=NULL;
			count=1;
			while(count<pos)
			{
				ptr2=ptr1;
				ptr1=ptr1->next;
				count=count+1;
			}
			NEW ->next=ptr1;
			ptr2->next=NEW;
			if(ptr1!=NULL)
			{
				ptr1->prev=NEW;
			}
			NEW ->prev=ptr2;
			ptr2->next=NEW;
		}
}
int LIST_128::DEL_POS_128(int pos)
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
		return NULL;
	}
	NODE_128 *Temp;
	int ele;
	//search a node
	if(start->next==NULL)
	{
		ele=start->data;
		Temp=start;
		start=start->next;
		start->prev=NULL;
	}
	if(pos==1)
	{
		ele=start->data;
		Temp=start;
		start=start->next;
		start->prev=NULL;
	}
	else
	{
		NODE_128 *ptr1=start;
		NODE_128 *ptr2=NULL;
		int count=1;
		while(count<pos)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
			count=count+1;
		}
		ele=ptr1->data;
		Temp=ptr1;
		ptr2->next=ptr1->next;
		if(ptr1->next!=NULL)
		{
			ptr1->next->prev=ptr2;
		}
	}
	delete Temp;
	return ele;
}

void LIST_128:: LIST_ALL_128()
{
	if(start==NULL)
	{
		cout<<"LIST is empty";
	}
	NODE_128 *ptr;
	ptr=start;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
void MENU()
{
		LIST_128 obj;
		int opt,ele,pos;
		do
		{
			cout<<"\n 1. ADD_FIRST";
			cout<<"\n 2. DEL_FIRST";
			cout<<"\n 3. ADD_END";
			cout<<"\n 4. DEL_END";
			cout<<"\n 5. ADD_POS";
			cout<<"\n 6. DEL_POS";
			cout<<"\n 7. LIST_ALL";
			cout<<"\n 8.EXIT";
			cout<<"\n Enter your option: ";
			cin>>opt;

			switch(opt)
			{
				case 1:
					cout<<"Enter your elemet: ";
					cin>>ele;
					obj.ADD_FIRST_128(ele);
					break;
				case 2:
					ele=obj.DEL_FIRST_128();
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 3:
					cout<<"Enter your elemet: ";
					cin>>ele;
					obj.ADD_END_128(ele);
					break;
				case 4:
					ele=obj.DEL_END_128();
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;
				case 5:
					cout<<"Enter your position: ";
					cin>>pos;
					obj.ADD_POS_128(ele,pos);
					break;
				case 6:

					cout<<"Enter your Position=>: ";
					cin>>ele;
					cout<<"Enter your Position=>: ";
					cin>>pos;
					ele=obj.DEL_POS_128(pos);
					if(ele != NULL)
					{
						cout<<ele<<"is deleted";
					}
					break;				case 7:
					obj.LIST_ALL_128();
					break;
				case 8:
					return;
				default:
					cout<<"INVALID OPTION";
				}

		}while(1);

}
void main()
{
	clrscr();
	MENU();
	getch();
}


