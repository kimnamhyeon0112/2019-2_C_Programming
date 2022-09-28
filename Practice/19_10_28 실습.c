#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
#include <string.h>
struct NODE {             // ���� ����Ʈ�� ��� ����ü
	struct NODE* next;    // ���� ����� �ּҸ� ������ ������
	char* data;             // �����͸� ������ ���
};

int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));    // �Ӹ� ��� ����
														// �Ӹ� ���� �����͸� �������� ����

	struct NODE* node1 = malloc(sizeof(struct NODE));   // ù ��° ��� ����
	head->next = node1;                                 // �Ӹ� ��� ������ ù ��° ���
	node1->data = 10;                                   // ù ��° ��忡 10 ����

	struct NODE* node2 = malloc(sizeof(struct NODE));   // �� ��° ��� ����
	node1->next = node2;                                // ù ��° ��� ������ �� ��° ���
	node2->data = 20;                                   // �� ��° ��忡 20 ����

	node2->next = NULL;                                 // �� ��° ��� ������ ��尡 ����(NULL)

	struct NODE* curr = head->next;    // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
	{
		printf("%d\n", curr->data);    // ���� ����� ������ ���
		curr = curr->next;             // �����Ϳ� ���� ����� �ּ� ����
	}

	free(node2);    // ��� �޸� ����
	free(node1);    // ��� �޸� ����
	free(head);     // �Ӹ� ��� �޸� ����

	return 0;
}

//#define _crt_secure_no_warnings    // fopen ���� ���� ���� ������ ���� ����
//#include <stdio.h>     // fopen, fgets, fclose �Լ��� ����� ��� ����

//int main()
//{
//	char buffer[20];    // ������ ���� �� ����� �ӽ� ����
//
//	file* fp = fopen("hello.txt", "r");    // hello.txt ������ �б� ���� ����.  
//										   // ���� �����͸� ��ȯ
//
//	fgets(buffer, sizeof(buffer), fp);    // hello.txt���� ���ڿ��� ����
//
//	printf("%s\n", buffer);    // hello, world!: ������ ���� ���
//
//	fclose(fp);    // ���� ������ �ݱ�
//
//	return 0;
//}

//int main()
//{
//
//	FILE* fp;
//	int index;
//	int data;
//
//	fp = fopen("test.txt", "w");
//
//	for (index = 0; index < 10; index++)
//	{
//		fprintf(fp, "%d\n", index);
//	}
//
//	fclose(fp);
//
//	fp = fopen("test.txt", "r");
//
//	while (fscanf(fp, "%d", &data) != EOF)
//	{
//		printf("%d\n", data);
//	}
//
//	fclose(fp);
//	return 0;
//
//}

//#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
//#include <stdio.h>
//#include <string.h>    // strtok �Լ��� ����� ��� ����

//int main()
//{
//	char s1[30] = "the little prince";  // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�
//	//(strtok, " "): 1��° ���ڿ� �迭
//	//2��° : ������
//	char* ptr = strtok(s1, " ");      // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
//
//	while (ptr != null)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
//	{
//		printf("%s\n", ptr);          // �ڸ� ���ڿ� ���
//		ptr = strtok(null, " ");      // ���� ���ڿ��� �߶� �����͸� ��ȯ
//	}
//
//	return 0;
//}										//strtok.c