#include <iostream>
using namespace std;
class STree
{
private:
	long long int* arr;
	long long int size;
	long long int* in;
	long long int GCD(long long int, long long int);
	long long int FUN(long long int, long long int);
public:
	STree(long long int);
	void insert(long long int, long int, long int);
	void Result1(long long int);
	long long int Index(long long int);
	void Update(long long int);
	void insert1(long int, long long int);
	long long int Root();
};
STree::STree(long long int s)
{
	size = 2 * s;
	arr = new long long int[size];
	for (long long int i = 0; i < size; i++)
		arr[i] = -1;
	in = new long long int[s + 1];
	for (long long int i = 0; i < s + 1; i++)
	{
		in[i] = -1;
	}
}
void STree::insert(long long int x, long int i, long int index)
{
	arr[i] = x;
	in[index] = i;
}
void STree::Result1(long long int s)
{
	if (arr[(s * 2)] != -1 && arr[(s * 2 + 1)] != -1)
	{
		arr[s] = GCD(arr[s * 2], arr[s * 2 + 1]);
		if (arr[s] == 1)
			arr[s] = FUN(arr[s * 2], arr[s * 2 + 1]);
		return;
	}
	if (arr[s * 2] == -1)
		Result1(s * 2);
	if (arr[s * 2 + 1] == -1)
		Result1(s * 2 + 1);
	if (arr[s] == -1)
	{
		arr[s] = GCD(arr[s * 2], arr[s * 2 + 1]);
		if (arr[s] == 1)
			arr[s] = FUN(arr[s * 2], arr[s * 2 + 1]);
	}
}
long long int STree::GCD(long long int x1, long long int x2)
{
	if (x1 == 0)
		return x2;
	else
		return GCD(x2 % x1, x1);
}
long long int STree::Index(long long int i)
{
	return in[i];
}
void STree::Update(long long int s)
{
	if (s == 1)
	{
		arr[s] = GCD(arr[s * 2], arr[s * 2 + 1]);
		if (arr[s] == 1)
			arr[s] = FUN(arr[s * 2], arr[s * 2 + 1]);
		return;
	}
	else
	{
		arr[s] = GCD(arr[s * 2], arr[s * 2 + 1]);
		if (arr[s] == 1)
			arr[s] = FUN(arr[s * 2], arr[s * 2 + 1]);
	}
	Update((s) / 2);
}
void STree::insert1(long int i, long long int x)
{
	arr[i] = x;
}
long long int STree::FUN(long long int x1, long long int x2)
{
	return x1 ^ x2;
}
long long int STree::Root()
{
	return arr[1];
}
int main()
{
	long long int s;
	cin >> s;
		STree ob(s);
		long int c = s;
		long long int x;
		for (long int i = 1; i <= s; i++)
		{
			cin >> x;
			ob.insert(x, c, i);
			c++;
		}
		ob.Result1(1);
		long long int x1 = ob.Root();
		long int u;
		cin >> u;
		if (u > 0)
		{
			long long int* U;
			U = new long long int[u];
			long int tail = 0;
			long long int y;
			long long int in;
			for (long int i = 0; i < u; i++)
			{
				cin >> in >> y;
				if (in <= s && in >= 1)
				{
					ob.insert1(ob.Index(in), y);
					ob.Update((ob.Index(in)) / 2);
					U[tail] = ob.Root();
					tail++;
				}
			}
			cout << x1 << endl;
			for (long int i = 0; i < tail; i++)
				cout << U[i] << endl;
		}
		else
			cout << x1 << endl;
	return 0;
}
