#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int num;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;

        TreeNode(){
            num=0;
            left=right=parent=NULL;
        }
        TreeNode(int k){
            num=k;
            left=right=parent=NULL;
        }
        TreeNode(int k, Node *l, Node*r, Node *p){
            this->num=k;
            this->left=l;
            this->right=r;
            this->parent=p;
        }   
};

class Tree{
    public:
        void buildtree();
        void insert(TreeNode *node, int num);
        void remove();
        void print_preorder();
        void print_levelorder();
        void get();
};

void Tree :: buildtree(){

}

void Tree :: insert(TreeNode *node, int num){
    if(node==NULL){

    }
    if(num<node->num){
        node->left=insert(node->left, num);
    }
}

void Tree :: remove(){

}

void Tree :: print_preorder(){

}

void Tree :: print_levelorder(){

}

void Tree :: get(){

}

int main(){
    vector<int>v1;
    cout<<"pls enter the number of nodes for the tree:\n";
    int n=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int tempv1=0;
        scanf("%d", &tempv1);
        v1.push_back(tempv1);
    }
    Tree t1(v1);

    cout<<"do you wish to insert anything, if yes pls enter the amount of node:\n";
    string answer;
    scanf("%s", &answer);
    if(answer=="yes"){
        int num_to_insert=0;
        cout<<"pls enter the amount:\n";
        scanf("%d", &num_to_insert);
        int insert_array[num_to_insert];
        for(int k=0; k<num_to_insert; k++){
            scanf("%d", &insert_array[k]);
        }
        for(int f=0; f<num_to_insert; f++){
            t1.insert(insert_array[f]);
        }
    }

    cout<<"The pre-order traversal of the tree is:\n";
    t1.print_preorder();
    cout<<'the level-order traversal of the tree is;\n';
    t1.print_levelorder();
    return 0;
}