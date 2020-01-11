#include <lcd.h>
#include "Nokia_5110.h"
const int pin0 = 7;   //naming pins foe ease
const int pin1 = 6;
const int pin2 = 5;
const int pin3 = 4;
const int pin4 = 3;
const int pin5 = 2;
const int pin6 = 30;
const int pin7 = 28;
const int pin8 = 26;
const int pin9 = 36;
const int pin10 = 34;
const int pin11 = 32;
const int pin12 = 1;//gnd
const int pin13 = 48;//vcc
const int pin14 = 40;//
const int pin15 = 0;//
const int pin16 = A10;//
const int pin17 = A9;//
const int pin18 = A8;//
//const int pin19 = 24;//

nokia_lcd my(A15, A14, A13, A12, A11);   //lcd decleration (rst, ce, dc, din, clk)
Nokia_5110 lcd = Nokia_5110(A15, A14, A13, A12, A11);//sck-clk9 mosi-din8 dc10 cs12 rst=11
int chknand =0;
int chkor =0;
int chkxor =0;
int chkand =0;
int chknor =0;
int chknot =0;


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
digitalWrite(pin0,HIGH);
digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==LOW){gate_1++;i++;}
 digitalWrite(pin0,HIGH);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
if(ifnand&&(gate_1>2)){lcd.print("NAND gate 1-WORKING");delay(1000);lcd.clear();}
else 
if(ifnand){lcd.print("NAND gate 1-not WORKING");delay(2000);lcd.clear();}

//............NAND GATE 2.................

digitalWrite(pin3,HIGH);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==LOW){gate_2++;i++;}
digitalWrite(pin3,HIGH);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
if(ifnand&&(gate_2>2)){lcd.print("NAND gate 2-WORKING");delay(2000);lcd.clear();}
else 
if(ifnand){lcd.print("NAND gate 2-not WORKING");delay(2000);lcd.clear();}


//............NAND GATE THREE..............

 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==LOW){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==HIGH ){gate_3++;i++;}
if(ifnand&&(gate_3>2)){lcd.print("NAND gate 3-WORKING");delay(2000);lcd.clear();}}
else 
{ if(ifnand){lcd.print("NAND gate 3-not WORKING");delay(2000);lcd.clear();}}

//...................NAND GATE 4.............
digitalWrite(pin9,HIGH);
 digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==LOW){gate_4++;i++;}
 digitalWrite(pin9,HIGH);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
digitalWrite(pin9,LOW);
digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
digitalWrite(pin9,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==HIGH ){gate_4++;i++;}
if(ifnand&&(gate_4>2)){lcd.print("nand gate 4-WORKING");delay(2000);lcd.clear();}}
else 
{ if(ifnand){lcd.print("NAND gate 4-not WORKING");delay(2000);lcd.clear();}}
if(i>=12){chknand=1;}
else if (i<11){chknand=0;}
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
digitalWrite(pin0,HIGH);
digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,HIGH);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}

pinMode(pin0,OUTPUT);//define for avoiding error 
pinMode(pin1,OUTPUT);
pinMode(pin2,INPUT);
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==LOW ){gate_1++;i++;}
if(ifor&&(gate_1>2)){lcd.print("OR gate 1-WORKING");delay(1000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 1-not WORKING");delay(2000);lcd.clear();}}

//............or GATE 2.................

digitalWrite(pin3,HIGH);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,HIGH);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
 
pinMode(pin3,OUTPUT);//define for avoiding error 
pinMode(pin4,OUTPUT);
pinMode(pin5,INPUT);
digitalWrite(pin3,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==LOW ){gate_2++;i++;}
if(ifor&&(gate_2>2)){lcd.print("OR gate 2-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 2-not WORKING");delay(2000);lcd.clear();}}


//............or GATE THREE..............

 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 
pinMode(pin6,OUTPUT);//define for avoiding error 
pinMode(pin7,OUTPUT);
pinMode(pin8,INPUT);
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==LOW ){gate_3++;i++;}
;if(ifor&&(gate_3>2)){lcd.print("OR gate 3-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 3-not WORKING");delay(2000);lcd.clear();}}

