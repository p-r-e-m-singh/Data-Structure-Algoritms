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

        void inorder_rec(node<X> *root){
            if(root!=nullptr){
                inorder_rec(root->left);
                cout<<root->value;
                inorder_rec(root->right);
            }
        }
        void preorder_rec(node<X> *root){

            if(root!=nullptr){
                cout<<root->value;
                inorder_rec(root->left);
                
                inorder_rec(root->right);
            }
        }
        void postorder_rec(node<X> *root){
            if(root!=nullptr){
                
                inorder_rec(root->left);
                inorder_rec(root->right);
                cout<<root->value<<" ";
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
    BST<int> t1;
    t1.insert(5);
    t1.insert(6);
    t1.insert(1);
    traversals<int> t2;
    t2.inorder_rec(t1.root);cout<<endl;
    t2.preorder_rec(t1.root);cout<<endl;
    t2.postorder_rec(t1.root);cout<<endl;
    return 0;
}