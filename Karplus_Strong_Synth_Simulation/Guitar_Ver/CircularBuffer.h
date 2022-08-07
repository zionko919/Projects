#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdint.h>
#include <queue>

class CircularBuffer {
public:
    explicit CircularBuffer(int capacity);
    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    ~CircularBuffer();
private:
//    std::queue<int16_t> data;
    int16_t *data;
    int capacity;
    int count;
    int front;
    int end;

};

#endif  // CIRCULARBUFFER_H_
