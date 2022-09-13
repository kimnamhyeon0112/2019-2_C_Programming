#include <stdio.h>

int gcd(int, int);
int lcm(int, int);
int main()
{
	int n1, n2, min, max, count = 0;
	while (1)
	{
		printf("enter two integers>> ");
		scanf("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0)
			break;
		else
		{
			if (n1 > n2)
				min = n2;
			else
				min = n1;
			printf("prime numbers: ");
			for (int i = 1; i <= min; i++)		//3 4 5 6 7 8 9 10
			{
				for (int j = 1; j <= i; j++)	// 1 2 3 4 5 6 7 8 9 10
				{
					if (count > 2)
						break;
					if (i%j == 0) //3 % 1 == 0, count = 1 4 % 2 ==
						count++;
				}
				if (count == 2)
					printf("%d ", i);
				count = 0;
			}
			printf("\ngcd=%d, lcm=%d\n", gcd(n1, n2), lcm(n1, n2));
		}
	}
}

int gcd(int a, int b)	//24 16
{
	if (b == 0)
		return a;
	else if (a == 0)
		return b;
	return gcd(b, a%b);	//16, 8
}
int lcm(int a, int b)
{
	return (a / gcd(a, b))*b;
}	//응용컴퓨터프로그래밍 중간고사 1번

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("data.txt", "r");
	char line[100];
	while (fgets(line, 100, fp) != NULL)
		printf("%s", line);
	fclose(fp);

}	//응용컴퓨터프로그래밍 중간고사 2번

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n1 = atoi(argv[2]), n2 = atoi(argv[3]);
	int num;
	if (!strcmp(argv[1], "add"))
		printf("%d", n1 + n2);
	int num[100], i = 0, *size;
	while (1)
	{
		printf("Enter the number: ");
		scanf("%d", &num[i]);
		i++;
		if (num[i] == '0')
			break;
	}
	size = (int*)malloc(i * sizeof(int));
	printf("%d", size);
//	printf("%d", num[i]);
	free(size);
}

#include <stdio.h>
#include <stdlib.h>
#define max 100

int stack[max];        // 스택의 긴  통
int top;            // 스택의 상단

void init_stack(void)
{
	top = -1;
}

int push(int t)
{

	if (top >= max - 1)
	{
		printf("\n    stack overflow.");
		return -1;
	}

	stack[++top] = t;
	return t;
}

int pop(void)
{
	if (top < 0)
	{
		printf("Invalid expression\n");
		return -1;
	}
	return stack[top--];
}

void print_stack(void)
{
	int i;
	printf("\n stack contents : top ----> bottom\n");
	for (i = top; i >= 0; i--)
		printf("%-6d", stack[i]);
}

int get_stack_top(void) // 스택의 top의 값을 가져온다.
{
	return (top < 0) ? -1 : stack[top];
}


int is_stack_empty(void) // 스택이 비어있는지 검사
{
	return (top < 0);
}

int is_operator(int k) // k 가 연산자인지 판단한다.
{
	return (k == '+' || k == '-' || k == '*' || k == '/');
}

int is_legal(char *s) // 후위표기법 수식이 적접한가 체크
{
	int f = 0;
	while (*s)
	{
		while (*s == ' ') // 처음 공백 넘어가기
			s++;
		if (is_operator(*s))
			f--;
		else
		{
			f++;
			while (*s != ' ')
				s++;
		}
		if (f < 1)
			break;
		s++;
	}
	return (f == 1);
}

int precedence(int op) // 연산자의 우선순위를 수치로 변환해준다.
{
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	else return 3;
}

void postfix(char *dst, char *src) // 중위표기법을 후위표기법으로 변환
{
	char c;
	init_stack();
	while (*src)
	{
		if (*src == '(')
		{
			push(*src);
			src++;
		}
		else if (*src == ')')
		{
			while (get_stack_top() != '(')
			{
				*dst++ = pop();
				*dst++ = ' ';
			}
			pop();
			src++;
		}
		else if (is_operator(*src))
		{
			while (!is_stack_empty() &&	precedence(get_stack_top()) >= precedence(*src))
			{
				*dst++ = pop();
				*dst++ = ' ';
			}
			push(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{
			do
			{
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			src++;
	}

	while (!is_stack_empty())
	{
		*dst++ = pop();
		*dst++ = ' ';
	}
	dst--;
	*dst = 0;
}

int calc(char *p) // 후위표기법을 계산한다.
{
	int i;
	init_stack();
	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			i = 0;
			do
			{
				i = i * 10 + *p - '0';
				p++;
			} while (*p >= '0' && *p <= '9');
			push(i);
		}
		else if (*p == '+')
		{
			push(pop() + pop());
			p++;
		}
		else if (*p == '*')
		{
			push(pop() * pop());
			p++;
		}
		else if (*p == '-')
		{
			i = pop();
			push(pop() - i);
			p++;
		}
		else if (*p == '/')
		{
			i = pop();
			push(pop() / i);
			p++;
		}
		else
			p++;
	}
	return pop();
}

void main(void)
{
	char Infix[256], Postfix[256];
	int r;
	while (1)
	{
		printf("enter an expression>> ");
		gets_s(Infix, 256);
		if (Infix[0] == '0')
			exit(1);
		else
		{
			postfix(Postfix, Infix);
			r = calc(Postfix);
			printf("%d\n", r);
		}
	}
}	//응용컴퓨터프로그래밍 중간고사 4번

#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	int n, i = 0, j, temp, num;
	int arr[3000];
	fp = fopen(argv[1], "r");
	printf("Integers in %s: ", argv[1]);
	while (fscanf(fp, "%d", &num) != EOF)
	{
		printf("%d ", num);
		arr[i] = num;
		i++;
	}
	n = i;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\nAfter sorting: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	fclose(fp);
	return 0;
}