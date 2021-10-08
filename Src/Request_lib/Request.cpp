/*
 * Request.cpp
 *
 *  Created on: 8 oct. 2021
 *      Author: Javier Presmanes
 */

#include "Request_lib/Request.h"

Request::Request(bool petition_f(), bool response_f(), uint32_t response_timeout, uint32_t num_petitions) {
	this->petition.set_callback(petition_f);
	this->response.set_callback(response_f);

	this->response_timer.set_period(response_timeout);

	this->petition.set_repetition(num_petitions);
}

void Request::reset() {
	this->response.reset();
	this->response.activate();

	this->petition.reset();
	this->petition.activate();

	this->response_timer.reset();

	this->_has_failed = false;
	this->_has_success = false;
	this->_is_trying = false;

	this->tries = 0;
}

void Request::init() {
	this->deactivate();
}

void Request::stop() {
	this->deactivate();

	this->response.deactivate();
	this->petition.deactivate();

	this->response_timer.deactivate();
}

void Request::start() {
	this->activate();

	this->reset();
}

bool Request::update() {
	if (this->is_active()) {

		if (this->petition.has_exceeded_repetitions()) {
			this->failed();
			this->stop();
		} else {
			if (this->check_response()) {
				this->stop();
				this->success();

				return true;
			} else {
				if (this->petition.execute()) {
					this->tries++;
				}
			}
		}
	}
	return false;
}

bool Request::check_response() {
	return this->response.execute();
}

void Request::failed() {
	this->_has_failed = true;
	this->times_failed++;
}

void Request::success() {
	this->_has_success = true;
	this->times_success++;
}

bool Request::has_failed() {
	return this->_has_failed;
}

bool Request::has_success() {
	return this->_has_success;
}

void Request::change_number_petitiosn(uint32_t new_val) {
	this->petition.set_repetition(new_val);
}

void Request::trying() {
	this->_is_trying = true;
}

uint32_t Request::get_number_petitions() {
	return this->petition.get_number_repetitions();
}

