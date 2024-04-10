#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

// class Node {
//     int count;
//     make_pair<int, Node> child =new HashMap<>();
// }

// void add(Node *node, int nums[]){
//     for(int i=0; i<; i++){
//         Node 
//     }
// }

// class TrieNode {
// public:
//     // Define a map attribute to store the child nodes and characters
//     map<char, TrieNode*> children;
//     // Define a flag attribute to indicate whether the node is the end of a word or not
//     bool check_temp;
//     // Define a constructor to initialize the attributes
//     TrieNode() {
//         check_temp = false;
//     }
// };

// class Trie {
// public:
//     // Define a root node attribute
//     TrieNode* root;
//     // Define a constructor to initialize the root node
//     Trie() {
//         root = new TrieNode();
//     }
//     // Define an insert method to insert a string of numbers into the trie
//     void insert(int array[], int size) {
//         // Start from the root node
//         TrieNode* node = root;
       
//         for (int i = 0; i < size; i++) {
          
//             int num = arr[i];
           
//             char c = num + '0';
         
//             if (node->children.count(c) == 0) {
//                 return false;
//             }
          
//             node = node->children[c];
//         }
       
//         return node->flag;
//     }

// };

class TrieNode {
public:
    TrieNode(){
        for(int i=0; i<10; i++){
            number[i]=NULL;
            repeat_time=0;
        }
    }
    TrieNode *number[10];
    int repeat_time;
};

class Trie {
public:
    TrieNode *root;
    Trie() {root=new TrieNode();}
    void insert( int **m, int r, int c){
        cout<<"checkpoint 1\n";
        TrieNode *temp= root;
        for(int i=0; i<r; i++){
            TrieNode *temp= root;
            for(int f=0; f<c; f++){
                cout<<m[i][f]<<"";
                TrieNode *next=temp->number[m[i][f]];
                if(next == NULL){
                next= new TrieNode();
                temp->number[m[i][f]]=next;
                }
                cout<<"\n";
                temp=next;
            }
            temp->repeat_time+=1;
        }
        //temp->repeat_time+=1;
    }  
    int find(int temp_col[], int c){
        cout<<"checkpoint 2\n";
        TrieNode *temp1=root;
        for(int a=0; a<c; a++){
            cout<<temp_col[a]<<"\n";
            if(temp1->number[temp_col[a]] != NULL){
                temp1=temp1->number[temp_col[a]];
            }
            else {
                return 0;
            }
        }
        return temp1->repeat_time;
    }
};

int main(){
    int r=0;
    cout<<"pls enter number of rows:\n";
    scanf("%d", &r);
    cout<<"pls enter number of columns:\n";
    int c=0;
    scanf("%d", &c);
    cout<<"pls enter the element of the matrix\n";
	int **m=(int**)malloc(r*sizeof(int*));
	for(int i=0; i<r;i++){
		m[i]=(int*)malloc(c*sizeof(int));
	}
	for(int i=0; i<r; i++){
		for(int k=0; k<c; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%d", &m[i][k]);
            fflush(stdin);
		}
    }
    Trie tree;
    tree.insert(m, r, c);
    int temp_col[c];
    int result=0;
    for(int k=0; k<c; k++){
        for(int f=0; f<r; f++){
            temp_col[f]=m[f][k];
            cout<<temp_col[f]<<" ";
        }
        cout<<"\n";
        result+=tree.find(temp_col, c);
        // temp_col[k]=0;
    }
    cout<<"the number of pair is"<<result;
    return 0;
}