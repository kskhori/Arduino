# This page is tutoreal for ROS-based Arduino program

## Connect your PC & Arduino devices

![Device Configuration](laser_circuit.pdf "Connection")

## Getting started
First of all please download & install Arduino IDE from official page.
    https://www.arduino.cc/en/software   
Then, you can edit .ino files.

## Run the code as ros node on Linux PC

```
cd <your workspace>
(source devel/setup.bash)
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0
```

## 2nd Device
```
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM1 __ns:=/laser
```
You can check Distance data by typing like 
```
rostopic echo /laser/laser_d3
```

## Something Wrong?

Please be careful with port and namespace
You may run same node.
