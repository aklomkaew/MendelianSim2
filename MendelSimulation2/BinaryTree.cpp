// -----------------------------------------------------------
// File: BinaryTree.cpp
// Atchima Klomkaew
// Programming Assignment 2 - MendelSimulation2
// This program is entire my own work
// Although some of the functions are either from or somewhat from Code Vault
// -----------------------------------------------------------
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	ClearTree(root);
}

Node *BinaryTree::SearchTree(char *key, Node *T)
{
	if(T != NULL)
	{
		if(strcmp(key, T->key) == 0)
			return T;
		else if(strcmp(key, T->key) < 0)
			return SearchTree(key, T->left);
		else
			return SearchTree(key, T->right);
	}
	return NULL;
}

bool BinaryTree::Insert(Node *newNode)
{
	Node *temp = root;
	Node *back = NULL;

	Node *t = SearchTree(newNode->key, root);
	if(t != NULL)
	{
		t->counter++;
		return true;
	}

	while(temp != NULL)
	{
		back = temp;
		if(strcmp(newNode->key, temp->key) < 0)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(back == NULL)
		root = newNode;
	else if(strcmp(newNode->key, back->key) < 0)
		back->left = newNode;
	else
		back->right = newNode;

	return true;
}

bool BinaryTree::Insert(char *key)
{
	Node *newNode = new Node();
	
	strcpy(newNode->key, key);
	newNode->counter = 1;
	newNode->left = newNode->right = NULL;

	return Insert(newNode);
}

// -- don't really need this
void BinaryTree::PrintOne(Node *T)
{
	cout << T->key << "\t\t" << T->counter << endl;
}

void BinaryTree::PrintTree()
{
	PrintAll(root);
}

void BinaryTree::ClearTree(Node *T)
{
	if(T == NULL)
		return;
	if(T->left != NULL)
		ClearTree(T->left);
	if(T->right != NULL)
		ClearTree(T->right);
	delete T;
}

Node *BinaryTree::DupNode(Node *T)
{
	Node *dup = new Node();
	*dup = *T;
	dup->left = dup->right = NULL;

	return dup;
}

void BinaryTree::PrintAll(Node *T)
{
	if(T != NULL)
	{
		// in-order
		PrintAll(T->left);
		PrintOne(T);
		PrintAll(T->right);
	}
}

Node *BinaryTree::GetRoot()
{
	return root;
}

void BinaryTree::CustomizedPrintOne(Node *T)
{
	cout << "\tGenotype = " << T->key 
		 << "\tOffspring count = " << T->counter << endl;
}

void BinaryTree::CustomizedPrintAll(Node *T)
{
	if(T != NULL)
	{
		// in-order
		CustomizedPrintAll(T->left);
		CustomizedPrintOne(T);
		CustomizedPrintAll(T->right);
	}
}