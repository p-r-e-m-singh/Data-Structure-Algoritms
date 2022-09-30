#include<iostream>
#include<string>
using namespace std;

template<class X> class queue {
    int tail,size,head;
    X *stk;
    public:
        queue(){
            tail =head= -1;
            size=0;
        }
        queue(int len){
            tail =head= -1;
            size=len;
            stk = new X[size];
        }
        void clear(){

            tail =head= -1;
        }
        bool isempty(){
            if(tail==-1) return true;
            else return false;

        }

        void push(X ele){
            if(tail==size-1){
                cout<<"queue Overflow!\n";
                return;
            }
            else
            {
                if(isempty()){
                    stk[++tail]=ele;
                    head = 0;
                }
                else
                stk[++tail]=ele;
            }
            
        }

        X dequeue(){
            if(isempty()){
                cout<<"queue is Empty";
                return (X)NULL;
            }
            else{
                return stk[head++];
            }
        }
        void HeadTail(){
            if(isempty()){
                cout<<"No Element at Head-Tail";
                return ;

            }
            else
            {
                cout<<"At Head : "<<stk[head]<<endl;
                cout<<"At Tail :"<<stk[tail]<<endl;
            }
            
        }
        void Display(){
            if(isempty()){
            cout<<"No Element to display!";
                return; 
            }
            for(int i=head;i<tail+1;i++){
                cout<<stk[i]<<" ";
            }cout<<endl;
        }


};
int main(){
    system("cls");
    int choice,noe;
    cout<<"Enter Choice for the type of elements:\n1. Integer\n2.Character\n3.String\n4.Float\nEnter Choice : ";
    cin>>choice;
    cout<<"Enter the length of the queue:";cin>>noe;
    switch (choice)
    {
    case 1:{
        system("cls");
        queue<int> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.dequeue an Element\n5.Inspect tail Element\n6.Display the queue\n0.To Exit the program\nEnter your choice Please : ";
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
                int v = s1.dequeue();
                cout<<"Element dequeueped: " <<v<<endl;
                break;}

            case 5:{
                s1.HeadTail();
                
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
        
        queue<char> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.dequeue an Element\n5.Inspect tail Element\n6.Display the queue\n0.To Exit the program\nEnter your choice Please : ";
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
                char v = s1.dequeue();
                cout<<"Element dequeueped: " <<v<<endl;
                break;}

            case 5:{
                s1.HeadTail();
                
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
        
        queue<string> s1(noe);
        int choice2=1;
        while(choice2!=0){
            
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.dequeue an Element\n5.Inspect tail Element\n6.Display the queue\n0.To Exit the program\nEnter your choice Please : ";
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
                
                cout<<"Element dequeueped: " <<s1.dequeue();
                break;}

            case 5:{
                s1.HeadTail();
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
        
        queue<float> s1(noe);
        int choice2=1;
        while(choice2!=0){
            cout<<"1.Clear the List\n2. Check is EMpty\n3.Push an Element\n4.dequeue an Element\n5.Inspect tail Element\n6.Display the queue\n0.To Exit the program\nEnter your choice Please : ";
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
                float v = s1.dequeue();
                cout<<"Element dequeueped: " <<v<<endl;
                break;}

            case 5:{
                s1.HeadTail();
            
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

// Using Linked Lists


// template<class X> class node{
//     public:
//         X value;
//         node<X> *next;
// };
// template<class X> class queue{
//     node<X> *first=nullptr , *last=nullptr, *temp=nullptr;
//     int size;
//     public:
//         queue(){
//             first=last=temp=nullptr;
//             size=0;
//         }
//         queue(int size){
//             this->size=size;
//             first=last=temp=nullptr;
//         }
//         void enqueue(){
//             int nov;
//             cout<<"Enter number of values you wanna enter";
//             cin>>nov;
//             int s_count=0;
//             if (s_count<size)
//             {
//                 for(int i=1;i<=nov;i++){
//                     X value;
//                     cin>>value;
//                     if(first==nullptr){
                        
//                         temp=new node<X>;
//                         temp->value=value;
//                         temp->next=nullptr;
//                         last=first=temp; 
//                         s_count++;
                    
//                     }
//                     else{

//                         temp = new node<X>;
//                         temp->value=value;
//                         temp->next=nullptr;
//                         last->next = temp;
                
//                         last = temp;
//                         s_count++;


//                     }

//             }
//             }
//             else
//             {
//                 cout<<"Array Overflow"<<endl;
//             }
            
            
//         }
//         bool is_empty(){
//             if(first==nullptr){
//                 return true;
//             }
//             return false;
//         }

//         void dequeue(){
//             if(is_empty()){
//                 cout<<"Array empty! nothng to delete";
//             }

//             else{
//                 temp=first;

//                 while (temp==nullptr)
//                 {
//                     temp=temp->next;

//                 }
//                 temp->value=(X)NULL;

                
//             }
//         }

//         void firstlast(){
//             if(is_empty()){
//                 cout<<"Queue Empty!";
//                 return;
//             }
//             else
//             {
//                 temp=first;

//                 while (temp==nullptr)
//                 {
//                     temp=temp->next;

//                 }
//                 cout<<"Element at first postition: "<<temp->value<<endl;
                
//                 cout<<"Element at last position : "<<last->value<<endl;
//             }
            


//         }

//         void display(){
            
//             if(first==nullptr){
//                 cout<<"List Empty\n";
//             }
//             else{
//                 node<X> *temp1 = first;
//                 while (temp1!=nullptr)
//                 {
//                     if(temp1->value=(X)NULL){
//                         cout<<" ";
//                     }
//                     else
//                     {
//                         cout<<temp1->value<<" ";
//                     }
                    
//                     temp1 = temp1->next;

//                 }
//                 cout<<endl;return;
                
//             }
            
//         }

//         void clear(){
//             node<X> *temp1 = new node<X>;
//             temp = first;
//             while(temp!=nullptr){
//                 temp1 = temp;
//                 temp->next;
//                 delete temp1;
//             }
//         }

//         ~queue(){
//             node<X> *temp1 = new node<X>;
//             temp = first;
//             while(temp!=nullptr){
//                 temp1 = temp;
//                 temp->next;
//                 delete temp1;
//             }
//         }
// };

// int main(){
    
//     queue <int>list1(5);
    

    
//     int choice;
//     do
//     {   
//         cout<<"1. Enqueue\n";
//         cout<<"2. Dequeue\n";
//         cout<<"3. Display\n";
//         cout<<"4. Display first &last\n";
//         cout<<"5. Clear the queue\n";
//         cout<<"0 to exit\n";
        
//         cout<<"Enter your choice : ";
//         cin>>choice;

//         switch (choice)
//         {
//         case 1:
//         list1.enqueue();            
//         break;

//         case 2:
//         list1.dequeue();break;



//         case 3:
//         list1.display();break;


//         case 4:
//         list1.firstlast();


        
//         break;
//         case 5:
//         list1.clear();
//         break;
//         case 0:
//         return 0;

        
//         default:
//             break;
//         }

//     } while (choice!=0);
    
//     return 0;
// }