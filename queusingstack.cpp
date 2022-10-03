#include<iostream>
using namespace std;
template<class X> class stack {
    
    X *stk;
    public:
    int top,size;
    stack(){
        top = -1;
        size=0;
        stk = nullptr;
    }
    stack(int len){
        top = -1;
        size=len;
        stk = new X[size];
    }
    void clear(){
        top = -1;
    }
    bool isempty(){
        if(top==-1) return true;
        else return false;

    }

    void push(X ele){
        if(top==size-1){
            cout<<"Stack Overflow!\n";
            return;
        }
        else
        {
            stk[++top]=ele;
        }
        
    }

    X pop(){
        if(isempty()){
            cout<<"Stack is Empty";
            return (X)NULL;
        }
        else{
            return stk[top--];
        }
    }
    void topEl(){
        if(isempty()){
            cout<<"No Element at top!";
            return ;

        }
        else
        {
            cout<<stk[top];
        }
        
    }
    void Display(){
        if(isempty()){
           cout<<"No Element to display!";
            return; 
        }
        for(int i=0;i<top+1;i++){
            cout<<stk[i]<<" ";
        }cout<<endl;
    }


};
template<class X> class qusingstk{
    int size,first,last;
    stack<X> ar;
    public:
        qusingstk(){
            size=0;
            first=last=-1;
            ar = nullptr;

        }
        qusingstk(int len){
            this->size=len;
            first=last=-1;
            ar = X(size);
            ar.top=-1;
        }
        void enqueue(X ele){
            ar.push(ele);
        }

        X dequeue(){
            stack<X> stk2(size);
            while(ar.top!=-1){
                stk2.push(ar.pop());
            }

            X rtn= stk2.pop();
            while (stk2.top!=-1)
            {
                ar.push(stk2.pop());
            }
            return rtn;
            

        }
        void display(){
            ar.Display();
        }
};


int main(){
    qusingstk<int> obj(5);
    obj.enqueue(5);
    obj.enqueue(10);
    cout<<obj.dequeue();
    obj.display();

    return 0;
}