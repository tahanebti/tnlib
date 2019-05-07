//
//  insertion sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void insertion_sort(vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i-1; j >= 0 && a[j] > a[id]; j--) {
            swap(a[j], a[id]);
            id = j;
        }
    }
}



int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    insertion_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}