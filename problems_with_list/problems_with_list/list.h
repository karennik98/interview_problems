#pragma once

template<typename T>
struct list_node
{
	T value;
	list_node<T>* next;

	list_node(T v, list_node<T>* n = nullptr)
		: value(v)
		, next(n)
	{
	}
};