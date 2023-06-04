#include<bits/stdc++.h>
using namespace std;
#define maxv 1e9
class node{
    public:
    int data;
    node*left;
    node*right;
    bool lthrd;
    bool rthrd;
};

class tree{
    
    public:
    node*root;
    tree(){
        root=new node();
        root->right=root;
        root->left=root;
        root->lthrd=true;
        root->data=maxv;
    }
    void insert(int key);
    void inorder();
};

void tree::inorder(){
    node*temp,*p;
    temp=root;
    while(true){
        p=temp;
        temp=temp->right;
        if(p->rthrd==false){
            while(temp->lthrd==false){
                temp=temp->left;
            }
        }
        if(temp==root)break;
        cout<<temp->data<<" ";
       
    }
    cout<<endl;
}


void tree::insert(int key){
    node*p=root;
    for(;;){
        if(p->data>key){
            if(p->lthrd==true){break;}
            p=p->left;
        }
        else if(p->data<key){
            if(p->rthrd==true){break;}
            p=p->right;
        }
        else {
            cout<<"wrong entry"<<endl;
            return;
        }
    }
    node*temp=new node();
    temp->data=key;
    temp->rthrd=temp->lthrd=true;
    if(p->data>key){
        temp->left=p->left;
        p->lthrd=false;
        temp->right=p;
        p->left=temp;
    }
    else if(p->data<key){
        temp->left=p;
        temp->right=p->right;
        p->rthrd=false;
        p->right=temp;
    }

}

int main(){
    tree t1;
    int t=-1;
    while(true){
        cout<<"1 to insert "<<endl;
        cout<<"2 for inorder "<<endl;
        cout<<"any other to exit"<<endl;
        cout<<"enter the choice: ";
        cin>>t;
        if(t==1){
            cout<<"enter the element to insert"<<endl;
            int key; cin>>key;
            t1.insert(key);
        }
        else if(t==2){
            cout<<"inorder is :"<<endl;
            cout<<"fck"<<endl;
            t1.inorder();
        }
        else break;
        cout<<"asdfgh"<<endl;
    }
}
