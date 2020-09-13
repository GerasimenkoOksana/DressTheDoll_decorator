#pragma once
#include<iostream>
#include<string>

using namespace std;

class Doll
{
protected:
	string name;
	char sex;
	string decor;
public:
	Doll(string n) : name(n) {}
	Doll (string n, char s, string d) : name(n), sex(s), decor(d) {}
	string getName() { return name; }	
	virtual string setDecor() = 0;
	void AddDecor(string d) { decor += d; }
	char getSex() { return sex; }
	string getDecor() { return decor; }
	void getRez()
	{
		cout << name << endl;
		cout << sex << endl;
		cout << decor << endl;
	}
};

class EuropeanWomanDoll :public Doll
{
public:
	EuropeanWomanDoll() :Doll("����������� �����-�������") { sex = 'w'; }
	string setDecor() { return ""; }
};
class EuropeanManDoll :public Doll
{
public:
	EuropeanManDoll() :Doll("����������� �����-�������") { sex = 'm'; }	
	string setDecor() { return ""; }
};
class AfricWomanDoll :public Doll
{
public:
	AfricWomanDoll() :Doll("����������� �����-�������") { sex = 'w'; }	
	string setDecor() { return ""; }
};
class AfricManDoll :public Doll
{
public:
	AfricManDoll() :Doll("����������� �����-�������") { sex = 'm'; }	
	string setDecor() { return ""; }
};
class ChineseWomanDoll :public Doll
{
public:
	ChineseWomanDoll() :Doll("��������� �����-�������") { sex = 'w'; }	
	string setDecor() { return ""; }
};
class ChineseManDoll :public Doll
{
public:
	ChineseManDoll() :Doll("��������� �����-�������") { sex = 'm'; }	
	string setDecor() { return ""; }
};
class DollDecorator :public Doll
{
protected:
	Doll* doll;
public:
	DollDecorator(string n, char s, string dec, Doll* d) : Doll(n, s, dec), doll(d) {}
	virtual ~DollDecorator() { delete doll; }
	string setDecor() { return ""; }
};

class Hairstyle : public DollDecorator
{
public:
	Hairstyle(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "������ ��������: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - ������� �����" << endl;
			cout << "2 - ������� ������" << endl;
			cout << "3 - ����" << endl;
		}
		else
		{
			cout << "1 - ���" << endl;
			cout << "2 - ��������" << endl;
			cout << "3 - �������" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: if (doll->getSex() == 'w') p = "������� �����";
			  else p = "���";
			break;
		case 2: if (doll->getSex() == 'w') p = "������� ������";
			  else p = "��������";
			break;
		case 3: if (doll->getSex() == 'w') p = "����";
			  else p = "�������";
			break;
		default:
			break;
		}
		p = "�������� - " + p + "\n";
		return p;
	}	
};

class Makeup : public DollDecorator
{
public:
	Makeup(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		string m;
		int v;
		if (doll->getSex() == 'm')
		{
			cout << "���������? 1 - ��, 2 - ���" << endl;
			cin >> v;
			if (v == 1)
				m = " �������� ";
			else m = " ��������";
			cout << "��������� ����? 1 - ����� 2 - ������" << endl;
			cin >> v;
			if (v == 1)
				m += ", ������ ����� ��������� ����  ";
			else m += ", ������ ����� ��������� ���� ";
		}
		else
		{
			cout << "������ ������: " << endl;
			cout << "1 - ����� �������� ������" << endl;
			cout << "2 - ������ ������� ������" << endl;
			cout << "3 - ��� �������" << endl;
			cin >> v;
			switch (v)
			{
			case 1: m = "����� �������� ������"; break;
			case 2: m = "������ ������� ������"; break;
			case 3: m = "������������ ���� ��� �������"; break;
			default:
				break;
			}
		}
		m = "���� - " + m + "\n";
		return m;
	}	
};

class �lothing : public DollDecorator
{
public:
	�lothing(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "������ ������: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - ������ � ��������" << endl;
			cout << "2 - �������� �����" << endl;
			cout << "3 - ������ �������" << endl;
		}
		else
		{
			cout << "1 - ������ � ��������" << endl;
			cout << "2 - ������� ������" << endl;
			cout << "3 - ����� � �����" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: p = "������ � ��������";
			break;
		case 2: if (doll->getSex() == 'w') p = "�������� �����";
			  else p = "������� ������";
			break;
		case 3: if (doll->getSex() == 'w') p = "������ �������";
			   else p = "����� � �����";
			break;
		default:
			break;
		}
		return "������ - " + p + "\n";
	}	
};

class Footwear : public DollDecorator
{
public:
	Footwear(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "������ �����: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - ���������" << endl;
			cout << "2 - ����� �� �������" << endl;
			cout << "3 - ��������� �� ���������" << endl;
		}
		else
		{
			cout << "1 - ���������" << endl;
			cout << "2 - ��������" << endl;
			cout << "3 - ������" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: p = "���������";
			break;
		case 2: if (doll->getSex() == 'w') p = "����� �� �������";
			  else p = "��������";
			break;
		case 3: if (doll->getSex() == 'w') p = "��������� �� ���������";
			   else p = "������";
			break;
		default:
			break;
		}		
		return "����� - " + p + "\n";
	}	
};

class Accessories : public DollDecorator
{
public:
	Accessories(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "������ ����������: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - ����� + ������ � ������������ " << endl;
			cout << "2 - ������ ������� �������" << endl;
			cout << "3 - �����" << endl;
		}
		else
		{
			cout << "1 - ��������" << endl;
			cout << "2 - ��������� ������� ����" << endl;
			cout << "3 - ������" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: if (doll->getSex() == 'w') p = "����� + ������ � ������������";
			  else p = "��������";
			break;
		case 2: if (doll->getSex() == 'w') p = "������ ������� �������";
			  else p = "��������� ������� ����";
			break;
		case 3: if (doll->getSex() == 'w') p = "�����";
			   else p = "������";
			break;
		default:
			break;
		}		
		return "��������� - " + p + "\n";
	}	
};
