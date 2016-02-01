#pragma once
#include <functional>

template <typename value_type>
class ValueProperty
{


public:
	value_type * value;
	std::function<value_type(value_type*)> __raw_get;
	std::function<void(value_type*, value_type)> __raw_set;

	std::function<void(value_type)> Set;
	std::function<value_type(void)> Get;

	ValueProperty()
	{
		value = new value_type();
	}

	ValueProperty(value_type copy_value)
	{
		std::cout << "copying";
		value = new value_type(copy_value);
	}

	// 'ValueProperty' is reserved by Microsoft
	ValueProperty(ValueProperty<value_type>& other_valueProperty)
	{
		value = new value_type(*(other_valueProperty.value));


		MakeSet(other_valueProperty.__raw_set);
		MakeGet(other_valueProperty.__raw_get);
	}

	void MakeSet(std::function<void(value_type*, value_type)> set)
	{
		using namespace std::placeholders;

		__raw_set = set;

		Set = std::bind(set, value, _1);
	}

	void MakeGet(std::function<value_type(value_type*)> get)
	{
		__raw_get = get;
		Get = std::bind(get, value);
	}
};


template <typename value_type2>
class Property
{
	value_type2 * value;


public:
	std::function<value_type2*(value_type2*)> __raw_get;
	std::function<void(value_type2*, value_type2)> __raw_set;

	std::function<void(value_type2)> Set;
	std::function<value_type2*(void)> Get;

	Property()
	{
		value = new value_type2();
	}

	Property(value_type2 copy_value)
	{
		value = new value_type2(copy_value);
	}

	// 'property' is reserved by Microsoft
	Property(Property<value_type2>& other_property)
	{
		value = new value_type2(*(other_property.value));

		MakeSet(other_property.__raw_set);
		MakeGet(other_property.__raw_get);
	}

	void MakeSet(std::function<void(value_type2*, value_type2)> set)
	{
		using namespace std::placeholders;

		__raw_set = set;

		Set = std::bind(set, value, _1);
	}

	void MakeGet(std::function<value_type2*(value_type2*)> get)
	{
		__raw_get = get;

		Get = std::bind(get, value);
	}
};