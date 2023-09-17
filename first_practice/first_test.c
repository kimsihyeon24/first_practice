#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 8,  NULL, NULL };
TreeNode n7 = { 10, NULL, NULL };
TreeNode n8 = { 11,  NULL, NULL };
TreeNode n9 = { 9, &n7, &n8 };
TreeNode n10 = { 7, &n6, &n9 };
TreeNode n11 = { 1, &n5, &n10 };

TreeNode* root = &n11;

// ���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		postorder(root->right);	// ������ ���� Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
	}
}



//============================�迭ǥ����=============================



// ���� Ʈ�� �迭 ǥ��
int tree[15];

// ���� ��ȸ �Լ�
void preorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        printf("%d ", tree[index]);
        preorderTraversal(2 * index + 1); // ���� �ڽ�
        preorderTraversal(2 * index + 2); // ������ �ڽ�
    }
}

// ���� ��ȸ �Լ�
void inorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        inorderTraversal(2 * index + 1); // ���� �ڽ�
        printf("%d ", tree[index]);
        inorderTraversal(2 * index + 2); // ������ �ڽ�
    }
}

// ���� ��ȸ �Լ�
void postorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        postorderTraversal(2 * index + 1); // ���� �ڽ�
        postorderTraversal(2 * index + 2); // ������ �ڽ�
        printf("%d ", tree[index]);
    }
}

int main() {
    // ���� Ʈ�� �迭 �ʱ�ȭ (-1�� ��尡 ������ ��Ÿ��)
    for (int i = 0; i < 15; i++) {
        tree[i] = -1;
    }

    // ���� Ʈ�� ����
    tree[0] = 1;
    tree[1] = 2;
    tree[2] = 7;
    tree[3] = 3;
    tree[4] = 6;
    tree[5] = 8;
    tree[6] = 9;
    tree[7] = 4; 
    tree[8] = 5; 
    tree[9] = -1;
    tree[10] = -1;
    tree[11] = -1;
    tree[12] = -1;
    tree[13] = 10;
    tree[14] = 11;
    

    printf("array tree\n");
    printf("���� ��ȸ ���: ");
    preorderTraversal(0);
    printf("\n");

    printf("���� ��ȸ ���: ");
    inorderTraversal(0);
    printf("\n");

    printf("���� ��ȸ ���: ");
    postorderTraversal(0);
    printf("\n");

  
    printf("linked tree\n");
       

        printf("���� ��ȸ=");
        preorder(root);
        printf("\n");

        printf("���� ��ȸ=");
        inorder(root);
        printf("\n");

        printf("���� ��ȸ=");
        postorder(root);
        printf("\n");
        return 0;
    
}
