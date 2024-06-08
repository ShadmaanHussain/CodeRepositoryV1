using namespace std;

class Queue {
    int* data;
    int fr;
    int size;
    int capacity;

    public:
    Queue() {
        fr = 0;
        int capacity = 10;
        data = new int[capacity];
        size = 0;
    }

    void enqueue(int val) {
        if(size == capacity) {
            capacity = capacity * 2;
            int *temp = new int[capacity];
            for(int i = 0; i < size; i++) {
                data[i] = temp[i];
            }
            delete [] data;
            data = temp;
        }
        data[size] = val;
        size++;
    }

    int front() {
        return data[fr];
    }

    void dequeue() {
        fr++;
    }

    int retSize() {
        return size - fr;
    }

    bool isEmpty() {
        if(size - fr == 0) return true;
        return false;
    }

};