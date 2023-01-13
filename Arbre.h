#ifndef ARBRE_ARBRE_H
#define ARBRE_ARBRE_H
#include <bits/stdc++.h>

template<class T>
class Node{
public:
    T data;
    Node*left;
    Node*right;
    explicit Node(T);
    Node();
    friend std::ostream &operator<<(std::ostream &out,Node<T> *n)
    {
       if(n) out<<n->data;
       else out<<"vide";
        return out;
    }
};

template<class T>
Node<T>::Node() = default;


template<class T>
class Arbre {

private :

    Node<T> *add_Node(Node<T> *, T);
    Node<T> *remove(Node<T> *, T);
    void toString(Node<T>* ,std::ostream &,int );
    T fun(Node<T> *);
public:
    Node<T> *racine;
    explicit Arbre(T);
    Arbre();
    void add(T);
    bool Search(T val);
    Node<T> *Search2(Node<T> *, T val);
    T min(Node<T> *node);
    void remove(T);

    friend std::ostream &operator<<(std::ostream &out,Arbre<T> *A)
    {
        A->toString(A->racine,out,0);
        return out;
    }
};



#endif 
