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
	Node **arrayOfKeys;       //������ ���������� �� ����, ��� � ���� ��� ���-�������
	~Heash();
	public:
		Heash();
		Add(AnsiString str);
		ShowList(TMemo *Memo);
    	Delete(int first, int second);
};
#endif
