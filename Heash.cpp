//---------------------------------------------------------------------------

#pragma hdrstop

#include "Heash.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
// �� ��� �, ����� ����������

const int n = 50;  // ���� �������� � ��� ������� 49, ������ ���� ���� ������,
// �� � ��� ������ �������� ���� ������ ����� �������

/*
 ���������� ����, ������ ������ �� 50 ���������� � �������� ���
*/
Heash::Heash(){
 arr = new Node*[n];
 for (int i = 0; i<n; i++)
	arr[i] = NULL;
}

/*
 ���������� ����, ������� ������� ��� �������� � ��������, ����� ��� ������ ����������
*/
Heash::~Heash(){
 for (int i = 0; i<n; i++)
 {
	Node *bl = arr[i];
	while (bl)
	{
		Node *del = bl;
		bl = bl->next;
		delete del;
	}
 }
 delete [] arr;
}

/*
 ������� ����������. ��� ���-����: ��������� ������ �������� ���������� ������
 ������ � ������� ������� �� 13 � ���������� �� �� ������� � ������. � �����
 ����� ��� ���� � �������
*/
Heash::Add(AnsiString str)
{
	int NewKey = 0, len = str.Length();
	for (int i = 1; i<=len; i++)
		NewKey+=str[i] % 13 * i; //���, ���� ������� ���������, 13 ����� �� ������, ��������
		//����������� �������� � ���������� ��������� ��� �� ����

	NewKey%= 50;      //���� �� ������� �� 50, �.�. ��� ������������ �������� ����

	if (arr[NewKey] == NULL)  //���� � ��� ��� �� ���� ����� � ����� ������, ������ �
		{
			Node *block = new Node();
			block->key = NewKey;
			block->info = str;
			arr[NewKey] = block;
		}
	else  //� ���� ����, �� ���� ������, �������������� ����������� �� �������
		{
			Node *bl = arr[NewKey];
			while (bl->next)
				bl = bl->next;

			Node *block = new Node();
			block->key = NewKey;
			block->info = str;
			bl->next = block;
		}
}
/*
 �������� ��������� �� ���������.
 ���� �����, ��� � � �����������, ������ �� ������ ���� ������, � ������ ��� �����
*/
Heash::Delete(int begin, int end)
{
	/*
	 ������ �� "����� ����� �����", ����� �� ������� ���� �� �������
	*/
	if (begin<0) begin = 0;
	if (end>=n) end = n-1;
	if (end<begin)
		{
			int t = begin;
			begin = end;
			end = t;
		}
	//��������
	for (int i = begin; i<=end; i++)
	{
		Node *bl = arr[i];
		while (bl)
		{
			Node *del = bl;
			bl = bl->next;
			delete del;
		}

		arr[i] = NULL;
	}
}
/*
 �� �, �������-��, ����� ��� �������
 ���� ��������� � ����� ������ �� ����, ������� ��������, �����, �������
*/
Heash::ShowList(TMemo *Memo)
{
	for (int i = 0; i<n; i++)
	{
		AnsiString s = i;
		if (arr[i] == NULL) Memo->Lines->Add(s+") *");
		else
		{
			AnsiString workStr = i;
			workStr+=')';
			Node*bl = arr[i];
			while (bl)
			{
				workStr+=(" " + bl->info);
				bl = bl->next;
			}
			Memo->Lines->Add(workStr);
		}
	}
}


