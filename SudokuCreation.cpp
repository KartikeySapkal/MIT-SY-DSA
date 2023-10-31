#include<iostream>
using namespace std;
#define N 4

void getArr(int arr[N][N]){ 
    cout<<"Enter Elements: "<<endl;
    for(int i=0; i<N; i++){ 
        for(int j=0; j<N; j++){
            cout<<"Enter Arr"<<"["<<i<<']'<<"["<<j<<']'<<" ";
            cin>>arr[i][j];
            while(arr[i][j]>N){
                cout<<"Entered num out of range>>!!(Range is from 1 to "<<N<<"): "<<endl;
                cout<<"Try again: "<<endl;
                cin>>arr[i][j];
            }

        }
            cout<<endl;
    }
}

void printArr(int arr[N][N]){ 
    for(int i=0; i<N; i++){ 
        cout<<"| ";
        for(int j=0; j<N; j++){
            cout<<arr[i][j]<<" | ";
        }
        cout<<endl;
    }
}

bool isSafe(int grid[N][N],int row, int col, int num){ 

    for(int i=0; i<N; i++){ 
        if(grid[row][i]==num)
        return false;
    }

    for(int x=0 ;x<N; x++)
        if(grid[x][col]==num)
        return false;

    int startRow = row - row%2;
    int startCol = col - col%2;

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            if(grid[i + startRow][j + startCol]==num)
                return false;
        return true;
}

bool solveSudoku(int grid[N][N], int row, int col){ 

    if(row==N-1 && col==N)
    return true;
    if(col == N){ 
        row++;
        col = 0;
    }

    if(grid[row][col]!=0)
    return solveSudoku(grid,row,col+1);
    for(int num = 1; num<=N; num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(solveSudoku(grid,row,col+1))
            return true;
        }
        grid[row][col] = 0;

    }
    return false;
}



int main(){ 

    int arr[N][N];

    getArr(arr);
    printArr(arr);
    cout<<"Solving This....."<<endl;
    
    for(int i=0; i<100; i+=19)
    cout<<"Processing..... ....."<<i<<"%"<<" Completed"<<endl;

    if(solveSudoku(arr,0,0))
    printArr(arr);
    else 
    cout<<"No Solutions LOL!> "<<endl;

    return 0;
}