#include<iostream>
#include<string>
#include"Decorator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	cout << "������ �����" << endl;
	Doll* doll=nullptr;
	cout << "1 - ����������� �����-�������" << endl;
	cout << "2 - ����������� �����-�������" << endl;
	cout << "3 - ����������� �����-�������" << endl;
	cout << "4 - ����������� �����-�������" << endl;
	cout << "5 - ��������� �����-�������" << endl;
	cout << "6 - ��������� �����-�������" << endl;
	int v;
	cin >> v;
	switch (v)
	{
	case 1:  doll = new EuropeanWomanDoll; 	break;
	case 2:  doll = new EuropeanManDoll; 	break;
	case 3:  doll = new AfricWomanDoll; 	break;
	case 4:  doll = new AfricManDoll; 	break;
	case 5:  doll = new ChineseWomanDoll; 	break;
	case 6:  doll = new ChineseManDoll; 	break;
	default: break;
	}
	doll = new Hairstyle(doll);
	string p = doll->setDecor();
	doll->AddDecor(p);
	doll = new Makeup(doll);
	p = doll->setDecor();
	doll->AddDecor(p);
	doll = new �lothing(doll);
	p = doll->setDecor();
	doll->AddDecor(p);
	doll = new Footwear(doll);
	p = doll->setDecor();
	doll->AddDecor(p);
	doll = new Accessories(doll);
	p = doll->setDecor();
	doll->AddDecor(p);
	doll->getRez();
	system("pause");
}