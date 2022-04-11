#ifndef AVLT_TYPE
#define AVLT_TYPE

#include "Bst.h"

template <typename obj_t>
class AVLt : public Bst<obj_t>
{
protected:
    /* Data */
    static const int ALLOWED_IMBALANCE = 1;

    struct node {
        // data element.
        obj_t data;
        // left node and right node.
        node *left;
        node *right;
        // height.
        int height;
        // copy constructor
        node(const obj_t & d, node * l, node * r, int h = 0){
            data = d;
            left = l;
            right = r;
            height = h;
        }
        // move constructor
        node(obj_t && d, node * l, node * r, int h = 0){
            data = std::move(d);
            left = l;
            right = r;
            height = h;
        }
    };

    node * m_root;
    
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
        
    };
    // rotate
    void rotate_left() {}
    void double_rotate_left() {}
    void rotate_right() {}
    void double_rotate_right() {}
public:
    // Constructor
    AVLt() : Bst<obj_t>::Bst() { };
    // Copy constructor
    AVLt(const AVLt & rhs) { m_root = clone(rhs.m_root); };
    // Move constructor
    AVLt(AVLt && rhs) : Bst<obj_t>::Bst(rhs) { };
    // Destructor
    ~AVLt() { }; // Will automaticly calls Bst's destructor.

    // Return the height of node t or -1 if nullptr.
    int height(node * t) { return (t == nullptr)? -1 : t->height; };

};

#endif