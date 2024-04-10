#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;

class Node{
    public:
        int num;
        Node *next;
        Node *prev;
        Node(int num, Node *next, Node *prev);
};

Node :: Node(int num, Node *next, Node *prev){
    this->next=next;
    this->num=num;
    this->prev=prev;
};

class List{
public:
    Node *root;
    List(){
        root=NULL;
    } 
    List(vector<int>v);
    void list(vector<int>v);
    void insert(int number, int pos);
    void remove(int pos);    
    //void concat(List l1, List l2);
    void print();
    void get(int key);
};

List :: List(vector<int>v){
    list(v);
};

void List :: list(vector<int>v){
    root=NULL;
    for(int i=0; i<v.size(); i++){
        insert(v[i], i);
    }
}

void List :: insert(int number, int pos){
    Node *temp=new Node(0, NULL, NULL);
    temp->prev=NULL;
    temp->next=NULL;
    temp->num=number;
    if(pos<0){
        cout<<"the position is not possible:\n";
        return;
    }
    if(pos==0){
        temp->next=root;
        if(root!=NULL){
            root->prev=temp;
        }
        root=temp;
        return;
    }
    else{
        Node *current=root;
        for(int i=0; i<pos-1; i++){
            if(current!=NULL){
                current=current->next;
            }
        }
        if(current!=NULL){
            temp->next=current->next;
            temp->prev=current;
            if(current->next!=NULL){
            current->next->prev=temp;
            }
            current->next=temp;
        }
    }
}

void List :: remove(int pos){
    if(root==NULL){
        return;
    }
    if(pos==0){
        Node *temp1=root;
        root=root->next;
        if(root!=NULL){
            root->prev=NULL;
            //since the previous node is now removed
        }
        delete temp1;
        return;
    }
    Node *temp2=root;
    int findcount=0;
    while(temp2->next!=NULL){
        temp2=temp2->next;
        findcount++;
        if(findcount==pos){
            break;
        }
    }
    Node *temp3=temp2->next;
    temp2->next=temp2->next->next;
    if(temp2->next!=NULL){
        temp2->next->prev=temp2;
    }
    delete temp3;
}

// void List :: concat(List l1, List l2){
//     Node *a=l1.root;
//     Node *b=l2.root;
//     if(a!=NULL && b!=NULL){
//         Node *current=l1.root;
//         while(current->next!=NULL){
//             current=current->next; 
//         }
//         current->next=l2.root;
//         l2.root->prev=current;
//     }
//     else{
//         cout<<"the two linklist can't be connected";
//     }
// }    

void List :: print(){
    Node *tempprint=root;
    if(tempprint==NULL){
        cout<<"the linklist is empty";
    }
    while(tempprint!=NULL){
        //cout<<tempprint->num<<" ";
        printf("%d", tempprint->num);
        tempprint=tempprint->next;
    }
    cout<<"end of the linklist\n";
}

void List :: get(int key){
    Node *tempget=root;
    if(tempget==NULL){
        cout<<"the list is empty\n";
    }
    int tempcount=0;
    while(tempget!=NULL){
        tempget=tempget->next;
        tempcount++;
        if(tempcount==key){
            printf("%d", tempget->num);
        }
    }
    cout<<"the position does not exist\n";
}

void get_number(List l1, List l2){
    cout<<"which list are you looking for:\n";
    int list_to_get=0;
    scanf("%d", &list_to_get);
    cout<<"now pls enter the position you are searching for:\n";
    int number_to_get=0;
    scanf("%d", &number_to_get);
    if(list_to_get==1){
        l1.get(number_to_get);
    }
    if(list_to_get==2){
        l2.get(number_to_get);
    }
}

int main(){
    vector<int> v1;
    vector<int> v2;
    int n1=0;
    int n2=0;
    cout<<"ple enter the amount of number for the first linklist:\n";
    scanf("%d", &n1);
    cout<<"pls enter the amount of number for the second linklist:\n";
    scanf("%d", &n2);
    for(int i=0; i<n1; i++){
        cout<<"pls enter the"<<i<<"th element for the first linkedlist:\n";
        int tempv1=0;
        scanf("%d", &tempv1);
        v1.push_back(tempv1);
    }
    for(int f=0; f<n2; f++){
        cout<<"pls enter the"<<f<<"th element for the second linkedlist:\n";
        int tempv2=0;
        scanf("%d", &tempv2);
        v2.push_back(tempv2);
    }
    List l1(v1);
    List l2(v2);

    cout<<"the first linkedlist is:\n";
    l1.print();
    cout<<"the seoncd linkedlist is:\n";
    l2.print();
    
    //operations:
    int num_to_insert=0;
    cout<<"pls enter the additional number you want to insert:\n";
    scanf("%d", &num_to_insert);
    cout<<"checkpoint1 \n";
    cout<<"pls enter the integer and their corrosponding position:\n";
    cout<<"checkpoint2 \n";
    int insert_num_array[num_to_insert];
    int insert_pos_array[num_to_insert];
    int temp_insert_pos_array[num_to_insert];
    for(int i=0; i<num_to_insert; i++){
        cout<<"pls enter the"<<i+1<<"th number to be inserted"<<" \n";
        scanf("%d", &insert_num_array[i]);
        // cout<<"pls enter the corrosponding position of the"<<i+1<<"th number"<<" \n";
        // scanf("%d", &insert_pos_array[i]);
        cout<<"the corrosponding position is:"<<i<<" \n";
        insert_pos_array[i]=i;
        cout<<"pls enter the corrosponding position \n";
        scanf("%d", &temp_insert_pos_array[i]);
    }
    // cout<<"this is insert_num_array\n";
    // for(int k=0; k<num_to_insert; k++){
    //     cout<<insert_num_array[k]<<" ";
    // }
    // cout<<"this is insert_position array\n:";
    // for(int d=0; d<num_to_insert; d++){
    //     cout<<temp_insert_pos_array[d]<<" ";
    // }
    

    for(int i=0; i<num_to_insert; i++){
        l1.insert(insert_num_array[i], temp_insert_pos_array[i]);
    }

    cout<<"this is the first linkedlist after inserting:\n";
    l1.print();

    int num_to_remove=0;
    cout<<"pls enter the amount of number to be removed from the second linklist:\n";
    scanf("%d", &num_to_remove);
    if(num_to_remove>0){
        int removing[num_to_remove];
        cout<<"pls enter the position of the number you wish to remove:\n";
        for(int l=0; l<num_to_remove; l++){
            scanf("%d", &removing[l]);
        }
        for(int j=0; j<num_to_remove; j++){
            l2.remove(removing[j]);
        }
    }
    else{
        cout<<"nothing from the second linkedlist will be deleted!\n";
    }
    // cout<<"do you wish to connect the first list and the second list:\n";
    // string answer;
    // scanf("%s", &answer);
    // if(answer=="yes"){
    //     l1.concat(l1, l2);
    // }
    // else{
    //     cout<<"the two list won't be connected\n";
    // }
    cout<<"do you wish to get any element from the list\n";
    string get_answer=0;
    scanf("%s", &get_answer);
    if(get_answer=="yes"){
        get_number(l1, l2);
    }
    else{
        cout<<"the number won't be connected";
    }

    cout<<"the final result is the following:\n";
    cout<<"first list:\n";
    l1.print();
    cout<<"second list:\n";
    l2.print();
    return 0;
}