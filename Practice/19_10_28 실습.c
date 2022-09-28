#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <string.h>
struct NODE {             // 연결 리스트의 노드 구조체
	struct NODE* next;    // 다음 노드의 주소를 저장할 포인터
	char* data;             // 데이터를 저장할 멤버
};

int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));    // 머리 노드 생성
														// 머리 노드는 데이터를 저장하지 않음

	struct NODE* node1 = malloc(sizeof(struct NODE));   // 첫 번째 노드 생성
	head->next = node1;                                 // 머리 노드 다음은 첫 번째 노드
	node1->data = 10;                                   // 첫 번째 노드에 10 저장

	struct NODE* node2 = malloc(sizeof(struct NODE));   // 두 번째 노드 생성
	node1->next = node2;                                // 첫 번째 노드 다음은 두 번째 노드
	node2->data = 20;                                   // 두 번째 노드에 20 저장

	node2->next = NULL;                                 // 두 번째 노드 다음은 노드가 없음(NULL)

	struct NODE* curr = head->next;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", curr->data);    // 현재 노드의 데이터 출력
		curr = curr->next;             // 포인터에 다음 노드의 주소 저장
	}

	free(node2);    // 노드 메모리 해제
	free(node1);    // 노드 메모리 해제
	free(head);     // 머리 노드 메모리 해제

	return 0;
}

//#define _crt_secure_no_warnings    // fopen 보안 경고로 인한 컴파일 에러 방지
//#include <stdio.h>     // fopen, fgets, fclose 함수가 선언된 헤더 파일

//int main()
//{
//	char buffer[20];    // 파일을 읽을 때 사용할 임시 공간
//
//	file* fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드로 열기.  
//										   // 파일 포인터를 반환
//
//	fgets(buffer, sizeof(buffer), fp);    // hello.txt에서 문자열을 읽음
//
//	printf("%s\n", buffer);    // hello, world!: 파일의 내용 출력
//
//	fclose(fp);    // 파일 포인터 닫기
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

//#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
//#include <stdio.h>
//#include <string.h>    // strtok 함수가 선언된 헤더 파일

//int main()
//{
//	char s1[30] = "the little prince";  // 크기가 30인 char형 배열을 선언하고 문자열 할당
//	//(strtok, " "): 1번째 문자열 배열
//	//2번째 : 구분자
//	char* ptr = strtok(s1, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
//
//	while (ptr != null)               // 자른 문자열이 나오지 않을 때까지 반복
//	{
//		printf("%s\n", ptr);          // 자른 문자열 출력
//		ptr = strtok(null, " ");      // 다음 문자열을 잘라서 포인터를 반환
//	}
//
//	return 0;
//}										//strtok.c