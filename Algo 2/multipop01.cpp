#include<iostream>
using namespace std;

class stack{
    private: 
        int *arr;
        int top;
        int capacity;

    public :
        void init(int size){
            // arr= (int *)malloc (size * sizeof(int));
            arr=new int[size];
            top= -1;
            capacity= size;
        }

        bool isfull(){
            return (top== capacity - 1);
        }

        void push(int x){
            if(isfull()){
                cout << "Stack Overflow"<<endl;
            }
            else{
                arr[++top]=x;
            }
        }

        bool isempty(){
            return (top==-1);
        }

        void pop(){
            if(isempty()){
                cout << "stack Underflow"<<endl;
            }
            else{
                cout<<arr[top--]<<" is popped."<<endl;
            }
        }

        void multipop(int N){
            if(top>=N-1){
                cout<<N<<" Enough Element present."<<endl;
                for(int i=0;i<N;i++){
                    pop();
                }
            }
            else{
                cout<<"Not enough elements in the stack."<<endl;

                for(int i=0;i<N;i++){
                    pop();
                }
            }
        }

        void display(){
            cout<<"The stack contains : "<<top + 1 <<"elements."<<endl;
            cout<<"Elements are: "<<endl;
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    stack s;
    s.init(11);
    int choice;
    do{
        cout<<"Enter 1 for push"<<endl;
        cout<<"Enter 2 for pop"<<endl;
        cout<<"Enter 3 for multipop"<<endl;
        cout<<"Enter 4 for display"<<endl;
        cout<<"Enter 5 for exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;
        switch(choice){
          case 1: cout<<"Enter elements : ";
            int x;
            cin>>x;
            s.push(x);
            break;
          case 2 : 
            s.pop();
            break;
          case 3 : "How many elements you want to remove?";
            int a;
            cin>>a;
            s.multipop(a);
            break;

          case 4 : 
            s.display();
            break;
              
        }
    }while(choice!=5);

    return 0;
}