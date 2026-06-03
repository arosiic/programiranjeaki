#include <bits/stdc++.h>
using namespace std;

int nimsum(const vector<int>& a) {
    int x = 0;
    for (int n : a) x ^= n;
    return x;
}

void potezracunara(vector<int>& a) {
    int x = nimsum(a);

    if (x == 0) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0) {
                a[i]--;
                cout << "Racunar uzima 1 iz gomile " << i + 1 << "\n";
                return;
            }
        }
    }

    for (int i = 0; i < a.size(); i++) {
        int cilj = a[i] ^ x;
        if (cilj < a[i]) {
            cout << "Racunar uzima " << a[i] - cilj
                 << " iz gomile " << i + 1 << "\n";
            a[i] = cilj;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool igrac = true;

    while (true) {
        int ukupno = 0;
        for (int x : a) ukupno += x;

        if (ukupno == 0) {
            cout << (igrac ? "Racunar pobedio\n"
                           : "Igrac pobedio\n");
            break;
        }

        if (igrac) {
            int g, k;
            cin >> g >> k;
            a[g - 1] -= k;
        } else {
            potezRacunara(a);
        }

        igrac = !igrac;
    }
}