#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
	string s;
	int saldo;
	int mini;
	int id;

	bool operator < (const node &b) const {
		if(mini != b.mini) return mini < b.mini;
		return false;
	}	
};

vector<node> v;

struct trio { int saldo, pos, id; };

trio maxx(const trio &a, const trio &b) {
	if(a.saldo > b.saldo) return a;
    if(b.saldo > a.saldo) return b;
    if(a.saldo == b.saldo) {
        if(v[a.pos].mini <= v[b.pos].mini) return a;
        return b;
    }
	return b;
}

const int T = 2e5 + 10;
trio seg[4*T];
int a,b;

vector<trio> vv;

ii calc(string s) {
	int mini = 0;
	int x = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') x++;
		else x--;
		mini = min(mini,x);
	}

	return ii(x,mini);
}

void build(int r, int i, int j) {
	if(i == j) seg[r] = vv[i]; 	
		else {
		int mid = (i+j) >> 1;
		build(2*r,i ,mid);
		build(2*r+1, mid+1,j);
		seg[r] = maxx(seg[2*r], seg[2*r+1]);
	}
}

void update(int r, int i, int j) {
	if(i > b or j < a) return;
	if(i >= a and j <= b) seg[r].saldo = -INF; 
	else {
		int mid = (i+j) >> 1;
		update(2*r, i, mid);
		update(2*r+1, mid+1, j);
		seg[r] = maxx(seg[2*r], seg[2*r+1]);
	}
}
		
trio query(int r, int i, int j) {	
	if(i > b or j < a) return trio({-INF,0, 0});
	if(i >= a and j <= b) return seg[r]; 
	int mid = (i+j) >> 1;
	return maxx(query(2*r, i, mid), query(2*r+1, mid+1, j));
}
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string s;
    int test = 0;

	for(int i = 0; i < n; i++) {
		cin >> s;
		ii tmp = calc(s);
		v.pb({s, tmp.fi, tmp.se, i});
        test += tmp.fi;
	}
    if(test != 0) { cout << "NO" << endl; return 0; }

	int best = -1;
	int pos = -1;

	for(int i = 0; i < v.size(); i++) 
		if(v[i].mini == 0) 
			if(v[i].saldo > best) best = v[i].saldo, pos = i;

	if(best == -1) { cout << "NO" << endl; return 0; }

	v[pos].saldo = -INF;
	vector<int> ans;
    set<int> conf;
    conf.insert(pos);
	ans.pb(pos);
	int saldo = best;
	int iter = 1;
	
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++) 
		vv.pb({v[i].saldo, i, v[i].id});

	build(1,0,n-1);	

	while(saldo >= 0 and iter < n) {
        node pqp = node({"",0,-saldo,0});
		int pode = lower_bound(v.begin(), v.end(), pqp) - v.begin();
        if(saldo - v[pode].mini < 0) break;
		a = pode; b = n-1;
		trio xx = query(1,0,n-1);
		saldo += xx.saldo;
		if(saldo < 0) break;
		ans.pb(xx.id);
        conf.insert(xx.id);
		a = xx.pos; b = xx.pos;
		update(1,0,n-1);
		iter++;
	}

	if(conf.size() != n or saldo != 0) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for(auto z : ans) cout << z+1 << " ";
		cout << endl;
	}
	return 0;
}
