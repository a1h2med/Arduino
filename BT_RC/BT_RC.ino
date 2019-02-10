char data;  // انتا بتعرف الvariable ع اساس انه char مش int لانه هيتبعتله حروف ويخزنها مش ارقام
void setup() {
  // put your setup code here, to run once:
pinMode (10,OUTPUT);
pinMode (9,OUTPUT);
pinMode (6,OUTPUT);
pinMode (5,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()){
   data=Serial.read();           

   /// خد بالك ان الcheck بيبقي ع حسب الحاجات اللي هتتبعتلك ف انا غيرتها عشان التجربه عندي ف لو هتغيرها تاني قشطه المهم تبقي زي اللي هيتبعتلك /////
  if (data=='F'){               // العربيه هنا هتمشي لقدام
    digitalWrite (10,HIGH);
    digitalWrite (9 , LOW);
    digitalWrite (6,HIGH);
    digitalWrite (5, LOW);
    }
  if (data=='B'){       // هنا العربيه هترجع لورا لاني عكست اتجاه العجل
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }
  if (data=='R'){          // هنا العربيه هتلف يمين وده عشان انا وقفت نص العربيه وشغلت النص التاني
    digitalWrite (10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite (5,LOW);
  }
  if (data=='L'){           // هنا للعربيه هتلف شمال وده عشان انا وقفت نص العربيه وشغلت التاني ف هتلف شمال
    digitalWrite (9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(5,LOW);
    digitalWrite (6,HIGH);
  }
}
Serial.println(data);
}
