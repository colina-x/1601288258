#include<stdio.h>
#include<stdlib.h>

//创建树
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} Node;

//创建树根
typedef struct {
	Node* root;
} Tree;

//插入树
void insert(Tree* tree, int value) {
	Node* node = malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL) {
		tree->root = node;
	}
	else {
		Node* temp = tree->root;
		while (temp != NULL) {
			if (value < temp->data) {
				if (temp->left == NULL) {
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;
				}

			}
		}
	}
}

//前序遍历
void preorder(Node* node) {
	if (node != NULL) {
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

//中序遍历
void inorder(Node* node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}

//后序遍历
void postorder(Node* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}

//左右子树交换
void change(Node* node) {
	if (node != NULL) {
		Node* temp = node->left;
		node->left = node->right;
		node->right = temp;
		change(node->left);
		change(node->right);
	}
}

int main() {

	int arr[7] = { 6,3,8,2,5,1,7 };
	printf("创建BST\n");
	printf("输入数据为：");
	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	Tree tree;
	tree.root = NULL;
	int i;
	for (i = 0; i < 7; i++) {
		insert(&tree, arr[i]);
	}
	printf("\n前序遍历：");
	preorder(tree.root);
	printf("\n中序遍历：");
	inorder(tree.root);
	printf("\n后序遍历：");
	postorder(tree.root);
	printf("\n左右子树交换");
	change(tree.root);
	printf("\n交换后前序遍历：");
	preorder(tree.root);
	printf("\n交换后中序遍历：");
	inorder(tree.root);
	printf("\n交换后后序遍历：");
	postorder(tree.root);
}
