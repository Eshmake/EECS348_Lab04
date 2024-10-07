
/* 
Name: Sina Asheghalishahi
KUID: 3127403
LAB Session: Wednesday 9 a.m.
LAB Assignment: 04
Description: Program takes in temp. value, temp. scale, and conversion target as input,
             and produces converted temp., temp. classification, and weather advisory as output.
Collaborators: None
*/

#include <stdio.h>

float celsius_to_fahrenheit (float celsius){            //conversion functions declared
    return (9/5.0)*celsius + 32;
}

float fahrenheit_to_celsius (float fahrenheit){
    return (5/9.0)*(fahrenheit-32);
}

float celsius_to_kelvin (float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius (float kelvin){
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin){
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}


int main(){             //main func. declared

    float initial_temp;         //var. declaration
    float final_temp;
    int initial_scale;
    int final_scale;

    int check1, check2, check3;


    while(!check1 || !check2 || !check3){           //while inputs are invalid, input collection process repeats

        
        printf("Enter the temperature: \n");        //input collection
        scanf("%f", &initial_temp);
        
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        scanf("%d", &initial_scale);

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        scanf("%d", &final_scale);

        if(1 <= initial_scale && initial_scale <= 3){check2 = 1;}           //checks if initial scale is in valid range

        if((1 <= final_scale && final_scale <= 3) && initial_scale != final_scale){check3 = 1;}     //checks if final scale is in valid range, and is not equal to initial scale

        if(initial_scale != 3 || (initial_scale == 3 && initial_temp >= 0)){check1 = 1;}        //checks for neg. kelvin

        if(!check1){printf("Invalid temperature entered. \n\n");}           //error messages printed based on check values
        if(!check2){printf("Invalid current scale entered. \n\n");}
        if(!check3){printf("Invalid conversion scale entered. \n\n");}

    }


    if(initial_scale == 1){                 //conversion is made based on initial and final scales
        if(final_scale == 2){
            final_temp = celsius_to_fahrenheit(initial_temp);
        }
        else{
            final_temp = celsius_to_kelvin(initial_temp);
        }
    }
    else if(initial_scale == 2){
        if(final_scale == 1){
            final_temp = fahrenheit_to_celsius(initial_temp);
        }
        else{
            final_temp = fahrenheit_to_kelvin(initial_temp);
        }
    }
    else{
        if(final_scale == 1){
            final_temp = kelvin_to_celsius(initial_temp);
        }
        else{
            final_temp = kelvin_to_fahrenheit(initial_temp);
        }
    }

    float class_temp;

    switch (final_scale)        //converted temp. printed w/ correct units
    {
    case 1:
        printf("Converted temperature: %.2fºC\n", final_temp);
        class_temp = final_temp;
        break;
    case 2:
        printf("Converted temperature: %.2fºF\n", final_temp);
        class_temp = fahrenheit_to_celsius(final_temp);
        break;
    case 3:
        printf("Converted temperature: %.2fK\n", final_temp);
        class_temp = kelvin_to_celsius(final_temp);
        break;
    }

    if(class_temp < 0){                 //converted temp. changed to celsius, and used to print corresponding temp. category and advisory messages
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Stay indoors\n");
    }
    else if(class_temp < 10){
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a jacket\n");
    }
    else if(class_temp < 25){
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: You should feel comfortable\n");
    }
    else if(class_temp <= 35){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Apply sunscreen and drink water\n");
    }
    else{
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors\n");
    }

    
    return 0;
}

