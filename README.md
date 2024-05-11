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

**Overall Evaluation**

Pawzzy was made to solve two problems: Cat boredom, and the guilt the owner feels when they know their cat has had nothing to do while they're gone. To fufill this goal, we had to make a robot that would be reliable both locally with the randomness of the cat and with the distance of the owner. Our robot has many traits that make it reliable, fun, and beneficial for everyone invovled. We made the robot chassis out of wood to give it a stable and study base. We gave it rubber feet for maximum stability, grip, turn resistence, and so it doesn't scratch any surfaces it is on. We gave it a light blue color of paint to make it visually appealing but also non-threatening. We rounded out the edges of the robot and smoothed over rough surfaces, so that it couldn't hurt anyone or anything brushing against it. Lastly, we use a simply ON/OFF control system for the user, so that the user is only encountered with simplicity and fun times, while the robot does all the hard work. Blynk is a reliable and trusted service that works very fast and reliably, and is very user friendly. 

**Output Display**

For the category Output Display, Pawzzy uses a single LED on the side of the frame to indicate when the robot has received the user's input. This allows for more understanding of the robot's status to the human, as the human knows that the robot has received the signal to activate. The L298N Motor controller also has an LED to display when power is turned on, but this is hidden from the human since the board is inside the box. 

**Manual User Input**

For the category Manual User Input, Pawzzy uses two different types of input: One through Blynk, where the user presses a digital button to activate the robot, and the other being a physical toggle switch on the side of the frame for controlling the 12V battery. The Blynk input is truly amazing as it allows the user to activate the machine from anywhere with an internet connection, which is perfect for when you are traveling and are away from your cat. At the airport, and want to make sure your cat is not bored? Simply go onto your phone, pressed the "ON" button, and forget about your worries.

**Automatic Sensor**

For the category Automatic Senor, Pawzzy an Ultrasonic Sensor, which when combined with a rotating servo gives the robot a sense of if the cat is close to the toy. This sensor senses distance, whcih we use to detect if the cat is close to the toy by closely aligning the senor and the toy. Using this input, the robot is able to move the toy away from the cat by itself, thereby making it harder and more engaging for the cat, as well as introducing more variables to make the moving process more random. 

**Actuators, Mechanisms, & Hardware**

For the category Actuators, Mechanisms, & Hardware, Pawzzy uses a total of 3 servos and one DC motor. These motors move the arm, move the ultrasonic sensor, and point the arm in the right direction. Each of these motors are aligned and placed so that they fufill their task accordingly, give precise positions, and are not moved under pressure. We use 3d prints for housing and placement, and we use wood for builds like the arm and the box that will be placed under stress, giving it a custom and fitting but rigid design. 

**Logic, Processing, and Control**

For the category Logic, Processing, and Control, Pawzzy uses a total of 3 boards, 2 with code in Arduino C++, 1 for controlling power and the DC motor: The Node ESP 8266 1.0, the Arduino Nano, and the L289N. Since Pawzzy is taking in a contant intake through the ultrasonic sensor and Blynk, it is important that the workload be split between 2 boards, so that one does not get clogged with data and that latency does not get in the way of executing crucial functions at certain times. Our boards are still able to communicate fast and efficiently through the Serial communication pins, where the position for the arm and the Ultrasonic Sensor is dicated by the ESP and received by the Nano, and all systems are able to use data from the others. Because of this two board system, we are able to use the constant input of the Ultrasonic Sensor to react quickly if there is a cat near the toy. The third board, the L289N, allows for us to draw power from a battery that we wouldn't have gotten from the nano or ESP themselves. 

### Parts List

### Lessons Learned

### Building Instructions


