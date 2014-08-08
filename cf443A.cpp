#include <iostream>
#include <cstdio>
using namespace std;

int a[1000];
int main() {
	int c;
	while ((c = getchar()) != EOF) {
		a[c]++;	
	}	
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++) 
		if (a[i] > 0) ans++;
	printf("%d\n", ans);
}
