#include <iostream>
#include <string>
#include <map>

using namespace std;

class HotDrink
{
public:
	virtual void prepare(int volume) = 0;
	
};


class Tea:public HotDrink
{
	void prepare(int volume) override {cout << "Tea : " << volume << endl;}
};


class Coffee:public HotDrink
{
	void prepare(int volume) override {cout << "Coffee : " << volume << endl;}	
};


class HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};


class TeaFactory:HotDrinkFactory
{
	unique_ptr<HotDrink> make() const override
	{
		return make_unique<Tea>();
	}
};

class CoffeeFactory:HotDrinkFactory
{
	unique_ptr<Coffee> make() const override
	{
		return make_unique<Coffee>();

	}
};

class DrinkFactory
{
	map<string, unique_ptr<HotDrinkFactory> > hot_factories;
public:
	DrinkFactory()
	{
		hot_factories["Coffee"] = make_unique<CoffeeFactory>();
		hot_factories["Tea"] = make_unique<TeaFactory>();
	}

	unique_ptr<HotDrink> make_drink(const string& name)
	{
		auto drink = hot_factories[name]->make();
		drink->prepare(200); //oops!
		return drink;
	}
};