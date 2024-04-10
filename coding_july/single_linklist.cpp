#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
	    Node* next;
	    Node* previous;
	    int num;
	    Node(Node* next, Node* previous, int num);
};

Node::Node(Node* next, Node* previous, int num){
	this->next = next;
	this->previous = previous;
	this->num = num;
};


class List{
public:
    Node *root=NULL;
    List(){
        root=NULL;
    }
    List(vector<int>v);
    void list(vector<int> v);
    void insert(int position, int number);
    void remove_givenposition(int pos);
    // void remove_giveninteger(int key);
    void concat(List l1, List l2);
    void print();
    void get(int key);
};

List :: List(vector<int>v){
    list(v);
}

void List :: list(vector<int> v){
    root=NULL;
    for(int i=0; i<v.size(); i++){
        insert(i, v[i]);
    }
}

void List :: insert(int position, int number){
    Node *temp=new Node(NULL, NULL, 0);
    temp->num=number;
    temp->next=NULL;

    if(position<0){
        cout<<"the position is not possible:\n";
    }
    if(position==0){
        temp->next=root; //if you are inserting in the first one
        root=temp;
        return;
    }
    else{
        Node* current=root;
        for(int i=0; i<position-1; i++){
            // remember to -1 bcs it only loops until the previous node
            if(current->next!=NULL){
                current=current->next;
            }
        }
        if(current!=NULL){
            temp->next=current->next;
            current->next=temp;
        }
    }
}

void List :: remove_givenposition(int pos){   //removing a number from a given position
    if(root==NULL){
        return;
    }
    if(pos==0){
        Node *temp1=root;
        root=root->next;
        delete temp1;
        return;
    }
    Node *temp2=root;
    int findcount=0;
    while(temp2->next!=0){
        temp2=temp2->next;
        findcount++;
        if(pos==findcount){
            break;
        }
    }
    // if(temp2->next==NULL){ 
    //     return; 
    // }
    Node *temp3=temp2->next;
    temp2->next=temp2->next->next;
    delete temp3;
    // if not misunderstood, temp3 used to save current next pointer, then link current node to next node
    //next, delete the old node which is temp3;
}

// void List :: remove_giveninteger(int key){

// }

void List :: concat(List l1, List l2){
    if(l1.root !=NULL && l2.root !=NULL){
        Node *current=l1.root;
        while(current->next !=NULL){
            current=current->next;
            //l1 iterate till the end of the list, the jump out
        }
        //connect the end of the l1 to the second list
        current->next=l2.root; 
    }
    else{
        cout<<"they can't be connected\n";
    }
}

void List :: print(){
    //this->root;
    Node *tempprint=root;
    if(tempprint==NULL){
        cout<<"the lniklist is empty:\n";
        return;
    }
    while(tempprint!=NULL){
        cout<<tempprint->num<<" ";
        tempprint=tempprint->next;
    }
    cout<<"end of the list \n";
}

void List :: get(int key){
    if(root->next==NULL){
        return;
    }
    else{
        Node *current;
        while(current!=NULL){
            if(current->num==key){
                return;
            }
            else{
                current=current->next;
            }
        }
        return;
    }
}

int main(){
    vector<int> v1;
    vector<int> v2;
    int n1=0;
    int n2=0;
    cout<<"pls enter the number of element for the first linklist:\n";
    scanf("%d", &n1);
    cout<<"pls enter the number of element for the second linklist:\n";
    scanf("%d", &n2);
    cout<<"enter the element for the first linklist:\n";
    for(int i=0; i<n1; i++){
        int tempvector1=0;
        scanf("%d", &tempvector1);
        v1.push_back(tempvector1);
    }
    cout<<"enter the element for the second linklist:\n";
    for(int k=0; k<n2; k++){
        int tempvector2=0;
        scanf("%d", &tempvector2);
        v2.push_back(tempvector2);
    }
    List l1(v1);
    List l2(v2);

    //operations
    l1.insert(2, 3);
    //l1.remove_givenposition(2);
    //l1.remove_givenposition(2);
    l1.concat(l1, l2);
    //slightly modify, if only concat(l2), it is unclear what we want to connect it to!!
    //connect the end of first list to the second one

    cout<<"the first list is:\n";
    l1.print();
    cout<<"the second list is:\n";
    l2.print();
    return 0;
}