#include<iostream.h>
#include<conio.h>

class SELECTION
{
     private:
	int A[10],i,Pos_min,j,n,TEMP;
     public:
       void GET();
       void PROCESS();
       void DISPLAY();
};
void SELECTION::GET()
{
     cout<<"\n Enter the array size :";
     cin>>n;
     cout<<"\n Enter the array element =>";
     for(i=1;i<=n;i++)
     cin>>A[i];
}
void SELECTION::PROCESS()
{
     for(i=1;i<=n-1;i++)
     {

	Pos_min=i;
	for(j=i+1;j<=n;j++)
	{
	   if(A[j]<A[Pos_min])
	   Pos_min=j;
	}
	if(Pos_min!=i)
	{
	   TEMP=A[Pos_min];
	   A[Pos_min]=A[i];
	   A[i]=TEMP;
	}
     }
}
void SELECTION::DISPLAY()
{
     cout<<"\n array elements are =>";
     for(i=1;i<=n;i++)
     cout<<A[i]<<" ";

}
void main()
{
     clrscr();
     SELECTION s;
     s.GET();
     s.DISPLAY();
     s.PROCESS();
     cout<<"\n After Sorting: ";
     s.DISPLAY();
     getch();
}
