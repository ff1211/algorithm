#ifndef VECTOR_TYPE
#define VECTOR_TYPE

#define DEBUG

#ifdef DEBUG
static size_t class_num = 0;
#endif

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
        std::cout << class_num << "'s "<< "constructor is called!" << std::endl;
        ++class_num;
        #endif
        m_size = size;
        m_capacity = size + SPARE_CAPACITY;
        m_data = new obj_t[m_capacity];
    }

    //copy constructor
    Vector(const Vector & rhs) {
        #ifdef DEBUG
        std::cout << class_num << "'s "<< "copy constructor is called!" << std::endl;
        ++class_num;
        #endif
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = new obj_t[rhs.m_capacity];
        std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
    }
    //move constructor
    Vector(Vector && rhs) {
        #ifdef DEBUG
        std::cout << class_num << "'s "<< "move constructor is called!" << std::endl;
        ++class_num;
        #endif
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_data = std::move(rhs.m_data);

        rhs.m_data = nullptr;
        rhs.m_capacity = 0;
        rhs.m_size = 0;
    }
    //copy assignment
    Vector &operator=(const Vector & rhs) {
        #ifdef DEBUG
        std::cout << class_num << "'s "<< "copy assignment is called!" << std::endl;
        ++class_num;
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
        std::cout << class_num << "'s "<< "move assignment is called!" << std::endl;
        ++class_num;
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
        ++m_size;
    }
    //rvalue reference
    void push_back(obj_t && val) {
        if(m_size + 1 > m_capacity)
            reserve(2 * m_size + 1);
        
        m_data[m_size] = val;
        ++m_size;
    }

    //delete last element
    void pop_back() {
        if(m_size == 0)
            return;
        else
            m_size--;
    }

    // Reference elements.
    obj_t & front() { return m_data[0]; } 
    const obj_t & front() const { return m_data[0]; }
    obj_t & back() { return m_data[m_size-1]; } 
    const obj_t & back() const { return m_data[m_size-1]; }

    //iterator
    typedef obj_t * iterator;
    typedef const obj_t * const_iterator;
    // non-const
    iterator end() { return &m_data[m_size]; }
    iterator begin() { return &m_data[0]; }
    // const
    const_iterator begin() const { return &m_data[0]; }
    const_iterator end() const { return &m_data[m_size]; }
};
#endif