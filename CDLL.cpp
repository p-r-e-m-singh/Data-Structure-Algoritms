#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

template<class X> class node{
    public:
        X value;
        node<X> *next;
        node<X> *prev;
};
template<class X> class CDLL{
    node<X> *last,*temp;
    public:
        CDLL(){
            last = temp=nullptr;

        }
        void addtotail(){
            int nov;
            cout<<"Enter number of values you wanna enter";
            cin>>nov;

            for(int i=1;i<=nov;i++){
                X value;
                cin>>value;
                if(last==nullptr){
                    
                    temp=new node<X>;
                    temp->value=value;
                    temp->next=temp->prev=temp;
                    last=temp; 
                
                }
                else{

                    temp = new node<X>;
                    temp->value=value;
                    temp->next=last->next;
                    last->next->prev=temp;
                    temp->prev=last;
                    last->next = temp;
            
                    last = temp;

                }
            }
        }

        void addtohead(){
            int nov;
            cout<<"Enter number of values you wanna enter";
            cin>>nov;

            for(int i=1;i<=nov;i++){
                X value;
                cin>>value;
                if(last==nullptr){
                    
                    temp=new node<X>;
                    temp->value=value;
                    temp->next=temp->prev=temp;
                    last=temp;
                
                }
                else{

                    temp = new node<X>;
                    temp->value=value;
                    temp->prev=last;
                    temp->next = last->next;
                    last->next->prev=temp;
                    last->next=temp;

                }
            }

        }
        //Need to correct this
        void insert_at_i(){
            int i,pos = 1;
            X value;
            cout<<"Enter the value of i: ";
            cin>>i;
            cout<<"Enter the value to be inserted : ";
            cin>>value;
            temp = new node<X>;
            node<X> *temp1,*temp2 = new node<X>;
            temp1->value=value;

            if(last==nullptr){
                cout<<"Array Is Empty\n + Addding at 1st Position\n";
                last = temp1;
                last->next=last->prev=last;
                

            }
            else{
                 temp = last->next;
                 while (i!=pos)
                {
                    temp2 = temp;
                    temp = temp->next;
                    pos++;
                
                }
                if(temp==last){

                    temp2->next=temp1;
                    temp1->prev=temp2;
                    temp1->next=temp;

                }
                else if (temp==last->next)
                {
                    temp1->next=temp;
                    temp->prev=temp1;
                    temp1->prev=last;
                    temp->next=temp1;
                }
                
                temp2->next=temp1;
                temp1->prev=temp2;
                temp1->next=temp;
                temp->prev=temp1;

            }
            
        }

        void remove_from_i()
        {
            int i;
            cout<<"Enter the value of i: ";
            cin>>i;
            int pos = 1;
            temp = new node<X>;
            if(last->next == nullptr){
                cout<<"List Empty can't delete";

            }

            else
            {
                node<X> *temp1 = new node<X>;
                temp = last->next;
                while(pos!=i){
                    temp1 = temp;
                    temp = temp->next;
                    pos++;
                }
                if(pos==1){
                    temp->next->prev=last;
                    temp = temp->next->prev; 
                    delete temp;

                }
                else if(temp == last){
                    temp1->next=temp->next;
                    temp->next->prev=temp1;
                    last=temp1;
                    delete temp;
                }

                else
                {
                    temp1->next=temp->next;
                    temp->next->prev=temp1;
                    delete temp;
                }
                

            }
            
        }
        
        // To be made further
        // /*void addinbw(){
        //     if(last->next==nullptr){
        //         cout<<"No Linked List exist to make addition in between";
        //     }
        //     else{
        //         X bwelem,prelem;
        //         temp = new node<X>;
        //         node<X>* temp1 = new node<X>;
        //         cout<<"Enter the element to be inserted";
        //         cin>>bwelem;
        //         temp1->value=bwelem;
        //         cout<<"Enter the value of the element after which "<<bwelem<<" is to be inserted";
        //         cin>>prelem;
        //         temp = last->next;
        //         while(temp->value!=prelem){
        //             temp = temp->next;
        //         }
        //         temp1->next=temp->next;
        //         temp->next = temp1;
                

                    
    
                

        //     }
        // }*/

        void deletefromstart(){
            if(last->next==nullptr){
                cout<<"Array empty! nothng to delete";
            }

            else{
                temp = new node<X>;
                temp = last->next;
                last->next=temp->next;
                delete temp;

            }
        }
        void deletefromend(){
            if(last->next==nullptr){
                cout<<"Array empty! nothng to delete";
            }

            else{
                temp = new node<X>;
                temp = last->prev;
                temp->next=last->next;
                last->next->prev=temp;
                delete last;
                last = temp;
                


               
            }
        }

        // void deleteinbw(){
        //     if(last->next==nullptr) cout<<"List Empty";
        //     else{
        //         X delem;
        //         cout<<"Enter the element to be deleted in b/w the linked list : ";
        //         cin>>delem;
        //         temp = new node<X>();
        //         temp = last->next;
        //         node<X> *temp1 = new node<X>;
        //         while (temp->value!=delem)
        //         {
        //             temp1=temp;
        //             temp = temp->next;
        //         }

        //         temp1->next = temp->next;
        //         temp->next->prev=temp1;
        //         delete temp;



                

        //     }
        // }
                // Start from here
        void operator +(CDLL l2){
            if(l2.last=nullptr){
                return;
            }
            else if(last=nullptr){
                last= l2.last;
            }
            else
            {
                node<X> *temp1 = new node<X>;
                temp1 = l2.last->next;
                
                l2.last->next = this->last->next;
                last->next = temp1;
                this->last->next->prev=l2.last;

                
                last = l2.last;
            }
            
            


        }


        void reverse(){
            
            node<X>* templast = new node<X>;
            temp = new node<X>;
            templast=last;
            
            while (templast!=last->next)
            {
                temp = templast;
                templast = templast->prev;
                swap(temp->next,temp->prev);

            }
            swap(templast->next,templast->prev);
            swap(last->next,last);
            
        }



        void search_elem(){
            int pos=1;
            X elem;
            cout<<"Enter the element you want to search : ";
            cin>>elem;
            temp = new node<X>;
            temp = last->next;
            while(temp->value!=elem){
                temp = temp->next;
                pos++;
            }
            cout<<"Element is at "<<pos<<"th position\n";


        }

        void display(){
            
            if(last->next==nullptr){
                cout<<"List Empty\n";
            }
            else{
                node<X> *temp1 = last->next;
                do
                {
                    cout<<temp1->value<<" ";
                    temp1 = temp1->next;
                } while (temp1!=last->next);
                
                cout<<endl;return;
                
            }
            
        }

        ~CDLL(){
            node<X> *temp1 = new node<X>;
            temp = last->next;
            do
            {
                temp1 = temp;
                temp->next;
                delete temp1;
            } while (temp!=last);
            
            delete temp;
        }
};

