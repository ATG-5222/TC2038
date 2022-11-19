#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define M 999999

using namespace std;

class D{
    public:
    int x, y, c;
    D(int n, int m, int c) {
        x = n; y = m; this -> c = c;
    }
    bool operator < (D a) {
        return(c < a.c);
    }
    int gx() {
        return x;
    }
    int gy() {
        return y;
    }
    int gc() {
        return c;
    }
};

class G{
    public:
    vector <D> ar;
    int graph;
    G(int _graph) {
        this -> graph = _graph;
    }

    void Kruskal() {
        vector <D> t;
        int *s = new int[graph];
        memset(s, -1, sizeof(int) *graph);
        sort(ar.begin(), ar.end());
        for(int i = 0; i < ar.size(); i++) {
            int x = find(s, ar[i].gx()), y = find(s, ar[i].gy());
            if(y != x) {
                t.push_back(ar[i]);
                merge(s, x, y);
            }
        }
        for(int i = 0; i < t.size(); i++) {
            int x = 0 + t[i].gx(), y = 0 + t[i].gy();
            cout << "(" << x << ", " << y << ")" << endl;
        }
    }

    void Dijkstra(vector <int> & arr, int n) {
        for(int j = 0; j < n; j++) {
            vector <int> d(n, M);
            d[j] = 0;
            int v = 0;
            for(int p = 0; p < n; p++) {
                v = j + p;
                if(v >= n) {
                    v = v - n;
                }
                for(int q = 0; q < n; q++) {
                    if((arr[v * n + q] > 0) && (arr[v * n + q] + d[v] < d[q])) {
                        d[q] = arr[v * n + q] + d[v];
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                if(i != j) {
                    if(i >= j)
                    Add(j, i, d[i]);
                }
            }
        }
    }

    void Add(int n, int m, int c) {
        D ari(n, m, c);
        ar.push_back(ari);
    }

    void merge(int s[], int x1, int y2) {
        int a = find(s, x1), b = find(s, y2);
        s[a] = b;
    }

    int find(int j[], int i) {
        if(j[i] == -1) {
            return i;
        }
        return find(j, j[i]);
    }
};