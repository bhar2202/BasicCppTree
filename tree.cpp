#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class treeNode
{

public:
    int hp;
    string name;
    treeNode(int hp, string name);
    treeNode(const treeNode&);
    void operator=(const treeNode&);
    treeNode* left;
    treeNode* right;
};

treeNode::treeNode(int hp, string name): hp{hp}, name{name}, left{nullptr}, right{nullptr}
{

}

class BinaryTree
{
    public:
        treeNode* root;
        BinaryTree();
        void DestructorRecursive(treeNode* root);
        ~BinaryTree();
        BinaryTree(const BinaryTree& other);
        BinaryTree& operator=(const BinaryTree& other);
        void add(treeNode* curr, int hp, string name);
        void print(treeNode* root);
    
};

BinaryTree::BinaryTree(): root{nullptr}
{
}


void BinaryTree::DestructorRecursive(treeNode* root){
    if(root != nullptr){
        DestructorRecursive(root->left);
        DestructorRecursive(root->right);
        delete root;
    }
}

BinaryTree::~BinaryTree()
{

    DestructorRecursive(root);

}

/*

adds a node to the tree

*/
void BinaryTree::add(treeNode* curr, int hp, string name){

    

    if(root == nullptr){ // set the root if it's null
        treeNode* newNode = new treeNode(hp, name);
        root = newNode;
    } else if(curr->hp >= hp){ // go left if less than or equal to 
        if(curr->left == nullptr){
            treeNode* newNode = new treeNode(hp, name);
            curr->left = newNode;
        } else {
            add(curr->left,hp,name);
        }
    } else { // go right if greater than 
        if(curr->right == nullptr){
            treeNode* newNode = new treeNode(hp, name);
            curr->right = newNode;
        } else {
            add(curr->right,hp,name);
        }
    }

}

void BinaryTree::print(treeNode* root){
    if(root != nullptr){
        cout << "Hp: " << std::to_string(root->hp) << endl;
        cout << "Name: " << root->name << endl << endl;
        print(root->left);
        print(root->right);
    }
}

int main(){


    BinaryTree myTree;
    myTree.add(myTree.root,12,"tom");
    myTree.add(myTree.root,56,"amy");
    myTree.add(myTree.root,5,"joe");
    myTree.add(myTree.root,34,"rose");
    myTree.print(myTree.root);


    return 0;
}