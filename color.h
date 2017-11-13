#ifndef COLOR_h
#define COLOR_H

/*
   Copyright(c) Charles Shapiro, October 2017
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

  Colors for the RGB LED.  
  Could eventually be generated from a spreadsheet if I can see that many different hues.
  NB that 0 is _brightest_, 255 is _off_
 */

struct color {
  int red_val;
  int blue_val;
  int green_val;
};

static color Colors[] = 
{
   {0,255,255}, // Red
   {0,0,255},    // Cyan
   {255,255,0}, // Green
   {255,0,0}, // Magenta
   {255,0,255},   // Blue
   {0,255,0}   // Yellow
//   {0,0,255},    // Cyan
//   {255,0,0},  // Magenta
//   {0,0,0}       // White
};


// static color * ColorP = Colors;
static int ColorSize = sizeof(Colors) / sizeof(struct color);

#endif

