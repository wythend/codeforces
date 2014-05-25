#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200000;
vector<int> G[N];
int f[N];
int g[N];
int cnt;
vector<int> ans;

void dfs(int x, int fa, int d, int s1, int s2) {
	int s;
	if (d == 0) s = s1; else s = s2;
	if (f[x] ^ s != g[x]) {
		cnt++;
		ans.push_back(x);
		if (d == 0) s1 = 1 - s1; else s2 = 1 - s2;
	}
	for (int i = 0; i < G[x].size(); i++) {
		if (G[x][i] != fa) {
			dfs(G[x][i], x, 1 - d, s1, s2);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &g[i]);
	}
	dfs(0, -1, 0, 0, 0);
	printf("%d", cnt);
	for (int i = 0; i < ans.size(); i++) {
		printf(" %d", ans[i] + 1);
	}
	printf("\n");
	return 0;
}
