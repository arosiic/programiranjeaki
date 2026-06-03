#include <bits/stdc++.h>
using namespace std;

void potezracunara(vector<int>& a) {

    int vecih = 0;
    for (int x : a)
        if (x > 1) vecih++;

    if (vecih == 0) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i]) {
                a[i]--;
                return;
            }
        }
    }

    int xr = 0;
    for (int x : a) xr ^= x;

    if (vecih == 1) {
        int idx = -1;
        int jedinica = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 1) idx = i;
            if (a[i] == 1) jedinica++;
        }

        if (jedinica % 2 == 0)
            a[idx] = 1;
        else
            a[idx] = 0;

        return;
    }

    for (int i = 0; i < a.size(); i++) {
        int cilj = a[i] ^ xr;

        if (cilj < a[i]) {
            a[i] = cilj;
            return;
        }
    }
}