#include<iostream>
using namespace std;

int Binarysearch(int arr[], int n, int length)
   {
    int l=0;
    int h=length-1;
    
    while(l<=h)
    {
       int mid=(l+h)/2;
           if (n==arr[mid])
            return  mid;
             else if (n<arr[mid])
                  h=mid-1;
             else  l=mid+1;
    }
    return -1;
}


int main()
{
   int arr[100]={};
   int s;
   cout<<"enter size of arr : ";
   cin>>s;

   for(int i=0;i<s;i++)
    cin>>arr[i];
   int x;
   cout<<"no. to find: "<<endl;
   cin>>x;   

int result = Binarysearch(arr, x, s);
cout << "Found at index: " << result;
return 0;
}