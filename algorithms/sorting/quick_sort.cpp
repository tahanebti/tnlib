//
//  quick sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

template<typename T>
int partition(vector<T>& a, int lo, int hi) {
    T pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[hi]);
    return i;
}

template<typename T>
void quick_sort(vector<T>& a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quick_sort(a, lo, p-1);
        quick_sort(a, p+1, hi);
    }
}

int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    quick_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}