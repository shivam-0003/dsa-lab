#include<iostream>
using namespace std;

struct Stack {
    int size=0;
    int top=-1;
    int *s=nullptr;

};
void create (struct Stack *st)
{
    
    cout<<"enter size : "<<endl;
    cin>>st->size;
    st->s=new int[st->size];
    st->top=-1;
    
}

void display(const Stack &st)
{
    if (st.top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = st.top; i >= 0; i--)
        cout << st.s[i] << " ";
    cout << endl;
}


void push(Stack *st, int x)
{
    if(st->top==st->size-1)
    cout<<"stack overflow ";
    else{
    st->top++;
    st->s[st->top]=x;}
}
int pop (Stack *st)
{
    int x=-1;
    if(st->top==-1)
    cout<<"stack underflow "<<endl;
    else{
    x= st->s[st->top];
    st->top--;}
    return x;
}

int main()
{
    Stack st;
    create(&st);
    
    int n;
    cout<<"no. of elements: ";
    cin>>n;
 
    
    for (int i = 0; i < n && st.top < st.size - 1; i++)
    {
        int x;
        cout << "Enter element " << i + 1 << ": ";
        cin >> x;
        push(&st, x);
    }

    cout<<" stack elements: ";
    display(st);
    delete[] st.s;
    return 0;

}