//...................or GATE 4.............
digitalWrite(pin9,HIGH);
 digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
 digitalWrite(pin9,HIGH);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
digitalWrite(pin9,LOW);
digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
pinMode(pin9,OUTPUT);//define for avoiding error 
pinMode(pin10,OUTPUT);
pinMode(pin11,INPUT);
digitalWrite(pin9,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==LOW ){gate_4++;i++;}
if(ifor&&(gate_4>2)){lcd.print("OR gate 4-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifor){lcd.print("OR gate 4-not WORKING");delay(2000);lcd.clear();}}
if(i>=11){chkor=1;}
else if (i<10){chkor=0;}
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
digitalWrite(pin0,HIGH);
digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}

 digitalWrite(pin0,HIGH);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==LOW){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==LOW){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==LOW){gate_1++;i++;}
if(ifand&&(gate_1>2)){lcd.print("AND gate 1-WORKING");delay(1000);lcd.clear();}}}
else 
{ if(ifand){lcd.print("AND gate 1-not WORKING");delay(2000);lcd.clear();}}

//............and GATE 2.................

digitalWrite(pin3,HIGH);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,HIGH);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==LOW){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==LOW){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==LOW){gate_2++;i++;}
if(ifand&&(gate_2>2){lcd.print("AND gate 2-WORKING");delay(2000);lcd.clear();}}}
else 
{ if(ifand){lcd.print("AND gate 2-not WORKING");delay(2000);lcd.clear();}}


//............and GATE THREE..............

 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==LOW){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==LOW){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==LOW){gate_3++;i++;}
if(ifand&&(gate_3>2){lcd.print("AND gate 3-WORKING");delay(2000);lcd.clear();}}}
else 
{ if(ifand){lcd.print("AND gate 3-not WORKING");delay(2000);lcd.clear();}}

//...................AND GATE 4.............
digitalWrite(pin9,HIGH);
 digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
 digitalWrite(pin9,HIGH);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==LOW){gate_4++;i++;}
digitalWrite(pin9,LOW);
digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==LOW){gate_4++;i++;}
digitalWrite(pin9,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==LOW){gate_4++;i++;}
if(ifand&&(gate_4>2){lcd.print("and gate 4-WORKING");delay(2000);lcd.clear();}}}
else 
{ if(ifand){lcd.print("AND gate 4-not WORKING");delay(2000);lcd.clear();}}
if(i>=12){chkand=1;}
else if (i<11){chkand=0;}
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
digitalWrite(pin0,HIGH);
digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==LOW){gate_1++;i++;}
 digitalWrite(pin0,HIGH);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,HIGH);
if(digitalRead(pin2)==HIGH){gate_1++;i++;}
 digitalWrite(pin0,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==LOW ){gate_1++;i++;}
if(ifxor&&(gate_1>2)){lcd.print("XOR gate 1-WORKING");delay(1000);lcd.clear();}
else 
{if(ifxor){lcd.print("XOR gate 1-not WORKING");delay(2000);lcd.clear();}}

//............XOR GATE 2.................

digitalWrite(pin3,HIGH);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==LOW){gate_2++;i++;}
digitalWrite(pin3,HIGH);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==HIGH){gate_2++;i++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==LOW ){gate_2++;i++;}
if(ifxor&&(gate_2>2)){lcd.print("XOR gate 2-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 2-not WORKING");delay(2000);lcd.clear();}}


//............XOR GATE THREE..............

 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==LOW){gate_3++;i++;}
 digitalWrite(pin6,HIGH);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin8)==HIGH){gate_3++;i++;}
 digitalWrite(pin6,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==LOW ){gate_3++;i++;}
if(ifxor&&(gate_3>2)){lcd.print("XOR gate 3-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 3-not WORKING");delay(2000);lcd.clear();}}

//...................XOR GATE 4.............
digitalWrite(pin9,HIGH);
 digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==LOW){gate_4++;i++;}
 digitalWrite(pin9,HIGH);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
