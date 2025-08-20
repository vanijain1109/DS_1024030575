#include<iostream>
using namespace std;
int reverseArr(int arr[], int n) {
    int start = 0, end = n - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
}
int main(){
    int arr[50],n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"Entered array : ";
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Reversed array : ";
    reverseArr(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}