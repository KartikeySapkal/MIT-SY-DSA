#include<iostream>
#include<cstring>

using namespace std;


class bank{ 
	public: 
	int balance;
	char name[50];
	char password[50];
	char password2[50];
	int acc_no = 4121005;
		
	
	
	bank(){ 
	cout<<"\nSetting Up New User"; 
	
	// account creation
	cout<<"\n\n\nEnter Your Name: "<<endl;
	cin>>name;
	cout<<"Generating Account no: \n.\n.\n..."<<endl;
	acc_no = acc_no + 4; 
	cout<<"Your Acc_No is: "<<acc_no << endl;
	cout<<"Setting Password\n\n";
	cout<<"Create Your Password: "<<endl;
	cin>>password;
	cout<<"Verify Password again: "<<endl; 
	cin >>password2;
	
	//verification
	bool flag = true;
	
	while(flag){
	
	if(strcmp(password,password2)==0)
{ 
		cout<<"Account Successfully Created>>!\n\n"<<endl;
		flag = false;
		break;
		} 
	
	else
		{
	cout<<"Account Creation Failed.!"<<endl;
	cout<<"INITIATING PASSWORD CREATION PROCESS AGAIN\n.\n.\n";	
	cout<<"Enter Password again: "<<endl;
	cin>>password;
	cout<<"Verify Password: "<<endl;
	cin>>password2;
	
		}

	}
	cout<<"\n\n";

}
//setting up functions	
int login();

};


int bank :: login(){ 
	
	int key;
	char passkey[50];
	cout<<"Enter Your Bank Account Number : "<<endl;
	cin>>key;
	cout<<"Enter Your Password: "<<endl;
	cin>>passkey;
	
	//initiating login process
	
	bool flag = true;
	
	while(flag){
	
	if((key==acc_no) && (strcmp(password,passkey)==0)){ 
	cout<<"Login Successfull"<<endl;
	return 1;
	flag = false;
	break;
	}
	else
	{ 
	cout<<"Enter Your Bank Account Number again: "<<endl;
	cin>>key;
	cout<<"Enter Your Password: "<<endl;
	cin>>passkey;
		}	
	}
	cout<<"Technical Error"<<endl;
	exit(0);
	return 0; 

}

int main(){ 
	
	cout<<"Welcome To Banking Management System\n";
	bank b1;
	b1.login();
	
//	if(b1.login){ 
//	
//	cout<<"Choose Operations: "<<endl;
//	
//	
//	}
	
	return 0;
}
