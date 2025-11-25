#include<iostream>
using namespace std;

int main()
{  int arr[]={64 , 34 , 25 , 12 , 22 , 11 , 90};
  int n = sizeof(arr) / sizeof(arr[0]); // to know no. of elements in arr 

  for (int i=0;i<n-1;i++)
   {
       for (int j=0;j<n-i-1;j++)
      {
         if(arr[j] > arr[j+1])
        {
         int temp=arr[j];  //elements swapping 
         arr[j]=arr[j+1];
         arr[j+1]=temp;
        }
      }
    }
  cout<<"this is your sorted array: "<<endl;
  for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

     return 0;
}
    