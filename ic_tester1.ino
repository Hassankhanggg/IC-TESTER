#include <lcd.h>
#include "Nokia_5110.h"
//naming pins foe ease
const int pin_1 = 7;//ic pin   1      0//previosuly used pins name
const int pin_2 = 6;//ic pin   2       1
const int pin_3 = 5;//ic pin   3       2
const int pin_4 = 4;//ic pin   4       3
const int pin_5 = 3;//ic pin   5       4
const int pin_6 = 2;//ic pin   6       5
const int pin_7 = 1;//ic pin  7        12
const int pin_8 = 0;//ic pin  8        15
const int pin_9 = 34;//ic pin 9        14
const int pin_10 = 32;//ic pin  10     8 = preveios pin name   26 =previous pin
const int pin_11 = 30;//ic pin  11     7          28
const int pin_12 = 28;//ic pin  12     6          30
const int pin_13 = 26;//ic pin 13      11         32
const int pin_14 = 24;//ic pin 14      10         34
const int pin_15 = 22;//ic pin  15     9          36
const int pin_16 = 36;//vcc    16      13         48 or directly attach it to vcc+5v
const int pin_lcd1 = A10;// lcd        16
const int pin_lcd2 = A9;// lcd         17
const int pin_lcd3 = A8;// lcd         18

// include the library code:
#include <LiquidCrystal.h>
int contrast = 75;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 49, en = 45, d4 = 35, d5 = 33, d6 = 31, d7 = 29;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


nokia_lcd my(A15, A14, A13, A12, A11);   //lcd decleration (rst, ce, dc, din, clk)
Nokia_5110 lcd = Nokia_5110(A15, A14, A13, A12, A11);//sck-clk9 mosi-din8 dc10 cs12 rst=11
int chknand =0;
int chkor =0;
int chkxor =0;
int chkand =0;
int chknor =0;
int chknot =0;
int chkdecod=0;


// .................NAND GATE 1................
void nandfunc (int ifnand){
//lcd.print("matching with nand");
//delay(1000);
//lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for nand......................................................
digitalWrite(pin_1,HIGH);
digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==LOW){gate_1++;i++;}
 digitalWrite(pin_1,HIGH);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
if(ifnand&&(gate_1>3)){lcd.print("NAND gate 1-WORKING");delay(1000);lcd.clear();}
else 
if(ifnand){lcd.print("NAND gate 1-not WORKING");delay(1000);lcd.clear();}

//............NAND GATE 2.................

digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==LOW){gate_2++;i++;}
digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
if(ifnand&&(gate_2>3)){lcd.print("NAND gate 2-WORKING");delay(1000);lcd.clear();}
else 
if(ifnand){lcd.print("NAND gate 2-not WORKING");delay(1000);lcd.clear();}


//............NAND GATE THREE..............

 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==LOW){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==HIGH ){gate_3++;i++;}
if(ifnand&&(gate_3>3)){lcd.print("NAND gate 3-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnand){lcd.print("NAND gate 3-not WORKING");delay(1000);lcd.clear();}}

//...................NAND GATE 4.............
digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==LOW){gate_4++;i++;}
 digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
digitalWrite(pin_15,LOW);
digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
digitalWrite(pin_15,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==HIGH ){gate_4++;i++;}
if(ifnand&&(gate_4>3)){lcd.print("nand gate 4-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnand){lcd.print("NAND gate 4-not WORKING");delay(1000);lcd.clear();}}
if((i>=8)&&(gate_1==4||gate_2==4||gate_3==4||gate_4==4)){chknand=1;}
else if (i<8){chknand=0;}
}

// .................or GATE ................
void orfunc (int ifor){
//lcd.print("matching with or");delay(1000);lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for or......................................................
digitalWrite(pin_1,HIGH);
digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,HIGH);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}

pinMode(pin_1,OUTPUT);//define for avoiding error 
pinMode(pin_2,OUTPUT);
pinMode(pin_3,INPUT);
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==LOW ){gate_1++;i++;}
if(ifor&&(gate_1>3)){lcd.print("OR gate 1-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 1-not WORKING");delay(1000);lcd.clear();}}

