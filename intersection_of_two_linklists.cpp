#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
	int num;
	struct node *next=NULL;
};

typedef struct node node;

void print_linked_list(node *root_node){
	node* iternode = root_node;
	
	while(iternode != NULL){
		printf("%d ", iternode->num);
		iternode = iternode->next;
	}
}

int length(node *root){
    int len=0;
    while(root->next!=NULL){
        len++;
        root=root->next;
    }
    return len+1;
}

node *findintersection(node *root, node *root2){
    print_linked_list(root);
    print_linked_list(root2);
    int N=0;
    int N2=0;
    N=length(root);
    N2=length(root2);
	node *a=root;
    node *b=root2;
    cout<<N<<" "<<N2;
    if(N>N2){
        while(N>N2){
            a=a->next;
            N--;
        }
    }
    else if(N<N2){
        while(N<N2){
            b=b->next;
            N2--;
        }
    }
    while(a!=NULL && b!=NULL){
        if(a==b){
            return a;
        }
        a=a->next;
        b=b->next;
    }
    return NULL;
}

void mergelinkedlist(node *root, node *root2, node *root3){
    node *temp=root;
    node *temp2=root2;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->next==NULL){
            temp->next=root3;
            break;
        }
    }
    while(temp2!=NULL){
        temp2=temp2->next;
        if(temp2->next==NULL){
            temp2->next=root3;
            break;
        }
    }
    return;
}

node *createlinklist(){ 
    int N=0;
    cout<<"pls enter the length of the linklist:\n";
    scanf("%d", &N);
    if(N==0){
        return NULL;
    }
    int number=0;
    int c=0;
    node *root=new node;
    node *temp=root;
    scanf("%d", &number);
    root->num=number;
    for(int i=1; i<N; i++){
        // if (c==0){
        //     scanf("%d", &number);
        //     temp->num=number;
        //     root->next=temp;
        //     c++;
        // }
    //    else{
            scanf("%d", &number);
            node *temp1=new node;
            temp1->num=number;
            temp->next=temp1;
            temp=temp1;
     //   }
    }
    return root;
}



int main(){
	cout<<"pls enter the first linklist:\n";
    node *root=NULL;
    root=createlinklist();
    print_linked_list(root);
    cout<<"pls enter the second linklist:\n";
    node*root2=NULL;
    root2=createlinklist();
    print_linked_list(root2);
    cout<<"pls enter the merged section of linklist:\n";
    node *root3=createlinklist();
    mergelinkedlist(root, root2, root3);
    node *result=NULL;
    result=findintersection(root, root2);
    cout<<"the intersection of two linklist is:\n"<<result->num;
    return 0;
}