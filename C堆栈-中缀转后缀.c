#include<stdio.h>

char a[100],stack[100];

//检测
int exam(char x[])
{
	/*	a用于判断()是否相同    */
	int a = 0, mistake = 0, k = 0;

	/*	排除除数字'+' '*' '-' '/' '(' ')' 以外字符	*/
	if (x[k] > 57 || x[k] < 40 || x[k] == 44 || x[k] == 46) {
		mistake = 1;
	}
	/*	第一位为运算符或空时报错	*/
	if (x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/' || x[0] == '\0') {
		mistake = 1;
	}
	if (mistake == 0) {
		while (x[k] != '\0')
		{
			/*	排除除数字'+' '*' '-' '/' '(' ')' 以外字符	*/
			if (x[k] > 57 || x[k] < 40 || x[k] == 44 || x[k] == 46) {
				mistake = 1;
				break;
			}
			/*	第一位为运算符时报错	*/
			if (x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/')
			{
				mistake = 1;
				break;
			}

			if (x[k] == '(') a += 1;
			/*	')'后必为运算符或')'或结束	*/
			if (x[k] == ')')
			{
				a -= 1;
				if (x[k + 1] != '+' && x[k + 1] != '-' && x[k + 1] != '*' && x[k + 1] != '/' && x[k + 1] != ')' && x[k + 1] != '\0')
				{
					mistake = 1;
					break;
				}
			}
			/*	排除')'出现在'('前	*/
			if (a < 0)
			{
				mistake = 1;
				break;
			}
			/*	排除运算符或'('后为运算符或')'	*/
			if (x[k] == '+' || x[k] == '-' || x[k] == '*' || x[k] == '/' || x[k] == '(')
			{
				if (x[k + 1] == '+' || x[k + 1] == '-' || x[k + 1] == '*' || x[k + 1] == '/' || x[k + 1] == ')')
				{
					mistake = 1;
					break;
				}
			}
			k += 1;
		}
	}
	/*	排除最后一位为运算符	*/
	if (x[k-1] == '+' || x[k-1] == '-' || x[k-1] == '*' || x[k-1] == '/')
	{
		mistake = 1;
	}
	/*排除'(' ')'不相等*/
	if (a != 0) mistake = 1;
	/*报错退出*/
	if (mistake == 1)
	{
		printf("error");
		exit();
	}
}



int main()
{
	printf("请输入中缀表达式: ");
	gets(a);
	exam(a);
	int i = 0, j = 0;
	printf("后缀表达式为:");

	while (a[i] != '\0')
	{
		/*	字符为数字则打印	*/
		if (a[i] >= 48 && a[i] <= 57)
		{
		printf("%c", a[i]);
		}
		else
		{
			/* 栈空或为'('直接入栈 */
			if (j == 0 || a[i] == '(')
			{
				stack[j] = a[i];
				j += 1;
			}
			else
			{
				/*	为'*' '/'时弹出站内'*' '/'	*/
				if (a[i] == '*' || a[i] == '/')
				{
					while (j >= 0)
					{
						if (stack[j-1] == '*' || stack[j-1] == '/')
						{
							j -= 1;
							printf("%c ", stack[j]);
							stack[j] = '\0';
						}
						else break;
					}
					stack[j] = a[i];
					j += 1;
				}
				/*	为'+' '-'弹出'*' '/' '+' '-'	*/
				if (a[i] == '+' || a[i] == '-')
				{
					while (j > 0)
					{
						if (stack[j-1] == '*' || stack[j-1] == '/' || stack[j-1] == '+' || stack[j-1] == '-')
						{
							j -= 1;
							printf("%c ", stack[j]);
							stack[j] = '\0';
						}
						else break;
					}
					stack[j] = a[i];
					j += 1;
				}
				/*	为')'弹出'('前所有字符，'(' ')'不打印	*/
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
		/*	分割字符	*/
		if (!((a[i + 1] > 47 && a[i + 1] < 58)||a[i+1]==40)) printf(" ");
		i += 1;
	}
	/*	弹出栈中剩余元素	*/
	for (j=j-1; j >= 0; j--)
	{
		printf("%c", stack[j]);
		if (j == 0) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}
}
