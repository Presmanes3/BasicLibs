#include "StateMachine_lib/TransitionChecks.h"
#include "Action_lib/Action.h"

TransitionChecks::TransitionChecks() {

}

TransitionChecks::TransitionChecks(State *dst) {
	this->destiny_state = dst;
}

TransitionChecks::TransitionChecks(State *dst, Action **checks, uint32_t size) {
	this->destiny_state = dst;
	this->checks.set_pool(checks, size);
}

State* TransitionChecks::check_all_transitions() {
	if (!this->checks.is_null()) {
		uint32_t num_checks = this->checks.get_size();

		for (uint32_t x = 0; x < num_checks; x++) {
			Action *check = this->checks.get_element(x);

			if (check->is_executable()) {
				bool ret = check->execute();

				if (ret) {
					return this->destiny_state;
				}
			}
		}
	}

	return nullptr;
}

State* TransitionChecks::check_new_transition() {
	if (!this->checks.is_null()) {

		Action *check = this->checks.get_next_element();

		if (check->is_executable()) {
			bool ret = check->execute();

			if (ret) {
				return this->destiny_state;
			}
		}
	}

	return nullptr;
}

void TransitionChecks::add_checking(Action *action) {
	this->checks.add_element(action);
}

ArrayPointerVector<Action>* TransitionChecks::get_checkings_vector() {
	return &this->checks;
}

void TransitionChecks::set_destiny(State *dst) {
	this->destiny_state = nullptr;
}

State* TransitionChecks::get_destiny() {
	return this->destiny_state;
}
