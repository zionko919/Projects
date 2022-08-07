#include <stdexcept>
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int capacity) : capacity(capacity)
{
    if (capacity < 1)
    {
        throw std::invalid_argument
                ("RB constructor: capacity must be greater than zero");
    }
    data = new int16_t[capacity];
    front = 0;
    end = -1;
    count = 0;
    // if (cap < 1) {
    //     throw std::invalid_argument
    //             ("CB constructor: capacity must be greater than zero");
    // }
    // capacity = cap;
}

int CircularBuffer::size()
{
    return count;
    // return data.size();
}

bool CircularBuffer::isEmpty()
{
    return count == 0;
    // return data.empty();
}

bool CircularBuffer::isFull()
{
    return count == capacity;
    // return static_cast<int>(data.size()) >= capacity;
}

void CircularBuffer::enqueue(int16_t x)
{
    if (isFull())
    {
        throw std::runtime_error
                ("enqueue: can't enqueue to a full circle");
    }
    end = (end+1) % capacity;
    count++;
    data[end] = x;
    // if ( !isFull() ) {
    //     data.push(x);
    // } else {
    //     throw std::runtime_error("enqueue: can't enqueue to a full circle");
    // }
}

int16_t CircularBuffer::dequeue()
{
    int16_t temp = peek();
    front = (front+1) % capacity;
    count--;
    return temp;
    // int16_t temp;
    // if ( !isEmpty() ) {
    //     temp = data.front();
    //     data.pop();
    // } else {
    //     throw std::runtime_error("dequeue: can't dequeue to a empty circle");
    // }
    // return temp;
}

int16_t CircularBuffer::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error
                ("enqueue: can't peek or dequeue from a empty circle");
    }
    return data[front];
    // if ( isEmpty() ) {
    //     throw std::runtime_error("peek: can't peek an empty circle");
    // }
    // return data.front();
}

CircularBuffer::~CircularBuffer()
{
    delete[] data;
}
