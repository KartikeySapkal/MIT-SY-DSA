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
	return;
	}
	else{
	
	top++;
	s[top] = s1;
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
	return temp;
	}
}


class expression{ 	
public: 
string infix,prefix,postfix;
stack stk;

bool isoperator(char x){ 

	if(x == '+'|| x=='-'|| x=='*'|| x=='/'|| x=='^'|| x=='%')
	return true;
	else
	return false;
	
}	

void prefix_to_infix(){ 

	cout<<"Enter Expression: "<<endl;
	cin>>prefix;
	
	int count = prefix.length();

	for(int i = count-1; i>=0 ; i--){ 
	
	if(isoperator(prefix[i])){ 
	
	string op1 = stk.pop();
	string op2 = stk.pop();
	
	string temp = "("+op1+prefix[i]+op2+")";
//	cout<<"Temp "<<temp<<endl;
	stk.push(temp);
	
	}
	
	else 
	stk.push(string(1,prefix[i]));	

	}
cout<<stk.pop();
}		

};


int main(){ 

	stack s1;
//	s1.push("Kartikey");
//	s1.pop();
	
	expression e;
	e.prefix_to_infix();
	
	
	return 0;
}
