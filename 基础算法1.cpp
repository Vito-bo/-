

#if 0
// 整数二分算法

#include <iostream>
using namespace std;

const int N = 100010;
int n, m, k;
int q[N];

int main()
{
	cin >> n >> m;

	for (int i = 0; i<n; i++)
		cin >> q[i];
	while (m--)
	{
		cin >> k;

		int l = 0, r = n - 1;

		// 区间[l,r]被划分为[l,mid]和[mid+1,r]时使用
		while (l<r)
		{
			int mid = l + r >> 1;
			if (q[mid] >= k) r = mid;
			else l = mid + 1;
		}

		if (q[l] != k) cout << "-1 -1" << endl;
		else
		{
			cout << l << " ";
			int l = 0, r = n - 1;
			// 区间[l,r]被划分为[l,mid-1]和[mid,r]时使用
			while (l<r)
			{
				int mid = l + r + 1 >> 1;
				if (q[mid] <= k) l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}
	}

}

// 2.二分法求数的三次方跟
int main()
{
	double x;
	cin >> x;

	double l=-10000,r=10000;
	while(r-l>1e-8)
	{
		double mid=(l+r)/2;
		if(mid*mid*mid >=x) r=mid;
		else l=mid;
	}
	printf("%lf\n",l);
	return 0;
}

#endif


#if 0
//2.大整数相加

#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> Add(vector<int>& A, vector<int>& B)
{
	vector<int> c;

	int t = 0; //进位
	for (int i = 0; i<A.size() || i<B.size(); i++)
	{
		if (i<A.size()) t += A[i];
		if (i<B.size()) t += B[i];
		c.push_back(t % 10);
		t /= 10;
	}

	if (t) c.push_back(1);
	return c;
}

int main()
{
	string a, b;
	vector<int> A, B;

	cin >> a >> b;  // a=12345
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); // A={5,4,3,2,1}
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	auto c = Add(A, B);
	for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);

	return 0;
}

#endif

#if 0
// 高精度减法
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 判断是否 A>=B
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())
		return A.size()>B.size();
	// 从高位到低位依次判断
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] != B[i])
			return A[i]>B[i];
	}
	return true;
}

vector<int> Sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;
	int t = 0; //借位
	for (int i = 0; i<A.size(); i++)
	{
		t = A[i] - t;
		if (i<B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t<0) t = 1; //发生借位
		else t = 0;
	}

	// 去掉前导0
	while (C.size()>1 && C.back() == 0) C.pop_back();

	return C;
}

int main()
{
	string a, b;
	cin >> a >> b;

	vector<int> A, B;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');


	if (cmp(A, B))
	{
		auto C = Sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	}
	else
	{
		auto C = Sub(B, A);
		cout << "-";
		for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	}

	return 0;
}
#endif 

#if 0
// 高精度乘法
#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> Mul(vector<int>& A, int& b)
{
	vector<int> C;
	int t = 0; //进位

	for (int i = 0; i<A.size() || t; i++)
	{
		if (i<A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	// 去掉前导0
	while (C.size()>1 && C.back() == 0) C.pop_back();
	return C;
}

int main()
{
	string a;
	cin >> a;
	int b;
	cin >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	auto C = Mul(A, b);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

	return 0;
}
#endif

// 高精度除法

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


// A/b 商为C,余数为r
vector<int> div(vector<int>& A, int b, int& r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}

	reverse(C.begin(), C.end());
	//去除前导0
	while (C.size()>1 && C.back() == 0) C.pop_back();

	return C;
}

int main()
{
	string a;
	int b;
	cin >> a >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

	int r; //r为余数
	auto C = div(A, b, r);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl << r << endl;

	return 0;
}


