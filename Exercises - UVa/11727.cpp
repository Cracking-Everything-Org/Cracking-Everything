#include <stdio.h>
using namespace std;

int main() {
	int T, a, b, c;
	int caseNum = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &a, &b, &c);

		if (a < b && c < b) {
			if (a < c) {
				printf("Case %d: %d\n", caseNum, c);
			}
			else {
				printf("Case %d: %d\n", caseNum, a);
			}
		}
		if (a < c && b < c) {
			if (a < b) {
				printf("Case %d: %d\n", caseNum, b);
			}
			else {
				printf("Case %d: %d\n", caseNum, a);
			}
		}
		if (b < a && c < a) {
			if (b < c) {
				printf("Case %d: %d\n", caseNum, c);
			}
			else {
				printf("Case %d: %d\n", caseNum, b);
			}
		}

		caseNum++;
	}
	return 0;
}