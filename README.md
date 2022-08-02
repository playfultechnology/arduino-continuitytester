# arduino-continuitytester
An Arduino sketch to assist in determining continuity and connectivity of pins of an arbitrary interface

# Example:
I needed to work out how to use a Dance Dance Revolution dancemat as an input to my Arduino.
It has both button inputs for each of the directions, but also lights under each pad.

![DDR Mat](https://github.com/playfultechnology/arduino-continuitytester/blob/main/ddr_mat.jpg)

The mat had a female DE-15 connector (i.e. a VGA connector), so I bought a breakout board (like this one https://www.amazon.co.uk/sourcing-map-Connector-Solderless-Positioning/dp/B07MQSKL9L/ ), and connected all the wires to pins on an Arduino Nano, then ran the sketch. The output was as follows:

## DEFAULT:
The following pins were always connected, *but only in one direction*.
Suggests that there is a diode - perhaps a light-emitting diode (LED) - between them...
 * A2->10, 
 * A5->A1, 
 * A2->3, 
 * A5->A3

## DIRECTIONAL PADS:
When a directional pad is stepped on, the following pins become connected *in both directions*
We can see some common pins: 2, 7, 8 - these could be ground
 * Top Right: 2 <-> 6
 * Top : 4 <-> 7
 * Top Left: 2 <-> A0
 * Left: 8 <-> 11
 * Right: 7 <-> A4
 * Down 5 <-> 8
