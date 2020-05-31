#pragma once
#include <random>


template<typename T>
T randomNumber(T min, T max) {
	thread_local std::mt19937 gen{ std::random_device{}() };
	using dist = std::conditional_t<
		std::is_integral<T>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
	>;
	return dist{ min, max }(gen);
}