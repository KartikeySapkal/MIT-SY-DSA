#include<iostream>
using namespace std;
int main(){ 

    int k;
    cout<<"Enter K for rotation: "<<endl;
    cin>>k;
    
    
    int n=5;
    int arr[n+k];
    for(int i=0; i<n; i++){ 
    cin>>arr[i];   
    }
        
    // cout<<arr[1];
    int count=0;
    for(int i=n-1; i>=0; i--){ 
        arr[i+k] = arr[i];
        count++;
    }
    for(int i=0; i<k; i++){ 
        arr[i] = arr[n+i] ;
        count++;
    }

    for(int i=0; i<n; i++){ 
        cout<<arr[i]<<" ";
    }
    cout<<count<<endl;


    return 0;
}