#include<iostream>
using namespace std;
int main(){
int arr[50] , n;
cout<<"Enter size of the array : ";
cin>>n;
int count = 0;
cout<<"Enter array elements : ";
for(int i = 0 ; i < n ; i++){
     cin>>arr[i];
}
for(int i = 0 ; i < n ; i++){
	for(int j = i + 1 ; j < n ; j++){
		if(arr[i]>arr[j]){
			count++;
		}
	}
}
cout<<"Number of inversions in the array : "<<count;
return 0;
}