const int a = 2; 
const int b = 3; 
const int c = 4; 
const int d = 5;
const int e = 6;
const int f = 7; 
const int g = 8; 

bool bPress = false;
const int buttonPin = 10;


int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     

void setup() {
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode( buttonPin , INPUT_PULLUP );
  Serial.begin(9600);
  displayDigit(buttonPushCounter);
}

void loop() {
   buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    
    if (buttonState == LOW) {
      bPress = true;
      buttonPushCounter++;
      if( buttonPushCounter > 9) buttonPushCounter =0 ;
      Serial.println("on");
    
    } else {
      Serial.println("off");
    }
    delay(50);
  }

  lastButtonState = buttonState;
  if( bPress ){
     turnOff();
     displayDigit(buttonPushCounter);
  }
}

void displayDigit(int digit){
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 if(digit !=2)
 digitalWrite(c,HIGH);

 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);

 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
}
void turnOff(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

/*
a= 2
b= 3
c= 4
d= 5
e= 6
f= 7
g= 8
button= 10
*/