//............or GATE 2.................

digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
 
pinMode(pin_4,OUTPUT);//define for avoiding error 
pinMode(pin_5,OUTPUT);
pinMode(pin_6,INPUT);
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==LOW ){gate_2++;i++;}
if(ifor&&(gate_2>3)){lcd.print("OR gate 2-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 2-not WORKING");delay(1000);lcd.clear();}}


//............or GATE THREE..............

 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 
pinMode(pin_12,OUTPUT);//define for avoiding error 
pinMode(pin_11,OUTPUT);
pinMode(pin_10,INPUT);
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==LOW ){gate_3++;i++;}
;if(ifor&&(gate_3>2)){lcd.print("OR gate 3-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 3-not WORKING");delay(1000);lcd.clear();}}

//...................or GATE 4.............
digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
 digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
digitalWrite(pin_15,LOW);
digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
pinMode(pin_15,OUTPUT);//define for avoiding error 
pinMode(pin_14,OUTPUT);
pinMode(pin_13,INPUT);
digitalWrite(pin_15,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==LOW ){gate_4++;i++;}
if(ifor&&(gate_4>2)){lcd.print("OR gate 4-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 4-not WORKING");delay(1000);lcd.clear();}}
if((i>=8)&&(gate_1==4||gate_2==4||gate_3==4||gate_4==4)){chkor=1;}
else if (i<8){chkor=0;}
}

// .................AND GATE 1................
bool andfunc (int ifand){
//lcd.print("mataching with and");
//delay(1000);
//lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for and......................................................
digitalWrite(pin_1,HIGH);
digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}

 digitalWrite(pin_1,HIGH);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==LOW){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==LOW){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==LOW){gate_1++;i++;}
if(ifand&&(gate_1>3)){lcd.print("AND gate 1-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifand){lcd.print("AND gate 1-not WORKING");delay(1000);lcd.clear();}}

//............and GATE 2.................

digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==LOW){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==LOW){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==LOW){gate_2++;i++;}
if(ifand&&(gate_2>3)){lcd.print("AND gate 2-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifand){lcd.print("AND gate 2-not WORKING");delay(2000);lcd.clear();}}


//............and GATE THREE..............

 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==LOW){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==LOW){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==LOW){gate_3++;i++;}
if(ifand&&(gate_3>3)){lcd.print("AND gate 3-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifand){lcd.print("AND gate 3-not WORKING");delay(1000);lcd.clear();}}

//...................AND GATE 4.............
digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
 digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==LOW){gate_4++;i++;}
digitalWrite(pin_15,LOW);
digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==LOW){gate_4++;i++;}
digitalWrite(pin_15,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==LOW){gate_4++;i++;}
if(ifand&&(gate_4>3)){lcd.print("and gate 4-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifand){lcd.print("AND gate 4-not WORKING");delay(1000);lcd.clear();}}
if((i>=8)&&(gate_1==4||gate_2==4||gate_3==4||gate_4==4)){chkand=1;}
else if (i<8){chkand=0;}
}


// .................XOR GATE 1................
bool xorfunc (int ifxor){
//lcd.print("matching with xor");
//delay(1000);
//lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for XOR......................................................
digitalWrite(pin_1,HIGH);
digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==LOW){gate_1++;i++;}
 digitalWrite(pin_1,HIGH);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,HIGH);
if(digitalRead(pin_3)==HIGH){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==LOW ){gate_1++;i++;}
if(ifxor&&(gate_1>2)){lcd.print("XOR gate 1-WORKING");delay(1000);lcd.clear();}
else 
{if(ifxor){lcd.print("XOR gate 1-not WORKING");delay(1000);lcd.clear();}}

//............XOR GATE 2.................

digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==LOW){gate_2++;i++;}
digitalWrite(pin_4,HIGH);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==HIGH){gate_2++;i++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==LOW ){gate_2++;i++;}
if(ifxor&&(gate_2>2)){lcd.print("XOR gate 2-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 2-not WORKING");delay(1000);lcd.clear();}}


