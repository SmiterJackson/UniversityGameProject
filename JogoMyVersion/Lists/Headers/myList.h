#pragma once

#include "stdafx.h"

template<typename T>
class MyList {
public:
	MyList():
		first(nullptr), last(nullptr), size(0)
	{};
	~MyList()
	{
		if (first != nullptr) {
			ListType<T>* aux;

			while (first->GetNextItem() != nullptr) {
				aux = first->GetNextItem();
				delete first;
				first = aux;
			}

			delete first;
		}
	};

	// Internal Classs
public:
	template<typename T_Type>
	class ListType {
	public:
		ListType() :
			type(), type_next(nullptr), type_previous(nullptr)
		{};
		ListType(ListType<T_Type>& Other) :
			type(Other.type), type_next(Other.type_next), type_previous(Other.type_previous)
		{};
		ListType(const T_Type& Type) :
			type(Type), type_next(nullptr), type_previous(nullptr)
		{};
		ListType(T_Type&& Type) :
			type(Type), type_next(nullptr), type_previous(nullptr)
		{};
		ListType(T_Type& Type, ListType<T_Type>*& Type_previous) :
			type(Type), type_next(nullptr), type_previous(Type_previous)
		{};
		ListType(T_Type& Type, ListType<T_Type>*& Type_next, ListType<T_Type>*& Type_previous) :
			type(Type), type_next(Type_next), type_previous(Type_previous)
		{};
		~ListType()
		{};

		// SETS / GETS
		const T_Type& GetItem() { return type; };
		void SetItem(T_Type& newItem) { type = newItem; };

		ListType<T_Type>*& GetNextItem() { return type_next; };
		void SetNextItem(ListType<T_Type>* newNext) { type_next = newNext; };

		ListType<T_Type>*& GetPreviousItem() { return type_previous; };
		void SetPreviousItem(ListType<T_Type>* newprevious) { type_previous = newprevious; };

		void operator= (ListType<T_Type> other)
		{
			this->type = other.type;
			this->type_next = other.type_next;
			this->type_previous = other.type_previous;
		};

	private:
		T_Type type;
		ListType<T_Type>* type_next, *type_previous;
	};

public:
	// SETS / GETS
	const T& GetFirst() const { return first->GetItem(); };
	const T& GetLast() const { return last->GetItem(); };
	const unsigned int GetSize() const { return size; };

	// FUNCTIONS
	void Pop_back()
	{
		if (last != nullptr) 
		{
			ListType<T>* aux = last->GetPreviousItem();
			if (last == first) 
			{
				delete first;
				first = nullptr;
				last = nullptr;
				size--;
				return;
			}
			//aux = last->GetPreviousItem();
			delete last;
			aux->SetNextItem(nullptr);
			last = aux;

			size--;
		}
	};
	void Push_back(const T& newItem)
	{
		ListType<T>* aux = new ListType<T>(newItem, last);
		if(aux == nullptr)
		{
			std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
			return;
		}
		if (last == nullptr && first == nullptr)
		{
			first = aux;
			last = aux;
			size++;
			return;
		}
		last->SetNextItem(aux);
		last = aux;
		size++;
	};
	void Push_back(T&& newItem)
	{
		ListType<T>* aux = new ListType<T>(newItem, last);
		if (aux == nullptr)
		{
			std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
			return;
		}
		if (last == nullptr && first == nullptr)
		{
			first = aux;
			last = aux;
			size++;
			return;
		}
		last->SetNextItem(aux);
		last = aux;
		size++;
	};

	// Operators overloads
	void operator+= (const T& item)
	{
		ListType<T>* aux = new ListType<T>(item, last);
		if (aux == nullptr)
		{
			std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
			return;
		}
		if (last == nullptr && first == nullptr)
		{
			first = aux;
			last = aux;
			size++;
			return;
		}
		last->SetNextItem(aux);
		last = aux;
		size++;
	};
	void operator+= (T&& item)
	{
		ListType<T>* aux = new ListType<T>(item, last);
		if (aux == nullptr)
		{
			std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
			return;
		}
		if (last == nullptr && first == nullptr)
		{
			first = aux;
			last = aux;
			size++;
			return;
		}
		last->SetNextItem(aux);
		last = aux;
		size++;
	};
	void operator+= (std::vector<T>& list2)
	{
		unsigned int i = 0;
		ListType<T>* aux = nullptr;
		if (last == nullptr && first == nullptr)
		{
			aux = new ListType<T>(list2[i]);
			if (aux == nullptr)
			{
				std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
				return;
			}
			size++;
			i++;

			first = aux;
			last = aux;
		}

		while (i < list2.size())
		{
			aux = new ListType<T>(list2[i], last);
			if(aux == nullptr)
			{
				std::cerr << "Nao foi possivel alocar para expandir um novo elemento em MyList." << std::endl;
				break;
			}
			size++;
			last->SetNextItem(aux);
			last = aux;
			++i;
		}
	};
	const T& operator[] (unsigned int const required)
	{
		ListType<T>* aux = first;
		for (unsigned int i = 0; i < required; ++i)
			aux = aux->GetNextItem();

		return aux->GetItem();
	};

private:
	ListType<T>* first, *last;
	unsigned int size;
};