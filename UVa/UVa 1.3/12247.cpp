#include <cstdio>
#include <algorithm>
using namespace std;

bool inUse(int c, int s[], int b[]) {
	for (int i = 0; i < 3; i++) {
		if (c == s[i])
			return true;
	}
	for (int i = 0; i < 2; i++) {
		if (c == b[i])
			return true;
	}
	return false;
}

int main() {
	int sis[3], bro[2];
	while (scanf("%d %d %d %d %d", &sis[0], &sis[1], &sis[2], &bro[0], &bro[1]), sis[0]
			|| sis[1] || sis[2] || bro[0] || bro[1]) {
		sort(sis, sis + 3);
		sort(bro, bro + 2);
		int lc = 0;
		bool used[3] = { false, false, false };

		for (int i = 0; i < 2; i++) {
			bool found = false;
			for (int j = 0; j < 3; j++) {
				if ((sis[j] > bro[i]) && !used[j]) {
					used[j] = true;
					lc++;
					found = true;
					break;
				}
			}
			if (!found) {
				for (int j = 0; j < 3; j++) {
					if (!used[j])
						used[j] = true;
					break;
				}
			}

		}
		if (lc == 2) {
			printf("-1\n");
			continue;
		}

		int lastC = 0;
		if (lc != 0) {
			for (int i = 0; i < 3; i++) {
				if (!used[i])
					lastC = sis[i];
			}
		}

		int trumpC = lastC + 1;
		while (inUse(trumpC, sis, bro)) {
			trumpC++;
		}
		if (trumpC > 52)
			trumpC = -1;

		printf("%d\n", trumpC);
	}

	return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;
// int a,b,c,e,d;

// bool winAgainstTwo(int n, int a, int b, int c){
//     int NbiggerThan = 0;
//     if (n > a) NbiggerThan ++;
//     if (n > b) NbiggerThan ++;
//     if (n > c) NbiggerThan ++;
//     return (NbiggerThan >= 2);
// }

// bool notUsed(int i){
//     if (i != a && i != b && i != c && i != d && c != e) return true;
//     else return false;
// }

// void showMinimumWinner(int a, int b, int c){
//     int maxCandidate = 0; 
//     if(a>b && a>c) maxCandidate = max(b,c);
//     else if(b>a && b>c) maxCandidate = max(a,c);
//     else if(c>a && c>b)  maxCandidate = max(a,b);

//     int newCandidate = maxCandidate;
//     for(int i=maxCandidate+1; i<=52 ; i++){
//         if(notUsed(i)) {
//             cout << i << endl;
//             newCandidate = i;
//         }
//     }
//     if(newCandidate == maxCandidate) cout << "-1" << endl;
// }

// int main(){
//     while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e), a || b || c || d || e){
//         if(winAgainstTwo(d,a,b,c) && winAgainstTwo(e,a,b,c)){
//             showMinimumWinner(a,b,c);
//         } else cout << "-1" << endl;
//     }
//     return 0;
// }