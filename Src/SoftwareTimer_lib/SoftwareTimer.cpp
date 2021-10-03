#include <SoftwareTimer_lib/SoftwareTimer.h>

void SoftwareTimer::set_period(uint32_t period) {

	float period_s = 0;

	switch (this->base_time) {
		case BASE_MILLIS: {
			period_s = period / 1000;
		}
		break;

		case BASE_MICROS: {
			period_s = period / 1000000;
		}
		break;
	}

	this->period = (float) period;

	this->frequecy_Hz = 1 / (float) period_s;
}

void SoftwareTimer::start() {
	this->activate();
	this->ref_time = this->get_current_time();
}

void SoftwareTimer::stop() {
	this->deactivate();
}

void SoftwareTimer::reset() {
	this->activate();
	this->ref_time = this->get_current_time();
}

bool SoftwareTimer::check() {
	if (this->is_active()) {
		this->time_done = this->compute_time_done();
		this->time_left = this->compute_time_left();
		this->percentage_done = this->compute_percentage_done();
		this->percentage_left = this->compute_percentage_left();

		if (this->time_done >= this->period) {
			this->ref_time = this->get_current_time();

			return true;
		}
	}

	return false;
}

float SoftwareTimer::compute_percentage_done() {
	return (this->time_done * 100) / this->period;
}

float SoftwareTimer::compute_percentage_left() {
	return 100 - this->percentage_done;
}

uint32_t SoftwareTimer::compute_time_done() {
	uint32_t time_done = 0;
	uint32_t current_time = this->get_current_time();

	if (current_time < this->ref_time) {
		// Overflow handling of the function
		uint32_t max_timer_value = this->get_hardware_timer_autoreload();
		time_done = max_timer_value - this->ref_time + current_time;
	} else {
		time_done = current_time - this->ref_time;
	}

	return time_done;
}

uint32_t SoftwareTimer::compute_time_left() {
	return this->period - this->time_done;
}

uint32_t SoftwareTimer::get_current_time() {
	return this->hw_timer->Instance->CNT;
}

uint32_t SoftwareTimer::get_hardware_timer_autoreload() {
	return this->hw_timer->Instance->ARR;
}

