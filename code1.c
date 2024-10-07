
/* 
Name: Sina Asheghalishahi
KUID: 3127403
LAB Session: Wednesday 9 a.m.
LAB Assignment: 04
Description: Program takes in an NFL score and input, and prints all possible valid point
             combinations as output to terminal.
Collaborators: None
*/

#include <stdio.h>

void score_comb(int score){                 //score_comb func. declaration

    int td = 6, fg = 3, safety = 2, td_plus_2con = 8, td_plus_1fg = 7;      //initialization of pt values

    for (int a = 0; a <= score / td_plus_2con; a++){                        //Nested for-loop heuristically checks all possibl