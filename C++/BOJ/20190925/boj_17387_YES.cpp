/*
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

struct point {
    lint x, y;
    bool operator<=(point& p) {
        if (this->x == p.x) return this->y <= p.y;
        return this->x <= p.x;
    }
};

lint ccw(point p1, point p2, point p3) {
    lint tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}

bool isIntersect(point p1, point p2, point p3, point p4) {
    int ab = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cd = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if (ab == 0 && cd == 0) {
        if (p2 <= p1) swap(p1, p2);
        if (p4 <= p3) swap(p3, p4);
        return p1 <= p4 && p3 <= p2;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    point p[4];
    for (int i=0;i<4;++i) cin >> p[i].x >> p[i].y;
    cout << isIntersect(p[0], p[1], p[2], p[3]);
}*/