#include<iostream.h>
#include<conio.h>

class LINEAR_39
{
    private:
       int A[10],i,j,n,temp,ele;
    public:
       void GET();
       void LINEAR();
       void DISPLAY();
};
void LINEAR_39::GET()
{
    cout<<"\n Enter Array Size=>";
    cin>>n;
    cout<<"\n Enter Array Elements=>";
    for(i=1;i<=n;i++)
    cin>>A[i];
}
void LINEAR_39::LINEAR()
{
    cout<<"\n Enter elements to be Serch=>";
    cin>>ele;
    for(i=1;i<=n;i++)
    {
       if(A[i]==ele)
       {
	 cout<<"\n Successfuly Serch ";
	 cout<<"\n Element is found at position"<<i;
	return;
       }
    }
    if(i>=n)
    {
	cout<<"\n Unsuccessfuly Serch ";
	cout<<"\n Element is not found";
     }

}
void  LINEAR_39::DISPLAY()
{
   cout<<"\n Elements are=>";
   for(i=1;i<=n;i++)
   cout<<A[i]<<" ";
}
void main()
{
   clrscr();
   LINEAR_39 l;
   l.GET();
   l.LINEAR();
   l.DISPLAY();
   getch();
}