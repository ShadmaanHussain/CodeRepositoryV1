using namespace std;
template <typename V>

class stack {
    private:
    V* data;
    int nextIndex;
    int size;

    public:
    stack() {
        size = 5;
        data = new V[size];
        nextIndex = 0;
    }

    void push(V val) {
        if(nextIndex == size) {
            size = size * 2;
            int *temp = new int[size];
            for(int i = 0; i < size; i++) {
                data[i] = temp[i];
            }
            temp[nextIndex] = val;
            nextIndex++;
            delete [] data;
            data = temp;
        } 
        data[nextIndex] = val;
        nextIndex++;
    }

    int top() {
        return data[nextIndex-1];
    }

    int pop() {
        int val = data[nextIndex-1];
        nextIndex--;
        return val;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        if(nextIndex == 0) return true;
        return false;
    }

    ~stack() {
        delete [] data;
    }
};