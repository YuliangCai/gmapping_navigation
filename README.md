
# gmapping_navigation
#### The code is to implement 2-D navigation based on ROS navigation_stack, kobuki robot, and Asus proxion live RGB-D camera.The code will implement a fake-laser with the depth image data of camera.

## Prerequisite
#### hardware 
- robot which provide odom message to ROS
- RGB-D camera
#### software 
- ROS kinetic (should also works on other version)
- ROS navigtion_stack 
- openni2
- kuboki robot package 
- depthimage_to_laser package

## Install
install navigation stack
```
sudo apt-get install ros-kinetic-navigation 
```
install depthimage_to_laser package
```
sudo apt-get install ros-kinetic-depthimage-to-laserscan
```
install install gmapping package
```
sudo apt-get install ros-kinetic-gmapping
```
install kobuki package
```
sudo apt-get install ros-kinetic-kobuki ros-kinetic-kobuki-core
```
install gmapping_navigation package
```
git clone 
