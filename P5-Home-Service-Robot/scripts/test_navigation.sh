xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/map/Aparup.world" &

sleep 15

xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch  map_file:=/home/workspace/catkin_ws/src/map/map.yaml" &

sleep 10

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" 
