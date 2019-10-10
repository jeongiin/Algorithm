#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std; //merge 함수를 사용하기 위해서 필요함

int A[1000000], B[1000000], R[2000000];


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int asize, bsize;
	cin >> asize >> bsize;
	for (int i = 0; i < asize; i++) cin >> A[i];
	for (int i = 0; i < bsize; i++) cin >> B[i];

	merge(A, A + asize, B, B + bsize, R);


	for (int i = 0; i < (asize+bsize) ; i++)
		cout << R[i] << ' ';
	


	return 0;
}