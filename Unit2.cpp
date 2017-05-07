//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Heash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

/*
Лабараторная работа №7 заключённого группы 653504 Хлопцева Андрея
номер в группе по списку 30, вариант задания 15.
Задание:
1) Создать хэш-таблцу
2) Заполнить её
3) Добавить функционалку (в моём варианте удаление всех записей с ключами
из диапазона K1 < key < K2)

P.S. При коллизии использовал метод цепочек.
P.S.S. Заполнял таблицу мусором из файлика, файлик приложен, надо к нему только
путь указать
*/

// Так-с начнём, начальная фун-ция. Очистка всех мемчиков, создание таблицы и
// её заполнение из файла


TForm2 *Form2;        // глобальные хэш и форма
Heash *ListHash;

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	Memo2->Clear();
	//	Пропишите, плиз путь к файлу (Data.txt), ну или свой закиньте рандомных строк
	Memo1->Lines->LoadFromFile("D:\\Лабораторные ОАИП 2 семестр\\LabWork7\\Data.txt");
	ListHash = new Heash();
	int i = 0;
	while (i < Memo1->Lines->Count)
		ListHash->Add(Memo1->Lines->Strings[i++]);
}


// Кнопочка обновления для хэш-таблицы. При нажатии удаляет старую таблицу и выводит изменённую.
// Можно было бы и без неё обойтись, но тогда на форме было бы пустовато

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    Memo2->Clear();
	ListHash->ShowList(Memo2);
}



//  Добовление строки в хэш

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	ListHash->Add(Edit1->Text);
}


// Читает два числа из формы и удаляет все ключи в этом промежутке

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	ListHash->Delete(Edit2->Text.ToInt(), Edit3->Text.ToInt());
}
//---------------------------------------------------------------------------

