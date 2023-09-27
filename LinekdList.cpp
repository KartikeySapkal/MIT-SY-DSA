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
	
	cout<<"Enter Values to insert"<<endl;
	
	cout<<"Enter Your Name: "<<endl;
	cin>>temp->studName;
		
	cout<<"ENter Package In LPA: "<<endl;
	cin>>temp->package;
	
	cout<<"Enter Your Company Name: "<<endl;
	cin>>temp->companyName;
	
	temp->next=NULL;
	
	cout<<"Do you want to insert at first Node: (y/n)"<<endl;
	cin>>ch;
	p=head;
	
	if(ch=='y'){ 

	temp->next = p;
	head = temp;
	
	}
	else{
	cout<<"Enter Student Name After Which you want to add: "<<endl;
	cin>>info;	
	while(p!=NULL){ 
		if(strcmp((p->studName),info)==0)
		{
			temp->next = p->next;
			p->next = temp;	
			break;
		}
		
		else
			p=p->next;
		
	}	
}	
	
}

void sll::del(){ 

	Node *temp,*prev;
	
	char key[50];
	
	temp = head;
	prev = NULL;

	cout<<"Enter Student Name Whose Record You want to Delete: "<<endl;
	cin>>key;
	
	
	while(temp!=NULL){ 
		
		if(strcmp((temp->studName),key)==0)
	{
		if(temp==head){ 
		head = head->next;
		delete(temp);
		break;
		}
		
		else{
		
	
		prev->next = temp->next;
		delete(temp);
		break;
}
	}
	else{
		prev=temp;
		temp = temp->next;
		}
	}
	
	
}

void sll::search(){
	
	char key[50];
	Node *temp =head;
	cout<<"ENter Student Name to Search"<<endl;
	cin>>key;
	while(temp!=NULL){ 
	if(strcmp(temp->studName,key)==0){ 
	
		cout<<"Record Found"<<endl;
		cout<<"Name \t\tCompany \t\tPackage"<<endl;
		cout<<temp->studName<<"\t\t"<<temp->companyName<<"\t\t"<<temp->package;
		cout<<endl;
		break;
	
	}
	else
	temp=temp->next;
	
	
	if(temp==NULL)
	{
	cout<<"Record Not Found"<<endl;
	break;					
		}
	}
}


int main(){ 

	int choice;
 	
 	sll s1;
 	
	cout<<"Welcome to Placement Analalysis System"<<endl;
	cout<<"Menu"<<endl;
	
	
	
	char ch ='y';
	
	while(ch=='y'){
		
	cout<<"1.Create Entry\n2.Add Entry\n3.Delete Entry\n4.Search Entry\n5.Update Entry\n6.Sort Entries\n7.Reverse\n8.Exit"<<endl;
	cin>>choice;
	
	switch(choice){ 
	
	
		
	case 1: 
	cout<<"Creating Entry: "<<endl;
	s1.create();	
	break;
	case 2: 
	cout<<"inserting Entries: "<<endl;
	s1.insert();
	break;
	case 3: 
	cout<<"Deleting Entry"<<endl;
	s1.del();
	break;
	case 4:
	cout<<"Searching Entry: "<<endl;
	s1.search();
	break;
	case 5: 
	cout<<"Updating Entry: "<<endl;
//	s1.update();
	break;
	case 6: 
	cout<<"Sorting Entries: "<<endl;
//	s1.sort();
	break;
	case 7: 
	cout<<"Reversing Entries"<<endl;
//	s1.reverse();
	break;
	case 8: 
	cout<<"Thanks"<<endl;	
	ch='n';
	exit(0);
	
	}
		
}
	
	return 0;
}








