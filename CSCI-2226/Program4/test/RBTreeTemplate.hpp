#pragma once

#include <vector>
#include <iostream>

enum Color {RED, BLACK};

template <class T> struct Node
{
    T data;
    Color color;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    // Node(T data, Node<T>* parent):
    //     data{data},
    //     left{nullptr},
    //     right{nullptr},
    //     parent{parent} {}
};

template <class T> class RBTree
{
    private:
        Node<T>* root;
    
    public:
        RBTree():
            root{nullptr} {}
        
        Node<T>* Min(Node<T>* node)
        {
            if (node == nullptr)
                throw "Empty Tree";
            if (node->left == nullptr)
                return node;
            return Min(node->left);
        }

        Node<T>* Min()
        {
            return Min(root);
        }

        Node<T>* Max(Node<T>* node)
        {
            if (node == nullptr)
                throw "Empty Tree";
            if (node->right == nullptr)
                return node;
            return Max(node->right);
        }

        Node<T>* Max()
        {
            return Max(root);
        }

        void Insert(Node<T>*& node, Node<T>* parent, T data)
        {
            if(node == nullptr)
            {
                std::cerr << "Inserting " << data << std::endl;
                node = new Node<T>;
                node->parent = parent;
                node->data = data;
                node->left = nullptr;
                node->right = nullptr;
                node->color = RED;
                ReColor(node);
            } 
            else if (data < node->data)
            {
                Insert(node->left, node, data);
            }
            else
            {
                Insert(node->right, node, data);
            }
        }

        void Insert(T data)
        {
            Insert(root, nullptr, data);
        }

        void BulkInsert(std::vector<T> dataSet)
        {
            for(auto data : dataSet)
            {
                Insert(data);
            }
        }

        Node<T>* Find(Node<T>* node, T data)
        {
            if(node == nullptr)
                return nullptr;
            if(node->data == data)
                return node;
            if(data < node->data)
                return Find(node->left, data);
            return Find(node->right, data);
        }

        Node<T>* Find(T data)
        {
            return Find(root, data);
        }

        void DeleteNode(Node<T>*& root)
        {
            Node<T>* temp = root;
            if(root->left == nullptr)
            {
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr)
            {
                root = root->left;
                delete temp;
            }
            else
            {
                //get rightmost element in left subtree
                Node<T>* max = Max(root->left);
                root->data = max->data;
                Delete(root->left, max->data);
            }
        }

        void Delete(Node<T>*& root, T data)
        {
            if(data < root->data)
                Delete(root->left, data);
            else if (data > root->data)
                Delete(root->right, data);
            else
                DeleteNode(root);
        }

        void Delete(T data)
        {
            Delete(this->root, data);
        }

        //get items in sorted order
        void Inorder(Node<T>*& node)
        {
            if(node == nullptr) return;

            Inorder(node->left);
            std::cout << "[" << node->data << "]";
            Inorder(node->right);
        }

        void Inorder()
        {
            Inorder(root);
            std::cout << std::endl;
        }

        int getHeight(Node<T>* root)
        {
            if (root = nullptr) return 0;
            return std::max<int>(getHeight(root->left), getHeight(root->right)) + 1;
        }

        int getHeight()
        {
            return getHeight(root);
        }

        void DestroyTree(Node<T>* root)
        {
            if (root != nullptr)
            {
                DestroyTree(root->left);
                DestroyTree(root->right);
                delete root;
            }
        }

        void DestroyTree()
        {
            DestroyTree(root);
        }

        void CopyTree(Node<T>*& copy, Node<T>* original)
        {
            if (original == nullptr)
                copy = nullptr;
            else
            {
                copy = new Node<T>(original->data, nullptr);
                std::cout << "Copying " << original->data << std::endl;
                CopyTree(copy->left, original->left);
                CopyTree(copy->right, original->right);
            }
        }

        RBTree(const RBTree& original)
        {
            CopyTree(root, original.root);
        }

        void operator=(const RBTree& original)
        {
            if (&original == this)
                return;
            DestroyTree(root);
            CopyTree(root, original.root);
        }

        ~RBTree()
        {
            DestroyTree();
        }



        Node<T>* RotateRight(Node<T>* node)
        {
            std::cerr << "Hi31" <<std::endl;
            Node<T>* leftChild = node->left;
            std::cerr << "Hi32" <<std::endl;
            Node<T>* rightGrandChild = leftChild->right;
            std::cerr << "Hi33" <<std::endl;
            leftChild->right = node;
            std::cerr << "Hi34" <<std::endl;
            node->left = rightGrandChild;
            std::cerr << "Hi35" <<std::endl;

            return leftChild;
        }

        Node<T>* RotateLeft(Node<T>* node)
        {
            Node<T>* rightChild = node->right;
            Node<T>* leftGrandChild = rightChild->left;

            rightChild->left = node;
            node->right = leftGrandChild;

            return rightChild;
        }

        Node<T>* RotateRightLeft(Node<T>* node)
        {
            Node<T>* rightChild = node->right;
            node->right = RotateRight(rightChild);
            return RotateLeft(node);
        }

        Node<T>* RotateLeftRight(Node<T>* node)
        {
            Node<T>* leftChild = node->left;
            node->left = RotateLeft(leftChild);
            return RotateRight(node);
        }

        //returns the difference of the heights of the left and right subtrees of node (used for AVL trees)
        // int Difference(Node<T>* node) const
        // {
        //     return getHeight(node->left) - getHeight(node->right);
        // }
        // 
        // used in AVL trees
        // Node<T>* Balance (Node<T>* node)
        // {
        //     int balanceFactor = Difference(node);
        //     if (balanceFactor > 1)
        //     {
        //         if (Difference(node->left) > 1)
        //             return RotateRight(node);
        //         else
        //             return RotateLeftRight(node);
        //     }
        // 
        //     else if (balanceFactor < -1)
        //     {
        //         if (Difference(node->right) < 0) //should be -1
        //             return RotateLeft(node);
        //         else
        //             return RotateRightLeft(node);
        //     }
        //     else
        //         return node;
        // }





        Node<T>* Parent(Node<T>* node)
        {
            return node->parent;
        }

        Node<T>* GrandParent(Node<T>* node)
        {
            Node<T>* parent = Parent(node);
            if (parent == nullptr)
                return nullptr;
            else
                return Parent(parent);
        }

        Node<T>* Uncle(Node<T>* node)
        {
            Node<T>* grandParent = GrandParent(node);
            if (grandParent == nullptr)
                return nullptr;
            else if (Parent(node) == grandParent->left)
                return grandParent->right;
            else
                return grandParent->left;
        }

        Color GetColor(Node<T>* node)
        {
            if (node == nullptr)
                return BLACK;
            else
                return node->color;
        }

        void SetColor(Node<T>* node, Color color)
        {
            if (node != nullptr)
                node->color = color;
        }

        void ReColor(Node<T>* node)
        {
            if (node == nullptr)
                return;
            Node<T>* parent = Parent(node);
            Node<T>* grandParent = GrandParent(node);
            Node<T>* uncle = Uncle(node);

            if (parent == nullptr)
                node->color = BLACK;
            else if (parent != nullptr || GetColor(parent) != BLACK)
            {
                if (GetColor(uncle) == RED)
                {
                    std::cerr << "Hi10" << std::endl;
                    SetColor(parent, BLACK);
                    SetColor(uncle, BLACK);
                    SetColor(grandParent, RED);
                    std::cerr << "Hi11" <<std::endl;
                    ReColor(grandParent);
                    std::cerr << "Hi12" <<std::endl;
                }
                else
                {
                    std::cerr << "Hi13" <<std::endl;
                    ReStructure(node);
                    std::cerr << "Hi14" <<std::endl;
                }
            }
        }

        void ReStructure(Node<T>* node)
        {
            Node<T>* parent = Parent(node);
            Node<T>* grandParent = GrandParent(node);
            Color nodeColor = GetColor(node);
            Color parentColor = GetColor(parent);
            Color grandParentColor = GetColor(grandParent);

            std::cerr << "Hi21" <<std::endl;

            if (grandParent == nullptr)
            {
                std::cerr << "Hi28" << std::endl;
            }
            else if (grandParent->left == parent && parent->left == node)
            {
                std::cerr << "Hi22" <<std::endl;
                RotateRight(grandParent);
                std::cerr << "Hi23" <<std::endl;
                SetColor(grandParent, parentColor);
                std::cerr << "Hi24" <<std::endl;
                SetColor(parent, grandParentColor);
                std::cerr << "Right Shift" <<std::endl;
            }
            else if (grandParent->left == parent && parent->right == node)
            {
                std::cerr << "Hi25" <<std::endl;
                RotateLeftRight(parent);
                SetColor(grandParent, nodeColor);
                SetColor(node, grandParentColor);
                std::cerr << "LeftRight Shift" <<std::endl;
            }
            else if (grandParent->right == parent && parent->right == node)
            {
                std::cerr << "Hi26" <<std::endl;
                RotateLeft(grandParent);
                SetColor(grandParent, parentColor);
                SetColor(parent, grandParentColor);
                std::cerr << "Left Shift" <<std::endl;
            }
            else if (grandParent->right == parent && parent->left == node)
            {
                std::cerr << "Hi27" <<std::endl;
                RotateRightLeft(parent);
                SetColor(grandParent, nodeColor);
                SetColor(node, grandParentColor);
                std::cerr << "RightLeft Shift" <<std::endl;
            }
        }

        int GetBlackHeight(Node<T>* root)
        {
            if (root == nullptr)
                return 0;
            if (GetColor(root) == BLACK)
                return std::max<int>(getBlackHeight(root->left), getBlackHeight(root->right)) + 1;
            else
                return std::max<int>(getHeight(root->left), getHeight(root->right));
        }

        int GetBlackHeight()
        {
            return GetBlackHeight(root);
        }
};