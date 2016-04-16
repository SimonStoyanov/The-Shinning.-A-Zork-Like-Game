#ifndef P2STRING_H
#define P2STRING_H

#include <string.h>
#include <cstring>
#include "p2Vector.h"

class p2String{
private:
	char* string;
	uint max_size;
	void alloc(unsigned int size){
		string = new char[size];
	}
public:
	// Constructor
	p2String(){
		alloc(1);
		string[0] = '\0';
		max_size = 1;
	}
	p2String(uint i){
		max_size = i;
		alloc(max_size);
	}
	p2String(const char* _string){
		max_size = strlen(_string) + 1;
		alloc(max_size);
		strcpy_s(this->string, max_size, _string);

	}
	p2String(const p2String& abc){
		max_size = strlen(abc.string) + 1;
		alloc(max_size);
		strcpy_s(this->string, max_size, abc.string);
	}
	// Destructor
	~p2String(){
		delete[] this->string;
		this->string = nullptr;
		max_size = 0;
	}
	// Methods
	// Pop Back
	void pop_back(){
		string[lenght()] = '\0';
	}
	// Length
	unsigned int lenght() const{
		return strlen(this->string);
	}
	// Return text
	char* c_str() const {
		return this->string;
	}
	// Assign class(=)
	const p2String& operator=(const p2String& str2){
		delete[] string;
		max_size = str2.lenght() + 1;
		alloc(max_size);
		strcpy_s(this->string, max_size, str2.c_str());
		return *this;
	}
	// Comparison ==
	bool operator==(const p2String str2){//return 0 if both string are equal
		return strcmp(string, str2.c_str()) == 0;
	}
	// Comparison !=
	bool operator!=(p2String str2){//return something different than zero if both are different
		return strcmp(this->string, str2.c_str()) != 0;
	}
	// Operator []
	char operator[](unsigned int i){
		char* str = this->string;
		return str[i];
	}
	// Empty
	bool empty() const{
		return this->lenght() == 0;
	}
	// Shrink
	void shrink_to_fit(){
		unsigned int size = this->lenght() + 1;
	}
	// Push Back
	void push_back(const char c){
		char* temp = new char[max_size];
		strcpy_s(temp, max_size, string);
		delete[] string;
		*(temp + max_size - 1) = '\0';
		*(temp + max_size - 2) = c;
		string = temp;
		max_size += 1;
	}

	// Tokenize
	void Tokenize(const char separator, p2Vector<p2String>& tokens){
		uint i = 0;
		while (*(string + i) != 0){
			p2String temporal;
			while (*(string + i) != separator && *(string + i) && *(string + i) != '\n'){
				temporal.push_back(*(string + i));
				i++;
			}
			tokens.push_back(temporal);
			if (*(string + i)) i++;
		}
	}


};


#endif