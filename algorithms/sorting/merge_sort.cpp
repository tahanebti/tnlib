//
//  merge sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


template<typename T>
void merge(vector<T>& a, int l, int m, int r) {
    int lp = l, rp = m;
    int len = r-l+1;
    vector<T> x(len);
    for (int i = 0; i < len; i++) {
        x[i] =  lp == m       ? a[rp++] :
                rp == r       ? a[lp++] :
                a[lp] < a[rp] ? a[lp++] :
                a[rp++];
    }
    for (int i = 0; i < len; i++) {
        a[l+i] = x[i];
    }
}

template<typename T>
void merge_sort(vector<T>& a, int l, int r) {
    if (r-l < 2) return;
    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    merge(a, l, m, r);
}

template<typename T>
void merge(T* a, int m, int n) {
    int l = 0, r = m;
    T* x = (T*)malloc(n*sizeof(T));
    for (int i = 0; i < n; i++) {
        x[i] = l == m       ? a[r++] :
                r == n      ? a[l++] :
                a[l] < a[r] ? a[l++] :
                a[r++];
    }
    copy(x, x+n, a);
    free(x);
}

template<typename T>
void merge_sort(T* a, int n) {
    if (n < 2) return;
    int m = n/2;
    merge_sort(a, m);
    merge_sort(a+m, n-m);
    merge(a, m, n);
}

int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    merge_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}