#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string>row;
    int oper[n];
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        row.pb(s);
        if(row[i][0] == 'g' or row[i][0] == 'i') {
            int aux; cin >> aux;
            oper[i] = aux;
        }
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<string>resp;
    for(int i = 0; i < row.size(); i++) {
        if(row[i][0] == 'r') {
            if(pq.empty()) {
                int x = 1;
                resp.pb("insert " + to_string(x));
                pq.push(x);
            }
            resp.pb(row[i]);
            pq.pop();
        }
        else if(row[i][0] == 'g') {
            int x = oper[i];
            if((!pq.empty() and pq.top() > x) or pq.empty()) {
                resp.pb("insert " + to_string(x));
                pq.push(x);
                resp.pb(row[i] + " " + to_string(x));
            } 
            else if(x == pq.top()) {
                resp.pb(row[i] + " " + to_string(x));
            } else {
                while(!pq.empty() and pq.top() < x) {
                    resp.pb("removeMin");
                    pq.pop();
                }
                if(pq.top() == x) {
                    resp.pb(row[i] + " " + to_string(x));
                } else {
                    resp.pb("insert " + to_string(x));
                    pq.push(x);
                    resp.pb(row[i] + " " + to_string(x));
                }
            }
        } else {
            int x = oper[i];
            pq.push(x);
            resp.pb(row[i] + " " + to_string(x));
        }
    }
    cout << resp.size() << endl;
    for(auto id : resp)
        cout << id << endl;

    return 0;
}

