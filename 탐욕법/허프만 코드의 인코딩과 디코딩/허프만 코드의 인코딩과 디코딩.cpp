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
#include <map>
#include <string>
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
map<char, string> encoInfo;	//character�� ���� ���ڵ���� ����

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

void cacheEncoding(Node* root, string code) {
	if (root->left == nullptr) {
		encoInfo.insert(pair<char, string>(root->ch, code));
		return;
	}

	code.push_back('0');
	cacheEncoding(root->left, code);

	code.pop_back();
	code.push_back('1');
	cacheEncoding(root->right, code);
}

void Encoding(Node* root, vector<char> str) {
	for (int i = 0; i < str.size(); i++) {
		string code = encoInfo[str[i]];

		for (int j = 0; j < code.size(); j++) {
			if (i + 1 == str.size() && j + 1 == code.size()) {
				printf("%c", code[j]);
			}
			else {
				printf("%c ", code[j]);
			}
		}
	}
	printf("\n");
}

void Decoding(Node* root, vector<int> num) {
	Node* cur = root;

	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 0) cur = cur->left;
		else cur = cur->right;

		if (cur->left == nullptr) {
			if(i+1 == num.size())
				printf("%c", cur->ch);
			else
				printf("%c ", cur->ch);
			cur = root;
		}
	}
	printf("\n");
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

	cacheEncoding(root, string());

	int probNum;
	int k;
	vector<char> str;
	cin >> probNum;
	FOR(i, probNum) {
		str.clear();
		cin >> k;
		FOR(j, k) {
			char tmp;
			cin >> tmp;
			str.push_back(tmp);
		}
		Encoding(root, str);
	}

	vector<int> code;
	cin >> probNum;
	FOR(i, probNum) {
		code.clear();
		cin >> k;
		FOR(j, k) {
			int tmp;
			cin >> tmp;
			code.push_back(tmp);
		}
		Decoding(root, code);
	}

	freeTree(root);
	
	return 0;
}