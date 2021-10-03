#include <SoftwareTimer_lib/SoftwareTimer.h>
#include "StateMachine_lib/inc/Action/Action.h"
#include "StateMachine_lib/inc/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

void Action::set_timer(SoftwareTimer *timer) {
	// Check if timer is null
	if (timer != nullptr) {
		this->timer = timer;
		this->timer->activate();
		this->_is_periodic = true;
	}
}

void Action::set_repetition(uint32_t repetitions) {
	if (repetitions != 0) {
		this->_has_repetitions = true;
	} else {
		this->_has_repetitions = false;
	}

	this->repetitions = repetitions;

}

void Action::set_callback(bool func()) {
	// Check if function is null
	if (func != nullptr) {
		this->_is_executable = true;
		this->callback = func;
	}
}

bool Action::is_executable() {
	return this->_is_executable;
}

bool Action::execute() {
	bool ret = false;

	if (this->check_execution_conditions()) {
		this->execution_time_calculator.start();

		ret = this->callback();

		this->add_time_executed();

		this->execution_time_calculator.stop();
	}

	return ret;
}

void Action::add_time_executed() {
	this->times_executed++;
}

void Action::reset() {
	this->times_executed = 0;
}

bool Action::check_repetitions() {
	if (this->_has_repetitions) {
		if (this->times_executed >= this->repetitions) {
			this->_has_exceed_repetitions = true;
			return false;
		}
	}
	return true;
}

bool Action::is_bloqued() {
	return this->_has_exceed_repetitions;
}

bool Action::check_execution_conditions() {
	bool can_be_executed = false;

	if (this->is_executable()) {			// If can be executed

		if (this->check_repetitions()) {	// If has not exceed repetitions

			if (this->_is_periodic) {		// If its periodic

				if (this->timer->check()) {	// If time has past
					can_be_executed = true;
				}

			} else {
				can_be_executed = true;
			}
		}
	}

	return can_be_executed;
}

















