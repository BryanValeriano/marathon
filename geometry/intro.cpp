#include <iostream>

using namespace std;

typedef long long ll;

struct point {
    ll x, y;
    
    point() {}
    
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    point operator + (const point &B) const {
        return point(this->x + B.x, this->y + B.y);
    }

    point operator - (const point &B) const {
        return point(this->x - B.x, this->y - B.y);
    }
    
    point operator * (int val) const {
        return point(this->x * val, this->y * val);
    }
    
    ll operator * (const point &B) const {
        return x*B.x + y*B.y;
    }
    
    ll operator ^ (const point &B) const {
        return x*B.y - y*B.x;
    }
};

bool inter(const point &A, const point &B, const point &C, const point &D) {
    point AB = B-A;
    point AC = C-A;
    point AD = D-A;
    
    if((AB^AC) * (AB^AD) > 0) 
        return false;
    
    point CD = D-C;
    point CA = A-C;
    point CB = B-C;
        
    if((CD^CA) * (CD^CB) > 0) 
        return false;
        
    return true;
}

point p, q;

int main() {
    p = point(10, 3);
    q = point(0, 1);

    point a = p*3;
    
    cout << a.x << " " << a.y << endl;
    cout << p*q << " " << q*p << endl;
    cout << (p^q) << " " ;
    cout << (q^p) << endl;
    
    point A = point(2,3);
    point B = point(4,5);
    point C = point(5, 4);
    point D = point(0, 3);
    cout << inter(A, B, C, D) << endl;
    
    cout << inter(D, A, B, C) << endl;
    
    
    return 0;
}
