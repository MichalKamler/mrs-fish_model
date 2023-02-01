#ifndef RATE_CONTROLLER_H
#define RATE_CONTROLLER_H

#include <multirotor_model.h>
#include <controllers/pid.h>
#include <controllers/references.h>
#include <eigen3/Eigen/Eigen>

namespace mrs_multirotor_simulator
{

class RateController {

public:
  struct Params
  {
    double          kp;
    double          kd;
    double          ki;
    Eigen::Matrix3d J;
  };

  RateController();

  void setParams(const Params& params);

  reference::ControlGroup getControlSignal(const MultirotorModel::State& state, const reference::AttitudeRate& reference, const double& dt);

private:
  Params params_;

  PIDController pid_x_;
  PIDController pid_y_;
  PIDController pid_z_;
};

}  // namespace mrs_multirotor_simulator

#endif  // RATE_CONTROLLER_H
