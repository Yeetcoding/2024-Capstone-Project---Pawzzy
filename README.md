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

For the category Output Display, Pawzzy uses a single LED on the side of the frame to indicate when the robot has received the user's input, as shown in Fig.8. This allows for more understanding of the robot's status to the human, as the human knows that the robot has received the signal to activate. The L298N Motor controller also has an LED to display when power is turned on, but this is hidden from the human since the board is inside the box. 

< insert Fig.8 (LED) here >
*Fig.8*

**Manual User Input**

For the category Manual User Input, Pawzzy uses two different types of input: One through Blynk (shown in Fig.9), where the user presses a digital button to activate the robot, and the other being a physical toggle switch on the side of the frame for controlling the 12V battery. The Blynk input is truly amazing as it allows the user to activate the machine from anywhere with an internet connection, which is perfect for when you are traveling and are away from your cat. At the airport, and want to make sure your cat is not bored? Simply go onto your phone, pressed the "ON" button, and forget about your worries.

< insert Fig.9 (Blynk Screenshots) here >
*Fig.9*
< insert Fig.10 (Toggle Switch) here >
*Fig.10*

**Automatic Sensor**

For the category Automatic Senor, Pawzzy uses an Ultrasonic Sensor, as shown in Fig.11. When combined with a rotating servo, this sensor gives the robot a sense of if the cat is close to the toy. This sensor senses distance, which we use to detect if the cat is close to the toy by closely aligning the senor and the toy. Using this input, the robot is able to move the toy away from the cat by itself, thereby making it harder and more engaging for the cat, as well as introducing more variables to make the moving process more random. 

< insert Fig.11 (Ultrasonic Sensor) here >

**Actuators, Mechanisms, & Hardware**

For the category Actuators, Mechanisms, & Hardware, Pawzzy uses a total of 3 servos and one DC motor, which are all shown in Fig.12. These motors move the arm, move the ultrasonic sensor, and point the arm in the right direction. Each of these motors are aligned and placed so that they fufill their task accordingly, give precise positions, and are not moved under pressure. We use 3d prints for housing and placement, and we use wood for builds like the arm and the box that will be placed under stress, giving it a custom and fitting but rigid design. 

< insert Fig.12 (Servos and Motors) >

**Logic, Processing, and Control**

For the category Logic, Processing, and Control, Pawzzy uses a total of 3 boards, 2 with code in Arduino C++, 1 for controlling power and the DC motor: The Node ESP 8266 1.0, the Arduino Nano, and the L289N, all of which are shown in Fig.13. Since Pawzzy is taking in a contant intake through the ultrasonic sensor and Blynk, it is important that the workload be split between 2 boards, so that one does not get clogged with data and that latency does not get in the way of executing crucial functions at certain times. Our boards are still able to communicate fast and efficiently through the Serial communication pins, where the position for the arm and the Ultrasonic Sensor is dicated by the ESP and received by the Nano, and all systems are able to use data from the others. Because of this two board system, we are able to use the constant input of the Ultrasonic Sensor to react quickly if there is a cat near the toy. The third board, the L289N, allows for us to draw power from a battery that we wouldn't have gotten from the nano or ESP themselves. 

< insert Fig.13 (Boards) >

**Additonal Adjustments**

When designing this, we made sure to do some thinking about how we would put everything together, instead of just throwing it all into a box. We use wood to make a rigid structure, and sand down the edges to make a good and quality feel. We soldered all of the wire joints and components together, so that the internal structure would have a reliable electrical system. We also put thought into the color of our paint - when researching a color that cats like, we found that blue was a common one. We picked our robot to have that blue for its inviting and friendly appeal, so that it would look good to the cat but also the human. We also made sure that the structure and construction of this project would ensure that the different components would work together flawlessly, which it does, as no wires get in the way of the sensor or turntable, and each moving part moves freely without any unecessary friction, and has the suppor that it needs to remain reliable. We are also able to make all of this at a reasonable price, and have no issues with running too close to the budget limit.

Because of the above reasons, we believe we qualify for these additives:
  - +10% for Construction, Quality, Aestetics, and Visual Appeal
  - +10% for Level of Effort
  - +10% for Construction/Production Cost

### Parts List
- Acrylic Disk, $4.50
- Servo (x3), $13.50
- Node ESP 8266 1.0, $5.00
- Arduino Nano, $6.5
- L289N Motor Controller, $3.00
- DC Motor, $1.40
- Solder Board (x2), $4.4
- Door Hinge, $1.16
- Battery Pack, $6.00
- Plywood, $10
- Marble (x3), $0.30
- Ultrasonic Sensor, $1.80 

### Lessons Learned

- **Beware of the data input from the Ultrasonic Sensor**: During both of our previous capstone projects, we learned how constantly using ultrasonic sensors in a project bog down the time efficiency of the microcontrollers, so we made sure to institute a system that would be able to handle this situation.
- **You can speed up motors with a higher power source but still control it with a microcontroller**: When trying to make the arm servo go faster in order to launch the toy, Chase figured out that if you connect the ground of the Arduino and Power source together and attach the servo's data pin to the Arduino, you can control the servo but it will go significantly faster.
- **Plan out your work schedule and what you are going to make ahead of time**: Both of us have benefited from planning ahead of time what each of us will do with the time we have. In each of our own previous capstone projects, neiter of us planned ahead and barely got work done in time, but this year we were able to work efficiently both as a tem and as individuals because of our planning.
- **Take things step by step**: A concept that is often reiterated throughout all of engineering, it applies also to our situation. The software itself is complex and can get very confusing, so taking it step by step deliberately (especially the very small steps, such as simple Serial communication over a wire or hooking up a servo by itself) and not rushing ahead really helped to make sure all of the "foundations" were sound.
- **Pick a nice color of paint. Make it look 'perty**: Something that we both liked is how well our project looked when we finshed, especially after we put serious thought and effort into what we'd like it to look like. Making it look better, regardless of functionality (but not at the cost of), made us appriciate it more and make it look more friendly and awesome. This was a big difference from our past projects, as our previous projects looked more 'thrown' together than 'put' together.
- **Help others when you can**: Working in a robotics classroom environment like the one in Windosr helps you be around many different people with the same mindset, which means you can have many different opportunities to learn outside/other than the typical lecture to assignment structure. Being able to help others gives you a break from working on your project, gives you a look at other cool projects, and helps you form connections that might pay off later. After all, we know that we appreiciate a helping hand, so why not be that helping hand for another when you can?
- **Don't be a wimp - find a good partner**: Having a good partner changes the game with these capstone projects, as you can get a second view on the project instanly but you can also split the workload with your other partner. Even if you think you can do great yourself, you can do double with a good partner. Both of us chose to go solo with our previous projects, and work together for this one, and the difference is huge because both of us put pour best foot forward and worked hard together. Having a partner is definitely the best choice if you can find a good one. 

### Building Instructions

**If for some reason you've read through all of this and decided you want a crack at making Pawzzy, here are some "simple" steps to guide you along the way:**
1. 



