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
	EuropeanWomanDoll() :Doll("Европейская кукла-девочка") { sex = 'w'; }
	string setDecor() { return ""; }
};
class EuropeanManDoll :public Doll
{
public:
	EuropeanManDoll() :Doll("Европейская кукла-мальчик") { sex = 'm'; }	
	string setDecor() { return ""; }
};
class AfricWomanDoll :public Doll
{
public:
	AfricWomanDoll() :Doll("Африканская кукла-девочка") { sex = 'w'; }	
	string setDecor() { return ""; }
};
class AfricManDoll :public Doll
{
public:
	AfricManDoll() :Doll("Африканская кукла-мальчик") { sex = 'm'; }	
	string setDecor() { return ""; }
};
class ChineseWomanDoll :public Doll
{
public:
	ChineseWomanDoll() :Doll("Китайская кукла-девочка") { sex = 'w'; }	
	string setDecor() { return ""; }
};
class ChineseManDoll :public Doll
{
public:
	ChineseManDoll() :Doll("Китайская кукла-мальчик") { sex = 'm'; }	
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
		cout << "Выбери прическу: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - Высокий хвост" << endl;
			cout << "2 - Длинные локоны" << endl;
			cout << "3 - Каре" << endl;
		}
		else
		{
			cout << "1 - Боб" << endl;
			cout << "2 - Полубокс" << endl;
			cout << "3 - Канадка" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: if (doll->getSex() == 'w') p = "Высокий хвост";
			  else p = "Боб";
			break;
		case 2: if (doll->getSex() == 'w') p = "Длинные локоны";
			  else p = "Полубокс";
			break;
		case 3: if (doll->getSex() == 'w') p = "Каре";
			  else p = "Канадка";
			break;
		default:
			break;
		}
		p = "Прическа - " + p + "\n";
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
			cout << "Побриться? 1 - да, 2 - нет" << endl;
			cin >> v;
			if (v == 1)
				m = " Выбритый ";
			else m = " Небритый";
			cout << "Туалетная вода? 1 - много 2 - слегка" << endl;
			cin >> v;
			if (v == 1)
				m += ", резкий запах туалетной воды  ";
			else m += ", легкий запах туалетной воды ";
		}
		else
		{
			cout << "Сделай макияж: " << endl;
			cout << "1 - Яркий вечерний макияж" << endl;
			cout << "2 - Легкий дневной макияж" << endl;
			cout << "3 - Без макияжа" << endl;
			cin >> v;
			switch (v)
			{
			case 1: m = "Яркий вечерний макияж"; break;
			case 2: m = "Легкий дневной макияж"; break;
			case 3: m = "Естественное лицо без макияжа"; break;
			default:
				break;
			}
		}
		m = "Лицо - " + m + "\n";
		return m;
	}	
};

class Сlothing : public DollDecorator
{
public:
	Сlothing(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "Выбери одежду: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - Джинсы и футболка" << endl;
			cout << "2 - Школьная форма" << endl;
			cout << "3 - Платье невесты" << endl;
		}
		else
		{
			cout << "1 - Джинсы и футболка" << endl;
			cout << "2 - Деловой костюм" << endl;
			cout << "3 - Шорты и майка" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: p = "Джинсы и футболка";
			break;
		case 2: if (doll->getSex() == 'w') p = "Школьная форма";
			  else p = "Деловой костюм";
			break;
		case 3: if (doll->getSex() == 'w') p = "Платье невесты";
			   else p = "Шорты и майка";
			break;
		default:
			break;
		}
		return "Одежда - " + p + "\n";
	}	
};

class Footwear : public DollDecorator
{
public:
	Footwear(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "Выбери обувь: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - кроссовки" << endl;
			cout << "2 - туфли на шпильке" << endl;
			cout << "3 - босоножки на платформе" << endl;
		}
		else
		{
			cout << "1 - кроссовки" << endl;
			cout << "2 - мокасины" << endl;
			cout << "3 - сланцы" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: p = "кроссовки";
			break;
		case 2: if (doll->getSex() == 'w') p = "туфли на шпильке";
			  else p = "мокасины";
			break;
		case 3: if (doll->getSex() == 'w') p = "босоножки на платформе";
			   else p = "сланцы";
			break;
		default:
			break;
		}		
		return "Обувь - " + p + "\n";
	}	
};

class Accessories : public DollDecorator
{
public:
	Accessories(Doll* d) : DollDecorator(d->getName(), d->getSex(), d->getDecor(), d) {}
	string setDecor() override
	{
		cout << "Выбери аксессуары: " << endl;
		if (doll->getSex() == 'w')
		{
			cout << "1 - колье + серьги с бриллиантами " << endl;
			cout << "2 - тонкая золотая цепочка" << endl;
			cout << "3 - чокер" << endl;
		}
		else
		{
			cout << "1 - перстень" << endl;
			cout << "2 - массивная золотая цепь" << endl;
			cout << "3 - ничего" << endl;
		}
		int n;
		string p;
		cin >> n;
		switch (n)
		{
		case 1: if (doll->getSex() == 'w') p = "колье + серьги с бриллиантами";
			  else p = "перстень";
			break;
		case 2: if (doll->getSex() == 'w') p = "тонкая золотая цепочка";
			  else p = "массивная золотая цепь";
			break;
		case 3: if (doll->getSex() == 'w') p = "чокер";
			   else p = "ничего";
			break;
		default:
			break;
		}		
		return "Украшения - " + p + "\n";
	}	
};
