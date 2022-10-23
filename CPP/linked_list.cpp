#include<bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    int val;
};
node* getnode(int v){
    node* x = new node;
    x->val = v;
    x->next  = NULL;
    return x;
}
void insert(node* &curr, int val){
    curr->next = getnode(val);
    curr = curr->next;
}

bool search(node* root, int v){
    node* temp = root;
    while(temp!=NULL){
        if(temp->val==v){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node* root = getnode(-1);
    node* curr = root;

    int n;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        int x;
        cin>>x;
        insert(curr,x);
    }

    root  = root->next;
    curr = root;
    while(curr){
        cout<<curr->val<<" -> ";
        curr = curr->next;
    }
    cout<<"NULL";

}
