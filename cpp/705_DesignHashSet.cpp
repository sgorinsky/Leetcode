class MyHashSet {
public:
    bool arr[1000000] {false};
    MyHashSet() {
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    bool contains(int key) {
        return arr[key];
    }
};
