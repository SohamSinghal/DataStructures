#include<iostream>
using namespace std;
int Partition(int arr[],int start,int end)
{
    int piv = arr[start];
    int i = end+1;
    for(int j = end;j>=start+1;j--)
    {
        if (arr[j]>piv)
        {
            int c;
            i--;
            c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }
    }
        int c;
        c = arr[start];
        arr[start] = arr[i-1];
        arr[i-1] = c;
    return(i-1);
}

void QuickSort(int arr[],int start,int end) 
{
    if  (end>start)
    {
        int index = Partition(arr,start,end);
        QuickSort(arr,start,index-1);
        QuickSort(arr,index+1,end);
    }
}
int main()
{
    int arr[] = {4, 9, 10, 20, 17, 16, 15, 5, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array"<<endl;
    for(int i = 0; i<=len-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr,0,len-1);
    cout<<"Sorted Array"<<endl;
    for(int i = 0; i<=len-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}
