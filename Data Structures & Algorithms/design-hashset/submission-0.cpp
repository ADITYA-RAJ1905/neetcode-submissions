class MyHashSet {
public:

    static const int n = 1009;
    vector<vector<int>> arr;

    MyHashSet() {
        arr.resize(n);
    }

    void add(int key) {

        int idx = key % n;

        for(int x : arr[idx]){
            if(x == key)
                return;
        }

        arr[idx].push_back(key);
    }

    void remove(int key) {

        int idx = key % n;

        auto &bucket = arr[idx];

        for(int i = 0; i < bucket.size(); i++){
            if(bucket[i] == key){
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
    }

    bool contains(int key) {

        int idx = key % n;

        for(int x : arr[idx]){
            if(x == key)
                return true;
        }

        return false;
    }
};