#include <iostream>
#include <string>
using namespace std;

int getValue(int C[], int D[], int H[], int S[], char tempChar, char tempChar2){
	if(tempChar=='A'){
		if(tempChar2=='C'){
			C[0]=C[0]+4;
			C[4]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+4;
			D[4]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+4;
			H[4]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+4;
			S[4]=1;
		}
		return 4;
	}
	else if(tempChar=='K'){
		if(tempChar2=='C'){
			C[0]=C[0]+3;
			C[3]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+3;
			D[3]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+3;
			H[3]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+3;
			S[3]=1;
		}
		return 3;
	}
	else if(tempChar=='Q'){
		if(tempChar2=='C'){
			C[0]=C[0]+2;
			C[2]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+2;
			D[2]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+2;
			H[2]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+2;
			S[2]=1;
		}
		return 2;
	}
	else if(tempChar=='J'){
		if(tempChar2=='C'){
			C[0]=C[0]+1;
			C[1]=1;
		}
		else if(tempChar2=='D'){
			D[0]=D[0]+1;
			D[1]=1;
		}
		else if(tempChar2=='H'){
			H[0]=H[0]+1;
			H[1]=1;
		}
		else if(tempChar2=='S'){
			S[0]=S[0]+1;
			S[1]=1;
		}
		return 1;
	}
	return 0;
}

void countCards(int C[], int D[], int H[], int S[], char tempChar){
	if(tempChar=='C') C[5]++;
	else if(tempChar=='D') D[5]++;
	else if(tempChar=='H') H[5]++;
	else if(tempChar=='S') S[5]++;
}

void checkCond(int &ans, int valueSuit[]){
	if(valueSuit[5]==1){
		if((valueSuit[3]==1)||(valueSuit[2]==1)||(valueSuit[1]==1)) ans--;
	}
	else if(valueSuit[5]==2){
		if((valueSuit[2]==1)&&(valueSuit[1]==1)){
			ans--;
			ans--;
		}
		else if((valueSuit[2]==1)||(valueSuit[1]==1)) ans--;
	}
	else if (valueSuit[5]==3){
		if(valueSuit[1]==1) ans--;
	}
}

void checkCond2(int &ans, int valueSuit[]){
	if(valueSuit[5]==0) ans=ans+2;
	else if(valueSuit[5]==1) ans=ans+2;
	else if(valueSuit[5]==2) ans=ans+1;
}

bool isNoTrump(int ans, int valueSuit[]){
	if (ans<16) return false;
	if (valueSuit[5]==1){
		if (valueSuit[4]==1) return true;
	}
	if (valueSuit[5]==2){
		if((valueSuit[3]==1)||(valueSuit[4]==1)) return true;
	}
	if(valueSuit[5]>=3){
		if((valueSuit[2]==1)||(valueSuit[3]==1)||(valueSuit[4]==1)) return true;
	}
	return false;
}

char getCharMaxBid(int numC, int numD, int numH, int numS){
	if((numS>=numC)&&(numS>=numD)&&(numS>=numH)){
		return 'S';
	}
	if((numH>=numC)&&(numH>=numD)&&(numH>=numS)){
		return 'H';
	}
	if((numD>=numC)&&(numD>=numS)&&(numD>=numH)){
		return 'D';
	}
	if((numC>=numS)&&(numC>=numD)&&(numC>=numH)){
		return 'C';
	}
	return ' ';
}

