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
* A0->3
* A3->12
* A3->A1
* A0->A4

## DIRECTIONAL PADS:
When a directional pad is stepped on, the following pins become connected *in both directions*
 * Top Right: 2 <-> 6
 * Top : 4 <-> 7
 * Top Left: 2 <-> A2
 * Left: 8 <-> 10
 * Right: 7 <-> 11
 * Down 5 <-> 8

Note that there are several common pins that are shared (this may not initially appear obvious, since the code output will always list lower-numbered pins first) - 2, 7, 8 are shared by the buttons inputs, while A0 are A3 are shared by the high side of the LEDs. With some rearrangement, we can deduce the following:

2, 7, 8 = GND
6 = Top-right
4 = Top
A2 = Top-left
10 = Left
11 = Right
5 = Down

A0, A3 = +V
3, 12, A1, A4 = pull-down to GND to light LEDs
