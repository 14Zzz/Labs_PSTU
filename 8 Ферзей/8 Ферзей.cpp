#include <iostream>
using namespace std;
int doska [8][8];

void stawim(int i, int j)
{
	for (int x = 0; x <= 7; x++)
	{
	    int tmp = j - i + x;;
		doska[x][j]++;
		doska[i][x]++;
		if (tmp >= 0 && tmp <= 7)
		{
			doska [x][tmp]++;
		}
		tmp = j + i - x;
		if (tmp >= 0 && tmp <= 7)
		{
			doska[x][tmp]++;
		}
	}
	doska [i][j] = -1;
}

void ybiraem(int i, int j)
{
	for (int x = 0; x <= 7; x++)
	{
	    int tmp = j - i + x;
		doska[x][j]--;
		doska[i][x]--;
		if (tmp >= 0 && tmp <= 7)
		{
			doska[x][tmp]--;
		}
		tmp = j + i - x;
		if (tmp >= 0 && tmp <= 7)
		{
			doska[x][tmp]--;
		}
	}
	doska [i][j] = 0;
}

bool ntQ(int i)
{
	bool Flag = false;
	for (int j = 0; j <= 7; j++)
	{
		if (doska [i][j] == 0)
		{
			stawim(i, j);
			if (i == 7)
			{
				Flag = true;
			}
			else
			{
				if (!(Flag = ntQ(i + 1)))
				{
					ybiraem(i, j);
				}
			}
		}
		if (Flag)
		{
			j = 8;
		}
	}
	return Flag;
}

int main()
{
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			doska [i][j] = 0;
		}
	}
	ntQ(0);
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (doska [i][j] == -1)
			{
				cout << "[Q]";
			}
			else
			{
				cout << " = ";
			}
		}
		cout << endl;
	}
	return 0;
}
