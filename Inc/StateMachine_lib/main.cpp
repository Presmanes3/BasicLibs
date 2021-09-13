#include "StateMachine/State.h"
#include "Action/Action.h"
#include "stdio.h"

bool read_temp_sensor_callback()
{
    printf("Sensor read\n");

    return false;
}

bool test1()
{
    printf("Test 1!\n");

    return false;
}

bool test2()
{
    printf("Test 2!\n");

    return false;
}

bool test3()
{
    printf("Test 3!\n");

    return false;
}

int main()
{
    Action read_temp = Action();
    Action b = Action();
    Action c = Action();
    Action d = Action();

    State<15> awake_state = State<15>();

    awake_state.add_action(&read_temp);
    awake_state.add_action(&b);
    awake_state.add_action(&c);
    awake_state.add_action(&d);

    read_temp.set_callback(&read_temp_sensor_callback);
    b.set_callback(&test1);
    c.set_callback(&test2);
    d.set_callback(&test3);

    while (true)
    {
        awake_state.update();
    }
}