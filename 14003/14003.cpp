#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[1000001];
int dp[1000001];
int dp_idx[1000001];
int prevt[1000001];
int dp_size = 0;
int last_idx = 0;
vector<int> path;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	memset(prevt, -1, sizeof(prevt));
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(dp, dp + dp_size, arr[i]) - dp;
		dp[idx] = arr[i];
		dp_idx[idx] = i;
		if (idx) {
			prevt[i] = dp_idx[idx - 1];
		}
		if (idx == dp_size) {
			dp_size++;
			last_idx = i;
		}
	}
	for (int i = 0; i < dp_size; i++) {
		path.push_back(arr[last_idx]);
		last_idx = prevt[last_idx];
	}
	cout << dp_size << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	
    return 0;
}