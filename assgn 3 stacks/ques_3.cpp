#include<iostream>
using namespace std;

bool isbalanced(char expr[])
  {
    char stack [1000];
    int top = -1;

    for (int i=0; expr[i]!= '\0';i++)
    {
        char ch = expr[i];

        if (ch=='('||ch=='{'||ch=='[')
        {
            stack[++top]=ch;
        }
        else if (ch==')'||ch=='}'||ch==']')
        {
            if (top==-1)
            return false;

            char topchar=stack[top];
            top = top-1;
             
            if ((ch == ')' && topchar != '(') || 
                (ch == '}' && topchar != '{') || 
                (ch == ']' && topchar != '['))
                return false;
        }
    }
      return (top==-1);
  }

  int main() {
    char expr[1000];
    
    cout << "Enter an expression: ";
    cin.getline(expr, 1000);

    if (isbalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}