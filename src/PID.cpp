#include "PID.h"


/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {

  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;

  d_error = 0.0;
  p_error = 0.0;
  i_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return (-Kp*d_error - Ki*i_error - Kd*d_error);
}

