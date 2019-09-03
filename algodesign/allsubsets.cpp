#include <bits/stdc++.h>
using namespace std;

void process_solution(int a[], int k) {
	int i;
	printf("{");
	for(i = 1; i <= k; i++)
		if(a[i] == true) printf(" %d", i);
	printf(" }\n");
}

void construct_candidates(int c[], int *ncandidates) {
	c[0] = true;
	c[1] = false;
	*ncandidates = 2;
}

bool is_a_solution(int k, int n) {
	return (k == n);
}

void backtrack(int a[], int k, int n) {
	int c[n];
	int ncandidates;
	int i;

	if(is_a_solution(k,n))
		process_solution(a,k);
	else {
		k++;
		construct_candidates(c,&ncandidates);
		for(i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,n);
		}
	}
}

void generate_subsets(int n) {
	int a[n];
	backtrack(a, 0, n);
}

int main() {
	int n;
	printf("Number of sets: ");
	scanf("%d", &n);
	generate_subsets(n);
    return 0;
}

