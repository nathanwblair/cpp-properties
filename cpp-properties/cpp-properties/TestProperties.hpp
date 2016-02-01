#pragma once
#include <iostream>
#include <string>
#include "property.hpp"

struct TestProperties
{

	void Run()
	{
#if BROKEN_TEST_CASES

		height = Property<int>(0);
		height.MakeGet([](auto& value) {

			auto length = Property<int>(0);
			length.MakeGet([](auto& value) {
				return 0;
			});

			printf(std::to_string(length.Get()).c_str());

			auto var = 0;
			std::cin >> var;

			return 0;
		});

		printf(std::to_string(height.Get()).c_str());

		auto var = 0;
		std::cin >> var;

#endif
		ValueProperty<int> height(0);
		height.MakeGet([](auto * value) {

			return *value;
		});

		height.MakeSet([](auto * value, auto newValue) {
			if (newValue > 0)
				*value = newValue;
			else
				*value = 0;
		});

		height.Set(-2);

		printf(std::to_string(height.Get()).c_str());

		height.Set(2);

		printf(std::to_string(height.Get()).c_str());
		

		Property<ValueProperty<int>> length(height);

		length.MakeGet([](auto * value) {

			return value;
		});

		length.MakeSet([](auto * value, auto newValue) {
			*value = newValue;
		});


		printf(std::to_string(length.Get()->Get()).c_str());

		length.Get()->Set(-2);
		length.Get()->Get();

		printf(std::to_string(length.Get()->Get()).c_str());


	}
};