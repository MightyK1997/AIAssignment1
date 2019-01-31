File Descriptions:
1. Boid.h and Boid.Cpp: Contains the Boid class and code for controlling the boid such as changing position, rotation and color or getting boid kinematic data. 
Also draws breadcrumbs on screen.
2. DataTypes.h and DataTypes.cpp: Contains the DynamicSteeringOutput, KinematicSteeringOutput structs and Kinematic class and related update code.
3. DynamicAlign.h and DynamicAlighn.cpp: Contains the DynamicAlign class and the GetSteering function definition and implementation.
4. DynamicArrive.h and DynamicArrive.cpp: Contains the DynamicArrive class and the GetSteering function definition and implementation.
5. DynamicLookWhereYouGo.h and DynamicLookWhereYouGo.cpp: Contains the DLookWhereYouAreGoing class and the GetSteering function definition and implementation.
6. DynamicSeperation.h and DynamicSeperation.cpp: Contains the DynamicSeperation class and the GetSteering function definition and implementation.
7. Flocking-behavior.h and Flocking-behavior.cpp: Contains the Flocking Class. It also contains the implementation of Flocking algorithm. This class also contains the boid data for
implementing Flocking.
8. KinematicSeek.h and KinematicSeek.cpp: Contains the KinematicSeek class and the GetSteering function definition and implementation.
9. main.cpp: Default cpp file associated with openframeworks
10. ofApp.cpp: Default cpp file associated with openframeworks. Calls the update and draw functions of different algorithm implementations. Also
handles logic for switching betweeen different algorithms and handling mouse clicks.
11. ofApp.h: Default header file associated with openframeworks. Contains the algorithm objects created.
12. Seek-Steering-Arrive.h: Contains the SeekSteeringArrive class and corresponding function definitions including constructors, destructor and Update and Draw functions.
which is used to implement the click to move seek steering behavior. The update function calls the corresponding steering behaviors. 
13 Seek-Steering-Arrive.cpp: Contains the implementations of functions such as Update and Draw.
14. Wander-Steering-Dynamic.h: Contains the WanderDynamic class, which is used to implement the wander behavior. Contains definitions of constructors and Update and Draw.
15. Wander-Steering-Dynamic.cpp: Contains the implementations of Update and Draw functions of WanderDynamic class.
16. Wander-Steering-Kinematic.h: Contains the WanderKinematic class, which is used to implement the wander behavior in kinematic. Contains definitions of constructors and Update and Draw.
17. Wander-Steering-Kinematic.cpp: Contains the implementations of Update and Draw functions of WanderKinematic class.
18. Basic-motion.h:Contains the BasicMotion class and function definitions. Used to implement the basic motion of moving around the screen.
19. Basic-Motion.cpp: Contains the function implementations of BasicMotion class.
20. DynamicFace.h and DynamicFace.cpp: Contains the DynamicFace class and Get steering function and implementation.
21. DynamicSeek.h and DynamicSeek.cpp: Contains the DynamicSeek class and Get steering function and implementation.
22. DynamicVelocityMatch.h and DynamicVelocityMatch.cpp: Contains the VelocityMatch class and Get steering function and implementation.
23. DynamicWander.h: Contains the DynamicWander class and also contains the details of various offsets used for wander.
24. DynamicWander.cpp: Contains implementation of GetSteering for DynamicWander class.



Special Instructions for compilation: None