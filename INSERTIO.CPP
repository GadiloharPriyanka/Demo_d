#include<iostream.h>
#include<conio.h>

class INSERTION
{
     private:
	int A[10],n,i,j,ele,temp,ptr;
     public:
       void GET();
       void PROCESS();
       void DISPLAY();
};
void INSERTION::GET()
{
     cout<<"\n Enter the Range :";
     cin>>n;
     cout<<"\n Element are =>";
     for(i=1;i<=n;i++)
     cin>>A[i];
}
void INSERTION::PROCESS()
{
     for(i=2;i<=n;i++)
     {
	ele=A[i];
	j=i-1;
	while(ele<A[j])
	{
	   A[j+1]=A[j];
	   j--;
	}
	A[j+1]=ele;
     }
}
void INSERTION::DISPLAY()
{
     cout<<"\n Sorted element using Insertion sort:\n\t =>";
     for(i=1;i<=n;i++)
     cout<<A[i]<<" ";

}
void main()
{
     clrscr();
     INSERTION s;
     s.GET();
     s.PROCESS();
     s.DISPLAY();
     getch();
}
