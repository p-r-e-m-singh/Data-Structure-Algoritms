#include<iostream>
using namespace std;
template<class X>class node{
    public:
    node<X> *left;
    node<X> *right;
    X value;
};
template<class X>class traversals{
    node<X> *temp;
    public:


        void inorder_rec(node<X> *temp){
            if(temp!=nullptr){
                inorder_rec(temp->left);
                cout<<temp->value<<" ";
                inorder_rec(temp->right);
            }
        }
        void preorder_rec(node<X> *temp){

            if(temp!=nullptr){
                cout<<temp->value<<" ";
                preorder_rec(temp->left);
                
                preorder_rec(temp->right);
            }
        }
        void postorder_rec(node<X> *temp){
            if(temp!=nullptr){
                
                postorder_rec(temp->left);
                postorder_rec(temp->right);
                cout<<temp->value<<" ";
            }
        }

        


};
template<class X> class BST{
    
    public:
        node<X> *root;
        BST(){
            root = nullptr;
        }

        void insert(X ele){

            if(root==nullptr){
                root = new node<X>;
                root->value=ele;
                root->left=root->right=nullptr;
            }
            else{
                node<X> *p = root;
                node<X> *q= new node<X>;
                node<X> *p1= new node<X>;
                q->value=ele;
                q->left=q->right=nullptr;
                while(p!=nullptr){
                    if(ele<p->value){
                        p1=p;
                        p=p->left;
                    }
                    else
                    {
                        p1=p;
                        p=p->right;
                    }
                    
                }
                if(ele<p1->value){
                    p1->left=q;
                }
                else if(ele>=p1->value){
                    p1->right=q;
                }
            }
        }

        int height(){

        }

        void delet(X elem){
            node<X> *temp1;
            node<X> *temp = root;
            if(elem<temp->value){
                temp1=temp;
                temp = temp->left;
                if(elem == temp->value){
                    temp1=temp;
                    if(temp1->left==nullptr || temp1->right!=nullptr){
                        temp=temp->right;
                        temp1->value=temp->value;
                        if(temp->left==nullptr){
                            temp=temp->right;
                            temp1->right=temp;

                        }
                        else{
                            temp= temp->left;
                            temp1->right=temp;
                        }
                    }
                    else if (temp1->right = nullptr){
                        
                        while (temp!=nullptr){
                            
                        }
                        
                    }
                    

                }
            }



        }

        // void inorder_rec(node<X> *root){
        //     if(root!=nullptr){
        //         inorder_rec(root->left);
        //         cout<<root->value;
        //         inorder_rec(root->right);
        //     }
        // }
        // void preorder_rec(node<X> *root){

        //     if(root!=nullptr){
        //         cout<<root->value;
        //         inorder_rec(root->left);
                
        //         inorder_rec(root->right);
        //     }
        // }
        // void postorder_rec(node<X> *root){
        //     if(root!=nullptr){
                
        //         inorder_rec(root->left);
        //         inorder_rec(root->right);
        //         cout<<root->value<<" ";
        //     }
        // }
        

};
int main(){
    int choice;
    cout<<"Enter Datatype choice : 1. Integer\n2.Char\n3.Integer\n4.String\nINput : ";

    cin>>choice;
    switch (choice)
    {
    case 1:{
        BST<int> t1;
        int c2;
        cout<<"1.For Insertintg in the BST\n2.For Traversal\n3.For Deletion\n4.To Exit\nEnter : ";
        cin>>c2;
        switch (c2)
        {
        case 1:{
            int noe;
            cout<<"Enter number of values to Enter : ";
            cin>>noe;
            for(int i=0;i<noe;i++){
                int val;
                cout<<"Enter"<<i+1<<"th element";
                cin>>val;
                t1.insert(val);
            }
            break;
        }
        case 2:{
            traversals<int> trav;
            int c3;
            cout<<"1.In order traversal\n2.Pre Order Traversal\n3.Post-Order Traversal\nEnter :";
            cin>>c3;
            switch (c3)
            {
            case 1:{
                trav.inorder_rec(t1.root);
                break;
            }
            case 2:{
                trav.preorder_rec(t1.root);
                break;
            }
            case 3:{
                trav.postorder_rec(t1.root);
                break;
            }
            default:{

                break;
            }
            }
        }
        case 3:{

        }
        default:{
            break;
        }
        }
        break;
    }
    default:
        break;
    }

    
    t1.insert(25);
    t1.insert(20);
    t1.insert(36);
    t1.insert(10);
    t1.insert(22);
    t1.insert(30);
    t1.insert(40);
    t1.insert(5);
    t1.insert(12);
    t1.insert(28);
    t1.insert(38);
    t1.insert(48);
    t1.insert(1);
    t1.insert(8);
    t1.insert(15);
    t1.insert(45);
    t1.insert(50);
    traversals<int> t2;
    t2.inorder_rec(t1.root);cout<<endl;
    t2.preorder_rec(t1.root);cout<<endl;
    t2.postorder_rec(t1.root);cout<<endl;
    return 0;
}