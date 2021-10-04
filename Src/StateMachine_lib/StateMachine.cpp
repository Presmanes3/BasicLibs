#include <StateMachine_lib/StateMachine.h>

StateMachine::StateMachine() {

}

void StateMachine::add_state_pool(State **pool, uint32_t size) {
	this->statePool.set_pool(pool, size);
}

void StateMachine::add_check_transitions_pool(TransitionCheck **pool, uint32_t size) {
	this->transitionChecksPool.set_pool(pool, size);
}

