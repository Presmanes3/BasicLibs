#ifndef _ARRAY_POINTER_VECTOR_H_
#define _ARRAY_POINTER_VECTOR_H_

#include "stdint.h"

template <class type>
class ArrayPointerVector{
	public:
		ArrayPointerVector(){

		};

		void set_pool(type** pool, uint32_t size){
			this->size = size;
			this->pool = pool;
		};

		type* get_element(uint32_t id){

			if(id >= 0 && id < this->size){
				return this->pool[id];
			}

			return nullptr;
		}

		void add_element(type* new_element){
			for(uint32_t x = 0; x < this->size; x++){
				if(this->pool[x] == nullptr){
					this->pool[x] = new_element;
					break;
				}
			}
		}

		uint32_t get_size(){
			return this->size;
		}



	private:
		type** pool;

		uint32_t size = 0;
};










#endif
