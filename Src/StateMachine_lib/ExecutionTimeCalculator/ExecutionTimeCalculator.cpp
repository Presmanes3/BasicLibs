#include "StateMachine_lib/inc/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

void ExecutionTimeCalculator::start() {
	this->start_time = this->get_current_time();
}

void ExecutionTimeCalculator::stop() {
	this->stop_time = this->get_current_time();

	this->get_time_past();
}

void ExecutionTimeCalculator::set_hardware_timer(TIM_HandleTypeDef* hw_timer){
	if(hw_timer != nullptr){
		this->hw_timer = hw_timer;
	}
}

uint32_t ExecutionTimeCalculator::get_time_past() {
	uint32_t difference = 0;

	if (this->stop_time >= this->start_time) {
		difference = this->stop_time - this->start_time;
	} else {
		difference = this->get_hardware_timer_autoreload() - this->start_time + this->stop_time;
	}

	this->time_past = difference;

	return difference;
}

uint32_t ExecutionTimeCalculator::get_current_time() {
	if(this->hw_timer != nullptr){
		return this->hw_timer->Instance->CNT;
	}
	return 0;
}

uint32_t ExecutionTimeCalculator::get_hardware_timer_autoreload() {
	if(this->hw_timer != nullptr){
		return this->hw_timer->Instance->ARR;
	}
	return 0;
}
