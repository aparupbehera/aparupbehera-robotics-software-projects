xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/map/Aparup.world" &

sleep 15

xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch  map_file:=/home/workspace/catkin_ws/src/map/map.yaml" &

sleep 10

xterm -e "roslaunch add_markers view_navigation.launch rviz_path:=/home/workspace/catkin_ws/src/rvizConfig/rVizConfig.rviz" &

sleep 10

xterm -e "rosrun add_markers add_markers" &
 
xterm -e "rosrun pick_objects pick_objects"


