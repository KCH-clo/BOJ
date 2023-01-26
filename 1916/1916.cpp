#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987987987
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> pq;
vector<pii> adj[1001];
int N, M, S, E;
int dist[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < 1001; i++) dist[i] = INF;

	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		adj[s].push_back({ e, c });
	}
	cin >> S >> E;

	dist[S] = 0;
	pq.push({ 0, S });
	while (!pq.empty()) {
		int v = pq.top().second;
		int c = -pq.top().first;
		pq.pop();

		if (dist[v] < c) continue;

		for (pii next : adj[v]) {
			int nv = next.first;
			int nc = next.second;
			if (dist[v] + nc < dist[nv]) {
				dist[nv] = dist[v] + nc;
				pq.push({ -dist[nv], nv });
			}
		}
	}

	cout << dist[E] << "\n";

	return 0;
}