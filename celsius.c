#include <stdio.h>
#include <stdlib.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main(int argc, char *argv[])
{
  float fahrenheit, celsius;
  fahrenheit = atof(argv[1]);
  printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
  celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;

  printf("Celsius equivalent: %.2f\n", celsius);

  return 0;
}