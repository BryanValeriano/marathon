#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#include <time.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ull unsigned long long int
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define ii pair<int,int>
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MAXN 100050

using namespace std;

char s1[MAXN], s2[MAXN];
int pref[MAXN], suff[MAXN], sum[MAXN];

int main(void) {
	gets(s1);
	gets(s2);
	int tams1 = strlen(s1), tams2 = strlen(s2);
	
	pref[0] = suff[0] = pref[tams1 + 1] = suff[tams1 + 1] = 0;
	
	for(int i = 1; i <= tams1; i++) {
		pref[i] = pref[i-1];
		if(s2[pref[i]] == s1[i-1]) {
            cout << i << " " << pref[i] << " | " << s2[pref[i]] << " " << s1[i-1] << endl;
            pref[i]++;
        }
	}
	
	for(int i = tams1; i > 0; i--) {
		suff[i] = suff[i+1];
		if(s2[tams2-1-suff[i]] == s1[i-1]) {
            cout << i << " " << suff[i] << " | " << s2[tams2-1-suff[i]] << " " << s1[i-1] << endl;
            suff[i]++;
        }
	}
	
	int maxx = 0;
	for(int i = 0; i <= tams1; i++) {
		sum[i] = min(tams2, pref[i] + suff[i+1]);
		maxx = max(maxx, sum[i]);
	}
	
	if(maxx == 0) return 0*puts("-");
	if(maxx == tams2) return 0*puts(s2);
	
	for(int i = 0; i <= tams1; i++) {
		if(sum[i] == maxx) {
			for(int j = 0; j < pref[i]; j++) putchar(s2[j]);
			for(int j = tams2 - suff[i+1]; j < tams2; j++) putchar(s2[j]);
			puts("");
			return 0;
		}
	}
	
	return 0;
}
