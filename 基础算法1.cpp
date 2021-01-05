

#if 0
// ���������㷨

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

		// ����[l,r]������Ϊ[l,mid]��[mid+1,r]ʱʹ��
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
			// ����[l,r]������Ϊ[l,mid-1]��[mid,r]ʱʹ��
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

// 2.���ַ����������η���
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
//2.���������

#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> Add(vector<int>& A, vector<int>& B)
{
	vector<int> c;

	int t = 0; //��λ
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
// �߾��ȼ���
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// �ж��Ƿ� A>=B
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())
		return A.size()>B.size();
	// �Ӹ�λ����λ�����ж�
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
	int t = 0; //��λ
	for (int i = 0; i<A.size(); i++)
	{
		t = A[i] - t;
		if (i<B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t<0) t = 1; //������λ
		else t = 0;
	}

	// ȥ��ǰ��0
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
// �߾��ȳ˷�
#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> Mul(vector<int>& A, int& b)
{
	vector<int> C;
	int t = 0; //��λ

	for (int i = 0; i<A.size() || t; i++)
	{
		if (i<A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}

	// ȥ��ǰ��0
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

// �߾��ȳ���

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


// A/b ��ΪC,����Ϊr
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
	//ȥ��ǰ��0
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

	int r; //rΪ����
	auto C = div(A, b, r);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl << r << endl;

	return 0;
}


