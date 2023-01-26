#include <iostream>
#include <algorithm>
#include <vector>
int n, w, x, y, z;
long long s;
using namespace std;

int lower_bound(vector<int>& arr, int target, int l, int r) {
	int m;
	while (l < r) {
		m = (l + r) / 2;
		if (arr[m] >= target)
			r = m;
		else
			l = m + 1;
	}
	return r;
}

int main()
{
	vector<int> v[4];
	vector<int> b;
	vector<int> c;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &w, &x, &y, &z);
		v[0].push_back(w);
		v[1].push_back(x);
		v[2].push_back(y);
		v[3].push_back(z);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b.push_back(v[0][i] + v[1][j]);
			c.push_back(v[2][i] + v[3][j]);
		}
	}
	sort(c.begin(), c.end());
	c.push_back(1 << 30);
	int q = 0;
	int minr = c.size() - 1;
	for (int i = 0; i < n * n; i++)
	{
		if (c[c.size() - 2] >= -b[i]) {
			int lb = lower_bound(c, -b[i], 0, minr);
			int ub = lower_bound(c, -b[i] + 1, 0, minr);
			s += ub - lb;
		}
	}
	cout << s;
	return 0;
}