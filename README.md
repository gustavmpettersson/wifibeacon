# wifibeacon

MHacks8 2016 :)
## Inspiration
Attach the WiFi beacon to devices you keep loosing, maybe your purse? When lost activate the beacon by going to a webpage and lights and sounds will help you locate the device.

## What it does
Put it in any item you wish not to loose. If lost go to the associated webpage and activate the alarm to locate your stuff.

## How I built it
The hack is built with the MHacks hackerboard based on the ESP8266 uProcessor and WiFi module. Simple Arduino code flashes lights and sounds a buzzer when activated. The alarm is deactivated by the onboard button. 
  The project is based on the tutorial by the MHacks team at: http://mhacks.github.io/

## Challenges I ran into
After having completed the basic hardware and software to make the alarm work when tethered to the computer the next step was to go wireless. Frustratingly, the wifi at the venue caused problems all the time. This version definitely works in the serial (tethered) mode and hopefully in the wireless mode, but this is not verified due to these issues :/ 

## Accomplishments that I'm proud of
We managed to get the hackerboard to do the alarm tasks we wanted and demonstrated (intermittent) wifi functionality as well.

## What I learned
If you want to work with hardware at a hackathon, come prepared with a plan and a team. Trying to wing it will not work especially your first time! Hardware is hard

## What's next for WiFi beacon
The plan of what to do initially, which can hopefully be accomplished in the future:
- Verify WiFi verison works
- Automatically connect to open WiFi networks (for travel use)
- Program to easily change the webpage that triggers the beacon to go off
