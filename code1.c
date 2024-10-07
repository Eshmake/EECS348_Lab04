
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

    for (int a = 0; a <= score / td_plus_2con; a++){                        //Nested for-loop heuristically checks all possible point
        for (int b = 0; b <= score / td_plus_1fg; b++){                     //combinations by iteratively incrementing number of each 
            for (int c = 0; c <= score / td; c++){                          //pt category from largest to smallest by 1, and comparing 
                for (int d = 0; d <= score / fg; d++){                      //resulting sum with given score.
                    for (int e = 0; e <= score / safety; e++){

                        int pts = (a*td_plus_2con) + (b*td_plus_1fg) + (c*td) + (d*fg) + (e*safety);

                        if(pts == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);        //current combination is printed if matches score
                        }
                    }
                }
            }
        }
    }
}

int main(){             //main func. declaration

    int score;

    printf("Enter 0 or 1 to STOP\n");       
    printf("Enter the NFL score: \n");

    while(score >= 2) {
        scanf("%d", &score);        //input collection

        if (score < 2) {            //termination case
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d: \n", score);     
        score_comb(score);      //output generation
        printf("\n");
    }

    return 0; 
}