int main(){
	string cards;
	
	int i=0;
	int ans=0;
	int valueC[6];
	int valueD[6];
	int valueH[6];
	int valueS[6];
	bool noTrumpC=0;
	bool noTrumpD=0;
	bool noTrumpH=0;
	bool noTrumpS=0;
	for(int j=0;j<6;j++){
		valueC[j]=0;
		valueD[j]=0;
		valueH[j]=0;
		valueS[j]=0;
	}
	while(getline(cin,cards,' ')){
		ans=ans+getValue(valueC,valueD,valueH,valueS,cards[0],cards[1]);
		countCards(valueC,valueD,valueH,valueS,cards[1]);
		i++;
		while(i<13){
			if(i==12) getline(cin,cards);
			else getline(cin,cards,' ');
			ans=ans+getValue(valueC,valueD,valueH,valueS,cards[0],cards[1]);
			countCards(valueC,valueD,valueH,valueS,cards[1]);
			i++;
		}	
		checkCond(ans,valueC);
		checkCond(ans,valueD);
		checkCond(ans,valueH);
		checkCond(ans,valueS);		
		noTrumpC=isNoTrump(ans,valueC);
		noTrumpD=isNoTrump(ans,valueD);
		noTrumpH=isNoTrump(ans,valueH);
		noTrumpS=isNoTrump(ans,valueS);
		checkCond2(ans,valueC);
		checkCond2(ans,valueD);
		checkCond2(ans,valueH);
		checkCond2(ans,valueS);
	
		if((noTrumpC)&&(noTrumpD)&&(noTrumpH)&&(noTrumpS)){
			cout << "BID NO-TRUMP" << endl;
		}
		else if(ans<14){
			cout << "PASS" << endl;
		}
		else{
			cout << "BID " << getCharMaxBid(valueC[5],valueD[5],valueH[5],valueS[5]) << endl;
		}
		
		i=0;
		ans=0;
		noTrumpC=false;
		noTrumpD=false;
		noTrumpH=false;
		noTrumpS=false;
		for(int j=0;j<6;j++){
			valueC[j]=0;
			valueD[j]=0;
			valueH[j]=0;
			valueS[j]=0;
		}
	}
	return 0;
}

// #include <string>
// #include <map>
// #include <iostream>
// #include <vector>
// using namespace std;

// map<char, int> suitCounter;
// map<char, map<char, int> > suitCards;
// map<char, bool> suitStopped;
// int totalPoints, beforeNT;
// string card;

// void ruleOne(string card){
//     if(card[0] == 'A'){ 
//         totalPoints +=4;
//         suitCards[card[1]]['A']++;
//     }
//     else if(card[0] == 'K') {
//         totalPoints +=3;
//         suitCards[card[1]]['K']++;
//     }
//     else if(card[0] == 'Q') {
//         totalPoints +=2;
//         suitCards[card[1]]['Q']++;
//     } 
//     else if(card[0] == 'J') {
//         totalPoints +=1;
//         suitCards[card[1]]['J']++;
//     }
//     else {
//         suitCards[card[1]]['O']++;
//     }
// }

// void ruleTwo(string card){
//     if(suitCards['S']['K'] == 1 && suitCounter['S'] == 1) totalPoints--;
//     if(suitCards['H']['K'] == 1 && suitCounter['H'] == 1) totalPoints--;
//     if(suitCards['D']['K'] == 1 && suitCounter['D'] == 1) totalPoints--;
//     if(suitCards['C']['K'] == 1 && suitCounter['C'] == 1) totalPoints--;
// }

// void ruleThree(string card){
//     if(suitCards['S']['Q'] == 1 && suitCounter['S'] <= 2) totalPoints--;
//     if(suitCards['H']['Q'] == 1 && suitCounter['H'] <= 2) totalPoints--;
//     if(suitCards['D']['Q'] == 1 && suitCounter['D'] <= 2) totalPoints--;
//     if(suitCards['C']['Q'] == 1 && suitCounter['C'] <= 2) totalPoints--;
// }

// void ruleFour(string card){
//     if(suitCards['S']['J'] == 1 && suitCounter['S'] <= 3) totalPoints--;
//     if(suitCards['H']['J'] == 1 && suitCounter['H'] <= 3) totalPoints--;
//     if(suitCards['D']['J'] == 1 && suitCounter['D'] <= 3) totalPoints--;
//     if(suitCards['C']['J'] == 1 && suitCounter['C'] <= 3) totalPoints--;
// }

