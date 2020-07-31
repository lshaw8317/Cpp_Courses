#pragma once
using namespace std;

class Weapon
{
protected:
	int strength;
	char type;
public:
	int modified;
	Weapon(int s, char t) : strength(s), type(t),modified(s) {};
	int return_strength()
	{
		return strength;
	}
	char return_type()
	{
		return type;
	}
	virtual bool battle() { cout << "Called weapon" << endl; return true; };
};
class Rock : public Weapon
{
public:
	Rock(int s) : Weapon(s, 'r') {};
	bool battle(Weapon w)
	{
		if (w.return_type() == 's') 
		{ 
			modified = strength * 2;
			w.modified = w.return_strength() / 2;
		}
		else if (w.return_type() == 'p') 
		{ 
			modified = strength / 2; 
			w.modified = w.return_strength() * 2;
		}
		else { cout << "Please battle using different weapons" << endl; }
		return (w.modified < modified) ? true : false;
	}
};
class Paper : public Weapon
{
public:
	Paper(int s) : Weapon(s,'p') {};
	bool battle(Weapon w)
	{
		if (w.return_type() == 's')
		{
			modified = strength / 2;
			w.modified = w.return_strength() * 2;
		}
		else if (w.return_type() == 'r')
		{
			modified = strength * 2;
			w.modified = w.return_strength() / 2;
		}
		else { cout << "Please battle using different weapons" << endl; }
		return (w.modified < modified) ? true : false;
	}
};
class Scissors : public Weapon
{
public:
	Scissors(int s) : Weapon(s, 's') {};
	bool battle(Weapon w)
	{
		if (w.return_type() == 'p')
		{
			modified = strength * 2;
			w.modified = w.return_strength() / 2;
		}
		else if (w.return_type() == 'r')
		{
			modified = strength / 2;
			w.modified = w.return_strength() * 2;
		}
		else { cout << "Please battle using different weapons" << endl; }
		return (w.modified < modified) ? true : false;
	}
};
