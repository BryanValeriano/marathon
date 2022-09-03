#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 1e12;
const double PI = acos(-1.0);

struct robot {
	bool isMoving;
	int time;
	int pos;
	int goal;

	robot(bool isMoving, int pos, int goal, int time) :
		isMoving(isMoving), pos(pos), goal(goal), time(time) {}

	ii move(int delta) {
		time += delta;
		if(!isMoving) return mk(pos,pos);
		int oldPos = pos;
		int newPos = pos;

		if(delta >= abs(pos-goal)) newPos = goal;
		else newPos = pos + delta * (pos < goal? 1 : -1);
		pos = newPos;
		isMoving = !(pos == goal);
		return mk(min(newPos, oldPos), max(newPos, oldPos));
	}

	void setGoal(int newGoal) {
		isMoving = 1;
		goal = newGoal;
	}

	
};

struct node {
	//1 is commanda 0 is query
	int time;
	int pos;

	node() {}

	node(int pos, int time):
		pos(pos), time(time) {}

	bool operator < (const node &b) {
		return time < b.time;
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int ans = 0;
		vector<node> time;
		robot r = robot(0,0,0,0);

		for(int i = 0; i < n; i++) {
			int t,x; cin >> t >> x;
			time.eb(x,t);
		}

		time.eb(INF, INF);
		sort(time.begin(), time.end());
		int lastGoal = -INF;

		for(node n : time) {
			int delta = max(0ll, n.time - r.time);
			ii xy = r.move(delta);
			ans += (lastGoal >= xy.fi && lastGoal <= xy.se);
			lastGoal = n.pos;
			if(r.isMoving) continue;
			r.setGoal(n.pos);
		}

		cout << ans << endl;
	}
    return 0;
}

