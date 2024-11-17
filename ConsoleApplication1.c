#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRINT(array, size)			\
	for(int i = 0; i < size; ++i)	\
		printf("%d ", array[i]);	\
	putchar('\n')

typedef struct LinkList
{
	struct LinkList* pre;
	int data;
	struct LinkList* next;
} LinkList;

LinkList* CreateLink(int count);

void PrintNodeA(LinkList* list);

void PrintNodeD(LinkList* list);

int DeleteNode(LinkList* list, int target);

int DostoryLink(LinkList* list);

LinkList* SearchNode(LinkList* list, int target);

int ZapLink(LinkList* list);

LinkList* GetLastNode(LinkList* list);

LinkList* MergeLinkLists(LinkList* list1, LinkList* list2);

void ReverseLinkList(LinkList* list);

void BSort(int array[], int size, int (*compare)(const void* a, const void* b));

int compare(const void* a, const void* b);

void SSort(int array[], int size, int (*compare)(const void* a, const void* b));

int main()
{
	/*LinkList* i = CreateLink(2);
	LinkList* o = CreateLink(3);
	PrintNodeA(i);
	ReverseLinkList(i);
	PrintNodeA(i);
	PrintNodeD(i->pre);*/
	
	int array[SIZE] = { 5,6,4,3,9,8,7,1,10,2 };
	int size = sizeof(array) / sizeof(array[0]);
	PRINT(array, size);
	SSort(array, size ,compare);
	PRINT(array, size);

	return 0;
}
void SSort(int array[], int size, int (*compare)(const void* a, const void* b))
{
	int i, j, min;
	for (i = 0; i < size; ++i)
	{
		min = i;
		for (j = i + 1; j < size; ++j)
		{
			if (compare(&array[j], &array[min]) < 0)
			{
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void BSort(int array[], int size, int (*compare)(const void* a, const void* b))
{
	int i, j;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (compare(&array[j], &array[j + 1]) > 0)
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int compare(const void* a, const void* b)
{
	return (*(int*)a) - (*(int*)b);
}

void ReverseLinkList(LinkList* head) {
	if (head == NULL || head->next == NULL) {
		return; // 空链表或只有头节点，直接返回
	}

	LinkList* cur = head->next; // 从第一个数据节点开始
	LinkList* temp = NULL;

	while (cur != NULL) {
		// 交换当前节点的 next 和 pre
		temp = cur->next;
		cur->next = cur->pre;
		cur->pre = temp;

		// 向前移动 cur（实际上是向原链表的后一个方向移动）
		cur = cur->pre; // 此时 cur->pre 已经被交换为原来的 next
	}

	// 更新头节点的 next 指针，使其指向新的第一个数据节点
	temp = head->next;
	head->next = temp->pre; // 原尾节点现在是新头节点
	if (head->next != NULL) {
		head->next->pre = head; // 新的第一个数据节点的 pre 指向头节点
	}

	if (temp != NULL) {
		temp->next = NULL;
	}
}

void PrintNodeD(LinkList* list)
{
	if (NULL == list) return;

	LinkList* Cur = list;

	while (NULL != Cur)
	{
		printf("%d\n", Cur->data);
		Cur = Cur->pre;
	}
}

int ZapLink(LinkList* list)
{
	if (NULL == list) return -1;

	LinkList* Cur = list->next;

	LinkList* temp;

	while (NULL != Cur)
	{
		temp = Cur->next;

		free(Cur);

		Cur = temp;
	}
	
	list->next = NULL;

	return 1;
}

LinkList * SearchNode(LinkList* list, int target)
{
	if (NULL == list) return NULL;

	LinkList* Cur = list->next;

	while (NULL != Cur && Cur->data != target)
	{
		Cur = Cur->next;
	}

	return Cur;

}

LinkList* GetLastNode(LinkList* list)
{
	if (NULL == list) return NULL;

	LinkList* Cur = list->next;

	while (NULL != Cur->next) Cur = Cur->next;

	return Cur;
}

LinkList* MergeLinkLists(LinkList* list1, LinkList* list2)
{
	if (NULL == list1 || NULL == list2)	return NULL;

	LinkList* first = GetLastNode(list1);

	LinkList* second = list2->next;

	if (NULL == second) {
		return list1; // 第二个链表没有数据节点，直接返回第一个链表
	}

	free(list2);
	list2 = NULL;

	first->next = second;
	second->pre = first;

	return list1;
}

void PrintNodeA(LinkList* list)
{
	if (NULL == list) return;

	LinkList* Cur = list->next;

	while (NULL != Cur)
	{
		printf("%d\n", Cur->data);
		Cur = Cur->next;
	}
}

int DostoryLink(LinkList* list)
{
	if (NULL == list) return -1;

	LinkList* Cur = list->next;

	LinkList* temp;

	while (NULL != Cur)
	{
		temp = Cur->next;

		free(Cur);

		Cur = temp;
	}

	free(list);

	return 1;
}

LinkList* CreateLink(int count)
{
	if (count <= 0) return NULL;

	LinkList* Link = (LinkList*)malloc(sizeof(LinkList));

	if (NULL == Link) return NULL;

	Link->pre = NULL;
	Link->data = -1;
	Link->next = NULL;

	LinkList* Cur = Link;

	for (int i = 1; i <= count; ++i)
	{
		LinkList* NNode = (LinkList*)malloc(sizeof(LinkList));
		if (NULL == NNode) {
			DostoryLink(Link);
			return NULL;
		}

		NNode->pre = Cur;
		NNode->data = i;
		NNode->next = NULL;

		Cur->next = NNode;
		Cur = NNode;
	}

	Cur->next = NULL;

	return Link;
}

int DeleteNode(LinkList* list, int target)
{
	if (NULL == list) return -1;

	LinkList* Cur = list->next;

	while (NULL != Cur && Cur->data != target)
	{
		Cur = Cur->next;
	}
	
	if (NULL == Cur)
	{
		return -1;
	}
	
	LinkList *before = Cur->pre, *after = Cur->next;

	if (NULL == after)
	{
		before->next = NULL;
	}
	else {
		before->next = after;
		after->pre = before;
	}
	
	free(Cur);

	return 1;
}
