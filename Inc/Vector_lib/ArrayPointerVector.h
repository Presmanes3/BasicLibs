#ifndef _ARRAY_POINTER_VECTOR_H_
#define _ARRAY_POINTER_VECTOR_H_

#include "stdint.h"

template<class type>
class ArrayPointerVector {
	public:
		ArrayPointerVector() {
			this->_is_null = true;
		}
		;

		void set_pool(type **pool, uint32_t size) {
			this->size = size;
			this->pool = pool;

			if (this->pool != nullptr) {
				this->_is_null = false;
			}
		}
		;

		type* get_element(uint32_t id) {

			if (id >= 0 && id < this->size) {
				return this->pool[id];
			}

			return nullptr;
		}

		type* get_next_element(){

			type* element = this->pool[this->current_element];

			if(this->current_element + 1 >= this->size){
				this->current_element = 0;
			}else{
				this->current_element++;
			}

			return element;
		}

		void add_element(type *new_element) {
			for (uint32_t x = 0; x < this->size; x++) {
				if (this->pool[x] == nullptr) {
					this->pool[x] = new_element;

					break;
				}
			}
		}

		uint32_t get_size() {
			return this->size;
		}

		bool is_null() {
			return this->_is_null;
		}

		void reset_elements_counter(){
			this->current_element = 0;
		}

	private:
		type **pool;

		uint32_t size = 0;
		uint32_t current_element = 0;

		bool _is_null;
};

#endif
