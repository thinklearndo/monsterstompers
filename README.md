# Monster Stompers

Nodejs server files are located in monster_stompers_server_files folder.

For the nodejs server, you will need to install play-sound:

 ```npm install play-sound```

Then you can run it with: 

```nodejs app.js```

Nodemcu files are located in the monster_stomper_mcu folder.

The following items will need to be changed for your setup in the monster_stomper_mcu.ino:

```serverIp``` - needs to be set to the ip address of the computer running the nodejs server.

```wifiName``` - needs to be changed to the wifi network name that you want the nodemcu to connect to, must be a 2.4 ghz wifi network.

```wifiPassword``` - needs to be changed to the wifi password.

Make sure the tilt switch has one leg connected to the pin labeled D1, and the other leg connected to ground.

The stomp.mp3 I got from http://soundbible.com/1721-Godzilla-Walking.html

