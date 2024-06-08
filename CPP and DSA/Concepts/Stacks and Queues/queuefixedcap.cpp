using namespace std;

class Queue {
    int *data;
    int nextI;
    int firstI;
    int capacity;
    int size;

    public:
    Queue() {
        nextI = 0;
        firstI = 0;
        capacity = 5;
        data = new int[capacity];
        size = 0;
    }

    void enqueue(int val) {
        if(size == capacity) {
            capacity = 2 * capacity;
            int *newData = new int[capacity];
            int i = 0;
            do {
                newData[i] = data[firstI];
                firstI++;
                if(firstI == size) {
                    firstI = 0;
                }
            } while(firstI != nextI);
            delete [] data;
            data = newData;
            firstI = 0;
            nextI = size;
        }
        data[nextI] = val;
        nextI++;
        if(nextI == capacity) {
            nextI = 0;
        }
        size++;
    }

    int front() {
        return data[firstI];
    }

    void dequeue() {
        if(size == 0) cout << "Queue Empty" << endl;
        firstI++;
        if(firstI == capacity) {
            firstI = 0;
        }
        size--;
    }

    int returnSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};