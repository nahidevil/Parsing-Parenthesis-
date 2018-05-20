#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
struct node *top;

void push(char symbol)
{
    struct node *temp=top, *newnode=new node;;
    newnode->data=symbol;

    if(top==NULL)
    {
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    struct node* temp=top;
    if(top==NULL)
        cout<<"stack is empty\n";
    else
    {
        top=top->next;
        delete temp;
    }
}
int check(char open,char close)
{

    if(open=='(' && close==')')
        return 1;
    else if(open=='{' && close=='}')
        return 1;
    else if(open=='[' && close==']')
        return 1;
    else
        return 0;

}
int balance_check(char exp[])
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' ||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' ||exp[i]=='}'||exp[i]==']')
        {
            if(top==NULL)
                return 0;
            else if(check(top->data,exp[i])==0)
                return 0;
            else
                pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
    top=NULL;
    char exp[50];
    cout<<"enter expression: ";
    cin>>exp;

    if(balance_check(exp)==1)
        cout<<"\nbalanced\n";
    else if(balance_check(exp)==0){
        cout<<"\nnot balanced\n";
        if(top->data=='(' || top->data=='{' || top->data=='[')
            cout<<"for closing parentheses\n";
        else
            cout<<"for opening parentheses\n";}
}
