2024-Capstone-Project---Pawzzy

Pawzzy

By Lincoln Willison and Chase Smith



















Overview

Pawzzy will be an automated cat entertainment system, designed to eliminate your cat’s boredom while you are gone. The system timing will be determined based on a simple user input in the form of a timer. Once the desired time set by the human is reached, the cat toys will activate. 
	Pawzzy will consist of 4 different systems, The Arm toy, the Laser, the Obstacle Detection System, and the Treat Dispenser, each working together to entice and entertain the cat. The central box, where all of the components will be housed, will be made of either wood, cardboard, or foam with weights on the bottom so that it won't move around during its session.  

Fig. 1

	The Arm Toy will be the main attraction, as it will control the toy that the cat chases. It will be rotated on 2 axes controlled each by a servo motor, so it could move up, down, left, and right, as shown in Fig 2. There will also be a reel controlled by a motor to control the reach of the toy, also shown in Fig 2. This reel will work in function with the arm to cast out the toy like a fishing line, then reel the toy in as the code dictates. The reel motor will also have an encoder, so that when the reel cannot reel in the toy if the cat captures the toy, the Arduino will know and can make decisions based off of that. 

Fig 2

	The Laser will be a separate system that is also controlled by two servos. The laser will be mounted on the two servos and point to various spots on the ground, as shown in Fig 3.


Fig 3

	The Obstacle detection system will be composed of an ultrasonic sensor and a servo. The servo will move the sensor in a semicircle, and the data collected from the sensor will be inputted into the Arduino. We have not yet determined where the sensor will be on the body, as the answer is better decided on testing.
The Treat Dispenser will dispense treats based on what happens to the toy, and how many treats the cat has already gotten. It will be controlled by a servo.  


Fig 4
Components:

________________________________
Key:
Red: Output Display
Blue: Manual User Input
Orange: Automatic Sensor
Green: Actuators, Mechanisms and Hardware
Yellow: Logic, Processing, and Control
_____________________________________

Arduino Mega - to provide and execute the code of the project
Laser Diode - to make a laser that the cat chases
Wood/foam/cardboard - for the structure of the box
3d Print Filament - for the arm, spool, internal and external structure
6 small servo motors - 2 for the Arm, 2 for the laser, one for the distance sensor, and 1 for the treat dispenser
Small DC motor with encoder - for controlling the string attached to the arm and knowing when the cat has captured the toy
Buttons - for time input and input from the cat
LED’s - indicators for the working status of the machine, mode, and if toy has been captured
Ultrasonic Sensor - for sensing objects that might obstruct the toy throws
Buzzer - to signal accepted inputs (ei. Timer button pressed), signaling the capture of the toy, and the dispense of a treat

