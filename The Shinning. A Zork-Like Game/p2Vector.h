#ifndef P2VECTOR_H
#define P2VECTOR_H

#define uint unsigned int
#define BLOCK 16

#include <string.h>

template <class TYPE>
class p2Vector{
private:
	TYPE* buffer;
	uint capacity;
	uint num_elements = 0;
public:
	// Constructors and Destructor
	p2Vector(){
		capacity = BLOCK;
		buffer = new TYPE[capacity];
	}

	p2Vector(p2Vector& v){
		capacity = v.capacity;
		buffer = new TYPE[v.capacity];
		num_elements = v.num_elements;
		memcpy(buffer, v.buffer, capacity*sizeof(TYPE));
	}

	p2Vector(uint size) :
		capacity(size)
	{
		buffer = new TYPE[capacity];
	}

	~p2Vector(){
		delete[] buffer;
	}

	// Methods
	uint size() const{
		return num_elements;
	}

	uint _capacity() const{
		return capacity;
	}

	void reserve(uint n){
		if (n > capacity){
			capacity = n;
			TYPE* buffer_aux = new TYPE[capacity];
			this->buffer = buffer_aux;
		}
	}
	void push_back(const TYPE& num){
		if (num_elements == capacity){
			capacity += 10;
			p2Vector<TYPE> aux(*this);
			
			delete[] buffer;
			memcpy(buffer, aux.buffer, capacity*sizeof(TYPE));
		}

		buffer[num_elements] = num;
		num_elements++;
	}
	void push_front(const TYPE& num){
		if (num_elements == capacity)	{
			capacity += 10;
			TYPE* aux = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++) aux[i] = buffer[i];
			delete[] buffer;
			buffer = aux;
		}

		for (int i = num_elements; i > 0; i--){
			buffer[i] = buffer[i - 1];
		}

		buffer[0] = num;
		num_elements++;
	}
	void pop_back(){
		if (num_elements > 0){
			delete buffer[--num_elements];
		}
	}

	TYPE& operator[] (uint index){
		return buffer[index];
	}
	const TYPE& operator[] (uint index) const{
		return buffer[index];
	}

	void remove(TYPE something){
		for (int i = 0; i < num_elements;){
			if (this[i] == something){
				this[i] = NULL;
			}
		}
	}

	void clear(){
		for (int i = 0; i < num_elements; ++i){
			this->pop_back();
		}
	}
};


#endif