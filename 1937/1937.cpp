#include <iostream>
using namespace std;

int dp[501][501];
int amount[501][501];

int dfs(int x, int y) {
	int& ans = dp[y][x];
	if (ans != 0)
		return ans;
	ans = 0;
	if (amount[x - 1][y] > amount[x][y])
		ans = max(ans, dfs(x - 1, y));
	if (amount[x + 1][y] > amount[x][y])
		ans = max(ans, dfs(x + 1, y));
	if (amount[x][y - 1] > amount[x][y])
		ans = max(ans, dfs(x, y - 1));
	if (amount[x][y + 1] > amount[x][y])
		ans = max(ans, dfs(x, y + 1));
	ans += 1;
	return ans;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			cin >> amount[i][j];
		}
	}
	int ans = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;

	return 0;
}