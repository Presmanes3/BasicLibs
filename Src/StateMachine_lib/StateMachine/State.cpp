#include "StateMachine_lib/inc/StateMachine/State.h"

#include "stdio.h"

State::State(){

}

void State::update() {
	update_actions_time.start();
	uint32_t action_id = this->current_update_action;

	Action *action = this->update_actions.get_action(action_id);

	if (this->action_exist(action)) {
		bool executed_succ = action->execute();

		if (executed_succ) {
			this->next_update_action();
		}
	}

	update_actions_time.stop();
}

void State::enter() {
	enter_actions_time.start();

	Action *action = nullptr;
	for (uint32_t x = 0; x < this->enter_actions.get_size(); x++) {
		action = this->enter_actions.get_action(x);

		if (this->action_exist(action)) {
			action->execute();
		}
	}

	enter_actions_time.stop();
}

void State::exit() {
	exit_actions_time.start();

	Action *action = nullptr;
	for (uint32_t x = 0; x < this->exit_actions.get_size(); x++) {
		action = this->exit_actions.get_action(x);

		if (this->action_exist(action)) {
			action->execute();
		}
	}

	exit_actions_time.stop();
}

void State::init() {

}

ActionVector* State::get_action_vector(ActionType type) {
	switch (type) {
		case ActionType::ACTION_UPDATE: {
			return &this->update_actions;
		}
		break;

		case ActionType::ACTION_ENTER: {
			return &this->enter_actions;
		}
		break;

		case ActionType::ACTION_EXIT: {
			return &this->exit_actions;
		}
		break;
	}

	return nullptr;
}

void State::add_action(ActionType type, Action* action_){
	ActionVector* vector = this->get_action_vector(type);

	vector->add_action(action_);
}

bool State::action_exist(Action* action){
	return action != nullptr;
}

void State::next_update_action() {
	if (this->current_update_action + 1 >= this->update_actions.get_size()) {
		this->current_update_action = 0;
	} else {
		this->current_update_action++;
	}
}

