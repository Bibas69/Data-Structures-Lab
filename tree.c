#include<stdio.h>
#include<stdlib.h>



struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node * createnode(int value){
    struct Node* n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}
void preorderT(struct Node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorderT(root->left);
        preorderT(root->right);
    }
}
void postorder (struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right); 
    }
}

struct Node* insert(struct Node * root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data<root->data){
        root->left = insert(root->left,data);
    }else{
        root->right = insert(root->right,data);
    }

    return root;
}

int main(){

    struct Node * root = NULL;
    int data;

    while(1){
    int choice;
    printf(" \n 1. insert in bst tree\n 2. Preorder traversal \n 3. postorder \n 4.inorder \n 5. invalid\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter a val for insert\n");
        scanf("%d",&data);
        root = insert(root,data);
        break;
        case 2:
        preorderT(root);
        break;
        case 3:
        postorder(root);
        break;
        inorder(root);
        break;
        default:
        printf("Invalid \n");
    }
    }


}