 #include <stdio.h>
 #include <stdlib.h>

 #define NODECOUNT 7

  struct bstNode {
        int data;
        struct bstNode *lchild, *rchild;
  };

  struct bstNode *root = NULL;
  int bstData[] = {100, 80, 120, 70, 90, 110, 130};
  int count = 0;

  /* construct binary search tree from Arrays */
  struct bstNode * implementBSTtree(int n) {
        struct bstNode *newnode;

        if (n >= NODECOUNT)
                return NULL;

        newnode = (struct bstNode *)malloc(sizeof (struct bstNode));
        /* node at position n - have its left child at the position (2 * n) + 1 */
        newnode->lchild = implementBSTtree((2 * n) + 1);
        newnode->data   = bstData[n];
        /* node at position n - have right child at the position (2 * n) + 2 */
        newnode->rchild = implementBSTtree((2 * n) + 2);
        return newnode;
  }

  /* Pre-Order traversal in Binary Search Tree */
  void preOrder(struct bstNode *myNode) {
        if (myNode) {
                printf("%d ", myNode->data);
                preOrder(myNode->lchild);
                preOrder(myNode->rchild);
        }
        return;
  }

    /* In-Order traversal in Binary Search Tree */
   void inOrder(struct bstNode * myNode) {
        if (myNode) {
                inOrder(myNode->lchild);
                printf("%d ", myNode->data);
                inOrder(myNode->rchild);
        }
        return;
  }

  /* Post-Order traversal in Binary Search Tree */
  void postOrder(struct bstNode *myNode) {
        if (myNode) {
                postOrder(myNode->lchild);
                postOrder(myNode->rchild);
                printf("%d ", myNode->data);
        }
        return;
  }

  int main() {
        int i = 0;
        printf("Data in Array:\n");
        while (i < NODECOUNT) {
                printf("%d ", bstData[i]);
                i++;
        }
        i = 0;
        root = implementBSTtree(i);
        printf("\nPre-Order:\n");
        preOrder(root);
        printf("\nIn-Order:\n");
        inOrder(root);
        printf("\nPost-Order:\n");
        postOrder(root);
        printf("\n");
        return 0;
  }