digitalWrite(pin9,LOW);
digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==HIGH){gate_4++;i++;}
digitalWrite(pin9,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==LOW ){gate_4++;i++;}
if(ifxor&&(gate_4>2)){lcd.print("XOR gate 4-WORKING");delay(2000);lcd.clear();}
else 
{ if(ifxor){lcd.print("XOR gate 4-not WORKING");delay(2000);lcd.clear();}}
if(i>=12){chkxor=1;}
else if (i<11){chkxor=0;}
}


// .................nor GATE 1................
bool norfunc (int ifnor){
pinMode(pin0,INPUT);
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
pinMode(pin3,INPUT);
pinMode(pin4,OUTPUT);
pinMode(pin5,OUTPUT);
pinMode(pin6,INPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(pin9,INPUT);
pinMode(pin10,OUTPUT);
pinMode(pin11,OUTPUT);
//lcd.print("matching with nor");delay(1000);lcd.clear();
int i=0;
int gate_1=0;
int gate_2=0;
int gate_3=0;
int gate_4=0;
//..........gate 1 for nor......................................................
digitalWrite(pin2,HIGH);
digitalWrite(pin1,HIGH);
if(digitalRead(pin0)==LOW){gate_1++;i++;}
 digitalWrite(pin2,HIGH);
 digitalWrite(pin1,LOW);
if(digitalRead(pin0)==LOW){gate_1++;i++;}
 digitalWrite(pin2,LOW);
 digitalWrite(pin1,HIGH);
if(digitalRead(pin0)==LOW){gate_1++;i++;}
 digitalWrite(pin2,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin0)==HIGH && (gate_1>2))
{i++; if(ifnor){lcd.print("NOR gate 1-WORKING");delay(1000);lcd.clear();}}
else 
{ if(ifnor){lcd.print("NOR gate 1-not WORKING");delay(2000);lcd.clear();}}

//............nor GATE 2.................

digitalWrite(pin5,HIGH);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin3)==LOW){gate_2++;i++;}
digitalWrite(pin5,HIGH);
 digitalWrite(pin4,LOW);
if(digitalRead(pin3)==LOW){gate_2++;i++;}
digitalWrite(pin5,LOW);
 digitalWrite(pin4,HIGH);
if(digitalRead(pin3)==LOW){gate_2++;i++;}
digitalWrite(pin5,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin3)==HIGH && (gate_2>2))
{ i++;if(ifnor){lcd.print("NOR gate 2-WORKING");delay(2000);lcd.clear();}}
else 
{ if(ifnor){lcd.print("NOR gate 2-not WORKING");delay(2000);lcd.clear();}}


//............NOR GATE THREE..............

 digitalWrite(pin8,HIGH);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin6)==LOW){gate_3++;i++;}
 digitalWrite(pin8,HIGH);
 digitalWrite(pin7,LOW);
if(digitalRead(pin6)==LOW){gate_3++;i++;}
 digitalWrite(pin8,LOW);
 digitalWrite(pin7,HIGH);
if(digitalRead(pin6)==LOW){gate_3++;i++;}
 digitalWrite(pin8,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin6)==HIGH && (gate_3>2))
{ i++;if(ifnor){lcd.print("NOR gate 3-WORKING");delay(2000);lcd.clear();}}
else 
{ if(ifnor){lcd.print("NOR gate 3-not WORKING");delay(2000);lcd.clear();}}

//...................NOR GATE 4.............
digitalWrite(pin11,HIGH);
 digitalWrite(pin10,HIGH);
if(digitalRead(pin9)==LOW){gate_4++;i++;}
 digitalWrite(pin11,HIGH);
 digitalWrite(pin10,LOW);
if(digitalRead(pin9)==LOW){gate_4++;i++;}
digitalWrite(pin11,LOW);
digitalWrite(pin10,HIGH);
if(digitalRead(pin9)==LOW){gate_4++;i++;}
digitalWrite(pin11,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin9)==HIGH && (gate_4>2)){
i++; if(ifnor){lcd.print("NOR gate 4-WORKING");delay(2000);lcd.clear();}}
else 
{ if(ifnor){lcd.print("NOR gate 4-not WORKING");delay(2000);lcd.clear();}}
if(i>=11){chknor=1;}
else if (i<10){chknor=0;}
}


// .................not GATE 1................

