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
#include <queue>
using namespace std;

//#define DEBUG
#define FOR(i, n) for(int i = 0; i < n; i++)

class Node {
public:
	char ch;
	int fre;
	Node* left;
	Node* right;

	Node(char _ch, int _fre, Node* _left, Node* _right) {
		ch = _ch; fre = _fre; left = _left; right = _right;
	}
};
class myGreater {
public:
	bool operator()(Node* a, Node* b) { return a->fre > b->fre; }
};

int n;
priority_queue<Node*, vector<Node*>, myGreater> pq;

Node* Solve() {
	//���� ���� ��� �ΰ��� ������.
	//���ο� ��带 ���� �� ���� ��带 ����, �׳��� ū ��带 �����ʿ� �ִ´�
	//���� ������� ��带 �ٽ� pq�� �ִ´�.
	//pq�� �����ִ� ��尡 1���� �Ǹ� �����.
	while (pq.size() > 1) {
		Node* leftchild = pq.top(); pq.pop();
		Node* rightchild = pq.top(); pq.pop();
		int newfre = leftchild->fre + rightchild->fre;

		Node* newNode = new Node('\0', newfre, leftchild, rightchild);
		pq.push(newNode);
	}

	return pq.top();
}

void printPreorder(Node* root, bool first = true) {
	if (root == nullptr) return;

	if (!first)
		printf(" ");

	if (root->left == nullptr) {
		printf("%c", root->ch);
	}
	else {
		printf("%d", root->fre);
	}
	printPreorder(root->left, false);
	printPreorder(root->right, false);
}

void printInorder(Node* root, bool& first) {
	if (root == nullptr) return;

	printInorder(root->left, first);
	if (root->left == nullptr) {
		if (!first) printf(" ");
		printf("%c", root->ch);
		first = false;

	}
	else {
		if (!first) printf(" ");
		printf("%d", root->fre);
		first = false;
	}
	printInorder(root->right, first);
}

void freeTree(Node* root) {
	if (root == nullptr) return;

	freeTree(root->left);
	freeTree(root->right);
	free(root);
	root = nullptr;
}

int main() {
	cin >> n;
	vector<Node*> nodes;
	FOR(i, n) {
		char ch;
		cin >> ch;
		Node* tmp = new Node(ch, -1, nullptr, nullptr);
		nodes.push_back(tmp);
	}
	FOR(i, n) {
		int tmp;
		cin >> tmp;
		nodes[i]->fre = tmp;
	}

	FOR(i, n) {
		pq.push(nodes[i]);
	}

	Node* root = Solve();

	printPreorder(root);
	printf("\n");
	bool first = true;	//���๮�� ���� issue�� ó���ϱ� ���� ����
	printInorder(root, first);

	freeTree(root);
	
	return 0;
}