#include <iostream>
#include <list>
using namespace std;


class MyHash {
    private:
    int bucketSize;
    list<int> *table;

    public:
    MyHash(int b) {
        bucketSize = b;
        table = new list<int>[bucketSize];
    }

    void insert(int key);
    void del(int key);
    bool search(int key);

};

void MyHash::insert(int key) {
    int i = key%bucketSize;
    table[i].push_back(key);
}

void MyHash::del(int key) {
    int i = key%bucketSize;
    table[i].remove(key);
}

bool MyHash::search(int key) {
    int i = key%bucketSize;
    for (auto x: table[i]) {
        if (x == key) {
            return true;
        }
    }
    return false;
}

int main() {
    MyHash myhash = MyHash(7);
    myhash.insert(70);
    myhash.insert(71);
    myhash.insert(9);
    myhash.insert(56);
    myhash.insert(72);

    cout << myhash.search(56) << endl;
    cout << myhash.search(57) << endl;

    myhash.del(56);
    cout << myhash.search(56) << endl;

    return 0;
}