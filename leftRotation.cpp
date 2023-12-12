#include<iostream>
using namespace std;
int main(){ 

    int k;
    cout<<"Enter K for rotation: "<<endl;
    cin>>k;
    
    
    int n=10;
    int arr[n+k];
    for(int i=0; i<n; i++){ 
    cin>>arr[i];   
    }
        
    // cout<<arr[1];

    for(int i=9; i>=0; i--){ 
        arr[i+k] = arr[i];
    }
    for(int i=0; i<k; i++){ 
        arr[i] = arr[n+i] ;   
    }

    for(int i=0; i<10; i++){ 
        cout<<arr[i]<<" ";
    }


    return 0;
}