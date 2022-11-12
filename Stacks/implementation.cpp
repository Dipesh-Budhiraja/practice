#include "header.h"
using namespace std;

class Stack {
private:
    int size;
    int *arr;
    int top;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[this->size];
        top = -1;
    }

    void push(int x) {
        if (top < size - 1) {
            arr[++top] = x;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return -1;
    }

    void pop() {
        if (top >= 0 && top < size) {
            top--;
        }
    }

    bool empty() {
        if (top >= 0) {
            return false;
        }
        return true;
    }
};


int main() {

    Stack st(5);
    st.push(42);
    st.push(23);
    st.push(44);

    cout << st.peek() << endl;
    
    st.pop();
    cout << st.peek() << endl;

    return 0;
}