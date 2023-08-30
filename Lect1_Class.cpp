#include<iostream>
using namespace std;

class students{ 
	protected: 
	int roll_no;
	char name[50];
	char gender;
	
	public: 
	void getinfo();
	void showinfo();

};

void students::getinfo(){
	cout<<"Enter Roll no: "<<endl;
	cin>>roll_no;
	
	cout<<"Enter Name: "<<endl;
	cin>>name;
	
	fflush;
	
	cout<<"Enter Gender: "<<endl;
	cin>>gender;
}

void students::showinfo(){ 
	cout<<roll_no<<"\t"<<name<<"\t\t"<<gender<<endl;
}



int main(){ 
	int size;
	cout<<"Enter No of students: "<<endl;
	cin>>size;
	
	students s[size];

	
	for(int i=0; i<size;i++){ 
		cout<<"Student no: "<<i+1<<endl;
		s[i].getinfo();
	}
	
		cout<<"Roll_no\tName\t\tGender"<<endl;
	
		for(int i=0; i<size;i++){ 
		s[i].showinfo();
	}
			
	return 0;
}
