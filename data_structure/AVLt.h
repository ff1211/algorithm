#ifndef AVLT_TYPE
#define AVLT_TYPE

#include "Bst.h"

template <typename obj_t>
class Avlt : public Bst<obj_t>
{
protected:
    /* Data */
    static const int ALLOWED_IMBALANCE = 1;
    typedef typename Bst<obj_t>::node node;
    
    // Internal method to return the height
    // t is the node that roots the subtree.
    int height(node * t) { return (t == nullptr)? -1 : t->height; };
    // Internal method to clone subtree.
    node * clone(node * t) {
        if(t == nullptr)
            return nullptr;
        return new node(t->data, clone(t->left), clone(t->right), t->height);
    }
    // Internal method to balance the tree.
    // t is the node that roots the subtree.
    void balance(node * & t) {
        if(t == nullptr)
            return;
        if(height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
            if(height(t->left->left) >= height(t->left->right))
                rotate_ll(t);
            else
                rotate_lr(t);
        } else if(height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
            if(height(t->right->right) >= height(t->right->left))
                rotate_rr(t);
            else
                rotate_rl(t);
        }
        t->height = std::max( height(t->left), height(t->right) ) + 1; 
    }
    // Rotate binary tree node with left left child.
    void rotate_ll(node * & k2) {
        node * k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
        k1->height = std::max( height(k1->left), height(k1->right) ) + 1;
        k2 = k1;
    }
    // Rotate binary tree node with right right child.
    void rotate_rr(node * & k1) {
        node * k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
        k1->height = std::max( height(k1->left), height(k1->right) ) + 1;
        k1 = k2;        
    }
    // Rotate binary tree node with left right child.
    void rotate_lr(node * & k3) {
        rotate_rr(k3->left);
        rotate_ll(k3);
    }
    // Rotate binary tree node with right left child.
    void rotate_rl(node * & k1) {
        rotate_ll(k1->right);
        rotate_rr(k1);
    }
public:
    // Constructor
    Avlt() { }; // Will automaticly calls Bst's constructor.
    // Copy constructor
    Avlt(const Avlt & rhs) : Bst<obj_t>::Bst(rhs) { };
    // Move constructor
    Avlt(Avlt && rhs) : Bst<obj_t>::Bst( std::move(rhs) ) { };
    // Destructor
    ~Avlt() { }; // Will automaticly calls Bst's destructor.

    // // Insert element.
    // void insert(const obj_t & x) { Bst<obj_t>::insert(x, this->m_root); }
    // void insert(obj_t && x) { Bst<obj_t>::insert(std::move(x), this->m_root); } // Rvalue reference.
    // // Remove element.
    // bool remove(const obj_t & x) { return Bst<obj_t>::remove(x, this->m_root); }
    // Return height.
    int height() { return height(this->m_root); }
};

#endif