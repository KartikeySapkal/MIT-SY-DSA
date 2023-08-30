//A menu driven programm for operations of insertion, deletion, sorting
//1.insertion
//2.deletion
//3.updation
//4.search
//5.sort
//6.exit

#include<iostream>
#include<string.h>
using namespace std;

class students{ 
	public: 
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

	int choice;
	char ch;
	int size;
	students s[100];
	cout<<"Enter Size: "<<endl;
	cin>>size;
	
		
	for(int i=0; i<size; i++){ 
		cout<<"Student no: "<<i+1<<endl;
		s[i].getinfo();
	}
	
				cout<<"Roll_no\tName\t\tGender"<<endl;
	
	for(int i=0; i<size; i++){ 
		s[i].showinfo();
	}
	

	
    cout<<"Welcome to Student Management System"<<endl;
    cout<<"Main Menu"<<endl;

	do{  
    cout<<"1.Insert\n2.Delete\n3.Update\n4.Search\n5.Sort\n6.Exit"<<endl;
    cin>>choice;
    
    switch (choice){ 
		case 1: 
		{
			int pos,val=90;
			cout<<"Performing Insertion"<<endl;
			cout<<"Enter Position: "<<endl;
			cin>>pos;
			
			
			cout<<"Enter Student RollNo/Name/Gender: "<<endl;
			cin>>s[val].roll_no>>s[val].name>>s[val].gender;
			
			for(int i=size;i>=pos; i--)
			{
				s[i+1].roll_no = s[i].roll_no;
				strcpy(s[i+1].name,s[i].name);
				s[i+1].gender=s[i].gender;
			}
				
			s[pos].roll_no = s[val].roll_no;
			strcpy(s[pos].name,s[val].name);
			s[pos].gender=s[val].gender;
			size++;
			cout<<"Roll_no\tName\t\tGender"<<endl;
	
	for(int i=0; i<size; i++){ 
		s[i].showinfo();
	}	
			break;
}
		
		case 2: {
		int pos=0,rn;		
		cout<<"Performing Deletion"<<endl;
		cout<<"Enter Rollno: "<<endl;
		cin>>rn;
		
		for(int i=0; i<size; i++){
			if(s[i].roll_no==rn)
				break;
			else 
			pos++;	
		}
		
		for(int i=pos; i<size; i++){ 
			
			s[i].roll_no=s[i+1].roll_no;
			strcpy(s[i].name,s[i+1].name);
			s[i].gender=s[i+1].gender;
		}	
		size--;

	cout<<"Roll_no\tName\t\tGender"<<endl;
	for(int i=0; i<size; i++){ 
		s[i].showinfo();
	}	
		
		
		break;
	}	
		case 3: 
		{
		cout<<"Performing Updation"<<endl;
		break;
	}
		case 4: 
		{	
		cout<<"Performing Searching operation"<<endl;
		break;
	}
		case 5: 
		{
		cout<<"Performing Sorting opeartion"<<endl;
		break;
	}
		case 6: 
		{	
		cout<<"Thank You"<<endl;
		ch='n';
		break;
		}	
		
	}
	
	cout<<"Do You Want to continue(y/n)?"<<endl;
	cin>>ch;
	
}while(ch=='y');
    
  		
	  
    
    return 0;
}
