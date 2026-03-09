#include <stdio.h>


enum MotorState{
    MOTOR_STOPPED,
    MOTOR_RUNNING_FORWARD,
    MOTOR_RUNNING_BACKWARD,
    MOTOR_OVERLOAD_ERROR
};

enum MotorState currentMotorState = MOTOR_STOPPED;

void controlMotor( enum MotorState newState){
    switch(newState){
    case MOTOR_STOPPED:
    //
    break;

    case MOTOR_RUNNING_FORWARD:
    //
    break;

    case MOTOR_OVERLOAD_ERROR:

    //
    break;

    default:
    break;
    }
    currentMotorState = newState;

}

int main() {
    controlMotor(MOTOR_RUNNING_FORWARD);
    if (check_motor_status_register() == OVERLOAD_DETECTED) {
        ...

        controlMotor(MOTOR_OVERLOAD_ERROR);
    }
    return 0;
}