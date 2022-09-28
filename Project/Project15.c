#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int element;
typedef struct
{
	element stack[MAX_SIZE];
	int top;
} StackType;

//초기화
void init(StackType *s)
{
	s->top = -1;
}

//스택의 공백상태를 검출하는 함수
int empty(StackType *s)
{
	return (s->top == -1);
}

//스택의 포화상태를 검출하는 함수
int full(StackType *s)
{
	return (s->top == (MAX_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (full(s))
	{
		fprintf(stderr, "stack is full \n");	//오류메세지
		return;
	}
	else s->stack[++(s->top)] = item;
}
element pop(StackType *s)
{
	if (empty(s))
	{
		fprintf(stderr, "stack is empty \n");	//오류메세지
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

element peek(StackType *s)
{
	if (empty(s))
	{
		fprintf(stderr, "stack is empty \n");	//오류메세지
		exit(1);
	}
	else
		return s->stack[s->top];
}

//중위 표기 수식을 후기 표기 수식으로 변환하는 프로그램
int itp(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// infix_to_postfix 함수
char *infix_to_postfix(char *exp)
{
	StackType s;
	char symbol;
	int i = 0, j = 0;
	int length = strlen(exp);
	char *temp = (char*)malloc(sizeof(30));
	init(&s);
	for (i = 0; i < length; i++)
		{
			symbol = exp[i++];
			switch (symbol)
			{
				case '+':
				case '-':
				case '*':
				case '/':
					push(&s,symbol);
					break;
				case ')':
				case ']':
				case '}':
					temp[j] = pop(&s);
					j++;
					break;
				case '(':
				case '[':
				case '{':
					break;
				default:
					temp[j] = symbol;
					j++;
					break;
			}
		}

		// 스택에 남아 있는 것을 temp 에 옮김
			while (!empty(&s))
			{
				temp[j++] = pop(&s);
			}
		return temp;
}

//Postfix 계산 함수
 char eval(char exp[])
{
	int op1, op2, value, i = 0;
	int length = strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for (i = 0; i < length; i++)
		{
			ch = exp[i];
			if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
			{
				value = ch - '0';
				push(&s, value);
			}
			else
			{
				op2 = pop(&s);
				op1 = pop(&s);
				switch (ch)
				{
					case '+': push(&s,op1 + op2); break;
					case '-': push(&s,op1 - op2); break;
					case '*': push(&s,op1 * op2); break;
					case '/': push(&s,op1 / op2); break;
				}
			}
		}
	return pop(&s);
}

int main()
{
	char a[80];
	int result;
	char *temp;
	printf("수식 입력: ");
	scanf("%s", a);
	// 문자열 temp는 a 문자열을 입력하여 postfix 로 변환된것
	temp = infix_to_postfix(a);
	printf("\n%s의 Postfix notation: %s\n", a, temp);
	result = eval(temp);
	printf("\n연산결과: %d\n", result);
	free(temp);
	return 0;
}