#ifndef VECTOR_TYPE
#define VECTOR_TYPE

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
#endif