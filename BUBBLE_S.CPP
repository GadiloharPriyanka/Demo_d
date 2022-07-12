#include<iostream.h>
#include<conio.h>

class BUBBLE
{
     private:
	int A[10],i,EXCH,j,n,TEMP;
     public:
	void GET();
	void PROCESS();
	void DISPLAY();
};
void BUBBLE::GET()
{
     cout<<"\n Enter the array size :";
     cin>>n;
     cout<<"\n Enter the array element =>";
     for(i=1;i<=n;i++)
     cin>>A[i];
}
void BUBBLE::PROCESS()
{

     for(i=1;i<=n-1;i++)
     {
	 EXCH=0;
	 for(j=1;j<=n-1;j++)
	 {
	     if(A[j]>A[j+1])
	     {
		 TEMP=A[j];
		 A[j]=A[j+1];
		 A[j+1]=TEMP;
		 EXCH=EXCH+1;

	     }
	 }
     }
}
void BUBBLE::DISPLAY()
{
     cout<<"\n The array element are =>";
     for(i=1;i<=n;i++)
       cout<<A[i]<<"\t";
}
void main()
{
     clrscr();
     BUBBLE b;
     b.GET();
     b.DISPLAY();
     b.PROCESS();
     cout<<"\n After sorting: ";
     b.DISPLAY();
     getch();
}
