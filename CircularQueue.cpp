#include<iostream>
using namespace std;

class CircularQue{ 
    public: 
    int items[20];
    int front,rear;

    CircularQue(){ 
        front = rear = -1;
        }

    bool isEmpty();
    bool isFull();
    void enQueue(int x);
    int deQueue();


    void roundRobinScheduling(int processes[], int n, int burstTime[], int timeQuantum){ 

        CircularQue readyQue;
        int remainingBurstTime[n];

        for(int  i=0; i<n; i++){ 
            remainingBurstTime[i] = burstTime[i];
        }

        int currentTime = 0;

        while(true){ 

            bool allProcessesComplete = true;

            for(int i=0; i<n; i++){ 

                if(remainingBurstTime[i]>0){
                    allProcessesComplete = false;

                    if(remainingBurstTime[i]>timeQuantum){ 
                        currentTime+=timeQuantum;
                        remainingBurstTime[i]-=timeQuantum;
                        readyQue.enQueue(processes[i]);
                    }
                    else{ 
                        currentTime +=remainingBurstTime[i];
                        remainingBurstTime[i]=0;
                        cout<<"Process "<<processes[i]<<" Completed at a time "<<currentTime <<endl;
                    }

                }

            }

            if(allProcessesComplete)
                break;

            while(!readyQue.isEmpty()){ 

                int frontProcess = readyQue.deQueue();
                cout<<"Process "<<frontProcess <<" resumed execution at time "<<currentTime<<endl;

                if(remainingBurstTime[frontProcess]> timeQuantum){ 
                    currentTime +=timeQuantum;
                    remainingBurstTime[frontProcess]-=timeQuantum;
                    readyQue.enQueue(frontProcess);
                }
                else{ 
                    currentTime +=remainingBurstTime[frontProcess];
                    remainingBurstTime[frontProcess] = 0;
                    cout<<"Process "<<frontProcess<<" completed at a time "<<currentTime<<endl;
                }
            }
        }
    }

};

void CircularQue::enQueue(int data){

    if(isFull()){
        cout<<"Queue is Full>!!lol"<<endl; 
    }
    else{ 
        if(isEmpty()){ 
            front = 0;
            rear = 0;
        }
        else{ 
            rear = (rear+1)%20;
        }
        items[rear] = data;
    }

}

int CircularQue::deQueue(){ 

    int temp;

    if(isEmpty()){
        cout<<"Queue is Empty.!"<<endl;
        return -1;
    }
    else if(front ==rear){
        temp = items[front];
        front= rear = -1;
    }
    else{
        temp = items[front];
        front = (front + 1) % 20; 
    }
        return temp;
}


bool CircularQue::isFull(){

    if((rear+1)%20 == front)
    return true;
    else
    return false;
}

bool CircularQue::isEmpty(){ 

    if(front == -1 && rear == -1)
    return false;
    else
    return true;

}





int main(){ 

    int n,timeQuantum;
    cout<<"Enter Number of Processes: "<<endl;
    cin>>n;

    int processes[n];
    int burstTime[n];

    for(int i=0; i<n; i++){ 
        cout<<"Enter Process ID for "<<i+1<<"th Process: ";
        cin>>processes[i];
        cout<<"Enter Burst Time For Process "<<i+1<<": ";
        cin>>burstTime[i];

        

    }
    cout<<"Enter Time Qunatum: "<<endl;
        cin>>timeQuantum;

    return 0;
}