

// 1-19 ACwing ’“”≤±“

// ∑Ω∑®1:π˛œ£±Ì
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int INF = 10000;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	unordered_set<int> hash;

	int v1 = INF, v2;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d", &a);
		b = m - a;
		if (hash.count(b))
		{
			hash.insert(a);
			if (a>b) swap(a, b);
			if (a < v1) v1 = a, v2 = b;
		}
		else
			hash.insert(a);
	}

	if (v1 == INF) puts("No Solution");
	else printf("%d %d\n", v1, v2);

	return 0;
}

#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int w[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);
	sort(w, w + n);

	for (int i = 0, j = n - 1; i++)
	{
		while (i < j && w[i] + w[j] > m) j--;
		if (i < j && w[i] + w[j] == m)
		{
			printf("%d %d", w[i], w[j]);
			return 0;
		}
	}

	puts("No Solution");
	return 0;
}