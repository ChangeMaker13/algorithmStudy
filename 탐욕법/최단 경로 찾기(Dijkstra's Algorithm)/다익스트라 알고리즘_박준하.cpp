/*
* 2018114686 ������ ���� �� �ҽ� �ڵ带 �ٸ� �ҽ� �ڵ带 �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;

//#define DEBUG
#define FOR(i, n) for(int i = 0; i < n; i++)
const int MAX = 20;
const int INF = 1234567890;

class Edge {
public:
	int s, e, w;

	Edge() {}
	Edge(int _s, int _e, int _w) {
		s = _s; e = _e; w = _w;
	}
};

int n, m;
int W[MAX][MAX];
int touch[MAX];
int length[MAX];
vector<Edge> edges;

void Solve() {
	while (edges.size() < n - 1) {
		//���� ����� ������ ã�´�.
		int min = INF;
		int nearv = 0;
		for (int i = 2; i <= n; i++) {
			if (min > length[i] && length[i] >= 0) {
				min = length[i];
				nearv = i;
			}
		}

		//edge�߰�
		int s = touch[nearv];
		int e = nearv;
		edges.push_back(Edge(s, e, W[s][e]));

		//�� ������ �����ϴ� ��Ʈ�� ������ ��Ʈ�� �� ª�� ������ �������ش�.
		for (int i = 2; i <= n; i++) {
			if (length[nearv] + W[nearv][i] < length[i]) {
				length[i] = length[nearv] + W[nearv][i];
				touch[i] = nearv;
			}
		}
		length[nearv] = -1;

		for (int i = 2; i <= n; i++) {
			printf("%d", touch[i]);
			if (i != n) printf(" ");
		}
		printf("\n");

		for (int i = 2; i <= n; i++) {
			if (length[i] == INF) printf("INF");
			else printf("%d", length[i]);
			if (i != n) printf(" ");
		}
		printf("\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			W[i][j] = INF;
	}
	FOR(i, m) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		W[s][e] = w;
	}

	//�ʱ�ȭ
	for (int i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}

	Solve();
	for (auto it : edges) {
		printf("%d %d %d\n", it.s, it.e, it.w);
	}

	return 0;
}