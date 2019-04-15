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

// Update for Path Finding

1. Boids/AStarPathFollow.h and cpp : Contains the Implementations of Draw and Update function for boids. Also contains functions to change the path follow heuristics and whether to use the grid or not.
2. DataTypes/DataTypes-PathFinding.h : Contains the Structs for Node, NodeRecord, DirectedWeightedEdge, Path and Heuristics. Also contains the enum specifying the different heuristics that are supported.
3. Movement/DynamicPathFollow.h and cpp : Contains the DynamicPathFollow class used to implement Dynamic path follow.
4. PathFinding/Algorithms/Dijkstra.h : Contains the definition for the AStar class, which is used to implement both AStar and Dijkstra.
5. PathFinding/Algorithms/Dijkstra.cpp : Contains the implementation of GetPath function for AStar which is used to get Path from either a Graph or Grid. Also contains helper functions to work with vectors.
6. PathFinding/Graph/Graph.h and Graph.cpp: Contains the Graph class which is used to implement the Graph for AStar.
7. PathFinding/Graph/Grid.h and Grid.cpp: Contains the Grid class which reads in a black and white image file and quantizes it into tiles.


//Update for Decision and Behavior Trees
1. Action.h and Action.cpp : Contains details about a particular action including queued time, expiry time and priority.
2. ActionManager.h and cpp : Is the main class which manages all the queued and active actions based on their priority and if they can interrupt each other.
3. ActionNode.h and cpp: Derives from DecisionTreeNode. Used as a leaf node for DecisionTrees, it contains the action that that node can perform which is invoked from action manager.
4. ActionTask.h and cpp: The behavior tree equivalent of ActionNode.
5. AI.h and cpp: The AI manager class for each type of AI in the world.
6. BehaviorTree.h and cpp: Contains the definition and implementation of the behavior tree.
7. Blackboard.h and cpp: Contains the definition and implementation of Blackboard which is used to share data in the behavior tree.
8. BooleanTask.h and cpp: Contains the definition and implementation of a boolean node. The boolean node is similar to a decision node in that it has two branches.
9. DecisionMakingBehavior.h: Is the base class for both decision tree and behavior tree.
10. DecisionNode.h and cpp: Is the node that makes decisions in the decision tree.
11. DecisionTree.h and cpp: Contains the definition and implementation of the decision tree.
12. DecisionTreeNode.h: Is the base class for allthe nodes in decision tree.
13. GameManager.h and cpp: Is the manager for all game data and keeps track of the players and AI.
14. Inverter.h and cpp: Inverts the input it gets from the nodes below it.
15. Selector.h and cpp: Implementation of the selector node.
16. Sequencer.h and cpp: Implementation of sequencer node/
17. Task.h: Base class of all tasks in behavior trees.
18. Tick.h: Used to share data between behavior tree and blackboard.
19. BehaviorTreelearning/Entropy.h and cpp: Contains the definitions and implementations of various functions used to calculate entropy and create the behavior tree.
20. Example.h: Contains the implementation of example class.


Link to post:
http://sai-upadhyayula.com/2019/04/14/decision-and-behavior-trees/



Special Instructions for compilation: 1. Requires openframeworks to be installed in the destination computer.
2. Copy "AIAssignment1" folder to openframeworks_path\apps\MyApps