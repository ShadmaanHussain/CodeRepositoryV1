#include<bits/stdc++.h>
using namespace std;

float geo_sum(int);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k;
	cin >> k;
	float ans = geo_sum(k);
	cout << ans;
	return 0;
}

float geo_sum(int k)
{
	if (k == 0)
	{
		return 1.0;
	}

	float sm_ans = geo_sum(k - 1);
	float c_val = pow(0.5, k);
	return c_val + sm_ans;
}


