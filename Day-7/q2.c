#include <stdio.h>
#include <stdlib.h>

struct CHAR {
    char symbol;
    int frequency;
};

struct Node {
    struct CHAR data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(struct CHAR data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%c ", root->data.symbol);
    inOrderTraversal(root->right);
}

struct Node* buildHuffmanTree(struct CHAR characters[], int n) {
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i]);
    }

    while (n > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->data.frequency > nodes[min2]->data.frequency) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < n; i++) {
            if (nodes[i]->data.frequency < nodes[min1]->data.frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->data.frequency < nodes[min2]->data.frequency) {
                min2 = i;
            }
        }
        struct CHAR specialChar = {'#', nodes[min1]->data.frequency + nodes[min2]->data.frequency};
        struct Node* newNode = createNode(specialChar);
        newNode->left = nodes[min1];
        newNode->right = nodes[min2];
        nodes[min1] = newNode;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    return nodes[0];
}

int main() {
    int n;
    printf("Enter the number of distinct characters: ");
    scanf("%d", &n);

    struct CHAR characters[n];

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &characters[i].symbol);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &characters[i].frequency);
    }
    struct Node* root = buildHuffmanTree(characters, n);
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);

    return 0;
}