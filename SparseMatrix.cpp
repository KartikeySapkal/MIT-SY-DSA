
//sparse matrix
//zero elemnets must be greater than half no of elements

#include<iostream>
using namespace std;
#define max 10

class sparse_matrix{ 
	public: 
	int data[max][3];
	int len;
	
	public: 
	sparse_matrix(int r,int c,int l){ 
	
		data[0][0]=r;
		data[0][1]=c;
		data[0][2]=l;
		len = 0;
	}
	
	sparse_matrix(){
		data[0][0]=0;
		data[0][1]=0;
		data[0][2]=0;
		len = 0;
	}
	
	
	void insert(int r,int c, int l);
	void show();
	void add(sparse_matrix s1, sparse_matrix s2);
	void multiply(sparse_matrix s1, sparse_matrix s2);
	sparse_matrix transpose();
	
};

void sparse_matrix :: insert(int r, int c, int v){ 
	
	data[len+1][0]=r;
	data[len+1][1]=c;
	data[len+1][2]=v;
	len++;
};

void sparse_matrix :: show(){ 
	
	for(int i=0; i<len+1; i++){ 
		cout<< data[i][0] << "   |\t";
		cout<< data[i][1] << "   |\t";
		cout<< data[i][2] << "   |\t";
		cout<< endl ;
	
	}
	cout<< endl ; 

}


sparse_matrix sparse_matrix :: transpose(){
	
	sparse_matrix t(data[0][1],data[0][0],data[0][2]);
	
	for(int i=0; i<data[0][1]; i++){ 
		for(int j=0; j<=len; j++)
		{ 
			if(data[j][1]==i){
				t.len++;
				
				t.data[t.len][0]=data[j][1];
				t.data[t.len][1]=data[j][0];
				t.data[t.len][2]=data[j][2];	

			}
		}
	}
	
	return t;	
}


int main(){ 
	
	int row,col,val;
	int r, c,v;
	
	cout<<"Enter Rows: "<<endl;
	cin>>row;
	
	cout<<"Enter cols: "<<endl;
	cin>>col;
	
	cout<<"Enter Vals: "<<endl;
	cin>>val;
	
	if(val>row*col*0.5){
		cout << "Cannot form sparse matrix " << endl;
		cout << "Enter Non zero values again" <<endl;
		cin>>val;
 	}
	
	sparse_matrix s1(row,col,val);
//	
//	cout << s1.data[0][0] << endl;
//	cout << s1.data[0][1] << endl;
//	cout << s1.data[0][2] << endl; 
	
//	int choice;
//	char ch;
	
	for(int i=0; i<val; i++){ 
		cout << "Enter Row no/col no /val: " << endl; 
		cin>>r>>c>>v;
		
		if(r>=row || c>=col){ 
		cout << "Invalid input" << endl;
		cout << "Enter Row no/col no /val: (again)" << endl; 
		cin>>r>>c>>v;
		}
		
		
		s1.insert(r,c,v);
	}
	
	//displyaing matrix
	cout<< "Dimention of matrix is: " << row << "x" << col << endl;
	cout<< "Rows|\tCols|\tVals|" << endl;
	s1.show();
	sparse_matrix b;
			
	b = s1.transpose();
	
	s1.show();
	
	
	return 0;
}

