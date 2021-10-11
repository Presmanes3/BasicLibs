#include <SoftwareTimer_lib/SoftwareTimer.h>

void SoftwareTimer::set_period(uint32_t period) {

	float period_s = 0;

	switch (this->base_time) {
		case BASE_SECONDS: {
			period_s = period;
		}
		break;
		case BASE_MILLIS: {
			period_s = (float) period * 0.001;
		}
		break;

		case BASE_MICROS: {
			period_s = (float) period * 0.000001;
		}
		break;
	}

	this->period = (float) period_s;

	this->frequecy_Hz = 1 / (float) period_s;
}

void SoftwareTimer::start() {
	this->reset();

	if (!this->is_active()) {
		this->activate();
	}

	this->reference = this->get_current_tick();
}

void SoftwareTimer::stop() {
	this->deactivate();
	this->reset();
}

void SoftwareTimer::reset() {
	this->reference = 0;
	this->time_from_overflow = 0;
	this->time_done = 0;
	this->time_left = 0;
	this->percentage_done = 0;
	this->percentage_left = 0;
	this->overflows = 0;
}

void SoftwareTimer::restart() {
	this->reset();
	this->activate();

	this->reference = this->get_current_tick();
}

bool SoftwareTimer::check() {
	if (this->is_active()) {
		this->time_done = this->compute_time_done();
		//this->time_left = this->compute_time_left();
		//this->percentage_done = this->compute_percentage_done();
		//this->percentage_left = this->compute_percentage_left();

		if (this->time_done >= this->period) {
			this->overflows = 0;
			this->time_from_overflow = 0;
			this->reference = this->get_current_tick();
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

float SoftwareTimer::compute_time_done() {
	uint32_t current_tick = this->get_current_tick();

	uint32_t ticks_done = current_tick - this->reference;

	float time_diff = (ticks_done * this->hw_timer_period);

	this->time_done = this->time_from_overflow + time_diff;

	return time_done;
}

float SoftwareTimer::compute_time_left() {
	return this->period - this->time_done;
}

uint32_t SoftwareTimer::get_current_tick() {
	return this->hw_timer->Instance->CNT;
}

uint32_t SoftwareTimer::get_hardware_timer_autoreload() {
	return this->hw_timer->Instance->ARR;
}

void SoftwareTimer::compute_hardware_timer_values() {
	this->hw_timer_frequency = HW_TIMER_FREQUENCY;
	this->hw_timer_period = 1 / this->hw_timer_frequency;
}

void SoftwareTimer::run_overflow() {
	if (this->is_active()) {
		uint32_t ticks_done = this->get_hardware_timer_autoreload() - this->reference;
		this->reference = 0;
		this->overflows++;
		this->time_from_overflow += (ticks_done * this->hw_timer_period);
	}
}

