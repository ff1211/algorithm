#ifndef BST_TYPE
#define BST_TYPE

template <typename obj_t>
class Bst
{
protected:
    /* Data */
    struct node {
        // data element.
        obj_t data;
        // left node and right node.
        node *left;
        node *right;
        // copy constructor
        node(const obj_t & d, node * l, node * r){
            data = d;
            left = l;
            right = r;
        }
        // move constructor
        node(obj_t && d, node * l, node * r){
            data = std::move(d);
            left = l;
            right = r;
        }
    };

    node * m_root;

    /* Method */
    // Internal method to test if an item is in a subtree.
    // x is the item to search for.
    // t is the node that roots the subtree.
    bool contains(const obj_t & x, node * t) {
        if(t == nullptr)
            return false;
        if(x < t->data)
            contains(x, t->left); // Search left subtree.
        else if(x > t->data)
            contains(x, t->right); // Search right subtree.
        else
            return true; // Match
    }
    // Internal method to find the smallest item in a subtree.
    // t is the node that roots the subtree.
    node * find_min(node * t) const {
        if(t == nullptr)
            return nullptr;
        if(t->left == nullptr)
            return t;
        else
            return find_min(t->left);
    }
    // Internal method to find the max item in a subtree.
    // t is the node that roots the subtree.
    node * find_max(node * t) const {
        if(t == nullptr)
            return nullptr;
        if(t->right == nullptr)
            return t;
        else
            return find_max(t->right);
    }
    // Internal method to clone subtree.
    virtual node * clone(node * t) {
        if(t == nullptr)
            return nullptr;
        return new node(t->data, clone(t->left), clone(t->right));
    }
    // Internal method to make subtree empty.
    void make_empty(node * t) {
        if(t == nullptr)
            return;
        make_empty(t->left);
        make_empty(t->right);
        t = nullptr;
    }
    // Internal method to insert into a subtree.
    // x is the item to insert.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.
    void insert(const obj_t & x, node * & t) {
        if(t == nullptr)
            t = new node(x, nullptr, nullptr);
        else if(x < t->data)
            insert(x, t->left);
        else if(x > t->data)
            insert(x, t->right);
            
        balance();
    }
    // Rvalue reference.
    void insert(obj_t && x, node * & t) {
        if(t == nullptr)
            t = new node(std::move(x), nullptr, nullptr);
        else if(x < t->data)
            insert(std::move(x), t->left);
        else if(x > t->data)
            insert(std::move(x), t->right);
        
        balance();
    }
    // Internal method to remove from a subtree.
    // x is the item to remove.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.
    void remove(const obj_t & x, node * & t) {
        if(t == nullptr)
            return;
        if(x < t->data)
            remove(x, t->left);
        else if(x > t->data)
            remove(x, t->right);
        else {
            if(t->left != nullptr && t->right != nullptr) {
                t->data = find_min(t->right)->data;
                remove(t->data, t->right);
            } else {
                node * old_node = t;
                t = (t->left == nullptr)? t->right : t->left;
                delete old_node;
            }
        }
        balance();
    }

    // Internal method to balance the tree.
    virtual void balance() {};
public:
    // Constructor
    Bst() { m_root = nullptr; }
    // Copy constructor
    Bst(const Bst & rhs) { m_root = clone(rhs.root); }
    // Move constructor
    Bst(Bst && rhs) { 
        m_root = rhs.root;
        rhs.root = nullptr;
    }
    // Destructor
    ~Bst() { make_empty(m_root); }

    // Find max element.
    const obj_t & find_max() { return find_max(m_root)->data; }
    // Find min element.
    const obj_t & find_min() { return find_min(m_root)->data; }
    // Test if an item is in this tree.
    bool contain(const obj_t & x) { return contain(x, m_root); }
    // Test if empty.
    bool empty() { return m_root != nullptr; }

    // Make the tree empty.
    void make_empty() { make_empty(m_root); }
    // Insert element.
    void insert(const obj_t & x) { insert(x, m_root); }
    void insert(obj_t && x) { insert(std::move(x), m_root); } // Rvalue reference.
    // Remove element.
    void remove(const obj_t & x) { remove(x, m_root); }
};


#endif