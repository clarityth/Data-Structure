#include <stdio.h>
#include <string.h>
#include "dll_address.h"

// main.c �ҽ��� �������� �ʰ� ��� Ȯ�ο����θ� ����մϴ�.
// �򰡽ÿ��� �Է� ���̳� Ƚ���� ����˴ϴ�.

// �����Ӱ� �Լ� �׽�Ʈ �ϴ� �����Դϴ�.
void test_free(void)
{

}

void test_list(void)
{
	DoublyLinkedList test_list;
	bool bool_result = true; 
	int int_result = 0;

	printf("1\n");
	list_init(&test_list);
	printf("2\n");
	bool_result = is_empty_list(&test_list);
	printf("3\n");
	
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	bool_result = is_full_list(&test_list);
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	char name[NAME_ARRAY_SIZE] = "";
	int id = 0;

	// insert_head
	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220001;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "���ο�");
	id = 20220002;
	insert_head(&test_list, name, id);
	
	strcpy_s(name, NAME_ARRAY_SIZE, "�����");
	id = 20220003;
	insert_head(&test_list, name, id);
	
	strcpy_s(name, NAME_ARRAY_SIZE, "�����");
	id = 20220004;
	insert_head(&test_list, name, id);
	
	strcpy_s(name, NAME_ARRAY_SIZE, "�����");
	id = 20220005;
	insert_head(&test_list, name, id);
	
	strcpy_s(name, NAME_ARRAY_SIZE, "��������");
	id = 20220006;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220007;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "�ϼ���");
	id = 20220008;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "�ϸ���");
	id = 20220009;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220010;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "�������");
	id = 20220011;
	insert_head(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220012;
	insert_head(&test_list, name, id);
	// insert_tail
	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220013;
	insert_tail(&test_list, name, id);
	
	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220014;
	insert_tail(&test_list, name, id);
	
	bool_result = is_full_list(&test_list);
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220015;
	insert_tail(&test_list, name, id);

  bool_result = is_full_list(&test_list);
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	strcpy_s(name, NAME_ARRAY_SIZE, "������");
	id = 20220016;
	insert_tail(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "���ٿ�");
	id = 20220017;
	insert_tail(&test_list, name, id);

	strcpy_s(name, NAME_ARRAY_SIZE, "�̸̹�");
	id = 20220018;
	insert_tail(&test_list, name, id);
	print_list(&test_list);

	bool_result = is_full_list(&test_list);
	if (bool_result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	
	search_name(&test_list, 20220014);
	search_id(&test_list, "������");
	search_id(&test_list, "������");

	if (is_empty_list(&test_list) == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");

	for(int i=0; i<MAX_ADDRESS_SIZE/2 + 1; i++){
		delete_head(&test_list);
		delete_tail(&test_list);
		print_list(&test_list);
	}

	if (is_empty_list(&test_list) == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");
}

int main(void)
{
	test_free();
	test_list();

	return 0;
}