#pragma once

#include <vector>
#include <iostream>

using namespace std;

enum Color {RED, BLACK};

template <class T> 
struct Node
{
    T data;
    Color color;
    Node<T>* right;
    Node<T>* left;
    Node<T>* parent;

    Node(){
        color = Color::BLACK;
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }

    Node(T data) : data(data) {
        color = Color::RED;
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }
};

template <typename T>
class RBTree {
    private:
    Node<T>* root;

    // to be called when inserting new nodes
    // if the code executes without going into the if statements, no violation
    // if the given node is the root, color it black
    // if the given node's parent in red, go to red violation (since all newly inserted nodes are red)
    void checkViolation(Node<T>* curNode){
        if (curNode == nullptr) {
            cout << "Error: curNode in checkViolation was nullptr" << endl;
            return;
        }

        if (curNode == root) curNode->color = Color::BLACK;
        else if (curNode->parent->color == Color::RED) redViolation(curNode);
    }


    // if the parent of the curNode is red:
    // if the uncle node is red, call redUncle()
    // if the uncle node is black, call blackUncle()
    void redViolation(Node<T>* curNode){
        if (curNode == nullptr) {
            cout << "Error: curNode in redViolation was nullptr" << endl;
            return;
        }

        Node<T>* parent = curNode->parent;

        if (parent == nullptr) {
            cout << "Error: parent in redViolation was nullptr" << endl;
            return;
        }

        Node<T>* grandparent = parent->parent;
        Node<T>* uncle = nullptr; 

        if (grandparent->left == parent) uncle = grandparent->right;
        else uncle = grandparent->right;

        if (uncle->color == Color::RED) redUncle(parent, uncle, grandparent);
        else blackUncle(curNode, parent, grandparent);
    }

    void redUncle(Node<T>* parent, Node<T>* uncle, Node<T>* grandparent){
        parent->color = Color::BLACK;

        if (uncle != nullptr) uncle->color = Color::BLACK;
        if (grandparent != nullptr) grandparent->color = Color::RED;
        checkViolation(grandparent);
    }

    void blackUncle(Node<T>* curNode, Node<T>* parent, Node<T>* grandparent){
        // if the parent is the left node of the grandparent
        if (grandparent->left == parent){
            // if the curNode is the right child of the parent, bring it to a state
            // where we can make curNode the root of the subtree with a right rotate
            if (parent->right == curNode) rotateLeft(parent);

            // rotate the grandparent node to the right so its left child is now the root of the subtree
            rotateRight(grandparent);

            // create a new variable for clarity and readability of which node is being refered to
            Node<T>* newParent = grandparent->parent;

            // change the root of the subtree to be black, and its children to red
            newParent->color = Color::BLACK;
            newParent->left->color = Color::RED;
            newParent->right->color = Color::RED;
        }
        // if the parent is the right node of the grandparent
        else{
            // if the curNode is the left child of the parent, bring it to a state
            // where we can make curNode the root of the subtree with a left rotate
            if (parent->left == curNode) rotateRight(parent);

            // rotate the grandparent node to the left so its right child is now the root of the subtree
            rotateLeft(grandparent);

            // create a new variable for clarity and readability of which node is being refered to
            Node<T>* newParent = grandparent->parent;

            // change the root of the subtree to be black, and its children to red
            newParent->color = Color::BLACK;
            newParent->left->color = Color::RED;
            newParent->right->color = Color::RED;
        }
        // TODO root->color = Color::BLACK;
    }

    void rotateLeft(Node<T>* curNode){
        // parameter check
        if (curNode == nullptr) {
            cout << "Error: rotateLeft was given nullptr" << endl;
            return;
        }

        // Get the right child of curNode
        Node<T>* rightChild = curNode->right;
        // check if right child exists
        if (rightChild == nullptr) {
            cout << "Error: curNode in rotateLeft does not have a right child" << endl;
            return;
        }

        // get left child from the right child of the current node
        // can be nullptr, watch for segfaults
        Node<T>* leftGrandChild = curNode->right->left;

        // bring down curNode to be the left of the right child, right child is now the root of subtree
        rightChild->left = curNode;

        // move left grandchild to be right of the current node
        curNode->right = leftGrandChild;

        // if the shifted node is the root, reassign root to the right child
        if (curNode == root){
            root = rightChild;
        }
        // else see if the curNode is the left or right child of its parent node
        else if (curNode == curNode->parent->left){
            // reassign the left of the parent to the right child
            curNode->parent->left = rightChild;
        }
        else {
            // reassign the right of the parent to the right child
            curNode->parent->right = rightChild;
        }

        // reassign parents to maintain connectivity of the tree
        rightChild->parent = curNode->parent;
        curNode->parent = rightChild;

        // only reassign parent if the node exists
        if (leftGrandChild != nullptr) leftGrandChild->parent = curNode;   
    }

    void rotateRight(Node<T>* curNode){
        // parameter check
        if (curNode == nullptr) {
            cout << "Error: rotateRight was given nullptr" << endl;
            return;
        }
        
        // Get the left child of curNode
        Node<T>* leftChild = curNode->left;
        // check if left child exists
        if (leftChild == nullptr) {
            cout << "Error: curNode in rotateRight does not have a left child" << endl;
            return;
        }

        // get right child from the left child of the current node
        // can be nullptr, watch for segfaults
        Node<T>* rightGrandChild = curNode->left->right;

        // bring down curNode to be the right of the left child, left child is now the root of subtree
        leftChild->right = curNode;

        // move right grandchild to be left of the current node
        curNode->left = rightGrandChild;

        // if the shifted node is the root, reassign root to the right child
        if (curNode == root){
            root = leftChild;
        }
        // else see if the curNode is the left or right child of its parent node
        else if (curNode == curNode->parent->left){
            // reassign the left of the parent to the left child
            curNode->parent->left = leftChild;
        }
        else {
            // reassign the right of the parent to the left child
            curNode->parent->right = leftChild;
        }

        // reassign parents to maintain connectivity of the tree
        leftChild->parent = curNode->parent;
        curNode->parent = leftChild;

        // only reassign the parent if the node exists
        if (rightGrandChild != nullptr) rightGrandChild->parent = curNode;
    }

    public:
    RBTree(){
        root = nullptr;
    }

    void insert(Node<T>* curNode, Node<T>* prevNode, T data){
        if (curNode == nullptr) {
            curNode = new Node<T>(data);
            curNode->parent = prevNode;

            if (root == nullptr) root = curNode;

            checkViolation(curNode);
        }
        else if (data < curNode->data) {
            insert(curNode->left, curNode, data);
        }
        else {
            insert(curNode->right, curNode, data);
        }
    }

    void insert(T data) { insert(root, nullptr, data); }
    
    Node<T>* find(Node<T>* curNode, T data){
        if (curNode == nullptr) return nullptr;
        else if (data < curNode->data) find(curNode->left, data);
        else if (data == curNode->data) return curNode;
        else find(curNode->right, data);
        return nullptr;
    }
    
    Node<T>* find(T data) { return find(root, data); }
};
