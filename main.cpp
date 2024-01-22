#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int, int> pii;

int n, q, vis[5000];
vector <pii> adj[5000];

int bfs(int k, int v) {
	int ans = 0;
	queue <int> q;
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	vis[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nv = adj[cur][i].first, rel = adj[cur][i].second;
			if (!vis[nv] && rel >= k) {
				vis[nv] = 1;
				q.push(nv);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({ b, c }), adj[b].push_back({ a, c });
	}
	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v;
		cout << bfs(k, v - 1) << endl;
	}
}