//............XOR GATE THREE..............

 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==LOW){gate_3++;i++;}
 digitalWrite(pin_12,HIGH);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==HIGH){gate_3++;i++;}
 digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==LOW ){gate_3++;i++;}
if(ifxor&&(gate_3>2)){lcd.print("XOR gate 3-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 3-not WORKING");delay(1000);lcd.clear();}}

//...................XOR GATE 4.............
digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==LOW){gate_4++;i++;}
 digitalWrite(pin_15,HIGH);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
digitalWrite(pin_15,LOW);
digitalWrite(pin_14,HIGH);
if(digitalRead(pin_13)==HIGH){gate_4++;i++;}
digitalWrite(pin_15,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==LOW ){gate_4++;i++;}
if(ifxor&&(gate_4>2)){lcd.print("XOR gate 4-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 4-not WORKING");delay(1000);lcd.clear();}}
if((i>=8)&&(gate_1==4||gate_2==4||gate_3==4||gate_4==4)){chkxor=1;}
else if (i<8){chkxor=0;}
}


// .................nor GATE 1................
bool norfunc (int ifnor){
pinMode(pin_1,INPUT);
pinMode(pin_2,OUTPUT);
pinMode(pin_3,OUTPUT);
pinMode(pin_4,INPUT);
pinMode(pin_5,OUTPUT);
pinMode(pin_6,OUTPUT);
pinMode(pin_12,INPUT);
pinMode(pin_11,OUTPUT);
pinMode(pin_10,OUTPUT);
pinMode(pin_15,INPUT);
pinMode(pin_14,OUTPUT);
pinMode(pin_13,OUTPUT);
//lcd.print("matching with nor");delay(1000);lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for nor......................................................
digitalWrite(pin_3,HIGH);
digitalWrite(pin_2,HIGH);
if(digitalRead(pin_1)==LOW){gate_1++;i++;}
 digitalWrite(pin_3,HIGH);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_1)==LOW){gate_1++;i++;}
 digitalWrite(pin_3,LOW);
 digitalWrite(pin_2,HIGH);
if(digitalRead(pin_1)==LOW){gate_1++;i++;}
 digitalWrite(pin_3,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_1)==HIGH ){gate_1++;i++;}
if(ifnor&&(gate_1>2)){lcd.print("NOR gate 1-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnor){lcd.print("NOR gate 1-not WORKING");delay(1000);lcd.clear();}}

//............nor GATE 2.................

digitalWrite(pin_6,HIGH);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_4)==LOW){gate_2++;i++;}
digitalWrite(pin_6,HIGH);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_4)==LOW){gate_2++;i++;}
digitalWrite(pin_6,LOW);
 digitalWrite(pin_5,HIGH);
if(digitalRead(pin_4)==LOW){gate_2++;i++;}
digitalWrite(pin_6,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_4)==HIGH ){gate_2++;i++;}
if(ifnor&&(gate_2>2)){lcd.print("NOR gate 2-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnor){lcd.print("NOR gate 2-not WORKING");delay(1000);lcd.clear();}}


//............NOR GATE THREE..............

 digitalWrite(pin_10,HIGH);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_12)==LOW){gate_3++;i++;}
 digitalWrite(pin_10,HIGH);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_12)==LOW){gate_3++;i++;}
 digitalWrite(pin_10,LOW);
 digitalWrite(pin_11,HIGH);
if(digitalRead(pin_12)==LOW){gate_3++;i++;}
 digitalWrite(pin_10,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_12)==HIGH ){gate_3++;i++;}
if(ifnor&&(gate_3>2)){lcd.print("NOR gate 3-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnor){lcd.print("NOR gate 3-not WORKING");delay(1000);lcd.clear();}}

//...................NOR GATE 4.............
digitalWrite(pin_13,HIGH);
 digitalWrite(pin_14,HIGH);
if(digitalRead(pin_15)==LOW){gate_4++;i++;}
 digitalWrite(pin_13,HIGH);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_15)==LOW){gate_4++;i++;}
