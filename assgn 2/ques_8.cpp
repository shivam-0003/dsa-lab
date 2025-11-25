#include<iostream>
using namespace std;



int main ()
{
    int n;
    cout<<"enter size: ";
    cin>>n;

    int * arr= new int [n];

    cout<<"enter values : ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
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
    //int arr[]= { 1,1,1,2,2,2,3,3,3,4,4,4};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int count=1;
    for (int i=1; i<n; i++)
    {
        if(arr[i] != arr[i-1])
        count++;
    }
    cout<<"total distinct elements = "<<count;
 
 return 0;

}