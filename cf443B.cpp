#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char s[400];
int K;

int main() {
	scanf("%s", s);
	scanf("%d", &K);
	int l = strlen(s);

	int ans = K - K % 2;
	if (K >= l ) ans = K + l - (K + l) % 2;
	for (int i = 0; i < l; i++)
	for (int j = i; j < l; j++) 
	if (j + 1 + j - i < l + K) {
		bool flag = true;
		for (int k = 0; j + 1 + k  < l && i + k <= j; k++)
		if (s[i + k] != s[j + 1 +k]) {
			flag = false;
			break;
		}
		if (flag && 2 * (j - i + 1) > ans) ans = 2 * (j - i + 1);
	}
	printf("%d\n", ans);
}
