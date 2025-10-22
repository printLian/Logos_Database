byte pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
 
int number[10][8] = {
  {1,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},
  {1,1,1,0,0,0,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,0,1,1,0}
};
 
void setup() {
  for (byte a = 0; a < 8; a++) {
    pinMode(pin[a], OUTPUT);
  }
}
 
void loop() {
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 8; b++) {
      digitalWrite(pin[b], number[a][b]);
    }
    delay(500);
  }
}
/*
a= 2
b= 3
c= 4
d= 5
e= 6
f= 7
g= 8
decimal =9
A series 7 segment
resistor to ground
*/