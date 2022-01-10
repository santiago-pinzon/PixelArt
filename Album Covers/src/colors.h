/**
* handles the filling of the color matrix which determines which H value is used to generate colors for the board
* the board is an int[][] array that holds the H value used to calculate the color for that specific LED
*/
#include <cstdlib>
#include "constants.h"
#include "util.h"

class Colors {
    public:
        Colors(){
            // for(int i = 0; i < 8; i ++) {
            //     primaryPallet[i] = rand() % 360;
            // }
            // pickColors();
        }

        //Code for all the different color modes where the higher the average intensity the higher up the color is
        //Add implementation details based on how spencer wants this to work
        //TODO: change to take in queueitem
        void getColor(int colorMode, int avg, int* colorBoard) {
            switch(colorMode) {
                case RAINBOW:
                        for(int i = 0; i < width; i ++) {
                            for(int j = 0; j < height; j++) {
                                //colorBoard[i][j] = 75;
                                colorBoard[arrayIndex(i , j)] = (TICK + i * 2 ) % 360; 
                            }
                        }
                    break; 
                case DIAGONAL_RAINBOW:
                        for(int i = 0; i < width; i ++) {
                            for(int j = 0; j < height; j++) {
                                colorBoard[arrayIndex(i , j)] = (TICK + i * 2 + j) % 360; 
                            }
                        }
                    break; 
                case SINGLE_COLOR:
                        for(int i = 0; i < width; i ++) {
                            for(int j = 0; j < height; j++) {
                                colorBoard[arrayIndex(i , j)] = color1; 
                            }
                        }
                    break; 
                case SPLIT_HORIZONTALLY: {
                    int tempColor1 = color1;
                    constrain(tempColor1, horiz_gradient, 359 - horiz_gradient);

                    for(int i = 0; i < width / 2; i ++) {
                        double posRatio = pow((double) (width/2 - i) / (double) (width/2), num_panels_horiz + 1);
                        double shift = horiz_gradient * posRatio;
                        int toWrite = tempColor1 + shift;

                        for(int j = 0; j < height; j++) {
                            colorBoard[arrayIndex(i , j)] = toWrite;
                            colorBoard[arrayIndex(width - 1 - i, j)] = toWrite;
                        }
                    }
                    break;
                }
                case SPLIT_VERTICALLY:
                    int tempColor1 = color1;
                    constrain(tempColor1, vert_gradient, 359 - vert_gradient);

                    for(int j = 0; j < height/2; j ++) {
                        double posRatio = pow((double) (height/2 - j) / (double) (height/2), num_panels_vert + 1);
                        int shift = vert_gradient * posRatio;
                        int toWrite = tempColor1 + shift;

                        for(int i = 0; i < width; i++) {  
                            colorBoard[arrayIndex(i, j)] = toWrite;
                            colorBoard[arrayIndex(i, height - 1 - j)] = toWrite;
                        }
                    }
                    break; 

            }

        }

    int color1 = 0;
    int color2 = 0;
    int primaryPallet[max_colors];

    void pickColors() {
        color1 = primaryPallet[rand() % numColors];
    }

    void generateColors() {
        for(int i = 0; i < max_colors; i ++) {
            primaryPallet[i] = rand() % 360;
        }
    }

    void setColors(int* pallet) {
        memcpy(primaryPallet, pallet, max_colors * sizeof(int));
        for(int i = 0; i < max_colors; i ++) {
            //Serial.println(primaryPallet[i]);
        }

    }
};
