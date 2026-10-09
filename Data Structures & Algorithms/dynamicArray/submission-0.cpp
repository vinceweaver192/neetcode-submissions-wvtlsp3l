class DynamicArray {
private:
    int cap;
    int size;
    int* arr;

public:

    DynamicArray(int capacity) {
        cap = capacity;
        size = 0;
        arr = new int[cap];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) { // boundary checking?
        if (size == cap)
            resize();
        arr[size] = n;
        size++;
    }

    int popback() { // boundary checking?
        if (size > 0)
            size--;
        return arr[size];
    }

    void resize() {
        cap = cap << 1;
        int* newArr = new int[cap];
        // copy all elements
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
