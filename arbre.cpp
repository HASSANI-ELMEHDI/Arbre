#include <iostream>
#include "Arbre.h"

using namespace std;
template<class T>
Node<T>::Node(T n) {
    right=left= nullptr;
    data=n;
}

template<class T>
Node<T>* Arbre<T>::add_Node(Node<T> *root,T n) {
    if(!root){
        auto *nd=new Node<T> ((T)n);
        return nd;
    }else{
        if(n<(root->data)) root->left= add_Node(root->left,n);
        else root->right= add_Node(root->right,n);
    }
    return root;
}
template<class T>
void Arbre<T>::add(T n)
{
    if(Search(n)==true) return ;
    racine= add_Node(racine,n);
}
template<class T>
Arbre<T>::Arbre(T n)
{
    racine=new Node(n);
}
template<class T>
Arbre<T>::Arbre() {
    racine= nullptr;
}


template<class T>
Node<T>* Arbre<T>::Search2(Node<T>*root,T n){
    if(root) {
        if (root->data == n) return root;
        else {
            if (n < (root->data)) return Search2(root->left, n);
            else return Search2(root->right, n);
        }
    }
    return nullptr;
}

//For searching a particular key in tree
template<class T>
bool Arbre<T>::Search(T val)
{
// Calling Search() operation
// and passing root node
    Node<T> * result = Search2(racine, val);
// If value is found then return true
// else return false
    return result != nullptr;
}
template<class T>
T Arbre<T>::min(Node<T>* node)
{

    if(node&&node->left== nullptr&&node->right== nullptr) return node->data;
    return min(node->left);
}
template<class T>
T Arbre<T>::fun(Node<T> * node)
{
// The successor is the minimum data value
// of the right subtree
    if (node->right != NULL)
    {
        return min(node->right);
    }else return node->data;

}
template<class T>
Node<T> * Arbre<T>::remove(Node<T> * node,T value)
{
// If the given node is
// not in Tree
    if (node == nullptr) return nullptr;
    // If we found the target,
    if (node->data == value)
    {
        if (node->left == nullptr && node->right == nullptr)
            node = nullptr;
            // If the node have only right child
        else if (node->left == nullptr && node->right != nullptr)
        {
            // Bypass node
            node = node->right;
        }
            // If the node have only left child
        else if (node->left != nullptr && node->right == nullptr)
        {
            // Bypass node
            node = node->left;
        }
            // If the node have both children (left and right)
        else
        {
            T funkey = fun(node);
            // Replace node's data with fun's data
            node->data = funkey;
            // Delete the old successor's key
            node->right = remove(node->right, funkey);
        }
    }
    else if (node->data<value)
        node->right = remove(node->right, value); 
    else node->left = remove(node->left, value);  
    // Return the updated Tree

    return node;
}

template<class T>
void  Arbre<T>::remove( T value) {
    racine=remove(racine,value);
}

template<class T>
void Arbre<T>::toString(Node<T>* node,ostream & str,int Niv)
{
    int esp; //for printing spaces
    if (node)
    {
        //print the right child
        toString(node->right,str, Niv + 1);
        str<<endl;
        for (esp = 0; esp < Niv; esp++)
            str<<"\t";
        str << node;
        //print the left child
        toString(node->left, str,Niv + 1);
    }

}