// void rulesFiveSixSeven(){
//     //rule 5
//     if(suitCounter['S'] == 2) totalPoints++; 
//     if(suitCounter['H'] == 2) totalPoints++; 
//     if(suitCounter['D'] == 2) totalPoints++; 
//     if(suitCounter['C'] == 2) totalPoints++;
//     //rule 6
//     if(suitCounter['S'] == 1) totalPoints+=2; 
//     if(suitCounter['H'] == 1) totalPoints+=2; 
//     if(suitCounter['D'] == 1) totalPoints+=2; 
//     if(suitCounter['C'] == 1) totalPoints+=2;
//     //rule 7
//     if(suitCounter['S'] == 0) totalPoints+=2; 
//     if(suitCounter['H'] == 0) totalPoints+=2; 
//     if(suitCounter['D'] == 0) totalPoints+=2; 
//     if(suitCounter['C'] == 0) totalPoints+=2;
// }

// void checkStopped(){
//     if(suitCards['S']['A'] == 1) suitStopped['S'] = true;
//     if(suitCards['H']['A'] == 1) suitStopped['H'] = true;
//     if(suitCards['D']['A'] == 1) suitStopped['D'] = true;
//     if(suitCards['C']['A'] == 1) suitStopped['C'] = true;
    
//     if(suitCards['S']['K'] == 1 && suitCounter['S'] >= 2) suitStopped['S'] = true;
//     if(suitCards['H']['K'] == 1 && suitCounter['H'] >= 2) suitStopped['H'] = true;
//     if(suitCards['D']['K'] == 1 && suitCounter['D'] >= 2) suitStopped['D'] = true;
//     if(suitCards['C']['K'] == 1 && suitCounter['C'] >= 2) suitStopped['C'] = true;
    
//     if(suitCards['S']['Q'] == 1 && suitCounter['S'] >= 3) suitStopped['S'] = true;
//     if(suitCards['H']['Q'] == 1 && suitCounter['H'] >= 3) suitStopped['H'] = true;
//     if(suitCards['D']['Q'] == 1 && suitCounter['D'] >= 3) suitStopped['D'] = true;
//     if(suitCards['C']['Q'] == 1 && suitCounter['C'] >= 3) suitStopped['C'] = true;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
// 	cin.tie(0);

//     suitCounter['S'] = 0;
//     suitCounter['H'] = 0;
//     suitCounter['D'] = 0;
//     suitCounter['C'] = 0;
    
//     suitCards['S']['K'] = 0;
//     suitCards['S']['Q'] = 0;
//     suitCards['S']['J'] = 0;
//     suitCards['S']['A'] = 0;

//     suitCards['H']['K'] = 0;
//     suitCards['H']['Q'] = 0;
//     suitCards['H']['J'] = 0;
//     suitCards['H']['A'] = 0;
    
//     suitCards['D']['K'] = 0;
//     suitCards['D']['Q'] = 0;
//     suitCards['D']['J'] = 0;
//     suitCards['D']['A'] = 0;
    
//     suitCards['C']['K'] = 0;
//     suitCards['C']['Q'] = 0;
//     suitCards['C']['J'] = 0;
//     suitCards['C']['A'] = 0;

//     suitStopped['S'] = false;
//     suitStopped['H'] = false;
//     suitStopped['D'] = false;
//     suitStopped['C'] = false;

//     while(cin >> card){ 
//         ruleOne(card);
//         for(int i=1; i<13; i++){
//             cin >> card;
//             ruleOne(card);
//         }
//         ruleTwo(card);
//         ruleThree(card);
//         ruleFour(card);
//         //no trump
//         beforeNT = totalPoints;
//         rulesFiveSixSeven();
//         checkStopped();
//         if(beforeNT >= 16 
//             && suitStopped['S'] 
//             && suitStopped['H']
//             && suitStopped['D']
//             && suitStopped['C'])
//             {
//             cout << "BID NO-TRUMP\n";
//             break;
//         }
//         if(totalPoints >= 14){
//             int firstMax = max(suitCounter['S'], suitCounter['H']);
//             int secondMax = max(firstMax, suitCounter['D']);
//             int lastMax = max(secondMax, suitCounter['C']);

//             if(suitCounter['S'] == lastMax) cout << "BID S\n";
//             else if(suitCounter['H'] == lastMax) cout << "BID H\n";
//             else if(suitCounter['D'] == lastMax) cout << "BID D\n";
//             else cout << "BID C\n";
//         } 
//         else cout << "PASS\n";
//     }
//     return 0;
// }