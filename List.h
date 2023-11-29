#pragma once
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
typedef unsigned __int64 my_type;
using namespace std;
struct token {
	string type_lexeme;
	string lexeme;

	my_type index;
	my_type hash;
	int size_lexeme;
	token();
	token(string new_type, string new_value, my_type new_index, my_type new_hash) : type_lexeme(new_type), lexeme(new_value), index(new_index), hash(new_hash){}
	
	~token() {
		
		//очищаем строку;
		lexeme.clear();
		//освобождаем память, занимаемой строкой;
		lexeme.shrink_to_fit();
		type_lexeme.clear();
		type_lexeme.shrink_to_fit();
	}
};

class Node {
public:
	token info_node;
	Node* prev; //предыдущий элемент;
	Node* next; //следующий элемент;

	Node(token information) {
		this->info_node = information;
		this->next = NULL;
		this->prev = NULL;
	}

	~Node() {
		info_node.~token();
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int amount_elems;
public:
	
	List() {
		head = NULL;
		tail = NULL;
		amount_elems = 0;
	}
	int get_size();

	//Добавить элемент в начало;
	void add_to_begin(token num);

	//Добавить элемент в конец;
	void add_to_end(token num);

	//Извлечь первый элемент;
	void remove_first_element();

	//Извлечь последний элемент;
	void remove_last_element();

	Node* get_elem(int index);
	Node* operator[] (int index);

	~List();


};