int main(){
    
    
    int type;
    cout<<"Ënter the dataype you want to continue with \n1.Integer \n2.Character \n3.String \n4.Float \n5.Boolean\n";
    cin>>type;
    switch (type)
    {
    case 1:{
        CDLL <int>list1,list2;
        int choice;
        do
        {   
            cout<<"1. add to Tail\n";
            cout<<"2. Add to Head\n";
            cout<<"3. Add in between\n";
            cout<<"4. Delete from Beginiing\n";
            cout<<"5. Delete from end\n";
            cout<<"6.Delete in between\n";
            cout<<"7.Display the list\n";
            cout<<"8. Insert in at ith pos\n";
            cout<<"9.Delete from ith pos\n";
            cout<<"10. Search in the list\n";
            cout<<"11. Concatenate two lists\n";

            cout<<"12. Reverse the list\n";
            cout<<"0 to exit\n";

            cout<<"Enter your choice : ";
            cin>>choice;

            switch (choice)
            {
            case 1:
            list1.addtotail();            
            break;

            case 2:
            list1.addtohead();break;

            case 3:
            // list1.addinbw();
            break;


            case 4:
            list1.deletefromstart();break;

            case 5:
            list1.deletefromend();break;

            case 6:
            // list1.deleteinbw();break;


            case 7:
            list1.display();break;

            case 8:
            list1.insert_at_i();break;

            case 9:
            list1.remove_from_i();break;

            case 10:
            list1.search_elem();

            break;

            case 11:
            list2.addtotail();
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
            break;

            case 12:
            list1.reverse();
            break;

            case 0:
            return 0;


            default:
                break;
            }

        } while (choice!=0);
            return 0;
        break;
    }
    case 2:{
        CDLL <char>list1,list2;
        int choice;
        do
        {   
            cout<<"1. add to Tail\n";
            cout<<"2. Add to Head\n";
            cout<<"3. Add in between\n";
            cout<<"4. Delete from Beginiing\n";
            cout<<"5. Delete from end\n";
            cout<<"6.Delete in between\n";
            cout<<"7.Display the list\n";
            cout<<"8. Insert in at ith pos\n";
            cout<<"9.Delete from ith pos\n";
            cout<<"10. Search in the list\n";
            cout<<"11. Concatenate two lists\n";
            cout<<"12. Reverse the list\n";
            cout<<"0 to exit\n";

            cout<<"Enter your choice : ";
            cin>>choice;

            switch (choice)
            {
            case 1:
            list1.addtotail();            
            break;

            case 2:
            list1.addtohead();break;

            case 3:
            // list1.addinbw();break;


            case 4:
            list1.deletefromstart();break;

            case 5:
            list1.deletefromend();break;

            case 6:
            // list1.deleteinbw();break;


            case 7:
            list1.display();break;

            case 8:
            list1.insert_at_i();break;

            case 9:
            list1.remove_from_i();break;

            case 10:
            list1.search_elem();

            break;

            case 11:
            list2.addtotail();
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
            break;

            case 12:
            list1.reverse();
            break;

            case 0:

            return 0;
            break;


            default:
                break;
            }

        } while (choice!=0);
            return 0;
        break;
    }
    case 3:{
        CDLL <string>list1,list2;
        int choice;
        do
        {   
            cout<<"1. add to Tail\n";
            cout<<"2. Add to Head\n";
            cout<<"3. Add in between\n";
            cout<<"4. Delete from Beginiing\n";
            cout<<"5. Delete from end\n";
            cout<<"6.Delete in between\n";
            cout<<"7.Display the list\n";
            cout<<"8. Insert in at ith pos\n";
            cout<<"9.Delete from ith pos\n";
            cout<<"10. Search in the list\n";
            cout<<"11. Concatenate two lists\n";

            cout<<"12. Reverse the list\n";
            cout<<"0 to exit\n";

            cout<<"Enter your choice : ";
            cin>>choice;

            switch (choice)
            {
            case 1:
            list1.addtotail();            
            break;

            case 2:
            list1.addtohead();break;

            case 3:
            // list1.addinbw();break;


            case 4:
            list1.deletefromstart();break;

            case 5:
            list1.deletefromend();break;

            case 6:
            // list1.deleteinbw();break;


            case 7:
            list1.display();break;

            case 8:
            list1.insert_at_i();break;

            case 9:
            list1.remove_from_i();break;

            case 10:
            list1.search_elem();

            break;

            case 11:
            list2.addtotail();
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
            break;

            case 12:
            list1.reverse();
            break;

            case 0:
            return 0;
            break;


            default:
                break;
            }

        } while (choice!=0);
            return 0;
        break;
    }
    case 4:{
        CDLL <float>list1;
        CDLL<float>list2;
        int choice;
        do
        {   
            cout<<"1. add to Tail\n";
            cout<<"2. Add to Head\n";
            cout<<"3. Add in between\n";
            cout<<"4. Delete from Beginiing\n";
            cout<<"5. Delete from end\n";
            cout<<"6.Delete in between\n";
            cout<<"7.Display the list\n";
            cout<<"8. Insert in at ith pos\n";
            cout<<"9.Delete from ith pos\n";
            cout<<"10. Search in the list\n";
            cout<<"11. Concatenate two lists\n";

            cout<<"12. Reverse the list\n";
            cout<<"0 to exit\n";
            
            cout<<"Enter your choice : ";
            cin>>choice;

            switch (choice)
            {
            case 1:
            list1.addtotail();            
            break;

            case 2:
            list1.addtohead();break;

            case 3:
            // list1.addinbw();break;


            case 4:
            list1.deletefromstart();break;

            case 5:
            list1.deletefromend();break;

            case 6:
            // list1.deleteinbw();break;


            case 7:
            list1.display();break;

            case 8:
            list1.insert_at_i();break;

            case 9:
            list1.remove_from_i();break;

            case 10:
            list1.search_elem();
            
            break;

            case 11:
            list2.addtotail();
            list1+list2;
            cout<<"After Concatenation, new List obtained is :";
            list1.display();
            break;

            case 12:
            list1.reverse();
            break;

            case 0:
            return 0;
            break;

            
            default:
                break;
            }

        } while (choice!=0);
             return 0;
        break;
    }
    case 5:{
        CDLL <bool>list1,list2;
        int choice;
    do
    {   
        cout<<"1. add to Tail\n";
        cout<<"2. Add to Head\n";
        cout<<"3. Add in between\n";
        cout<<"4. Delete from Beginiing\n";
        cout<<"5. Delete from end\n";
        cout<<"6.Delete in between\n";
        cout<<"7.Display the list\n";
        cout<<"8. Insert in at ith pos\n";
        cout<<"9.Delete from ith pos\n";
        cout<<"10. Search in the list\n";
        cout<<"11. Concatenate two lists\n";

        cout<<"12. Reverse the list\n";
        cout<<"0 to exit\n";
        
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
        list1.addtotail();            
        break;

        case 2:
        list1.addtohead();break;

        case 3:
        // list1.addinbw();break;


        case 4:
        list1.deletefromstart();break;

        case 5:
        list1.deletefromend();break;

        case 6:
        // list1.deleteinbw();break;


        case 7:
        list1.display();break;

        case 8:
        list1.insert_at_i();break;

        case 9:
        list1.remove_from_i();break;

        case 10:
        list1.search_elem();
        
        break;

        case 11:
        list2.addtotail();
        list1+list2;
        cout<<"After Concatenation, new List obtained is :";
        list1.display();
        break;

        case 12:
        list1.reverse();
        break;

        case 0:
        return 0;
        break;

        
        default:
            break;
        }

    } while (choice!=0);
        return 0;
        break;
    }

    
    default:
        cout<<"Enter correct option! --fatal error";
        return 0;
        break;
    }
    return 0;
}