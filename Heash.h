//---------------------------------------------------------------------------

#ifndef HeashH
#define HeashH
#include <vcl.h>
//---------------------------------------------------------------------------

/*
 Типичный узел хэша, содержит ключ, информацию, которую хэшировали и
сслыку на следующий элемент (при коллизии)
*/
struct Node{
	Node();
	int key;
	AnsiString info;
	Node *next;
};

Node::Node()          //конструктор узла, его обнуление
{
	info = "";
	next = NULL;
}

class Heash{
	Node **arrayOfKeys;       //массив указателей на узел, это и есть моя хэш-таблица
	~Heash();
	public:
		Heash();
		Add(AnsiString str);
		ShowList(TMemo *Memo);
    	Delete(int first, int second);
};
#endif