bool notfunc (int ifnot){
  pinMode(pin0,OUTPUT);
pinMode(pin1,INPUT);
pinMode(pin2,OUTPUT);
pinMode(pin3,INPUT);
pinMode(pin4,OUTPUT);
pinMode(pin5,INPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,INPUT);
pinMode(pin8,OUTPUT);
pinMode(pin9,INPUT);
pinMode(pin10,OUTPUT);
pinMode(pin11,INPUT);
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
digitalWrite(pin0,HIGH);
if(digitalRead(pin1)==LOW){gate_1++;i++;}
 digitalWrite(pin0,LOW);
if(digitalRead(pin1)==HIGH && (gate_1==1))
{i++; if(ifnot){lcd.print("not gate 1 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 1 not WORKING");delay(2000);lcd.clear();}}
//..........gate 2 for not......................................................
digitalWrite(pin2,HIGH);
if(digitalRead(pin3)==LOW){gate_2++;i++;}
 digitalWrite(pin2,LOW);
if(digitalRead(pin3)==HIGH && (gate_2==1))
{i++; if(ifnot){lcd.print("not gate 2 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 2 not WORKING");delay(2000);lcd.clear();}}
//..........gate 3 for not......................................................
digitalWrite(pin4,HIGH);
if(digitalRead(pin5)==LOW){gate_3++;i++;}
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==HIGH && (gate_3==1))
{i++; if(ifnot){lcd.print("not gate 3 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 3 not WORKING");delay(2000);lcd.clear();}}
//..........gate 4 for not......................................................
digitalWrite(pin6,HIGH);
if(digitalRead(pin7)==LOW){gate_4++;i++;}
 digitalWrite(pin6,LOW);
if(digitalRead(pin7)==HIGH && (gate_4==1))
{i++; if(ifnot){lcd.print("not gate 4 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 4 not WORKING");delay(2000);lcd.clear();}}
//..........gate 5 for not......................................................
digitalWrite(pin8,HIGH);
if(digitalRead(pin9)==LOW){gate_5++;i++;}
 digitalWrite(pin8,LOW);
if(digitalRead(pin9)==HIGH && (gate_5==1))
{i++; if(ifnot){lcd.print("not gate 5 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 5 not WORKING");delay(2000);lcd.clear();}}
//..........gate 6 for not......................................................
digitalWrite(pin10,HIGH);
if(digitalRead(pin11)==LOW){gate_6++;i++;}
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==HIGH && (gate_6==1))
{i++; if(ifnot){lcd.print("not gate 6 WORKING");delay(1000);lcd.clear();}}
else 
{i++;if(ifnot){lcd.print("not gate 6 not WORKING");delay(2000);lcd.clear();}}
if(i>=7){chknot=1;}
else if (i<6){chknot=0;}}

void setup() {


pinMode(pin0,OUTPUT);
pinMode(pin1,OUTPUT);
pinMode(pin2,INPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);
pinMode(pin5,INPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,INPUT);
pinMode(pin9,OUTPUT);
pinMode(pin10,OUTPUT);
pinMode(pin11,INPUT);

pinMode(pin12,OUTPUT);//VCC48
pinMode(pin13,OUTPUT);//VCC46
digitalWrite(pin12,LOW);//GND
digitalWrite(pin13,HIGH);//VCC

pinMode(pin16,OUTPUT);
pinMode(pin17,OUTPUT);
pinMode(pin18,OUTPUT);
digitalWrite(pin16,HIGH);//LCD-VCC
digitalWrite(pin17,HIGH);//LCD-BL
digitalWrite(pin18,LOW);//LCD-GND


//restricting nand to not execute during xor ic
int resnand=0;
digitalWrite(pin0,LOW);
 digitalWrite(pin1,LOW);
if(digitalRead(pin2)==LOW){resnand++;}
digitalWrite(pin3,LOW);
 digitalWrite(pin4,LOW);
if(digitalRead(pin5)==LOW){resnand++;}
digitalWrite(pin6,LOW);
 digitalWrite(pin7,LOW);
if(digitalRead(pin8)==LOW){resnand++;}
digitalWrite(pin9,LOW);
 digitalWrite(pin10,LOW);
if(digitalRead(pin11)==LOW){resnand++;}
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
}


}
void loop() {




}
