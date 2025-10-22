int leds_Uno[] = {2, 3, 4, 5, 6, 7, 8};
int leds_Dos[] = {22, 23, 24, 25, 26, 27, 28};
int button_Uno = 9;
int button_Dos = 10;
int numbers = 0;
int digit_Array[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1},
};

void setup(){
  for(int i = 0 ; i < 7 ; i++){
    pinMode(leds_Uno[i], OUTPUT);
    pinMode(leds_Dos[i], OUTPUT);
  }

  pinMode(button_Uno, INPUT);
  pinMode(button_Dos, INPUT);
}

void segmentOutput(int pins[], int digit){
  for(int i = 0 ; i < 7 ; i++){
    digitalWrite(pins[i], digit_Array[digit][i]);
}
}

void loop(){
  if (digitalRead(button_Uno) == HIGH){
    numbers--;
    if (numbers < 0) numbers = 99;
    delay(150);
  }
  
  if (digitalRead(button_Dos) == HIGH){
    numbers++;
    if (numbers > 99) numbers = 0;
    delay(150);
  }
  
  int tens = numbers / 10;
  int ones = numbers % 10;

  segmentOutput(leds_Uno, tens);
  segmentOutput(leds_Dos, ones);
}

/*
a1= 2
a2= 3
a3= 4
a4= 5
a5= 6
a6= 7
a7= 8

button 1= 9
button 2= 10

b1= 22
b2= 23
b3= 24
b4= 25
b5= 26
b6= 27
b7= 28
*/