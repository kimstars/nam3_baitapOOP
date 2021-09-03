#include <bits/stdc++.h>

using namespace std;

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
                    swap(arr[j], arr[j+1]);
				}
			}
		}
		return 1;
	}
	else
		return -1;
}

void PrintArr(){
    for (size_t i = 1; i <= 4 ; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    khoitao();
    while (sinhhv4()!=-1)
    {
        PrintArr();
      
    }
    

}