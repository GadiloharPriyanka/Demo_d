#include<iostream.h>
#include<conio.h>

class BINARY_39
{
    private:
       int A[10],i,j,n,f,temp,ele,low,high,mid;
    public:
       void GET();
       void BINARY();
       void DISPLAY();
};
void BINARY_39::GET()
{
    cout<<"\n Enter Array Size=>";
    cin>>n;
    cout<<"\n Enter Array Elements=>";
    for(i=1;i<=n;i++)
    cin>>A[i];
}
void BINARY_39::BINARY()
{
    cout<<"\n Enter elements to be Serch=>";
    cin>>ele;
    f=0;
    low=1;
    high=n;
    while(low<=high)
    {
       mid=(low+high)/2;
       if(A[mid]==ele)
       {
	  f=1;
	  cout<<"\n Successful search";
	  cout<<"\n Element is found at position "<<mid;
	  return;
       }
       else if(A[mid]<ele)
	 low=mid+1;
       else if(A[mid]>ele)
	 high=mid-1;
     }
     if(f==0)
      cout<<"\n Unsuccessful search:";
      cout<<"\n Element is not found ";
}
void BINARY_39::DISPLAY()
{
   cout<<"\n Elements are=>";
   for(i=1;i<=n;i++)
   cout<<A[i]<<" ";
}
void main()
{
   clrscr();
   BINARY_39 l;
   l.GET();
   l.BINARY();
   l.DISPLAY();
   getch();
}