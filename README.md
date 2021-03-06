# PID Control
The goal of this project is to develop a PID control model to control the steering angle of the autonomous car so it can stay on track.

### File Structure
1. ./src/PID.cpp & PID.h: PID calculation
2. ./main.cpp: main file to compile PID on simulator

## Mathematical Model & Psudo Code

```
cte = cross track error
cte_dot = cte - cte previos
total_cte += cte
steering_angle = -k_p * cte - k_d * (cte - cte_previos) - k_i * (total_cte)
```
k_p, k_d, k_i are control gains for the PID which can be set by manual tuning or optimization algorithm.
The writing below describes the trial and errors by manual tuning.

## P.I.D Implementation
I experiment setting the P, I , D values for different cases.
#### k_p = 2.0, k_d = 0 & k_i = 0, [-20, 20] degrees steer angle limit, throttle = 0.3 m/s^2
The model car started out pretty stable on the straight driving, but it also started to hug the right hand side of the track until it went up the curve. 

<p align="center">
  <img src = "https://github.com/ancabilloni/PID-Control/blob/master/gif/P.gif">
</p>


#### k_p = 2.0, k_d = 0.004, k_i = 0, [-20, 20] degrees steer angle limit, throttle = 0.3 m/s^2
The car tried to stay in the middle of the road somewhat as it moved in zig zag. 

<p align="center">
  <img src ="https://github.com/ancabilloni/PID-Control/blob/master/gif/PD.gif">
</p>
 
#### k_p = 0 & k_d = 0, k_i = 3.1, [-20, 20] degrees steer angle limit, throttle = 0.3 m/s^2
k_i element alone performed very stable on straight driving but slowly hugged the right hand side of the track. This is similar behavior with k_p only case.

#### k_p = 2.0, k_i = 0.004, k_d = 3.0, throttle = 0.3, [-20, 20] degrees steer angle limit, throttle = 0.3 m/s^2
With all elements P, I, D added to the control model, the car stays more consistently in the middle of the lane, less curve hugging and zig zag crossing. This is by far the best tuning parameters I have and after several loops of driving on the track, the car didn't fail or go off track.

However, the manual tuning values does not provide a smooth riding for the car.

<p align="center">
  <img src = "https://github.com/ancabilloni/PID-Control/blob/master/gif/PID.gif">
</p>

## Future Improvement
- Try optimization algorithm such as Twiddle.


