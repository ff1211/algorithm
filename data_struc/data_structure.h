#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE

#define DEBUG

template <typename obj_t>
class Vector
{
private:
    size_t m_size;
    size_t m_capacity;
    obj_t *m_data;

public:
    static const int SPARE_CAPACITY = 16;

    //constructor
    Vector(size_t size = 0) {
        #ifdef DEBUG
        std::cout << "Constructor is called!" << std::endl;
        #endif
        m_size = size;
        m_capacity = size + SPARE_CAPACITY;
        m_data = new obj_t[size * 2];
    }
    //copy constructor
    Vector(const Vector & rhs) {
        #ifdef DEBUG
        std::cout << "Copy constructor is called!" << std::endl;
        #endif
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = new obj_t[rhs.m_capacity];
        std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
    }
    //move constructor
    Vector(Vector && rhs) {
        #ifdef DEBUG
        std::cout << "Move constructor is called!" << std::endl;
        #endif
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = rhs.m_data;

        rhs.m_data = nullptr;
        rhs.m_capacity = 0;
        rhs.m_size = 0;
    }
    //copy assignment
    Vector &operator=(const Vector & rhs) {
        #ifdef DEBUG
        std::cout << "Copy assignment is called!" << std::endl;
        #endif
        if(this == &rhs) return *this;

        delete [] m_data;
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = new obj_t[rhs.m_capacity];
        std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);

        return *this;
    }
    // move assignment
    Vector &operator=(Vector && rhs) {
        #ifdef DEBUG
        std::cout << "Move assignment is called!" << std::endl;
        #endif
        if (this == &rhs) return *this;

        delete [] m_data;
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = rhs.m_data;

        rhs.m_data = nullptr;
        rhs.m_capacity = 0;
        rhs.m_size = 0;
        return *this;
    }
    // destructor
    ~Vector() {
        delete [] m_data;
    }
    //[] overload
    obj_t & operator[](size_t index) { return m_data[index]; }

    //return m_size
    size_t size() const { return m_size; }
    //return m_capacity
    size_t capacity() const { return m_capacity; }
    //resize
    void resize(size_t new_size) {
        if(new_size <= m_capacity)
            m_size = new_size;
        else
            reserve(2 * new_size);
    }
    //check if empty
    bool empty() const { return (m_size == 0); }
    //change capacity
    void reserve(size_t new_capacity) {
        if(new_capacity > m_capacity) {
            obj_t *new_data = new obj_t[new_capacity];
            std::copy(m_data, m_data + m_size, new_data);
            delete [] m_data;
            m_data = new_data;
            new_data = nullptr;
            m_capacity = new_capacity;
        }
    }

    //add element at the end
    //lvalue reference
    void push_back(const obj_t & val) {
        if(m_size + 1 > m_capacity)
            reserve(2 * m_size + 1);
        
        m_data[m_size] = val;
        m_size++;
    }
    //rvalue reference
    void push_back(obj_t && val) {
        if(m_size + 1 > m_capacity)
            reserve(2 * m_size + 1);
        
        m_data[m_size] = std::move(val);
        m_size++;
    }

    //delete last element
    void pop_back() {
        if(m_size == 0)
            return;
        else
            m_size--;
    }

    //iterator
    typedef obj_t * iterator;
    typedef const obj_t * const_iterator;
    //begin
    iterator begin() { return &m_data[0]; }
    const_iterator begin() const { return &m_data[0]; }
    //end
    iterator end() { return &m_data[m_size]; }
    const_iterator end() const { return &m_data[m_size]; }
};

template <typename obj_t>
class List
{
private:
    //data node
    struct node {
        obj_t data;
        node * prev;
        node * next;

        node(const obj_t & d = obj_t{}, node * p = nullptr, node * n = nullptr) {
            data = d;
            prev = p;
            next = n;
        }
        node(obj_t && d, node * p = nullptr, node * n = nullptr) {
            data = std::move(d);
            prev = p;
            next = n;
        }
    };
    //structure
    node * m_head;
    node * m_tail;
    size_t m_size;

