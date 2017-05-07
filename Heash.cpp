//---------------------------------------------------------------------------

#pragma hdrstop

#include "Heash.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
// �� ��� �, ����� ����������

const int numberOfKeys = 50;  	// ���� �������� � ��� ������� 49, ������ ���� ���� ������,
								// �� � ��� ������ �������� ���� ������ ����� �������

//	���������� ����, ������ ������ �� 50 ���������� � �������� ���
Heash::Heash()
{
	arrayOfKeys = new Node*[numberOfKeys];
 	for (int i = 0; i < numberOfKeys; i++)
		arrayOfKeys[i] = NULL;
}

//	���������� ����, ������� ������� ��� �������� � ��������, ����� ��� ������ ����������
Heash::~Heash()
{
	for (int i = 0; i < numberOfKeys; i++)
	{
		Node *block = arrayOfKeys[i];
		while (block)
		{
			Node *del = block;
			block = block->next;
			delete del;
		}
 	}
	delete [] arrayOfKeys;
}

//	������� ����������. ��� ���-����: ��������� ������ �������� ���������� ������
//	������ � ������� ������� �� 13 � ���������� �� �� ������� � ������. � �����
//	����� ��� ���� � �������
Heash::Add(AnsiString str)
{
	int NewKey = 0;
	int len = str.Length();
	for (int i = 1; i <= len; i++)
		NewKey += str[i] % 13 * i;  //	���, ���� ������� ���������, 13 ����� �� ������, ��������
									//	����������� �������� � ���������� ��������� ��� �� ����

	NewKey %= 50;      				//	���� �� ������� �� 50, �.�. ��� ������������ �������� ����

	if (arrayOfKeys[NewKey] == NULL)  		//	���� � ��� ��� �� ���� ����� � ����� ������, ������ �
	{
		Node *newBlock = new Node();
		newBlock->key = NewKey;
		newBlock->info = str;
		arrayOfKeys[NewKey] = newBlock;
	}
	else  							//	� ���� ����, �� ���� ������, �������������� ����������� �� �������
	{
		Node *block = arrayOfKeys[NewKey];
		while (block->next)
			block = block->next;
		Node *newBlock = new Node();
		newBlock->key = NewKey;
		newBlock->info = str;
		block->next = newBlock;
	}
}


//	�������� ��������� �� ���������.
//	���� �����, ��� � � �����������, ������ �� ������ ���� ������, � ������ ��� �����
Heash::Delete(int begin, int end)
{

//	������ �� "����� ����� �����", ����� �� ������� ���� �� �������
	if (begin < 0)
			begin = 0;

	if (end >= numberOfKeys)
			end = numberOfKeys - 1;

	if (end < begin)
	{
		int index = begin;
		begin = end;
		end = index;
	}

//	��������
	for (int i = begin; i <= end; i++)
	{
		Node *block = arrayOfKeys[i];
		while (block)
		{
			Node *deleteBlock = block;
			block = block->next;
			delete deleteBlock;
		}
		arrayOfKeys[i] = NULL;
	}
}

//	�� �, �������-��, ����� ��� �������
//	���� ��������� � ����� ������ �� ����, ������� ��������, �����, �������
Heash::ShowList(TMemo *Memo)
{
	for (int i = 0; i < numberOfKeys; i++)
	{
		AnsiString str = i;
		if (arrayOfKeys[i] == NULL)
			Memo->Lines->Add(str + ") *");
		else
		{
			AnsiString workStr = i;
			workStr += ')';
			Node *block = arrayOfKeys[i];
			while (block)
			{
				workStr += (" " + block->info);
				block = block->next;
			}
			Memo->Lines->Add(workStr);
		}
	}
}


