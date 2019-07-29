using namespace std;
#include <iostream> 
#include <string>
#include <vector>

void sortedMerge(vector<int> A, vector<int> B, int Asize, int Bsize){
    int indexMerged = Asize + Bsize -1;
    int indexA = Asize -1;
    int indexB = Bsize -1;

    while(indexB >= 0){
        if(indexA >= 0 && A[indexA] > B[indexB]){
            A[indexMerged] = A[indexA];
            indexA--;
        }else{
            A[indexMerged] = B[indexB];
            indexB--;
        }
        indexMerged--;
    }
}