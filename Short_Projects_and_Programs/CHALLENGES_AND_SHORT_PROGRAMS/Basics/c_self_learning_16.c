/* Self Learning C - Basic 16 - Elevator Puzzle */

#include <stdio.h>
#include <elevator.h>

enum ElevatorState {ElevatorState_DoorsFullyClosed,
                    ElevatorState_DoorsAreOpening,
                    ElevatorState_DoorsFullyOpen,
                    ElevatorState_DoorsAreClosing,
                    ElevatorState_MovingBetweenFloors};
                    
typedef enum elevatorState ElevatorState;
 
int main(int argc, char * argv[])
{
    ElevatorState state = ElevatorState_DoorsFullyClosed;

    int event;
    int counter = 0;

    // Begin the main loop. This loops forever; it has no terminating condition.
    for (;;)
    {
        // Get any pending event, if one exists
        event = elevatorGetEvent();
       
        // See what we got
        switch (event)
        {
        case 0 :        // Nothing has happened
            // There is no pending event. We have nothing to do.
            break;
           
        case 1 :        // UP button was pressed           
            if (state != ElevatorState_DoorsFullyClosed)
                break;           
            elevatorUp();
            state = ElevatorState_MovingBetweenFloors;
                break;
           
        case 2 :        // DOWN button was pressed
            if (state != ElevatorState_DoorsFullyClosed)
                break;        
            elevatorDown(); 
            state = ElevatorState_MovingBetweenFloors;          
                break;
           
        case 3 :        // OPEN button was pressed
            if (state == ElevatorState_MovingBetweenFloors)
                break;
            else if(state == ElevatorState_DoorsAreClosing || state == ElevatorState_DoorsFullyClosed){
                counter = 3;
                elevatorOpenDoors();
                state =  ElevatorState_DoorsAreOpening;
                break;
            }
            counter = 3;
            elevatorOpenDoors();
            state =  ElevatorState_DoorsAreOpening;
                break;
           
        case 4 :        // CLOSE button was pressed
            if (state == ElevatorState_MovingBetweenFloors)
                break;
            else if(state == ElevatorState_DoorsAreOpening || state == ElevatorState_DoorsFullyOpen){
                elevatorCloseDoors();
                state =  ElevatorState_DoorsAreClosing;
                break;
            }
            state = ElevatorState_DoorsFullyClosed;
                break;
            counter = 0;
            elevatorCloseDoors();
            state = ElevatorState_DoorsAreClosing;
                break;
          
        case 5 :        // Elevator reached the second floor
            printf("The elevator is at floor 2\n");
            counter = 3;
            elevatorOpenDoors();
            state = ElevatorState_DoorsAreOpening;
                break;
           
        case 6 :        // Elevator reached the first floor
            printf("The elevator is at floor 1\n");
            counter=3;
            elevatorOpenDoors();
            state = ElevatorState_DoorsAreOpening;
                break;
           
        case 7 :        // Elevator doors are now at the fully open position
            printf("The elevator doors are fully open\n");
            state = ElevatorState_DoorsFullyOpen;
                break;
           
        case 8 :        // Elevator doors are now at the fully closed position
            printf("The elevator doors are fully closed\n");
            state = ElevatorState_DoorsFullyClosed;
                break;
           
        case 100 :      // Timer: one second has elapsed since last Timer event
            if (counter != 0) {
                counter--;  
                if (counter == 0 && state != ElevatorState_MovingBetweenFloors){
                    elevatorCloseDoors();
                    state = ElevatorState_DoorsAreClosing;
                }
            }
            printf("Tick\n");
            break;
        }
    }
   
    // The loop above never ends. We never get here.
    return 0;
}