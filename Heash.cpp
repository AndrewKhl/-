//---------------------------------------------------------------------------

#pragma hdrstop

#include "Heash.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
// Ну что ж, самое интересное

const int numberOfKeys = 50;  	// макс значение в хэш таблице 49, больше было лень делать,
								// да и при выводе неудобно кучу пустых строк листать

//	Констуктор хэша, создаём массив из 50 указателей и обнуляем его
Heash::Heash()
{
	arrayOfKeys = new Node*[numberOfKeys];
 	for (int i = 0; i < numberOfKeys; i++)
		arrayOfKeys[i] = NULL;
}

//	Деструктор хэша, сначала удаляем все элементы в цепочках, потом сам массив указателей
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

//	Функция добавления. Мой хэш-ключ: складываю номера символов хэшируемой строки
//	взятых в остатке деления на 13 и умноженных на их позицию в строке. А потом
//	кидаю это чудо в таблицу
Heash::Add(AnsiString str)
{
	int NewKey = 0;
	int len = str.Length();
	for (int i = 1; i <= len; i++)
		NewKey += str[i] % 13 * i;  //	вот, если словами непонятно, 13 взято из головы, никакого
									//	сокрального значения и массонских заговоров это не несёт

	NewKey %= 50;      				//	берём по остатку на 50, т.к. это максимальное значение хэша

	if (arrayOfKeys[NewKey] == NULL)  		//	если у нас ещё не было строк с таким ключом, кидаем её
	{
		Node *newBlock = new Node();
		newBlock->key = NewKey;
		newBlock->info = str;
		arrayOfKeys[NewKey] = newBlock;
	}
	else  							//	а если были, то тоже кидаем, предварительно спустившись по цепочке
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


//	Удаление элементов из диапозона.
//	Тоже самое, что и в деструкторе, только не сносим весь массив, а только его часть
Heash::Delete(int begin, int end)
{

//	Защита от "очень умных людей", чтобы за границы хэша не вылезли
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

//	Удаление
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

//	Ну и, наконец-то, вывод сия шедевра
//	Если элементов с таким ключом не было, выводит звёздочку, иначе, цепочку
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


