#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool ehBissesto(int ano) {
	if(ano%4 == 0) {
		if(ano%100 == 0 and ano%400 != 0) return false;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int at = 1867;
	int day = 0;
	int n; cin >>n;
	string s[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	for(int i = 1; i <= n; i++) {
		if(ehBissesto(at+i)) day += 2;
		else day++;
		day %= 7;
	}

	cout <<s[day] <<endl;

	return 0;
}
 
