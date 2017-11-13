Compass_Rose

This is code to control an RGB LED with an HMC5883L chip.

I used the chip and carrier board sold by Marlin P Jones Inc (part #
31585 MP).  The Adafruit Sensor Library (
https://github.com/adafruit/Adafruit_Sensor ) to handle the interface
details.

My particular device put the LED on pins 9, 10, and 11, and the
compass on A4 (18) and A5 (19). The HMC5883 has a hard-coded I2C
address (0x1e), so you're going to have to do some fancy hardware stepping if
you want more than one controlled by a single Arduino or if you have
another device which also has that address.

The color values for the RGB are in "color.h".  Each color in the RGB
light has 255 brightness levels.  The compass gives about 2 degree
accuracy, so theoretically you could have up to 180 different colors
indicating directions.  I found that more than the basic 6 in the RGB
color scheme ( Red, Green, Blue, Yellow, Magenta, and Cyan ) were too
many for my eyes to distinguish.  Your mileage may vary.  Set up a
spreadsheet with the various RGB combinations, save it to a CSV, and
then use some basic text manipulation to fill the Colors array in
color.h if you wish to experiment further with this.

If you are using an RGB LED with a common cathode, 0 is brightest and
255 is off.  I suspect that common-anode RGB LEDs work the opposite
way (0 is off), but I don't have any of them around to test.

 Copyright (c) Charles Shapiro October 2017
 This file is part of the Compass Rose project

    Compass Rose is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Compass Rose.  If not, see <http://www.gnu.org/licenses/>.
