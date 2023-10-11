//implementing stack using Array
//LIFO 
//last inserted element is delete first or taken out first
//prefix to infix
#include<iostream>
#include<cstring>
using namespace std;
#define size 50

class stack{ 
	public: 
	string s[size];
	int top;
	
	stack(){ 
	top = -1;
	}
	
	bool isEmpty();
	bool isFull();
	void push(string s1);
	string pop();
	
};

bool stack::isEmpty(){ 

	if(top==-1)
	return true;
	else 
	return false;
}

bool stack::isFull(){ 

	if(top==size-1)
	return true;
	else 
	return false;
}

void stack::push(string s1){ 

	if(isFull()){ 
	cout<<"Stack is Full"<<endl;
	}
	else{
	
	top++;
	s[top] = s1;
	cout<<"Pushed"<<endl;
	}
}

string stack::pop(){ 
	string temp;
	if(isEmpty()){ 
	cout<<"Stack is Empty"<<endl;
	}
	
	else
	{ 
	temp = s[top];
	top--;
	cout<<"Popped"<<endl;
	return temp;
	}
}



int main(){ 


	stack s1;
	s1.push("Kartikey");
	s1.pop();
	return 0;
}
