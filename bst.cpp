//Original Author: Dripto Biswas
#include <iostream>
using namespace std;

struct node                         //defining node structure

{   int data;
    struct node *left;
    struct node *right;

}*root;

class BST{
  public:
  BST(){
  root = NULL;}
  
  void insert(node *tree, int a){
    node *temp = new node;
    temp->data = a;
    temp->right = NULL;              //Initialising node structure
    temp->left = NULL;
    if (root == NULL){
      root=temp;
    }
    if (tree != NULL){               //self-explanatory
      if (temp->data > tree->data){
        if (tree->right != NULL){
          insert(tree->right,temp->data);}
        else{
          tree->right = temp;}
      }
      if (temp->data < tree->data){
        if (tree->left != NULL){
        insert(tree->left,temp->data);}
        else{
        tree->left = temp;}
        
      }
      if (temp->data == tree->data){
        cout << "node exists already";
      }
    }

  }

  void display(node *curr){            //in-order traversal
    if (root == NULL){
      cout << "tree is empty"<<endl; 
    }
    if(curr != NULL){
      display(curr->left);
      cout << curr->data << " ";
      display(curr->right);}

  }
  void bsearch(node *curr,int val){        //search prints present or absent for search key
    if (root != NULL){
      if (root->data == val){
        cout << val <<" present!" << endl;}
      if (curr != NULL){
        if (val > curr->data){
          bsearch(curr->right,val);}
        if (val < curr->data) {
          bsearch(curr->left,val);}
        if (val == curr->data){
          cout << val << " present!"<< endl;}
      }
      else{
        cout << val << " absent!" << endl;}
    }
  }

};


int main(){
  BST bst;
  bst.insert(root,10);
  bst.insert(root,7);
  bst.insert(root,3);
  bst.insert(root,5);
  bst.insert(root,11);
  bst.display(root);
  cout << endl;
  bst.bsearch(root,1);
  bst.bsearch(root,7);

return 0;}






























































//Orginal Author: Dripto Biswas
