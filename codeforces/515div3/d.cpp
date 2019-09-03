#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 5;
int row[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) 
        cin >> row[i];
    list< pair<int,int> >box;
    int firstbox = 0;
    int iter = 0;
    box.emplace_front(iter, k);
    int maxobj = 0;
    int obj = 0;
    for(int i = 0; i < n; i++) {
        if(box.front().se >= row[i]) { 
            box.front().se -= row[i];
            obj++;
            maxobj = max(maxobj, obj);
        }
        else {
            if(iter + 1 < m) {
                iter++;
                box.emplace_front(iter, k);
            } else {
                pair<int,int> tmp = box.back();
                tmp.se += row[firstbox];
                firstbox++;
                obj--;
                while(tmp.se < row[i]) {
                    tmp.se += row[firstbox];
                    firstbox++;
                    obj--;
                }
                box.pop_back();
                box.push_front(tmp);
            }
            box.front().se -= row[i];
            obj++;
            maxobj = max(maxobj, obj);
        }
    }

    cout << maxobj << endl;
    return 0;
}

