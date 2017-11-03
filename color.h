#ifndef COLOR_h
#define COLOR_H
/*
color.h file. Eventually to be auto-generated from spreadsheet.
 */

struct color {
  char color_name[15];
  int red_val;
  int blue_val;
  int green_val;
};

static color Colors[] = 
{
  {"Red",0,255,255},
  {"Green",255,255,0},
  {"Blue",255,0,255},
  {"Yellow",0,255,0},
  {"White",0,0,0},
  {"Cyan",0,0,255},
  {"Magenta",255,0,0}
};
// static color * ColorP = Colors;
static int Color_size = sizeof(Colors) / sizeof(struct color);
#endif

