Aim: Use gmapping to pickup an object from one position and drop it in a different specified position. 

Three Essential elements of robotics:
- Perception
- Decision Making
- Action


Prerequisite packages installed:
   a. gmapping: With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
		Handles perception. The gmapping package provides laser-based SLAM (Simultaneous Localization and Mapping), as a ROS node called slam_gmapping. Using slam_gmapping, you can create a 2-D occupancy grid map (like a building floorplan) from laser and pose data collected by a mobile robot.
  b. turtlebot_teleop: With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
  c. turtlebot_rviz_launchers: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
  d. turtlebot_gazebo: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.

Packages created:
   a. map: Contains the world file and map files. The yaml is required to launch the map in Rviz. The yaml file only contains metadata about the map, which is given as a separate pgm image file.
   b. scripts: xterm is used to launch each script in its own window. This helps to track errors if errors are specific to one service. e.g home_service.sh 
        i)first runs and opens the world file in gazebo, 
		ii) sleeps for sometime  while the world loads
		iii) uses the meta map file to load the map in Rviz 
		iv) sleeps till the loading is done
		v) pick_objects and add_markers are run in their own respective windows and both packages collaborate to take the block from pickup to destinatin
   c. rvizConfig: Saved rvizConfig file for home_service, so there would be no need of resetting the config to view the service.
   d. add_markers: The Markers display allows programmatic addition of various primitive shapes to the 3D view by sending a visualization_msgs/Marker marker shapes to portray a cube. This cube disappears whenever the robot reaches the pickup point and reappears when the robot reaches the drop point.
   e. pick_objects: 2D motion of robot without manual intervention of Rviz tools. Pickup and Stop coordinates are assigned. The robot reaches the pickup first, stays there for a few seconds and travels to the stop location

