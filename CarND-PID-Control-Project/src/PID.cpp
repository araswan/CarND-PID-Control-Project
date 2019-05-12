#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0;
  i_error = 0;
  d_error = 0;
  prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // Proportional error.
  p_error = cte;

  // Integral error.
  i_error += cte;

  // Diferential error.
  d_error = cte - prev_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return  p_error * Kp + i_error * Ki + d_error * Kd;  // TODO: Add your total error calc here!
}