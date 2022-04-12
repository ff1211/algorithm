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
        // subtree height
        int height;
        // copy constructor
        node(const obj_t & d, node * l, node * r, int h = 0) :
            data    ( d     ),
            left    ( l     ),
            right   ( r     ),
            height  ( h     ) { }
        // move constructor
        node(obj_t && d, node * l, node * r, int h = 0) :
            data    ( std::move(d)  ),
            left    ( l     ),
            right   ( r     ),
            height  ( h     ) { }
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
        this->update_height(t);
        this->balance(t);
    }
    // Rvalue reference.
    void insert(obj_t && x, node * & t) {
        if(t == nullptr)
            t = new node(std::move(x), nullptr, nullptr);
        else if(x < t->data)
            insert(std::move(x), t->left);
        else if(x > t->data)
            insert(std::move(x), t->right);
        this->update_height(t);
        this->balance(t);
    }
    // Internal method to remove from a subtree.
    // x is the item to remove.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.
    // Return true if successfully removed, otherwise return false.
    bool remove(const obj_t & x, node * & t) {
        if(t == nullptr)
            return false;
        bool if_removed;
        if(x < t->data)
            if_removed = remove(x, t->left);
        else if(x > t->data)
            if_removed = remove(x, t->right);
        else {
            if(t->left != nullptr && t->right != nullptr) {
                t->data = find_min(t->right)->data;
                remove(t->data, t->right);
            } else {
                node * old_node = t;
                t = (t->left == nullptr)? t->right : t->left;
                delete old_node;
            }
            if_removed = true;
        }
        this->update_height(t);
        this->balance(t);
        return if_removed;
    }

    // Internal method to print tree.
    // t is the node that roots the subtree.
    // out is the out stream.
    void print_tree(const std::string& prefix, node * t, bool is_left, std::ostream & out) const {
        if(t == nullptr)
            return;
        out << prefix;
        out << (is_left ? "├──" : "└──" );

        // print the value of the node
        out << t->data << std::endl;

        // enter the next tree level - left and right branch
        print_tree(prefix + (is_left ? "│   " : "    "), t->left, true, out);
        print_tree(prefix + (is_left ? "│   " : "    "), t->right, false, out);        
    }
    // Internal method to update height.
    virtual void update_height(node * t) { }
    // Internal method to balance tree.
    virtual void balance(node * & t) { }
public:
    // Constructor
    Bst() { this->m_root = nullptr; }
    // Copy constructor
    Bst(const Bst & rhs) { m_root = clone(rhs.m_root); }
    // Move constructor
    Bst(Bst && rhs) { 
        this->m_root = rhs.m_root;
        rhs.m_root = nullptr;
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
    bool remove(const obj_t & x) { return remove(x, m_root); }
    // Print tree.
    void print_tree(std::ostream & out) { print_tree("", m_root, false, out); out << std::endl; }
};


#endif