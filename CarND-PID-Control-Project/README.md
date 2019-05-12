# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

Autonomous Vehicle Lateral Control using PID

1. Objective
This project was done to implement the lateral control or tracking of an autonomous vehicle using PID  (proportional-integral-differential) control on the cross track error (CTE). The Udacity simulation environment is used to implement real time control and test/tune the controller. This CTE is extracted from the simulator, which means the reference trajectory is given by the simulator. PID on cross track error is a simple but not a very effective controller for lateral control, other kinematic controller like Pure Pursuit or Stanley Controller can be used. Additionally, the PID can also be used on heading error to further improve tracking.

2. Parameters of PID controller
Description of PID values in PID control

P (proportional) cotnrol is responsible for direct reduction of the error propotional to the error value. This controller helps to reduce the error but usually by itself results in overshoot.

I (integral) accounts for correction of any existing steady state errors in the system which can happen due to system biases and hystersis. The integral of the error will accumulate over time, and the controller will respond by applying a stronger action. The controller shouldnt rely heavily on integral as may lead to a lagy behavior if used in place of Proportional 

D (differential) accounts for dampening the effect of proportional controller based on its current rate of change. It resists large change in rate of error, thus prevents overshoot behavior of the system. 

Finally parameters

PID parameters used for steering angles:

p value: 0.1
i value: 0.0005
d value: 5

How to tune the parameters

The parameters are tuned manually with the order of: p, d, i. The d and i are first setted to be zeros, and 0.2 was used for the p value, tehn adjusted the p value till it helped to drive around the first corner but with oscillations. Then to reduce the osciallations values slowly increased the d Value till the begavior imporved considerably. Finally some CTE bias was observed in the system, this is where the Intergral controller was required to improve the performance even more. Very slight value of I was used here = .0005.

Automatically fine tuning of the parameters can be done using:

Twiddle algorithm
Stochastic Gradient Descent Optmization
