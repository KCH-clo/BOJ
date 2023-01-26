#include <iostream>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

int N, M, K;

ll arr[1000000];
ll segtree[1 << 21];

ll make_segtree(int node, int left, int right) {
	if (left == right) return segtree[node] = arr[left];
	int mid = (left + right) / 2;
	ll lc = make_segtree(node * 2, left, mid);
	ll rc = make_segtree(node * 2 + 1, mid + 1, right);
	return segtree[node] = lc * rc % MOD;
}

ll update(int node, int left, int right, int idx, ll c) {
	if (left <= idx && idx <= right) {
		if (left == right) {
			return segtree[node] = c;
		}
		else {
			int mid = (left + right) / 2;
			ll lc = update(node * 2, left, mid, idx, c);
			ll rc = update(node * 2 + 1, mid + 1, right, idx, c);
			return segtree[node] = lc * rc % MOD;
		}
	}
	return segtree[node];
}

ll get_mul(int node, int left, int right, int l, int r) {
	if (right < l || r < left) 
		return 1LL;
	if (l <= left && right <= r)
		return segtree[node];
	else {
		int mid = (left + right) / 2;
		ll lc = get_mul(node * 2, left, mid, l, r);
		ll rc = get_mul(node * 2 + 1, mid + 1, right, l, r);
		return lc * rc % MOD;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	make_segtree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1)
			update(1, 0, N - 1, b - 1, c);
		else
			cout << get_mul(1, 0, N - 1, b - 1, c - 1) << '\n';
	}

	return 0;
}