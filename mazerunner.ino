int left_dir = 1;
int right_dir = 2;
int stra_dir = 3;
int back_dir = 4;
int end_of_line = 11;
int intersection = 10;
int usrcom = 71;
int current_dir;
int path[255];
int pathSize = 0;
void shortestPath(int path[], int &length) {
  int i = 0;

  while (i < length) {
    if (i + 4 < length) {
      // Replace 13432 with 4
      if (path[i] == 1 && path[i + 1] == 3 && path[i + 2] == 4 &&
          path[i + 3] == 3 && path[i + 4] == 2) {
        path[i] = 4;
        for (int j = i + 1; j < i + 5; j++) {
          path[j] = -1;
        }
        i += 5;
      }
      // Replace 134 with 2
      else if (path[i] == 1 && path[i + 1] == 3 && path[i + 2] == 4) {
        path[i] = 2;
        for (int j = i + 1; j < i + 3; j++) {
          path[j] = -1;
        }
        i += 3;
      }
    }

    // Add more pattern checks here for other replacements
    else if (i + 4 < length) {
      // Replace 23431 with 4
      if (path[i] == 2 && path[i + 1] == 3 && path[i + 2] == 4 &&
          path[i + 3] == 3 && path[i + 4] == 1) {
        path[i] = 4;
        for (int j = i + 1; j < i + 5; j++) {
          path[j] = -1;
        }
        i += 5;
      }
      // Replace 33431 with 2
      else if (path[i] == 3 && path[i + 1] == 3 && path[i + 2] == 4 &&
               path[i + 3] == 3 && path[i + 4] == 1) {
        path[i] = 2;
        for (int j = i + 1; j < i + 5; j++) {
          path[j] = -1;
        }
        i += 5;
      }
  
 
    }
    // Replace 13431 with 3
    else if (i + 4 < length) {
      if (path[i] == 1 && path[i + 1] == 3 && path[i + 2] == 4 &&
          path[i + 3] == 3 && path[i + 4] == 1) {
        path[i] = 3;
        for (int j = i + 1; j < i + 5; j++) {
          path[j] = -1;
        }
        i += 5;
      }
    }
    
    // Add more pattern checks here for other replacements

    i++;
  }

  // Remove marked elements
  int writeIndex = 0;
  for (int readIndex = 0; readIndex < length; readIndex++) {
    if (path[readIndex] != -1) {
      path[writeIndex] = path[readIndex];
      writeIndex++;
    }
  }

  length = writeIndex;
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Initialize the Serial Monitor
}

void loop() {
  current_dir = stra_dir;

  while (current_dir == stra_dir) {
    path[pathSize] = current_dir;
    pathSize++;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    usrcom = Serial.parseInt();
    if (usrcom == intersection) {
      current_dir = left_dir;
      Serial.println(current_dir);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize] = left_dir;
      pathSize++;
    } else if (usrcom == end_of_line) {
      current_dir = end_of_line;
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize] = back_dir;
      pathSize++;
    } else if (usrcom == right_dir) {
      current_dir = right_dir;
      Serial.println(current_dir);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      path[pathSize] = right_dir;
      pathSize++;

    }
  }

  // Print the path before shortening
  Serial.println("Path before shortening:");
  for (int i = 0; i < pathSize; i++) {
    Serial.print(path[i]);
    Serial.print(" ");
  }

  // Call the shortestPath function to simplify the path
  shortestPath(path, pathSize);

  // Print the simplified path
  Serial.println("\nSimplified Path:");
  for (int i = 0; i < pathSize; i++) {
    Serial.print(path[i]);
    Serial.print(" ");
  }
}
