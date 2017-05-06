//---------------------------------------------------------------------------

#pragma hdrstop

#include "Heash.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
// Ну что ж, самое интересное

const int n = 50;  // макс значение в хэш таблице 49, больше было лень делать,
// да и при выводе неудобно кучу пустых строк листать

/*
 Констуктор хэша, создаём массив из 50 указателей и обнуляем его
*/
Heash::Heash(){
 arr = new Node*[n];
 for (int i = 0; i<n; i++)
	arr[i] = NULL;
}

/*
 Деструктор хэша, сначала удаляем все этементы в цепочках, потом сам массив указателей
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
 Функция добавления. Мой хэш-ключ: складываю номера символов хэшируемой строки
 взятых в остатке деления на 13 и умноженных на их позицию в строке. А потом
 кидаю это чудо в таблицу
*/
Heash::Add(AnsiString str)
{
	int NewKey = 0, len = str.Length();
	for (int i = 1; i<=len; i++)
		NewKey+=str[i] % 13 * i; //вот, если словами непонятно, 13 взято из головы, никакого
		//сокрального значения и массонских заговоров это не несёт

	NewKey%= 50;      //берём по остатку на 50, т.к. это максимальное значение хэша

	if (arr[NewKey] == NULL)  //если у нас ещё не было строк с таким ключом, кидаем её
		{
			Node *block = new Node();
			block->key = NewKey;
			block->info = str;
			arr[NewKey] = block;
		}
	else  //а если были, то тоже кидаем, предварительно спустившись по цепочке
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
 Удаление элементов из диапозона.
 Тоже самое, что и в деструкторе, только не сносим весь массив, а только его часть
*/
Heash::Delete(int begin, int end)
{
	/*
	 Защита от "очень умных людей", чтобы за границы хэша не вылезли
	*/
	if (begin<0) begin = 0;
	if (end>=n) end = n-1;
	if (end<begin)
		{
			int t = begin;
			begin = end;
			end = t;
		}
	//Удаление
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
 Ну и, наконец-то, вывод сия шедевра
 Если элементов с таким ключом не было, выводит звёздочку, иначе, цепочку
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


