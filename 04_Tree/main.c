#include <stdio.h>
#include "binarytree.h"

void test_free(void)
{

}

void test_bt(void)
{
	BinaryTree* a1 = bt_create(1);
	BinaryTree* a2 = bt_create(2);
	BinaryTree* a3 = bt_create(3);
	BinaryTree* a4 = bt_create(4);
	BinaryTree* a5 = bt_create(5);
	BinaryTree* a6 = bt_create(6);
	BinaryTree* a7 = bt_create(7);
	if (bt_is_empty(a1) == true)
		printf("SUCCESS:isEmpty()\n");

	a1 = bt_make(a1, a2, a3);
	a2 = bt_make(a2, a4, a5);
	a3 = bt_make(a3, a6, a7);
	if (bt_is_empty(a1) == false)
		printf("SUCCESS:isEmpty()\n");
	if (bt_is_empty(a2) == false)
		printf("SUCCESS:isEmpty()\n");
	if (bt_is_empty(a3) == false)
		printf("SUCCESS:isEmpty()\n");

	printf("PreOrder:\n");
	bt_print_preorder(a1);
	printf("\n");
	printf("PostOrder:\n");
	bt_print_postorder(a1);
	printf("\n");
	printf("InOrder:\n");
	bt_print_inorder(a1);
	printf("\n");
}


int main(void)
{
	test_free();
	test_bt();

	return 0;
}