#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct BNode {
    int value;
    struct BNode* left;
    struct BNode* right;
} BNode;
static inline size_t max(size_t a, size_t b) {
    return a > b ? a : b;
}
size_t find_max_len(BNode* root, size_t* left_high, size_t* right_high) {
    *left_high = 0;
    *right_high = 0;
    if (!root) {
        return 0;
    }
    size_t left_left_high = 0;
    size_t left_right_high = 0;
    size_t left_max_len = find_max_len(root->left, &left_left_high, &left_right_high);
    if (root->left) {
        *left_high = max(left_left_high, left_right_high) + 1;
    }
    size_t right_left_high = 0;
    size_t right_right_high = 0;
    size_t right_max_len = find_max_len(root->right, &right_left_high, &right_right_high);
    if (root->right) {
        *right_high = max(right_left_high, right_right_high) + 1;
    }
    return max(*left_high + *right_high, max(left_max_len, right_max_len));
}
BNode* find_nearest_common_ancestor(BNode* root, BNode* a, BNode* b) {
    if (!root) {
        return NULL;
    }
    BNode* left = find_nearest_common_ancestor(root->left, a, b);
    BNode* right = find_nearest_common_ancestor(root->right, a, b);
    if (left && right) {
        return root;
    } else if (left) {
        return left;
    } else if (right) {
        return right;
    }
    if (root == a) {
        return a;
    }
    else if(root == b) {
        return b;
    }
    return NULL;
}
size_t move_value_uniform(BNode* root, int* balance) {
    *balance = 0;
    if (!root) {
        return 0;
    }
    int left_balance = 0;
    size_t left_steps = move_value_uniform(root->left, &left_balance);
    int right_balance = 0;
    size_t right_steps = move_value_uniform(root->right, &right_balance);
    *balance = left_balance + right_balance + root->value - 1;
    return abs(*balance) + left_steps + right_steps; 
}
BNode* btree_rebuild_by_preorder(int* pre, size_t pre_begin, int* in, size_t in_begin, size_t in_end) {
    if (in_begin >= in_end) {
        return NULL;
    }
    BNode* root = (BNode *)malloc(sizeof(BNode));
    root->value = pre[pre_begin];
    size_t i = in_begin;
    for (; i < in_end && pre[pre_begin] != in[i]; ++i) {}
    root->left = btree_rebuild_by_preorder(pre, pre_begin + 1, in, in_begin, i);
    root->right = btree_rebuild_by_preorder(pre, pre_begin + (i + 1 - in_begin), in, i + 1, in_end);
    return root;
}
BNode* btree_rebuild_by_postorder(int* post, size_t post_end, int* in, size_t in_begin, size_t in_end) {
    if (in_begin >= in_end) {
        return NULL;
    }
    BNode* root = (BNode *)malloc(sizeof(BNode));
    assert(post_end > 0);
    root->value = post[post_end - 1];
    size_t i = in_begin;
    for (; i < in_end && root->value != in[i]; ++i) {}
    root->left = btree_rebuild_by_postorder(post, post_end - (in_end - i), in, in_begin, i);
    root->right = btree_rebuild_by_postorder(post, post_end - 1, in, i + 1, in_end);
    return root;
}
#if 0
we have: root.value < left.value < right.value
            5                              5
           / \                            /
          6  10                          6
         / \               =>           /
         7  8                          7
             \                        /  
              9                      8
                                    / 
                                   9
                                  /
                                 10  
#endif
void btree_degenerate(BNode* root) {
    if (!root) {
        return;
    }
    btree_degenerate(root->left);
    BNode* left = root;
    for (; left->left; left = left->left) {}
    left->left = root->right;
    root->right = NULL;
    btree_degenerate(left->left);
}
#if 0
           A
         /   \
        B     C
       / \
      D   E
we know the pre order is: A B D E C
output the travel path of pre order: A B D B E B A C A, travel from A in pre order, and go back to A at last
#endif
void btree_preorder_path(BNode* root) {
    if (!root) {
        return;
    }
    printf("%d ", root->value);
    if (root->left) {
        btree_preorder_path(root->left);
        printf("%d ", root->value);
    }
    if (root->right) {
        btree_preorder_path(root->right);
        printf("%d ", root->value);
    }
}
size_t count_of_value(int* array, size_t begin, size_t end, int value, size_t pos[3]) {
    size_t count = 0;
    size_t i = begin;
    for (; i < end; ++i) {
        if (value == array[i]) {
            pos[count++] = i;
            assert(count <= 3);
        }
    }
    return count;
}
#if 0
Binary Search Tree: (in which left.value < root.value < right.value)
                    35
                   /  \
                 25   50
                 / \
               20 30
As btree_preorder_path does, we can get the path: 35 25 20 25 30 25 35 50 35
Now given the path: 35 25 20 25 30 25 35 50 35, we need to rebuild the binary search tree
#endif
BNode* rebuild_bst_by_preorder_path(int* preorder_path, size_t begin, size_t end) {
    if (begin >= end) {
        return NULL;
    }
    BNode* root = (BNode *)malloc(sizeof(BNode));
    root->value = preorder_path[begin];
    root->left = NULL;
    root->right = NULL;
    size_t pos[3];
    size_t count = count_of_value(preorder_path, begin, end, preorder_path[begin], pos);
    switch(count) {
    case 3:
        root->left = rebuild_bst_by_preorder_path(preorder_path, pos[0] + 1, pos[1]);
        root->right = rebuild_bst_by_preorder_path(preorder_path, pos[1] + 1, pos[2]);
        break;
    case 2:
        if (preorder_path[begin] > preorder_path[begin + 1]) {
            root->left = rebuild_bst_by_preorder_path(preorder_path, pos[0] + 1, pos[1]);
        } else {
            root->right = rebuild_bst_by_preorder_path(preorder_path, pos[0] + 1, pos[1]);
        }
        break;
    default:
        break;
    }
    return root;
}
int main(int argc, char* argv[]) {
    int a = 10;
    int* p = &a;
    printf("%d\n", ++*p);
    return 0;
}