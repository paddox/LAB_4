// techimet4.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "malloc.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <locale.h>

/** @struct tree
@brief ��������� ������
@var info ������.
@var left ��������� �� ������ ����.
@var right ��������� �� ������� ����.
 **/
struct tree {
  char info;
  struct tree *left;
  struct tree *right;
  };

/**
@function stree
@brief ���������� ������ ��������
@param root �������� �������
@param r ����� �������
@param info ������
@return root �������� ������� � ���������� �� �����**/
tree *stree(
  tree *root,
  tree *r,
  char info
  )
{
  if(!r)/**�������� ������� ����. � ������ ��� ���������� ��������� �����,
		� ��������� ������ ��������� ���������� ���� � ������������ � ��������
		� ��������� ������ �������� �� ���� �������� **/ {
    r = new tree;
    if(!r) {
      printf("�� ������� ������\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!root)
		{

			return r;}/* ������ ���� */
    if(info < root->info)
		{
			root->left = r;

	}

    else
		{
			root->right = r;

	}
	return r;
  }
  if(info < r->info)
    stree(r,r->left,info);
  else
    stree(r,r->right,info);

  return root;
}

/**
@function inorder
@brief �������������� �����
@param root ������
@return ������� ���������� ������ ��������**/
void inorder(struct tree *root)
{
  if(!root) return;

  inorder(root->left);
  if(root->info) printf("%c ", root->info);
  inorder(root->right);
}


/**
@function preorder
@brief ������ �����
@param root ������
@return ������� ���������� ������ ��������**/
void preorder(struct tree *root)
{
  if(!root) return;

  if(root->info) printf("%c ", root->info);
  preorder(root->left);
  preorder(root->right);
}


/**
@function postorder
@brief �������� �����
@param root ������
@return ������� ���������� ������ ��������**/
void postorder(struct tree *root)
{
  if(!root) return;

  postorder(root->left);
  postorder(root->right);
  if(root->info) printf("%c ", root->info);
}






int main()
{
	setlocale( LC_CTYPE, ".1251" );
	char s[80];
	tree* root;

	root = NULL;  /* ������������� ����� ������ */

	do {
    printf("������� �����: ");
    gets(s);
    root = stree(root, root, *s);
  } while(*s);

	std::cout << "������������ �����";
	inorder(root);
	std::cout << std::endl;
	std::cout << "������ �����";
	preorder(root);
	std::cout << std::endl;
	std::cout << "�������� �����";

	postorder(root);
	std::cout << std::endl;


	return 0;
}

