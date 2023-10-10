#include<iostream>
using namespace std;

class Node{ 

	public: 
	char pizzaName[50];
	char size[50];
	int quantity;
	int price;
	Node *next; 
};

class cll{ 

	public: 
	Node *head; 
	
	cll(){ 
	head = NULL;
	}
	 
	void insert(Node *temp);
	void del();
	void disp(); 

};

void cll::insert(Node *temp){ 

	Node *p = head; 
	if(head == NULL)
	{ 
	head = temp; 
	
	}

	else{ 
	
	while(p->next != head){ 
	 p = p->next;
	}
	p->next = temp; 
	temp->next = head;
	}

}

void cll::disp(){ 

	cout<<endl;
	
	if(head == NULL){ 
	cout<<"No Orders Available"<<endl;
	exit(0); 
	}

	Node *temp = head; 
	cout<<"Orders: "<<endl;
	do{ 
	cout<<"Pizza: "<<temp->pizzaName<<endl;;
	cout<<"Size: "<<temp->size<<endl;
	cout<<"Quantity: "<<temp->quantity<<endl;
	cout<<"Price: "<<temp->price<<endl;
	cout<<"Total Price = "<<temp->price*temp->quantity<<endl;
	temp = temp->next;
	}while(temp!=head);
	cout<<endl;
}

void cll::del()
{
	if(head == NULL)
	{ 
	cout<<"OrderList is Empty"<<endl;
	exit(0);
	}
	Node *p = head;
	while(p->next != head)
	  p = p->next;
	p->next = head->next;
	p = head;
	head = head->next;
	delete p;  	
}

int main(){ 

	int ch;
	cout<<"<<<< Welcome to Pizza'chio! >>>> "<<endl;
	cll s1; 
	while(true){ 
	cout<<"Menu"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"1.Place Order\n2.Take Order\n3.Display order"<<endl;
	cin>>ch;
	cout<<"--------------------------------------------------------"<<endl;
	switch(ch){ 		
	case 1: 
	{
	
	Node *temp = new Node;
	temp->next = temp;
	cout<<"Enter Pizza Name: "<<endl;
	cin>>temp->pizzaName;
	cout<<"Enter Pizza Size: "<<endl;
	cin>>temp->size;
	cout<<"Enter Quantity: "<<endl;
	cin>>temp->quantity;	
	cout<<"Enter Price: "<<endl;
	cin>>temp->price;
	s1.insert(temp);	
	break; 
}
	case 2: 
	s1.del();
	cout<<"Order Received"<<endl;
	break;
	
	case 3: 
	s1.disp();
	break;
	
	case 4: 
	cout<<"Thank You"<<endl;
	exit(0);
	break;	
	
	}	

}

	return 0;	
} 
