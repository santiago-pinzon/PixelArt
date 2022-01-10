//Holds any and all constants deemed useful for whatever.
//Organize by purpose
#ifndef CONSTANTS
#define CONSTANTS

#define ROWS 16 // defines the dimensions of a single panel
#define COLS 32 // ^^^^

#define NUM_FFT_BINS 512      // Defines the number of bins we are currently collecting from FFT

//Color Generation Constants
#define NUM_COLOR_MODES 5
#define RAINBOW 0
#define DIAGONAL_RAINBOW 1
#define SINGLE_COLOR 2
#define SPLIT_HORIZONTALLY 3
#define SPLIT_VERTICALLY 4 
#define JAN 5

#define NUM_VIEW_MODES 5
#define SINGLE_VIEW 5
#define DIAMOND 2
#define STARDUST 0
#define JAWS 1
#define INVERSE 3
#define STROBE 6
#define ROTATE 4 
#define PYRAMID 7 
#define STARDUSTCENTER 8 // can't change the colormode (or at least shouldnt be able to)
//#define KUTIE 7
//#define OSCILLOSCOPE // idk if we can do this but it would be fun


// stuff related to operations

int num_panels_vert = 1;
int num_panels_horiz = 1;
bool stereoAudio = false;
int height = num_panels_vert * 16;
int width = num_panels_horiz * 32;
int vertical_midpoint = height / 2;
int horizontal_midpoint = width / 2;
int num_leds_vert = 16;
int bass_index = 3;                                 //Bass end index
int mid_index = horizontal_midpoint / 2;      //Mid range end index


int TICK = 0; // loops every 256 values, useful since same number of hue options



//View modes, enable or disable
//index corresponds to viewmode constant

bool viewModes[8] = {true, true, true, true, true, false, false, false};
 
// Color modes, enable or disable
//index corresponds to viewmode constant
bool colorModes[6] = {false, false, false, true, true, false};
int horiz_gradient = 40;
int vert_gradient = 40;


// 1 = paused, 0 = not paused
// move with on/off
const int pause = 0;

// no idea what this should be, play around with it
const int tickDelay = 100;
unsigned long queueDelay = 10000;

#define KATIE 1


// Board defaults
int numColors = 5;                  // The number of colors we should pick from, ie. 3 means pick from colors 0-2
const int max_colors = 5;            // The max amount of colors allowed
double modeUpdate = 50;             // Minimum time between mode changes
int colorUpdate = 5000;             // Minimum time between color changes
double brightnessScale = 4;       // Brightness value (0-6ish)
unsigned long strobeDelay = 50;     // Time between strobe flashes
bool onOff = true;                  // Bool for if the board is on  
bool strobeOnOff = false;           // Bool for if the strobe light is on
bool flameOnOff = false;            // Bool for if the fire animation is on
int strobeColor = 0;                // 0 is white, 1 is red, 2 is green, 3 is blue
double alpha1 = .7;                // Base smoothing amount (0-1.0)
double alpha2 = .1;                // Mids smoothing amount (0-1.0)
double alpha3 = 1000;                // Base smoothing amount (0-1.0)

int dataSpacingMode = 0;            // Chooses how the raw fft data should be fit into the display data
                                    // 0 is even slices of data, 1 is averaged slices, 2 is log scale

bool displayText = false;            // Are we currently displaying text
bool ret = false;
unsigned long textTime = 0;
const char* words = "hey jan";
int textOffset = width - 7;

//ViewMode Constants
/**
 * TODO: FIgure out fucking names
 */


#endif
