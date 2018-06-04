#include "mode.h"
#include "Rover.h"
#include <AP_Math/AP_Math.h>


void ModeManual::update()
{
    float desired_steering, desired_throttle, final_throttle;
    float added_throttle=attitude_control.get_throttle_out_from_pitch(0);
    get_pilot_desired_steering_and_throttle(desired_steering, desired_throttle);
    final_throttle=constrain_float(desired_throttle+added_throttle, -100.0f, 100.0f);
    // copy RC scaled inputs to outputs
    g2.motors.set_throttle(final_throttle);
    g2.motors.set_steering(desired_steering, false);

}
