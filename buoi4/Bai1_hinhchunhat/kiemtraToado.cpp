#include <bits/stdc++.h>

using namespace std;

struct data
{
	int x;
	int y;
} typedef data;

int arr[10];
void khoitao()
{
	for (int i = 1; i <= 4; i++)
	{
		arr[i] = i;
	}
}

int sinhhv4()
{
	int vt = -1;
	for (int i = 4; i > 1; i--)
	{
		if (arr[i] > arr[i - 1])
		{
			vt = i - 1;
			break;
		}
	}
	if (vt != -1)
	{
		for (int i = 4; i >= 1; i--)
		{
			if (arr[i] > arr[vt])
			{
				int tg = arr[vt];
				arr[vt] = arr[i];
				arr[i] = tg;
				break;
			}
		}
		for (int i = vt + 1; i <= 4; i++)
		{
			for (int j = vt + 1; j < 4; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int tg = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = tg;
				}
			}
		}
		return 1;
	}
	else
		return -1;
}

int main()
{
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++)
	{
		data toado[5];
		for (int i = 1; i <= 4; i++)
		{
			cin >> toado[i].x >> toado[i].y;
		}
		khoitao();
		data dinh[5];
		int kt = 0;
		while (1)
		{
			for (int i = 1; i <= 4; i++)
			{
				dinh[i].x = toado[arr[i]].x;
				dinh[i].y = toado[arr[i]].y;
			}
			if ((dinh[1].x == dinh[4].x && dinh[1].y != dinh[4].y) && (dinh[2].x == dinh[3].x && dinh[2].y != dinh[3].y) && (dinh[1].y == dinh[2].y && dinh[1].x != dinh[2].x) && (dinh[4].y == dinh[3].y && dinh[4].x != dinh[3].x))
			{
				kt = 1;
				break;
			}
			if (sinhhv4() == -1)
				break;
		}
		
		if (kt == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}