digitalWrite(pin_13,LOW);
digitalWrite(pin_14,HIGH);
if(digitalRead(pin_15)==LOW){gate_4++;i++;}
digitalWrite(pin_13,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_15)==HIGH ){gate_4++;i++;}
if(ifnor&&(gate_4>2)){lcd.print("NOR gate 4-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifnor){lcd.print("NOR gate 4-not WORKING");delay(1000);lcd.clear();}}
if((i>=8)&&(gate_1==4||gate_2==4||gate_3==4||gate_4==4)){chknor=1;}
else if (i<8){chknor=0;}
}


// .................not GATE 1................

bool notfunc (int ifnot){
  pinMode(pin_1,OUTPUT);
pinMode(pin_2,INPUT);
pinMode(pin_3,OUTPUT);
pinMode(pin_4,INPUT);
pinMode(pin_5,OUTPUT);
pinMode(pin_6,INPUT);
pinMode(pin_12,OUTPUT);
pinMode(pin_11,INPUT);
pinMode(pin_10,OUTPUT);
pinMode(pin_15,INPUT);
pinMode(pin_14,OUTPUT);
pinMode(pin_13,INPUT);
//lcd.print("matching with not");
//delay(1000);
//lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
int gate_5=0;
int gate_6=0;
//..........gate 1 for not......................................................
digitalWrite(pin_1,HIGH);
if(digitalRead(pin_2)==LOW){gate_1++;i++;}
 digitalWrite(pin_1,LOW);
if(digitalRead(pin_2)==HIGH){gate_1++;i++;}
if(ifnot&&(gate_1>1)){lcd.print("not gate 1 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 1 not WORKING");delay(1000);lcd.clear();}}
//..........gate 2 for not......................................................
digitalWrite(pin_3,HIGH);
if(digitalRead(pin_4)==LOW){gate_2++;i++;}
 digitalWrite(pin_3,LOW);
if(digitalRead(pin_4)==HIGH){gate_2++;i++;}
if(ifnot&&(gate_2>1)){lcd.print("not gate 2 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 2 not WORKING");delay(1000);lcd.clear();}}
//..........gate 3 for not......................................................
digitalWrite(pin_5,HIGH);
if(digitalRead(pin_6)==LOW){gate_3++;i++;}
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==HIGH){gate_3++;i++;}
if(ifnot&&(gate_3>1)){lcd.print("not gate 3 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 3 not WORKING");delay(1000);lcd.clear();}}
//..........gate 4 for not......................................................
digitalWrite(pin_11,HIGH);
if(digitalRead(pin_10)==LOW){gate_4++;i++;}
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==HIGH ){gate_4++;i++;}
 if(ifnot&&(gate_4>=1)){lcd.print("not gate 4 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 4 not WORKING");delay(1000);lcd.clear();}}
//..........gate 5 for not......................................................
digitalWrite(pin_13,HIGH);
if(digitalRead(pin_12)==LOW){gate_5++;i++;}
 digitalWrite(pin_13,LOW);
if(digitalRead(pin_12)==HIGH ){gate_5++;i++;}
if(ifnot&&(gate_5>=1)){lcd.print("not gate 5 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 5 not WORKING");delay(1000);lcd.clear();}}
//..........gate 6 for not......................................................
digitalWrite(pin_15,HIGH);
if(digitalRead(pin_14)==LOW){gate_6++;i++;}
 digitalWrite(pin_15,LOW);
if(digitalRead(pin_14)==HIGH){gate_6++;i++;}
if(ifnot&&(gate_6>=1)){lcd.print("not gate 6 WORKING");delay(1000);lcd.clear();}
else 
{if(ifnot){lcd.print("not gate 6 not WORKING");delay(1000);lcd.clear();}}
if((i>=7)&&(gate_1==2||gate_2==2||gate_3==2||gate_4==2||gate_5==2||gate_6==2)){chknot=1;}
else if (i<7){chknot=0;}}

