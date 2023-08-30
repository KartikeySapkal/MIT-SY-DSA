#include<iostream>
using namespace std;

int main(){

	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int index,val;
	
	cout<<"Enter Index and Value: "<<endl;
	cin>>index>>val;
	
	for(int i=10; i<=index; i--)
		a[i+1]=a[i];
		
	a[index]=val;
	
	cout<<endl;
	for(int i=0;i<=10;i++){ 
	cout<<a[i]<<" ";
	}
		
	
	return 0;

}
