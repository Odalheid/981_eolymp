#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int subtree[100];
int ranks[100];
vector <pair<int, pair<int, int>>> v;

int get(const int &n) {
	if (n == subtree[n]) return n;
	return subtree[n] = get(subtree[n]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		if (ranks[a] < ranks[b]) {
			swap(a, b);
		}
		subtree[b] = a;
		if (ranks[a] == ranks[b]) {
			++ranks[a];
		}
	}
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	v.resize(edges);
	for (int i = 0; i < edges; ++i) {
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
	}
	int weight = 0;
	for (int i = 0; i < vertices; ++i) {
		subtree[i] = i;
		ranks[i] = 0;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < edges; ++i) {
		if (get(v[i].second.first - 1) != get(v[i].second.second - 1)) {
			weight += v[i].first;
			unite(v[i].second.first - 1, v[i].second.second - 1);
		}
	}
	cout << weight;
    return 0;
}