# Need4Stek

{EPITECH.} first year project.

C artificial intelligence that guides an autonomous car through a virtual racetrack.

<img alt="Need4Stek demo" src="/artwork/need4stek-demo.gif"/>

## Requirements

 - [A Linux distribution](https://en.wikipedia.org/wiki/Linux_distribution)
 - [Make](https://www.gnu.org/software/make/)
 - [GCC](https://gcc.gnu.org/)

## How to use Need4Stek?

 1. **Compile the AI**

Run this command from the root of the repository to build the `ai` executable:
```
make
```

 2. **Run V-REP 3.2.3**

A copy of V-REP for Linux 64-bits is available in the `V-REP_PLAYER_V3_2_3_rev4_64_Linux/` folder at the root of the repository. You can also download [V-REP 3.2.3 here](http://www.coppeliarobotics.com/previousversions.html).

To run V-REP 3.2.3, execute the `vrep.sh` Bash script.

If you're using the copy of V-REP shipped with Need4Stek, run this command from the root of the repository:
```
./V-REP_PLAYER_V3_2_3_rev4_64_Linux/vrep.sh
```

 3. **Import a scene**

Inside V-REP, go to `File` > `Open scene...` and import one of the scenes (`.ttt`) located in the `scene/` folder at the root of the repository. Each scene represents a racetrack.

 4. **Run the simulation**

Run this command from the root of the repository to run the simulation:
```
./pipes.sh
```

Then you can go back to the V-REP window and you will see the car making its way through the racetrack using our artificial intelligence.

## Authors

* **Benjamin Dubus** ([GitHub](https://github.com/dubus-b))
* **Ronan Boiteau** ([GitHub](https://github.com/ronanboiteau) / [LinkedIn](https://www.linkedin.com/in/ronanboiteau/))
* **Sélim Rinaz** ([GitHub](https://github.com/rinaz-a) / [LinkedIn](https://www.linkedin.com/in/selim-rinaz/))
