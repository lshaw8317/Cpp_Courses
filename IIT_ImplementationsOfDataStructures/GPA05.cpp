// GPA05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
struct node {
    int data;
    node* left;
    node* right;
};typedef struct node node;

//Helper Funcs
void printChildren(node* n, std::queue<node*>& q) {
    if (n->left != NULL) { q.push(n->left);std::cout << " " << n->left->data; }
    if (n->right != NULL) { q.push(n->right);std::cout << " " << n->right->data; }
}
void printTree(node* root) {
    std::queue<node*> q1, q2;
    q1.push(root);
    std::cout << root->data << std::endl;
    while (!q1.empty()) {
        q2 = q1;
        q1 = {};
        while (!q2.empty()) {
            printChildren(q2.front(), q1);
            q2.pop();
        }
        std::cout << std::endl;
    }
}
void subInOrder(node* n, std::vector<int>& v) {
    if (n->left != NULL) {
        subInOrder(n->left, v);
    }
    v.push_back(n->data);
    if (n->right != NULL) {
        subInOrder(n->right, v);
    }
}
node* sub_mBST(std::vector<int>::iterator left, std::vector<int>::iterator right) {
    node* n = new node;
    int d = std::distance(left, right) / 2;
    n->data = *(left + d);
    if (d == 0) { n->left = NULL;n->right = NULL; }
    else {
        n->left = sub_mBST(left, left + d);
        n->right = sub_mBST(left + d + 1, right);
    }
    return n;
}

//Assignment Funcs
//Part 1)
node* makeBinarySearchTree(std::vector<int>& v) {
    node* root = new node;
    root->data = v[0]; root->left = NULL;root->right = NULL;
    std::vector<int>::iterator it = v.begin();++it;
    for (;it != v.end();++it) {
        node* n = root;
        node* new_node = new node;new_node->data = *it;
        new_node->left = NULL;new_node->right = NULL;
        while (true) {
            if (*it < n->data) {
                if (n->left == NULL) { n->left = new_node; break; }
                else { n = n->left; }
            }
            else if (*it > n->data) {
                if (n->right == NULL) { n->right = new_node; break; }
                else { n = n->right; }
            }
            else {//*it==n.data - so skip as value already added
                delete new_node;
                break;
            }

        }
    }
    return root;
}
//Part 2)
std::vector<int> inOrderElements(node* root) {
    std::vector<int> v;
    subInOrder(root, v);
    return v;
}
//Part 3)
node* makeBalancedSearchTree(std::vector<int>& v) {
    node* n=new node;
    n->data = v[v.size() / 2];
    n->left = sub_mBST(v.begin(), v.begin() + v.size() / 2);
    n->right = sub_mBST(v.begin() + v.size() / 2 + 1, v.end());
    return n;
}
int main()
{
    std::cout << "Part 1" << std::endl;
    std::vector<int> v{ 1,3,2,5,4,8,6 };
    node* root = makeBinarySearchTree(v);
    printTree(root);
    std::cout << "\n\nPart 2" << std::endl;
    std::vector<int> inorder = inOrderElements(root);
    for (std::vector<int>::iterator it = inorder.begin();it != inorder.end();++it) { std::cout << " " << *it; }
    std::cout << "\n\nPart 3" << std::endl;
    std::sort(v.begin(), v.end());
    node* bal_root=makeBalancedSearchTree(v);
    printTree(bal_root);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
