# wifibeacon

MHacks 16:
## Inspiration
Attach the WiFi beacon to devices you keep loosing, maybe your purse? When lost activate the beacon by going to a webpage and lights and sounds will help you locate the device.

## What it does
Put it in any item you wish not to loose. If lost go to the associated webpage and activate the alarm to locate your stuff.

## How I built it
The hack is built with the MHacks hackerboard based on the ESP8266 uProcessor and WiFi module. Simple Arduino code flashes lights and sounds a buzzer when activated. The alarm is deactivated by the onboard button. 

## Challenges I ran into
After having completed the basic hardware and software to make the alarm work when tethered to the computer the next step was to go wireless. Frustratingly, the wifi at the venue caused problems all the time, and it made it impossible for me to complete the hack.

## Accomplishments that I'm proud of
I managed to get the hackerboard to provide the functionality I wanted in terms of the alarm system.

## What I learned
If you want to work with hardware at a hackathon, come prepared with a plan and a team. Trying to wing it will not work especially your first time!

## What's next for WiFi beacon
The plan of what to do initially, which can hopefully be accomplished in the future:
- Cut the cord by replacing the serial communication with WiFi
- Automatically connect to open WiFi networks (for travel use)
- Respond to webpage with ssid of networked connected to when disabled (recognize friend's ssid if you left your stuff)
