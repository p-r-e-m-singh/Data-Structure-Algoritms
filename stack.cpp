#include<iostream>
#include<string>
using namespace std;

template<class X> class stack {
    int top,size;
    X *stk;
    public:
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
        system("wait");
    }


};
int main(){
    system("cls");
    int choice,noe;
    cout<<"Enter Choice for the type of elements:\n1. Integer\n2.Character\n3.String\n4.Float\nEnter Choice : ";
    cin>>choice;
    cout<<"Enter the length of the stack:";cin>>noe;
    switch (choice)
    {
    case 1:{
        system("cls");
        stack<int> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.Pop an Element\n5.Inspect Top Element\n6.Display the stack\n0.To Exit the program\nEnter your choice Please : ";
            cin>>choice2;
            switch (choice2)
            {
            case 1:
                {s1.clear();
                break;}
            case 2:{
                if(s1.isempty()) cout<<"Yes! Its Empty\n";
                else cout<<"No Its non empty\n";
                break;}
            case 3:{
                int ele;
                cout<<"enter the element : ";
                cin>>ele;
                s1.push(ele);
                break;}
            case 4:{
                int v = s1.pop();
                cout<<"Element popped: " <<v<<endl;
                break;}

            case 5:{
                s1.topEl();
                
                break;}
            case 6:{
                s1.Display();
                break;}
            default:{
                break;}
            }
        }
        break;
    }
    case 2:{
        
        stack<char> s1(noe);
        int choice2;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.Pop an Element\n5.Inspect Top Element\n6.Display the stack\n0.To Exit the program\nEnter your choice Please : ";
            cin>>choice2;
            switch (choice2)
            {
            case 1:{
                s1.clear();
                break;}
            case 2:{
                if(s1.isempty()) cout<<"Yes! Its Empty\n";
                else cout<<"No Its non empty\n";
                break;}
            case 3:{
                char ele;
                cout<<"enter the element : ";
                cin>>ele;
                s1.push(ele);
                break;}
            case 4:{
                char v = s1.pop();
                cout<<"Element popped: " <<v<<endl;
                break;}

            case 5:{
                s1.topEl();
                
                break;}
            case 6:{
                s1.Display();
                break;}
            default:{
                break;}
            }
        }
        break;
    }
    case 3:{
        
        stack<string> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.Pop an Element\n5.Inspect Top Element\n6.Display the stack\n0.To Exit the program\nEnter your choice Please : ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:{
                s1.clear();
                break;}
            case 2:{
                if(s1.isempty()) cout<<"Yes! Its Empty\n";
                else cout<<"No Its non empty\n";
                break;}
            case 3:{
                string elem="";
                cout<<"enter the element : ";
                cin>>elem;
                s1.push(elem);
                break;}
            case 4:{
                
                cout<<"Element popped: " <<s1.pop();
                break;}

            case 5:{
                s1.topEl();
                break;}
            case 6:{
                s1.Display();
                break;}
            default:{
                break;}
            }
        }
        break;
    }
    case 4:{
        
        stack<float> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.Pop an Element\n5.Inspect Top Element\n6.Display the stack\n0.To Exit the program\nEnter your choice Please : ";
            cin>>choice2;
            switch (choice2)
            {
            case 1:{
                s1.clear();
                break;}
            case 2:{
                if(s1.isempty()) cout<<"Yes! Its Empty\n";
                else cout<<"No Its non empty\n";
                break;}
            case 3:{
                float ele;
                cout<<"enter the element : ";
                cin>>ele;
                s1.push(ele);
                break;}
            case 4:{
                float v = s1.pop();
                cout<<"Element popped: " <<v<<endl;
                break;}

            case 5:{
                s1.topEl();
            
                break;}
            case 6:{
                s1.Display();
                break;}
            default:{
                break;}
            }
        }
        break;
    
    
    }
    default:{
        break;
    
    }
    }
    return 0;
}

// Using Linked List
