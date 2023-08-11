#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
char name[50];
struct Node* left;
struct Node* right;
int subordinates;
};

struct Node*createNode(char* name);
void calculateSubordinates(struct Node* node);
void inOrderTraversal(struct Node* node);

int main(void) {
struct Node* root = createNode("CEO");
root->left = createNode("Manager 1");
root->left->left = createNode("Employee 1");
root->left->right = createNode("Employee 2");
root->left->right->left = createNode("Employee 3");
root->right = createNode("Manager 2");
root->right->left = createNode("Employee 4");

calculateSubordinates(root);
inOrderTraversal(root);

return 0;
}
struct Node*createNode(char* name){
  struct Node* newNode=malloc(sizeof(struct Node));
  if(newNode==NULL){
    printf("Node creation failed\n");
  }else{
    strcpy(newNode->name,name);
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->subordinates=0;
  }
  return newNode;
}
void calculateSubordinates(struct Node* node){
  if(node==NULL){
    return;
  }
  int leftsubordinates=0;
  int rightsubordinates=0;
  
  calculateSubordinates(node->left);
  calculateSubordinates(node->right);
  
  if(node->left!=NULL){
    leftsubordinates=node->left->subordinates+1;
  }

  if(node->right!=NULL){
    rightsubordinates=node->right->subordinates+1;
  }
  
  node->subordinates=leftsubordinates+rightsubordinates;

}

void inOrderTraversal(struct Node* node){
  if(node==NULL){
    return;
  }
  inOrderTraversal(node->left);
  if(node->subordinates>0){
    printf("Name : %s, Total Subordinates : %d\n",node->name,node->subordinates);
  }
  inOrderTraversal(node->right);
}