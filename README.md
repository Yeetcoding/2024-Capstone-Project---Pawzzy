**2024 Capstone Project**

# **PAWZZY**

< insert title photo here >

**By Chase Smith and Lincoln Willison**

May 15th, 2024

### Project Overview

This robot, named *Pawzzy*, is meant to entertain your cat while you, the owner, are away. One simple tap on your phone, and you don't have to worry about your cat 
feeling lonely! As you would with a cat toy, this machine takes a toy on a string, launches it, and then moves it around for the cat to try to catch. 

As shown in fig.1, the robot has a launch arm, where the toy is attached to moving reel. Like a fishing rod, this arm rotates forward very fast, and the reel is turned on so that the 
toy is launched at a desired distance. 

< insert fig.1 (launch arm) here >
*Fig. 1*

Then the toy is slowly reeled in as the arm is moved around on the rotating plate, shown in fig.2.

< insert fig.2 (rotating plate) here >
*Fig. 2*

As the toy is being reeled in, the Ultrasonic Sensor at the bottom of the box shown in fig.3 moves close to the direction of the toy, so that if the cat gets close the toy can react and make 
it harder for the cat.

< insert fig.3 (Ultrasonic Sensor) here >
*Fig. 3*

### System Details

The Robot consists of 2 main systems, the Throwing System and a Detection System. As shown in fig.4, the Throwing System consists of the Arm System, The Reel System, and the Turntable, while the Detection System consists of the Distance Sensor and the Servo with it. The Throwing System is responsable for throwing, reeling in, and moving the cat toy, whereas the Detetion System is responsible for detecting the cat and initiating an appropriate response to with the rest of the machine.

![Final_Drawing_Overveiw](https://github.com/Yeetcoding/2024-Capstone-Project---Pawzzy/assets/77801962/061eaaa7-deee-4a4c-ae49-4577d6c37f84)
*Fig.4*

The software for the project is written in Arduino C++, and it used with 2 microcrontrollers, the Node ESP-8266 1.0 and the Arduino Nano. The ESP is used to receive signals from the phone controller of the user and activate the system, as well as control the arm. Fig.5 shows the process and logic implimented in the ESP. 

![Pawzzy_FlowC_Transm](https://github.com/Yeetcoding/2024-Capstone-Project---Pawzzy/assets/77801962/dcd4d221-0082-4c01-916b-117aa6a327fc)

*Fig.5*

The Nano is in charge of intaking data from the Detection system and moving the sensor and arm point in the right direction, to help avoid the cat and moce the toy around. Fig.6 shows the process and logic implimented in the Nano, as well as how it makes decisions based on input.

![Pawzzy_FlowC_Receiver](https://github.com/Yeetcoding/2024-Capstone-Project---Pawzzy/assets/77801962/5c467d43-5346-45a2-b94f-f99de2aaa4d5)

*Fig.6*

The Arm Servo is connected to the ESP for control and the 12V battery for power. The Reel Motor is connected to the L289N Motor Control Board, which is controlled by the ESP and is powered by the 12V battery. The LED is connected to the ESP to show the received "ON" signal. The Distance Sensor, Arm Point servo, and Sensor servo are all controlled and powered by the Arduino Nano. Both boards are powered by power cables that plug into an extension cable, which plugs striaght into the wall. The two boards share a Serial connection over the ESP's TX (1) pin, the Nano's RX (0) pin, and a shared ground. All of the electronic wiring is shown on fig. 7. 

![IMG_3379](https://github.com/Yeetcoding/2024-Capstone-Project---Pawzzy/assets/77801962/adf66dbe-9762-46b7-8617-3a395ed4b5d2)

*Fig.7*


### Design Evaluation

### Parts List

### Lessons Learned

### Building Instructions


