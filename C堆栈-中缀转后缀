#include<stdio.h>

char a[10000],stack[10000];
int exam(char x[])
{
	int a = 0, mistake = 0, k = 0;
	while (x[k] != '\0')
	{
		if (x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/')
		{
			mistake = 1;
			break;
		}
		if (x[k] == '(') a += 1;
		if (x[k] == ')')
		{
			a -= 1;
			if (x[k+1] != '+' && x[k+1] != '-' && x[k+1] != '*' && x[k+1] != '/' && x[k + 1] != ')')
			{
				mistake = 1;
				break;
			}
		}
		if (a < 0)
		{
			mistake = 1;
			break;
		}
		if (x[k] == '+' || x[k] == '-' || x[k] == '*' || x[k] == '/' || x[k] == '(')
		{
			if (x[k + 1] == '+' || x[k + 1] == '-' || x[k + 1] == '*' || x[k + 1] == '/' || x[k+1] == ')')
			{
				mistake = 1;
				break;
			}
		}
		k += 1;
	}
	if (x[k-1] == '+' || x[k-1] == '-' || x[k-1] == '*' || x[k-1] == '/')
	{
		mistake = 1;
	}
	if (a != 0) mistake = 1;
	if (mistake == 1)
	{
		printf("error");
		exit();
	}
}



int main()
{
	gets(a);
	exam(a);
	int i = 0, j = 0;
	while (a[i] != '\0')
	{
		if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9')
		{
		printf("%c", a[i]);
		}
		else
		{
			if (j == 0 || a[i] == '(')
			{
				stack[j] = a[i];
				j += 1;
			}
			else
			{
				if (a[i] == '*' || a[i] == '/')
				{
					while (j >= 0)
					{
						if (stack[j-1] == '*' || stack[j-1] == '/')
						{
							j -= 1;
							printf("%c", stack[j]);
							stack[j] = '\0';
						}
						else break;
					}
					stack[j] = a[i];
					j += 1;
				}
				if (a[i] == '+' || a[i] == '-')
				{
					while (j > 0)
					{
						if (stack[j-1] == '*' || stack[j-1] == '/' || stack[j-1] == '+' || stack[j-1] == '-')
						{
							j -= 1;
							printf("%c", stack[j]);
							stack[j] = '\0';
						}
						else break;
					}
					stack[j] = a[i];
					j += 1;
				}
				if (a[i] == ')')
				{
					while (stack[j-1] != '(')
					{
						j -= 1;
						printf("%c", stack[j]);
						stack[j] = '\0';
					}
					j -= 1;
					stack[j] = '\0';
				}
			}
		}
		i += 1;
	}
	for (j=j-1; j >= 0; j--)
	{
		printf("%c", stack[j]);
	}
}