// .................DECODER 74139 GATE 1................
bool decodfunc (int ifdecod){
pinMode(pin_1,OUTPUT);//LOW Active enable
digitalWrite(pin_1,LOW);
pinMode(pin_2,OUTPUT);//switch 1
pinMode(pin_3,OUTPUT);//switch 2
pinMode(pin_4,INPUT);//data output a0 
pinMode(pin_5,INPUT);//data out  a1
pinMode(pin_6,INPUT);//data out a2
pinMode(pin_7,INPUT);//data out a3
pinMode(pin_8,OUTPUT);//gnd
digitalWrite(pin_8,LOW);
pinMode(pin_9,INPUT);//data out b3
pinMode(pin_10,INPUT);//b2
pinMode(pin_11,INPUT);//b1
pinMode(pin_12,INPUT);//b0
pinMode(pin_13,OUTPUT);//s1
pinMode(pin_14,OUTPUT);//s0
pinMode(pin_15,OUTPUT);// low enable gate b
digitalWrite(pin_15,LOW);
pinMode(pin_16,OUTPUT);//vcc
digitalWrite(pin_16,HIGH);
//lcd.print("matching with DECODER");delay(1000);lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
//..........gate 1 for DECODER IC ......................................................
pinMode(pin_1,OUTPUT);
digitalWrite(pin_1,0); //enable low active

digitalWrite(pin_2,HIGH);
digitalWrite(pin_3,HIGH);
if((digitalRead(pin_7)==HIGH)&&(digitalRead(pin_6)==HIGH)&&(digitalRead(pin_5)==HIGH)&&(digitalRead(pin_4)==LOW)){gate_1++;i++;}
digitalWrite(pin_2,LOW);
digitalWrite(pin_3,HIGH);
if((digitalRead(pin_7)==HIGH)&&(digitalRead(pin_6)==LOW)&&(digitalRead(pin_5)==HIGH)&&(digitalRead(pin_4)==HIGH)){gate_1++;i++;}
digitalWrite(pin_2,HIGH);
digitalWrite(pin_3,LOW);
if((digitalRead(pin_7)==HIGH)&&(digitalRead(pin_6)==HIGH)&&(digitalRead(pin_5)==LOW)&&(digitalRead(pin_4)==HIGH)){gate_1++;i++;}
digitalWrite(pin_2,LOW);
digitalWrite(pin_3,LOW);
if((digitalRead(pin_7)==LOW)&&(digitalRead(pin_6)==HIGH)&&(digitalRead(pin_5)==HIGH)&&(digitalRead(pin_4)==HIGH)){gate_1++;i++;}
if(ifdecod&&(gate_1>2)){lcd.print("DECODER gate 1 working");delay(1000);lcd.clear();}
else 
{ if(ifdecod){lcd.print("DECODER gate 1-not WORKING");delay(1000);lcd.clear();}}
//..........gate 2 for DECODER IC ......................................................
pinMode(pin_15,OUTPUT);
digitalWrite(pin_15,0); //enable low active
digitalWrite(pin_14,HIGH);
digitalWrite(pin_13,HIGH);
if((digitalRead(pin_9)==HIGH)&&(digitalRead(pin_10)==HIGH)&&(digitalRead(pin_11)==HIGH)&&(digitalRead(pin_12)==LOW)){gate_2++;i++;}
digitalWrite(pin_14,LOW);
digitalWrite(pin_13,HIGH);
if((digitalRead(pin_9)==HIGH)&&(digitalRead(pin_10)==LOW)&&(digitalRead(pin_11)==HIGH)&&(digitalRead(pin_12)==HIGH)){gate_2++;i++;}
digitalWrite(pin_14,HIGH);
digitalWrite(pin_13,LOW);
if((digitalRead(pin_9)==HIGH)&&(digitalRead(pin_10)==HIGH)&&(digitalRead(pin_11)==LOW)&&(digitalRead(pin_12)==HIGH)){gate_2++;i++;}
digitalWrite(pin_14,LOW);
digitalWrite(pin_13,LOW);
if((digitalRead(pin_9)==LOW)&&(digitalRead(pin_10)==HIGH)&&(digitalRead(pin_11)==HIGH)&&(digitalRead(pin_12)==HIGH)){gate_2++;i++;}
if(ifdecod&&(gate_2>2)){lcd.print("DECODER gate 2 working");delay(1000);lcd.clear();}
else 
{ if(ifdecod){lcd.print("DECODER gate 2 not WORKING");delay(1000);lcd.clear();}}

if((i>=3)&&(gate_1==4||gate_2==4)){chkdecod=1;}
else if (i<3){chkdecod=0;}
}


