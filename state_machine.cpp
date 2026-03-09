enum State{
    STATE_STOP,
    STATE_MOVE
};
void process_state(State &current_state, Event event) {
    switch(current_state) {
        case STATE_STOP:
        if ( event ==  BUTTON_On) {
            //
            current_state = STATE_MOVE;
        }
        break;
        case STATE_MOVE:
        if (event == BUTTON_OFF) {
            current_state = STATE_STOP;
        }
        break;
        
    }
}