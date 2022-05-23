#include "binarytree.h"
#include <stdlib.h>

BinaryTree* bt_create(int data)
{
  BinaryTree *new = (BinaryTree *)malloc(sizeof(BinaryTree));
  new->data = data;
  new->lchild = NULL;
  new->rchild = NULL;
  return new;
}

bool bt_is_empty(BinaryTree* bt)
{
  if (bt->lchild == NULL && bt->rchild == NULL)
    return true;
  else
    return false;
}

BinaryTree* bt_make(BinaryTree* root, BinaryTree* bt1, BinaryTree* bt2)
{
  /*
   * bt1, bt2가 다른 트리의 서브트리인지 고려하려면, BinaryTree 구조체에 parent를 추가한다.
   */
 
  if (root){
    if (bt1)
      root->lchild = bt1;
    if (bt2)
      root->rchild = bt2;
    return root;
  }
  // 예외처리
  else {
    printf("NULL Pointer Exception");
    return NULL;
  }
}

void bt_print_preorder(BinaryTree* bt)
{
  if (bt){
    printf("%d->", bt->data);
    if (bt->lchild)
      bt_print_preorder(bt->lchild);
    if (bt->rchild)
      bt_print_preorder(bt->rchild);
  }
  // 예외처리
  else {
    printf("NULL Pointer Exception");
    return;
  }
}

void bt_print_postorder(BinaryTree* bt)
{
  if (bt){
    if (bt->lchild)
      bt_print_postorder(bt->lchild);
    if (bt->rchild)
      bt_print_postorder(bt->rchild);
    printf("%d->", bt->data);
  }
  // 예외처리
  else {
    printf("NULL Pointer Exception");
    return;
  }
}

void bt_print_inorder(BinaryTree* bt)
{
  if (bt){
    if (bt->lchild)
      bt_print_inorder(bt->lchild);
    printf("%d->", bt->data);
    if (bt->rchild)
      bt_print_inorder(bt->rchild);
  }
  // 예외처리
  else {
    printf("NULL Pointer Exception");
    return;
  }
}