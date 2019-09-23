/**
 * It measures the tempo as you tap the drum 
 * and shows BPM(Beats Per Minute) on the display
 * @author Keonwoong Min
 */
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 9; // change to 8 when you use regular one
const int dp = 10;

int x = 0;
int y = 0;
int z = 0;

int ON = HIGH;
int OFF = LOW;

const int digit1Power = A3;
const int digit2Power = A4;
const int digit3Power = A5;

//piezo
const int PIEZO_PIN = A1;

//potentiometer
int potenPin= A2;  
int readValue; 
int writeValue;

int BPM;

float time0;
float time1;
float tempTime = 0;
int num = 0;

float interval0 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(digit1Power, OUTPUT);
  pinMode(digit2Power, OUTPUT);
  pinMode(digit3Power, OUTPUT);
  pinMode(potenPin, INPUT);  //set potPin to be an input
}

void loop() 
{
  readValue = analogRead(potenPin);
  writeValue = (255./1023.) * readValue; 
  Serial.println(writeValue);
  float myTemp = analogRead(PIEZO_PIN);

  if(BPM == 999)
  {
    firstDigit(-1);
    delay(5);
    secondDigit(-1);
    delay(5);
    thirdDigit(-1);
    delay(5);
  }
  else
  {
    for(int i =0; i < 1; i++)
    {
      thirdDigit((BPM/ 1U) %10);
      delay(5);
      secondDigit((BPM/ 10U) %10);
      delay(5);
      firstDigit((BPM/ 100U) %10); // 100th 
      delay(5);
    }
  }

 if(analogRead(PIEZO_PIN) - myTemp > writeValue)
  {
    delay(80);
    tempTime = millis();
    num = num%2;
    if(num == 0)
    {
       num++;
       time0 = tempTime;
       interval0 = abs(time0 - time1);
    }
    else 
    {
      num++;
      time1 = tempTime;
      interval0 = abs(time1 - time0);
    }
    BPM = 60000/(interval0);   
    if(BPM > 260)
    {
      BPM = 999;
    }
    
    for(int i =0; i < 2; i++)
    {
      thirdDigit(-2);
      delay(5);
      secondDigit(-2);
      delay(5);
      firstDigit(-2); // 100th 
      delay(5);
    }
  }

}//loop()

void firstDigit(int x)
{
  digitalWrite(digit1Power,LOW);
  digitalWrite(digit2Power,HIGH);
  digitalWrite(digit3Power,HIGH);
  switch(x)
  {
    case -2:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,ON);
      break;
    case -1:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,ON);
      digitalWrite(dp,ON);
      break;
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      digitalWrite(dp,OFF);
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      digitalWrite(dp,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(dp,OFF);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
  }
}

void secondDigit(int y)
{
  digitalWrite(digit1Power,HIGH);
  digitalWrite(digit2Power,LOW);
  digitalWrite(digit3Power,HIGH);
  switch(y)
  {
    case -2:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,ON);
      break;
    case -1:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,ON);
      digitalWrite(dp,ON);
      break;
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      digitalWrite(dp,OFF);
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      digitalWrite(dp,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(dp,OFF);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
  }
}

void thirdDigit(int z)
{
  digitalWrite(digit1Power,HIGH);
  digitalWrite(digit2Power,HIGH);
  digitalWrite(digit3Power,LOW);
  
  switch(z)
  {
    case -2:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,ON);
      break;
    case -1:
      digitalWrite(a,OFF);
      digitalWrite(b,OFF);
      digitalWrite(c,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,ON);
      digitalWrite(dp,ON);
      break;
    case 0:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 1:
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 2:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(e,ON);
      digitalWrite(d,ON);
      digitalWrite(c,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 3:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,OFF);
      digitalWrite(f,OFF);
      digitalWrite(dp,OFF);
      break;
    case 4:
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(a,OFF);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF); 
      digitalWrite(dp,OFF);
      break;  
    case 5:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(b,OFF);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
    case 6:
      digitalWrite(a,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(b,OFF);
      digitalWrite(dp,OFF);
      break;
    case 7:
      digitalWrite(a,ON);
      digitalWrite(f,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,OFF);
      digitalWrite(e,OFF);
      digitalWrite(g,OFF);
      digitalWrite(dp,OFF);
      break;
    case 8:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(e,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(dp,OFF);
      break;
    case 9:
      digitalWrite(a,ON);
      digitalWrite(b,ON);
      digitalWrite(c,ON);
      digitalWrite(d,ON);
      digitalWrite(f,ON);
      digitalWrite(g,ON);
      digitalWrite(e,OFF);
      digitalWrite(dp,OFF);
      break;
  }
}
