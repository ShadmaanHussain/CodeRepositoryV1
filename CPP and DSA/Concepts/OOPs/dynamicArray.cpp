using namespace std;

class dynamicArray
{
    int *data;
    int size;
    int nxtIndex;

public:
    dynamicArray()
    {
        data = new int[5];
        nxtIndex = 0;
        size = 5;
    }

    dynamicArray(dynamicArray const& d) {
        data = new int[d.size];
        for(int i = 0; i < d.nxtIndex; i++) {
            data[i] = d.data[i];
        }
        size = d.size;
        nxtIndex = d.nxtIndex;
    }

    void add(int el)
    {
        if (nxtIndex == size)
        {
            int *resized = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                resized[i] = data[i];
            }
            delete[] data;
            data = resized;
            size = size * 2;
        }
        data[nxtIndex] = el;
        nxtIndex++;
    }

    int get(int i) const
    {
        if (i < 0 || i >= nxtIndex)
        {
            return -1;
        }
        else
        {
            return data[i];
        }
    }

    void print() const
    {
        for (int i = 0; i < nxtIndex; i++)
        {
            cout << data[i] << " ";
        }
    }

    void add(int el, int i)
    {
        // reassign elements
        if (i > 0 && i < nxtIndex)
        {
            data[i] = el;
        }
        else if (i == nxtIndex)
        {
            add(el);
        }
        else
        {
            return;
        }
    }

    void operator= (dynamicArray const& d) {
        delete[] data;
        data = new int[d.size];
        for(int i = 0; i < d.nxtIndex; i++) {
            data[i] = d.data[i];
        }
        size = d.size;
        nxtIndex = d.nxtIndex;
    }
};