    void init() {
        m_size = 0;
        m_head = new node;
        m_tail = new node;
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }
public:
    // const_iterator
    class const_iterator{
    public:
        // constructor
        const_iterator() { current = nullptr; }

        //operators overlaod
        const obj_t & operator*() { return retrieve(); }
        const_iterator operator++() {
            current = current->next;
            return *this;
        }
        const_iterator operator++(int){
            const_iterator old = *this;
            ++( *this );
            return old;
        }
        bool operator==(const const_iterator & rhs) const { return rhs.current == current; }
        bool operator!=(const const_iterator & rhs) const { return rhs.current != current; }
    protected:
        node * current;
        obj_t & retrieve() const { return current->data; }
        const_iterator(node *p) { current = p; }

    friend class List<obj_t>;
    };
    
    // iterator
    class iterator : public const_iterator{
    public:
        // constructor
        iterator() {}
        //operators overlaod
        obj_t & operator*() { return this->retrieve(); }
        iterator & operator++() {
            this->current = this->current->next;
            return *this;
        }
        iterator operator++ (int) {
            iterator old = *this;
            ++( *this );
            return old;
        }
    protected:
        iterator( node *p ) : const_iterator(p) { }

    friend class List<obj_t>;
    };
public:
    List(size_t size = 0, const obj_t & val = obj_t{}) {
        // creat head and tail
        init();
        // if size == 0 return
        if(size == 0)
            return;
        // create the list
        iterator begin_pos(m_head);
        insert(begin_pos, size, val);
    }
    List(const List<obj_t> &rhs) {
        // creat head and tail
        init();
        // copy from rhs
        for(auto & x : rhs)
            push_back(x);
    }

    ~List() { 
        iterator it(m_head);

        while(it != m_tail)
            it = erase(it);
        delete this->m_tail;
    }

    // insert elements(lvalue reference)
    iterator insert(iterator position, size_t size = 0, const obj_t & val = obj_t{}) {
        iterator it(position);
        // if size == 0 or the position to insert is tail, return
        if(size == 0 || position.current == m_tail)
            return it;

        // the node before insertion
        node * prev_node = position.current;
        // the node after insertion
        node * after_node = position.current->next;
        // create inserted nodes
        for (size_t i = 0; i < size; i++){
            prev_node->next = new node(val);
            prev_node->next->prev = prev_node;
            ++it;
        }
        after_node->prev = prev_node->next;
        m_size = m_size + size;
        return it;
    }

    // insert single element(rvalue reference)
    iterator insert(const_iterator position, const obj_t && val = obj_t{}) {
        iterator it(position);
        it.current->next = new node(val);
        ++it;
        ++m_size;
        return it;
    }

    // delete element 
    iterator erase(iterator it) {
        it.current->prev->next = it.current->next;
        it.current->next->prev = it.current->prev;
        delete it.current;
        --m_size;
        ++it;
        return it;
    }

    // delete continuous element 
    iterator erase(iterator begin, iterator end) {
        begin.current->prev->next = end.current;
        end.current->prev = begin.current->prev;
        for(iterator itr = begin; itr != end;)
            itr = erase(itr);
        return end;
    }

    // add element at the end.
    void push_back(const obj_t & val) { insert(m_tail, val); }
    void push_back(obj_t && val) { insert(m_tail, val); }
    // add element at the begin.
    void push_front(const obj_t & val) { insert(m_head, val); }
    void push_front(obj_t && val) { insert(m_head, val); }

    iterator begin() { iterator it(m_head); return ++it; }
    iterator end() { iterator it(m_tail); return it; }
    const_iterator begin() const { const_iterator it(m_head); return ++it; }
    const_iterator end() const { const_iterator it(m_tail); return it; }
};

#endif