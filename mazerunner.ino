int left_dir = 1;
int right_dir = 2;
int stra_dir = 3;
int back_dir = 4;
int end_of_line = 11;
int intersection = 10;
int usrcom = 71;
int current_dir;
int path[100];
int pathSize = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Initialize the Serial Monitor


}

// the loop function runs over and over again forever
void loop() {
  
  current_dir = stra_dir;
  
  while (current_dir == 3) {
 Serial.println(current_dir);
       path[pathSize]=current_dir;
      pathSize++;
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  // Read the input from the Serial Monitor
  usrcom = Serial.parseInt();
  if(usrcom ==10 ){
    current_dir = left_dir;
    Serial.println(current_dir);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize]=left_dir;
      pathSize++;
            path[pathSize]=stra_dir;
      pathSize++;
      
  }
  else if(usrcom == 11){
    current_dir=end_of_line;
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize]=back_dir;
      pathSize++;
            path[pathSize]=stra_dir;
      pathSize++;
  }
  else if(usrcom==2){
    current_dir=right_dir;
       Serial.println(current_dir);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(5000);
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize]=right_dir;
      pathSize++;
            path[pathSize]=stra_dir;
      pathSize++;
}
    }
     for (int i = 0; i < pathSize; i++) {
    Serial.print(path[i]); // Use Serial.print to send data to the Serial Monitor
    Serial.print(" "); // Separate elements with a space
  }
  
  // Wait for a second
 
}
