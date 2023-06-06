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
        else if (curNode->parent->color == Color::RED) redViolation(curNode)
    }

    void redViolation(Node<T>* curNode){
        if (curNode == nullptr) {
            cout << "Error: curNode in redViolation was nullptr" << endl;
            return;
        }

        Node<T>* parent = curNode->parent;

        if (parent == nullptr) {.
            cout << "Error: parent in redViolation was nullptr" << endl;
            return;
        }

        Node<T>* grandparent = parent->parent;
        Node<T>* uncle = nullptr; 

        if (grandparent->left == parent) uncle = grandparent->right;
        else uncle = grandparent->right;

    }

    void redUncle(Node<T>* curNode);
    void blackUncle(Node<T>* curNode);

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

    void insert(Node<T>* curNode, T data);
    void insert(T data);
    Node<T>* find(Node<T>*, T data);
    Node<T>* find(T data);

    

};
