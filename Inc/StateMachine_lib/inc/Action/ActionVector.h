/*
 * ActionVector.h
 *
 *  Created on: 17 sept. 2021
 *      Author: Javier Presmanes
 */

#ifndef ACTIONVECTOR_H_
#define ACTIONVECTOR_H_

#include "Action.h"
#include "stdint.h"

class ActionVector {
	public:
		ActionVector() {
			this->pool = nullptr;
			this->size = 0;
		}

		void set_action_pool(Action** actions, uint8_t size_){
			this->size = size_;
			this->pool = actions;
		}

		Action* get_action(uint8_t id) {
			return this->pool[id];
		}

		void add_action(Action *action) {
			for(uint8_t x = 0; x < this->size; x++){
				if(this->pool[x] == nullptr){
					this->pool[x] = action;
					break;
				}
			}
		}

		uint8_t get_size() {
			return this->size;
		}

	private:
		Action **pool;

		uint8_t size;
};

#endif /* ACTIONVECTOR_H_ */
