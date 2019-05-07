//
//  bubble sort
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


template<typename T>
void bubble_sort(vector<T>& a) {
    bool has_changed = false;
    int i = 0, n = a.size();
    do {
        has_changed = false;
        for (int j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                has_changed = true;
            }
        }
        i++;
    } while (has_changed);
}


int main(){
    srand(time(0));
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand()%100;
    }
    bubble_sort(data);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    } cout << "\n";
    return 0;
}