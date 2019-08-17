#include <iostream>
#include <vector>
using namespace std;

int main() {
	int loanDur, nRec, m;
	double downPayment, p, loan, perces[101];
	while (true) {
		cin >> loanDur >> downPayment >> loan >> nRec;
		if (loanDur < 0) break;
		while (nRec--) {
			cin >> m >> p;
			for (int i = m; i < 101; i++) perces[i] = p;
		}
		int now = 0;
		double monthlyPayment = loan / loanDur;
		double curVal = (loan + downPayment) * (1 - perces[0]);
		double curLoan = loan;
		while (curVal < curLoan) {
			now++;
			curLoan -= monthlyPayment;
			curVal = curVal * (1-perces[now]);
		}
		cout << now << " month";
		if (now != 1) cout << "s";
		cout << endl;
	}

	return 0;
}