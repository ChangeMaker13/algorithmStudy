/*
* 2018114686 ������ ���� �� �ҽ� �ڵ带 �ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

//#define DEBUG
#define FOR(i, n) for(int i = 0; i < n; i++)
const int MAX = 55000;
const int MOD = 100000000;

int T;
int n, k;
int B[MAX];
int row = 0;

//row-1 �� B�� �̿��Ͽ� row�� ���.
void Calc_nextrow() {
	row += 1;

	int tmp = B[0];
	for (int i = 1; i < row + 1; i++) {
		int here = B[i];
		B[i] = (tmp + here) % MOD;
		tmp = here;
	}

#ifdef DEBUG
	printf("row : %d\n", row);
	FOR(i, row + 1) {
		printf("%d ", B[i]);
	}
	cout << endl;
#endif // DEBUG
}

//���� n, k�� �ش��ϴ� ���װ�� ���� ����
int Solve() {
	//�������
	if (k == 0 || n == k) return 1;

	while (row < n) Calc_nextrow();
	return B[k];
}

int main() {
	//�Է� �� �ʱ�ȭ
	cin >> T;
	memset(B, 0, sizeof(B));
	B[0] = 1;

	FOR(t, T) {
		cin >> n >> k;
		cout << Solve() << endl;
	}

	return 0;
}