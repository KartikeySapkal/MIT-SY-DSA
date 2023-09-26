#include<iostream>
#include<cstring>
using namespace std;

class Node{ 

	public: 
	char studName[50];
	char companyName[50];
	float package;	
	Node *next;
		
};

class sll{ 

	public: 
	Node *head;
	sll(){
	head = NULL;
	int len=0;
	}
	
	void create();
	void display();
	void insert();
	void del();
	void update();
	void search();
	void sort();
	void reverse();
};

void sll::create(){ 
	
	
	
	Node *temp, *p ; char ch;
  do{
  
	temp = new Node;
	cout<<"Enter Your Name: "<<endl;
	cin>>temp->studName;
		
	cout<<"ENter Package In LPA: "<<endl;
	cin>>temp->package;
	
	cout<<"Enter Your Company Name: "<<endl;
	cin>>temp->companyName;
	
	temp->next = NULL;
	
	if(head==NULL){ 
	head=temp;
	}
	else{ 
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;

	}
	cout<<"\n Do you want to add more nodes (y/n):  ";
	cin>>ch;
}while(ch=='y');
	
}


void sll::display(){
	
	Node *temp;
	temp = head;
	
	cout<<"Name \t\tCompany \t\tPackage"<<endl;
	while(temp!=NULL){ 
	cout<<temp->studName<<"\t\t"<<temp->companyName<<"\t\t"<<temp->package;
	cout<<endl;
	temp = temp->next;
	}
	
}

void sll::insert(){ 

	Node *temp,*p;
	temp = new Node;
	char ch;
	char info[50];
	
	cout<<"Do you want to insert at first Node: (y/n)"<<endl;
	cin>>ch;
	p=head;
	
	if(ch=='y'){ 
	
	cout<<"Enter Your Name: "<<endl;
	cin>>temp->studName;
		
	cout<<"ENter Package In LPA: "<<endl;
	cin>>temp->package;
	
	cout<<"Enter Your Company Name: "<<endl;
	cin>>temp->companyName;
	
	temp->next=NULL;
	
	
	temp->next = p;
	head = temp;
	
	}
	else{
	
	cout<<"Enter Student Name after Which you want to add Node: "<<endl;
	cin>>info;
	
	cout<<"Enter Your Name: "<<endl;
	cin>>temp->studName;
		
	cout<<"ENter Package In LPA: "<<endl;
	cin>>temp->package;
	
	cout<<"Enter Your Company Name: "<<endl;
	cin>>temp->companyName;	
	temp->next=NULL;	
		
	while(p!=NULL){ 
		if(strcmp((temp->studName),info)==0);
		{
			temp->next = p->next;
			p->next = temp;	
			p = p->next; 
		}
	}	
}	
	
}


int main(){ 

	int choice;
 	
 	sll s1;
 	
	cout<<"Welcome to Placement Analalysis System"<<endl;
	cout<<"Menu"<<endl;
	
	cout<<"1.Create Entry\n2.Add Entry\n3.Delete Entry\n4.Search Entry\n5.Update Entry\n6.Delete Entry\n7.Reverse\n8.Exit"<<endl;
	cin>>choice;
	
	
		s1.create();
		s1.display();
		s1.insert();
		s1.display();
	
	
	
	return 0;
}








