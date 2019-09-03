#include <bits/stdc++.h>
using namespace std;

void process_solution(int a[], int k) {
	int i;
	printf("{");
	for(i = 1; i <= k; i++)
		if(a[i] == true) printf(" %d", i);
	printf(" }\n");
}

void construct_candidates(int c[]) {
	c[0] = true;
	c[1] = false;
}

void backtrack(int a[], int k, int n) {
	int c[2];
	int i;

	if(k == n)
		process_solution(a,k);
	else {
		k++;
		construct_candidates(c);
		for(i = 0; i < 2; i++) {
			a[k] = c[i];
			backtrack(a,k,n);
		}
	}
}

int main() {
	int n;
	printf("Number of sets: ");
	scanf("%d", &n);
	int a[n];
	backtrack(a, 0, n);
    return 0;
}

