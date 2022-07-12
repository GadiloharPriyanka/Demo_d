#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
const int MAX=50;
class POSTFIX
{
    private:
	int stack[MAX];
	int top,num,ele,data;
	char s[20];
    public:
	POSTFIX();
	void SET_EXPR();
	void PUSH(int ele);
	int POP();
	void CALCULATE();
	void LIST_ALL();
};
POSTFIX::POSTFIX()
{
    top=-1;
}
void POSTFIX::SET_EXPR()
{
    gets(s);
}
void POSTFIX::PUSH(int ele)
{
    if(top==MAX-1)
    cout<<endl <<"Stack is Full";
    else
    {
	top++;
	stack[top]=ele;
    }
}
int POSTFIX::POP()
{
    if(top==-1)
    {
	cout<<endl <<"Stack is Empty";
	return NULL;
    }
   int data=stack[top];
   top--;
   return data;

}
void POSTFIX::CALCULATE()
{
    int n1,n2,n3;
    int i=0;
    char ch;
    while(s[i]!='\0')
    {
	int n=0;
	ch =s[i];
	if(ch==' '|| ch =='\t')
	{
	    i++;
	    continue;
	}
	if(isdigit (ch))
	{
	   while(isdigit(s[i]))
	   {
	      num=s[i]-'0';
	      n=n*10+num;
	      i++;
	   }
	   PUSH(n);
       }
       else
       {
	   n1=POP();
	   n2=POP();
	   switch(ch)
	   {
		case '+':n3=n2+n1;
		break;
		case '-':n3=n2-n1;
		break;
		case '/':n3=n2/n1;
		break;
		case '*':n3=n2*n1;
		break;
		case '%':n3=n2%n1;
		break;
		case '^':n3=pow(n2,n1);
		break;
		default:
		    cout<<" Invalid Choice ";
		exit(1);
	   }
	   PUSH(n3);
      }
      i++;
   }
}
void POSTFIX::LIST_ALL()
{
    num=POP();
    cout<<"\n Result is: "<< num;
}
void main()
{
     clrscr();
     cout<<"\n Enter Postfix expression to be evaluated :";
     POSTFIX p;
     p.SET_EXPR();
     p.CALCULATE();
     p.LIST_ALL();
     getch();
}