void setup() {


chknand =0;
chkor =0;
chkxor =0;
chkand =0;
chknor =0;
chknot =0;
chkdecod=0;
pinMode(53,OUTPUT);//VCC48
digitalWrite(53,HIGH);

pinMode(47,OUTPUT);//VCC48
digitalWrite(47,LOW);

analogWrite(51,contrast);

pinMode(27,OUTPUT);//VCC48
digitalWrite(27,HIGH);

pinMode(25,OUTPUT);//VCC48
digitalWrite(25,LOW);

  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  //delay(2000);

}
void loop() {
lcd.setCursor(0,0);
lcd.print("IC TESTER by ");delay(1000);
lcd.setCursor(1,0);
lcd.print("M.HASSAN & RAZZI");delay(1000);lcd.clear();

chknand =0;
chkor =0;
chkxor =0;
chkand =0;
chknor =0;
chknot =0;
chkdecod=0;
pinMode(pin_1,OUTPUT);
pinMode(pin_2,OUTPUT);
pinMode(pin_3,INPUT);
pinMode(pin_4,OUTPUT);
pinMode(pin_5,OUTPUT);
pinMode(pin_6,INPUT);
pinMode(pin_12,OUTPUT);
pinMode(pin_11,OUTPUT);
pinMode(pin_10,INPUT);
pinMode(pin_15,OUTPUT);
pinMode(pin_14,OUTPUT);
pinMode(pin_13,INPUT);

pinMode(pin_7,OUTPUT);//VCC48
pinMode(pin_16,OUTPUT);//VCC46
digitalWrite(pin_7,LOW);//GND
digitalWrite(pin_16,HIGH);//VCC

pinMode(pin_lcd1,OUTPUT);
pinMode(pin_lcd2,OUTPUT);
pinMode(pin_lcd3,OUTPUT);
digitalWrite(pin_lcd1,HIGH);//LCD-VCC
digitalWrite(pin_lcd2,HIGH);//LCD-BL
digitalWrite(pin_lcd3,LOW);//LCD-GND


//restricting nand to not execute during xor ic
int resnand=0;
digitalWrite(pin_1,LOW);
 digitalWrite(pin_2,LOW);
if(digitalRead(pin_3)==LOW){resnand++;}
digitalWrite(pin_4,LOW);
 digitalWrite(pin_5,LOW);
if(digitalRead(pin_6)==LOW){resnand++;}
digitalWrite(pin_12,LOW);
 digitalWrite(pin_11,LOW);
if(digitalRead(pin_10)==LOW){resnand++;}
digitalWrite(pin_15,LOW);
 digitalWrite(pin_14,LOW);
if(digitalRead(pin_13)==LOW){resnand++;}
if(resnand<2)
{
int ifnand=0;
nandfunc(ifnand);
if(chknand){nandfunc(1);}
}

int ifand=0;
andfunc(ifand);
if(chkand){andfunc(1);}

int ifnor=0;
norfunc(ifnor);
if(chknor){norfunc(1);}

if(chknor==0){
int ifor=0;
orfunc(ifor);
if(chkor){orfunc(1);}
}

if(chknand==0)
{
int ifxor=0;
xorfunc(ifxor);
if(chkxor){xorfunc(1);}

if(chknor==0){
int ifnot=0;
notfunc(ifnot);
if(chknot){notfunc(1);}
}

int ifdecod=0;
decodfunc(ifdecod);
if(chkdecod){decodfunc(1);}
}
chknand =0;
chkor =0;
chkxor =0;
chkand =0;
chknor =0;
chknot =0;
chkdecod=0;


}
