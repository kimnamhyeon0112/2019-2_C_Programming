#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char s[100];
	int tot, cnt[26] = { 0 };
	printf("Enter munja:");
	scanf("%s", &s);	//1¹ø
	int len = strlen(s);
	printf("length: %d \n", len);	//2¹ø
	
	for (i = 0; i < len; i++)
	{
		tot = s[i] - 'a';
		cnt[tot]++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%c: %d\n", i + 'a', cnt[i]);
	}
}