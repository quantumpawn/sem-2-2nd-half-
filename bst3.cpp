
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

  node* Min(node* root){
	while(root->left != NULL) root = root->left;
	return root;
  }

  // Function to search a delete a value from tree.
  struct node* Delete(struct node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);

	else {
		//No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		//2 children
		else { 
			struct node *temp = Min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
  int c = 0;
  void Countrun(node *curr){
    if (root == NULL){
      cout << 0; 
    }
    if(curr != NULL){
      Countrun(curr->left);
      c = c + 1;
      Countrun(curr->right);
    }
  }
  void Count(node *curr){
    Countrun(curr);
    cout << c << endl;
    c = 0;}

  void Rsearch(node *curr,int K1,int K2){
    if (root == NULL){
      cout << "tree is empty"<<endl; 
    }
    if(curr != NULL){
      Rsearch(curr->left,K1,K2);
      if (curr->data <= K2){
        if (curr->data >= K1){
          cout << curr->data << " ";}}
      Rsearch(curr->right,K1,K2);}

  }

};


int main(){
  BST bst;
  //Inserting nodes
  bst.insert(root,10);
  bst.insert(root,7);
  bst.insert(root,3);
  bst.insert(root,5);
  bst.insert(root,11);
  bst.display(root);  //Displaying initial tree
  cout << endl;
  //Checking if 5 is present:
  bst.bsearch(root,5);

  //Deleting node with val=5:
  bst.Delete(root,5);
  //Diplaying final binary tree:
  bst.display(root);
  cout << endl;
  bst.Count(root);
  bst.Rsearch(root,1,9);
return 0;}

