//
//  heap sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


template<typename T>
class heap{
private:
    vector<T> tree;
    int lastn = 1;
    void swim(int v) {
        while (v != 1 && tree[v] > tree[v/2]) {
            swap(tree[v], tree[v/2]);
            v /= 2;
        }
    }
    void sink(int v) {
        while (2*v <= lastn) {
            int id = 2*v;
            if (id < lastn && tree[id] < tree[id+1]) id++;
            if (tree[v] >= tree[id]) break;
            swap(tree[v], tree[id]);
            v = id;
        }
    }
public:
    heap() {}
    heap(const vector<T>& data) {
        build_heap(data);
    }
    bool is_empty() { return lastn = 1; }
    void build_heap(const vector<T>& data) {
        tree = vector<T>(2*data.size()+2);
        for (int i = 0; i < data.size(); i++) {
            insert(data[i]);
        }
    }
    void insert(const T& val) {
        if (lastn+1 == tree.size()) {
            vector<T> ntree (tree.size()*2);
            copy(all(tree), begin(ntree));
            tree = ntree;
        }
        tree[lastn] = val;
        lastn++;
        swim(lastn-1);
    }
    inline T peek() const { return tree[1]; }
    inline T pop() {
        T root = tree[1];
        swap(tree[1], tree[lastn-1]);
        tree[lastn-1] = 0;
        lastn--;
        sink(1);
        return root;
    }
};

template<typename T>
heap<T> heapify(const vector<T>& data) {
    heap<T> res(data);
    return res;
}

template<typename T>
void heap_sort(vector<T>& data) {
    heap<T> sorting_heap = heapify(data);
    int n = data.size();
    for (int i = n-1; i >= 0; i--) {
        data[i] = sorting_heap.pop();
    }
}

int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    heap_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}