This is the Linux release V3.2.3 rev4 64bit (Ubuntu 14.04.1)

****************************
****************************
FROM THE COMMAND LINE, run

$ ./vrep.sh 

to launch V-REP
****************************
****************************



**********************************
Various issues you might run into:
**********************************

1. When trying to start V-REP, following message displays: "Error: could not find or correctly load the V-REP library"
	a) Make sure you started V-REP with "./vrep.sh" FROM THE COMMAND LINE
	b) check what dependency is missing by typing "ldd libv_rep.so"

2. The remote API plugin doesn't load.
	a) Make sure the file libv_repExtRemoteApi.so is located in the V-REP directory
	b) check what dependency is missing by typing "ldd libv_repExtRemoteApi.so"

3. You are using a dongle license key, but V-REP displays 'No dongle was found' at launch time.
	a) See below



***************
Using a dongle:
***************

There are 2 methods to have the dongle recognized by V-REP:

1. With super-user rights (V-REP's user interfaces will slightly look different):
	a) $ sudo -E ./vrep.sh

2. Without super-user rights:
	a) $ lsusb
	b) Make sure that the dongle is correctly plugged and recognized (VID:1bc0, PID:8100)
	c) $ sudo cp 92-SLKey-HID.rules /etc/udev/rules.d/
	d) Restart the computer
	e) $ ./vrep.sh

When the dongle is detected by V-REP, it should flash

