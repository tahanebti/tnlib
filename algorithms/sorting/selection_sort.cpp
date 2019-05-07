//
//  selection sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void selection_sort(vector<T>& a) {
    int n = a.size();
//    for (int i = 0; i < n; i++) {
//        T min_el = numeric_limits<T>::max();
//        int min_id = i;
//        for (int j = i; j < n; j++) {
//            if (a[j] < min_el) {
//                min_el = a[j];
//                min_id = j;
//            }
//        }
//        swap(a[i], a[min_id]);
//    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[min_element(begin(a)+i, end(a))-begin(a)]);
    }
}


int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    selection_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}