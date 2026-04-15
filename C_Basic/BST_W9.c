#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode {
    int data;
    struct bstNode* r;
    struct bstNode* l;

}N;


N* addNode(N* root, int input);
int search(N* root, int input);
void inorder(N* root);
void preorder(N* root);
void postorder(N* root);
N* minValueNode(N* root);
N* deleteNode(N* root, int input);
int main()
{
    int inp, n,r;
    N* root = NULL;
    root = addNode(root,50);
    addNode(root, 30);
    addNode(root, 20);
    addNode(root, 40);
    addNode(root, 70);
    addNode(root, 60);
    addNode(root, 80);
    
    printf("Item for search: "); scanf("%d", &inp);
    
    if (search(root,inp)) {
        printf("Item: %d  found\n", inp);
    }
    else printf("Item not found\n");
    if (!root) printf("Tree is empty\n");
    else {
        printf("İnorder:");
        inorder(root);
        printf("\nPreorder:");
        preorder(root);
        printf("\nPostorder: "); postorder(root);

    }

     
    
    
    printf("Item for remove: "); scanf("%d", &r);

    root = deleteNode(root, r);
    
    if (!root) printf("Tree is empty\n");
    else {
        printf("İnorder:");
        inorder(root);
        printf("\nPreorder:");
        preorder(root);
        printf("\nPostorder: "); postorder(root);
        
    }



    return 0;
}

N* addNode(N* root, int input) {
    if (!root) {
        N* n = (N*)malloc(sizeof(N));
        if (!n) return NULL;
        n->data = input;
        n->r = n->l = NULL;
        return n;
    };
    if (root->data > input) {
        root->l = addNode(root->l, input);
    }
    else if (root->data < input) {
        root->r = addNode(root->r, input);

    }
    return root;
}
int search(N* root,int input) {
    if (!root) return 0;
    if (root->data == input) return 1;
    if (root->data > input) {
        return search(root->l, input);
    }
    else return search(root->r, input);

}
void inorder(N* root) {
    if (!root) return;
    
    inorder(root->l);
    printf("%d ", root->data);
    inorder(root->r);

}
void preorder(N* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->l);
    preorder(root->r);

}
void postorder(N* root) {
    if (!root) return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ", root->data);

}
N* minValueNode(N* root) {
    N* curr = root;
    while (curr->l) {
        curr= curr->l;
    }
    return curr;
}
N* deleteNode(N* root, int input) {
    if (!root) return root;

    if (input < root->data)
        root->l = deleteNode(root->l, input);
    else if (input > root->data)
        root->r = deleteNode(root->r, input);
    else {
        if (!root->l) {
            N* temp = root->r;
            free(root);
            return temp;
        }
        else if (!root->r) {
            N* temp = root->l;
            free(root);
            return temp;
        }
        N* temp = minValueNode(root->r);
        root->data = temp->data;
        root->r = deleteNode(root->r, temp->data);
    }
    return root;
}

