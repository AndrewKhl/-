//---------------------------------------------------------------------------

#ifndef HeashH
#define HeashH
#include <vcl.h>
//---------------------------------------------------------------------------

/*
 �������� ���� ����, �������� ����, ����������, ������� ���������� �
������ �� ��������� ������� (��� ��������)
*/
struct Node{
	Node();
	int key;
	AnsiString info;
	Node *next;
};

Node::Node()          //����������� ����, ��� ���������
{
	info = "";
	next = NULL;
}

class Heash{
	Node **arr;       //������ ���������� �� ����, ��� � ���� ��� ���-�������
	~Heash();
	public:
	Heash();
	Add(AnsiString str);
	ShowList(TMemo *Memo);
    Delete(int x, int y);
};
#endif
