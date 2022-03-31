#ifndef QUEUE_TYPE
#define QUEUE_TYPE

template <typename obj_t>
class Queue
{
private:
    size_t m_size;
    size_t m_capacity;
    size_t m_front;
    size_t m_back;
    obj_t *m_data;

    // test if full
    bool full() { return m_size == m_capacity; }
    // change capacity
    void reserve(size_t new_capacity) {
        obj_t * new_data = new obj_t[new_capacity];
        obj_t * p_front = m_data + m_front;
        size_t left_len = m_back + 1;
        if(m_back < m_front) {
            size_t right_len = m_size - m_front;
            std::copy(p_front, m_data + m_size, new_data);
            std::copy(m_data, m_data + left_len, new_data + right_len);
        } else
            std::copy(p_front, m_data + left_len, new_data);
        
        delete [] m_data;
        m_data = new_data;
        new_data = nullptr;
        m_front = 0;
        m_back = m_size - 1;
        m_capacity = new_capacity;
    }
public:
    static const int SPARE_CAPACITY = 16;
    Queue(size_t capacity = SPARE_CAPACITY) {
        m_size = 0;
        m_front = 0;
        m_back = 0;
        m_capacity = capacity;
        m_data = new obj_t[capacity];
    };
    ~Queue() { delete [] m_data; };

    // Access front element.
    obj_t & front() const { return m_data[m_front]; }
    // Access last element.
    obj_t & back() const { return m_data[m_back]; }

    // Test whether container is empty.
    bool empty() const { return !m_size; }
    // Returns the number of elements in the queue.
    size_t size() const { return m_size; }

    // Remove next element.
    void pop() {
        if(m_size == 0)
            return;
        else if(m_size > 1)
            m_front = (m_front == (m_capacity-1))? 0 : m_front+1;
        --m_size;
    }

    // Inserts a new element at the end of the queue.
    // Lvalue reference.
    void push(const obj_t & val) {
        if(m_size == 0) {
            m_data[m_back] = val;
        } else {
            if(full())
                reserve(2 * m_capacity);
            m_back = (m_back == (m_capacity-1))? 0 : m_back+1;
            m_data[m_back] = val;
        }
        ++m_size;
    }
    // Rvalue reference.
    void push(obj_t && val) {
        if(m_size == 0) {
            m_data[m_back] = val;
        } else {
            if(full())
                reserve(2 * m_capacity);
            m_back = (m_back == (m_capacity-1))? 0 : m_back+1;
            m_data[m_back] = val;
        }
        ++m_size;
    }
};

#endif