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

// 중위 순회
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf("%d ", root->data); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 전위 순회
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 후위 순회
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);	// 왼쪽 서브 트리 순회
		postorder(root->right);	// 오른쪽 서브 트리 순회
		printf("%d ", root->data); 	// 노드 방문
	}
}



//============================배열표현법=============================



// 이진 트리 배열 표현
int tree[15];

// 전위 순회 함수
void preorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        printf("%d ", tree[index]);
        preorderTraversal(2 * index + 1); // 왼쪽 자식
        preorderTraversal(2 * index + 2); // 오른쪽 자식
    }
}

// 중위 순회 함수
void inorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        inorderTraversal(2 * index + 1); // 왼쪽 자식
        printf("%d ", tree[index]);
        inorderTraversal(2 * index + 2); // 오른쪽 자식
    }
}

// 후위 순회 함수
void postorderTraversal(int index) {
    if (index < 15 && tree[index] != -1) {
        postorderTraversal(2 * index + 1); // 왼쪽 자식
        postorderTraversal(2 * index + 2); // 오른쪽 자식
        printf("%d ", tree[index]);
    }
}

int main() {
    // 이진 트리 배열 초기화 (-1은 노드가 없음을 나타냄)
    for (int i = 0; i < 15; i++) {
        tree[i] = -1;
    }

    // 이진 트리 생성
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
    printf("전위 순회 결과: ");
    preorderTraversal(0);
    printf("\n");

    printf("중위 순회 결과: ");
    inorderTraversal(0);
    printf("\n");

    printf("후위 순회 결과: ");
    postorderTraversal(0);
    printf("\n");

  
    printf("linked tree\n");
       

        printf("전위 순회=");
        preorder(root);
        printf("\n");

        printf("중위 순회=");
        inorder(root);
        printf("\n");

        printf("후위 순회=");
        postorder(root);
        printf("\n");
        return 0;
    
}
