#include<iostream>
using namespace std;
int arr[50];
int n=0;
void createarray()
  { 
  
  cout<<"Enter no. of elements : "<<endl;
  cin>>n;

  int arr[n];
  cout<<"enter elements: "<<endl;
  
    for (int i=0;i<n;i++)
               {
               cin >>arr[i] ;
               }
     
  
    }
void displayarray()
    {
        cout<<"The elements are: ";
        for(int i=0;i<n;i++)
          {
          cout<<arr[i]<<"  ";
          }
          cout<<endl;
    }
void insertelement()
    {
       int pos,val;
       cout<<"enter position: ";
       cin>>pos;

       cout<<"enter value: ";
       cin>>val;

       for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    cout << "Element inserted!" << endl;
}

void deleteelement()
{
    int pos;
    cout<<"enter pos: ";
    cin>>pos;

    for (int i=pos-1; i<n-1;i++)
    {
        arr[i]=arr[i+1];    
    }
    n--;
}
void linearsearch()
{int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }
}
int main()
   {
    int options;
    do {
         cout<<"  --MENU--"<<endl;
         cout<<"1. CREATE"<<endl;
         cout<<"2. DISPLAY"<<endl;
         cout<<"3. INSERT"<<endl;
         cout<<"4. DELETE"<<endl;
         cout<<"5. LINEAR SEARCH"<<endl;
         cout<<"6. EXIT"<<endl;
         cin>>options;
    switch(options){
                   case 1: createarray();break;
                   case 2: displayarray();break;
                   case 3: insertelement();break;
                   case 4: deleteelement();break;
                   case 5: linearsearch();break;
                   case 6: exit;break;
                  }
                  
        }while (options !=6);
        return 0 ;
    }
