#include<iostream.h>
#include<conio.h>

class QUICK
{
    private:
       int A[20],n,ele;
    public:
    void GET();
    void ASORT(int,int);
    int PARTITION(int,int);
    void DISPLAY();
};
void QUICK::GET()
{
    cout<<"\n Enter the Array Size=>";
    cin>>ele;
    cout<<"\n Enter the array element=>";
    for(int i=1;i<=ele;i++)
    cin>>A[i];
    ASORT(1,ele);
}
void QUICK::ASORT(int p,int q)
{
    if(p<q)
    {
	int j=PARTITION(p,q);
	ASORT(p,j-1);
	ASORT(j+1,q);
    }
}
int QUICK::PARTITION(int lb,int ub)
{
    int x,left,right,temp;
    x=A[lb];
    left=lb+1;
    right=ub;
    do
    {
       while(A[left]<x)
       left++;
       while(A[right]>x)
       right--;
       if(left<right)
       {
	  temp=A[left];
	  A[left]=A[right];
	  A[right]=temp;
       }
    }while(left<=right);
     A[lb]=A[right];
     A[right]=x;
     return(right);
}
void QUICK::DISPLAY()
{
    cout<<"\n The Array element are=>";
    for(int i=1;i<=ele;i++)
    cout<<A[i]<<" ";
}
void main()
{

    clrscr();
    QUICK d;
    d.GET();
    cout<<"\n After Sorting";
    d.DISPLAY();
    getch();
}