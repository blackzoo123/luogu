#include <iostream>
#include <cstdio>
#include <cstring>
#define N 85
using namespace std;

int main()
{
	int i, j, n, len, q;
	char s[N];
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		len = strlen(s);
		for (i = 1; i <= len; i++)
		{
			if (len%i == 0)
			{
				for (j = i; j <= len; j++)
				{
					if (s[j] != s[j%i])
						break;
				}
				if (j == len)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
		if (n)
			printf("\n");
	}
	return 0;
}
