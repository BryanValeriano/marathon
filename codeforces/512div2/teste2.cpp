#include<bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 9;

int n;
long long a[N];
int b[N];
int cnt[2][N];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 0; i <n; ++i){
		cin >> a[i];
		b[i] = __builtin_popcountll(a[i]);	
	}
	
	long long res = 0;
	int sufSum = 0;
	cnt[0][n] = 1;
	for(int i = n - 1; i >= 0; --i){
		int sum = 0, mx = 0;
		int add = 0;
		for(int j = i; j < n && j - i < 65; ++j){
			sum += b[j];
			mx = max(mx, b[j]);
			if(mx > sum - mx && sum % 2 == 0) --add;
		}		
		
		sufSum += b[i];
		add += cnt[sufSum & 1][i + 1];
		res += add;	
		
		cnt[0][i] = cnt[0][i + 1];
		cnt[1][i] = cnt[1][i + 1];
		if(sufSum & 1) ++cnt[1][i];
		else ++cnt[0][i];
	}
	
	cout << res << endl;
	return 0;
}
