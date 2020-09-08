#pragma once
#include <vector>
#include <string>
#include <sstream>

std::string numberToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

struct binaryTree {
    int n;
    std::vector<int> a;
    binaryTree(int c) {
        n = c;
        int num = pow(2, n + 1) - 1;
        for (int i = 0;i < num;i++) {
            a.push_back(-1);
        }
    }
};

std::string subpostOrderRepn(binaryTree& bst, int i) {
    if (2 * i + 2 < pow(2, bst.n + 1) - 1) {
        //right, node
        if (bst.a[2 * i + 1] == 0 && bst.a[2 * i + 2] != 0) { return subpostOrderRepn(bst, 2 * i + 2) + ',' + numberToString(bst.a[i]); }
        //left, node
        else if (bst.a[2 * i + 1] != 0 && bst.a[2 * i + 2] == 0) { return subpostOrderRepn(bst, 2 * i + 1) + ',' + numberToString(bst.a[i]); }
        //left, right, node
        else if (bst.a[2 * i + 1] != 0 && bst.a[2 * i + 2] != 0) { return subpostOrderRepn(bst, 2 * i + 1) + ',' + subpostOrderRepn(bst, 2 * i + 2) + ',' + numberToString(bst.a[i]); }
        //Leaf node, so just return node
        else { return numberToString(bst.a[i]); }
    }
    else { return numberToString(bst.a[i]); } //Leaf node
};
std::string subpreOrderRepn(binaryTree& bst, int i) {
    if (2 * i + 2 < pow(2, bst.n + 1) - 1) {
        //node, right
        if (bst.a[2 * i + 1] == 0 && bst.a[2 * i + 2] != 0) { return numberToString(bst.a[i]) + ',' + subpreOrderRepn(bst, 2 * i + 2); }
        //node, left
        else if (bst.a[2 * i + 1] != 0 && bst.a[2 * i + 2] == 0) { return numberToString(bst.a[i]) + ',' + subpreOrderRepn(bst, 2 * i + 1); }
        //node, left,right
        else if (bst.a[2 * i + 1] != 0 && bst.a[2 * i + 2] != 0) { return numberToString(bst.a[i]) + ',' + subpreOrderRepn(bst, 2 * i + 1) + ',' + subpreOrderRepn(bst, 2 * i + 2); }
        //Leaf node, so just return node
        else { return numberToString(bst.a[i]); }
    }
    else { return numberToString(bst.a[i]); } //Leaf node
};

typedef struct binaryTree binaryTree; //save having to write struct??

std::string preOrderRepn(binaryTree& bst, int i) {
    return subpreOrderRepn(bst, i) + '.';
};

std::string postOrderRepn(binaryTree& bst, int i) {
    return subpostOrderRepn(bst, i) + '.';
};
int heightOfBinaryTree(binaryTree& bst) {
    for (int j = bst.n;j > 0;j--) {
        int i = pow(2, j + 1) - 2;
        for (;i > pow(2, j) - 2;i--) {
            if (bst.a[i] != 0) { return j; }
        }
    }
}