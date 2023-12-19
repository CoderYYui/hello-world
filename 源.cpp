#include <iostream>
#include <cstring>
#include <algorithm>
#include<cmath>

using namespace std;

const int N = 10000;

int a[N] , b[N] , c[N] , d[N] , e[N] , f[N] , dei[N] , deii[N] ;
int multre[N]  ;
int n,x;

void add()
{
	bool flag = true;

	for (int i = 0; i < N; i++)
	{
		if(a[i]>0||b[i]>0) { c[i] = a[i] + b[i]; }
		
	}

	for (int i = 0; i < N; i++)
		if (c[i])
		{
			if (!flag && c[i] > 0) cout << " + ";

			cout << c[i] << "x" << "^" << i;
			flag = false;
		}
}

void sub()
{
	bool flag = true;

	for (int i = 0; i < N; i++)
	{
		if (a[i] > 0 || b[i] > 0) { d[i] = a[i] - b[i]; }
	}

	for (int i = 0; i < N; i++)
		if (d[i])
		{
			if (!flag) cout << " + ";

			cout << d[i] << "x" << "^" << i;
			flag = false;
		}
}

void mult()
{
	bool flag = true;

	for (int i = 0; i < N; i++)
	{
		if (a[i])
		{
			int mii = i;
			int xii = a[i];

			for (int i = 0; i < N; i++)
			{
				if (b[i])
				{
					int newmi = mii + i;
					int newxi = xii * b[i];
					multre[newmi] = newxi;
				}
			}

		}

	}

	for (int i = 0; i < N; i++)
		if (multre[i])
		{
			if (!flag) cout << " + ";

			cout << multre[i] << "x" << "^" << i;
			flag = false;
		}
}

void eva()
{
	long long re = 0;
	for (int i = 0; i < N; i++)
	{
		if(a[i])
		{
			re += a[i] * pow(x, i);
		}
	}
	cout << re << endl;
}

void der()
{
	int re = 0;
	bool flag=true;

	for (int i = 0; i < N; i++)
	{
		re = a[i] * i;
		dei[i] = re;
		deii[i] = i - 1;
	}
	
	for (int i = 0; i < N; i++)
		if (dei[i])
		{
			if (!flag) cout << " + ";

			cout << dei[i] << "x" << "^" << deii[i];

			flag = false;

		}

}

int main()
{
	cout << "����������:";
	cin >> n;
	cout << "������aÿһ���ϵ��������:" << endl;
	for (int i = 0; i < n; i++)
	{
		int c, p;
		cin >> c >> p;
		a[p] += c;
	}
	cout << "������bÿһ���ϵ��������:" << endl;
	for (int i = 0; i < n; i++)
	{
		int c, p;
		cin >> c >> p;
		b[p] += c;
	}

	cout << "���������㷽ʽ��";
	string way;
	cin >> way;

	if (way == "add") add();

	if (way == "sub") sub();

	if (way == "mult") mult();

	if (way == "eva") {
							cout << "����������ֵ��";
							cin >> x;
							eva();
						}

	if (way == "der") { der(); }

	return 0;
}