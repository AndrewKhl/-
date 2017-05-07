//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Heash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

/*
������������ ������ �7 ������������ ������ 653504 �������� ������
����� � ������ �� ������ 30, ������� ������� 15.
�������:
1) ������� ���-������
2) ��������� �
3) �������� ������������ (� ��� �������� �������� ���� ������� � �������
�� ��������� K1 < key < K2)

P.S. ��� �������� ����������� ����� �������.
P.S.S. �������� ������� ������� �� �������, ������ ��������, ���� � ���� ������
���� �������
*/

// ���-� �����, ��������� ���-���. ������� ���� ��������, �������� ������� �
// � ���������� �� �����


TForm2 *Form2;        // ���������� ��� � �����
Heash *ListHash;

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Clear();
	Memo2->Clear();
	//	���������, ���� ���� � ����� (Data.txt), �� ��� ���� �������� ��������� �����
	Memo1->Lines->LoadFromFile("D:\\������������ ���� 2 �������\\LabWork7\\Data.txt");
	ListHash = new Heash();
	int i = 0;
	while (i < Memo1->Lines->Count)
		ListHash->Add(Memo1->Lines->Strings[i++]);
}


// �������� ���������� ��� ���-�������. ��� ������� ������� ������ ������� � ������� ���������.
// ����� ���� �� � ��� �� ��������, �� ����� �� ����� ���� �� ���������

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    Memo2->Clear();
	ListHash->ShowList(Memo2);
}



//  ���������� ������ � ���

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	ListHash->Add(Edit1->Text);
}


// ������ ��� ����� �� ����� � ������� ��� ����� � ���� ����������

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	ListHash->Delete(Edit2->Text.ToInt(), Edit3->Text.ToInt());
}
//---------------------------------------------------------------------------

