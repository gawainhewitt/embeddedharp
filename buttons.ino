//this function manages 4-state buttons (pressed, held, released, off)
unsigned int scrollTime = 250;
long unsigned int heldTimer = 0;
long unsigned int menuTimer = 0;


const byte buttonPins[] = {3,1,2,5,4}; //UP, LEFT, CENTRE, RIGHT, DOWN
byte buttonStates[NUM_BUTTONS];

void buttonUpdate() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    boolean buttonState = digitalRead(buttonPins[i]);
    if (buttonStates[i] == 3) {
      buttonStates[i] = 2;
      Serial.println(buttonStates[i]);
    }
    if ((buttonState == LOW) && (buttonStates[i] == 0)) {
      buttonStates[i] = 3;
      heldTimer = millis();
      menuTimer = millis();
      bigMenu = false;
    }
    if (buttonStates[i] == 1) {
      buttonStates[i] = 0;
    }
    if ((buttonState == HIGH) && (buttonStates[i] == 2)) {
      buttonStates[i] = 1;
    }
  }
  //0-off
  //3-momentary on
  //2-on
  //1-momentary off
}

//this function acts upon button presses
void buttonActions() {
  if (buttonStates[UP] == 3) {
    Serial.print("up menu: ");
    Serial.println(activeMenuInput);
    Serial.print("buttonState ");
    Serial.println(buttonStates[0]);
    activeMenuInput--;
  }

  if (buttonStates[DOWN] == 3) {
    Serial.print("down menu: ");
    Serial.println(activeMenuInput);
    activeMenuInput++;
  }

  if (buttonStates[LEFT] == 3) {
    switch (activeMenuInput) {
      case 0:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
      case 1:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
      case 2:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
      case 3:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
      case 4:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
      case 5:
        Serial.print("left menu: ");
        Serial.println(activeMenuInput);
        break;
    }
  }

  if (buttonStates[CENTRE] == 3) {
    switch (activeMenuInput) {
      case 0:
        Serial.print("centre menu: ");
        Serial.println(activeMenuInput);
        break;
      case 4:
        Serial.print("centre menu: ");
        Serial.println(activeMenuInput);
        break;
    }
  }

  if (buttonStates[RIGHT] == 3) {
    switch (activeMenuInput) {
      case 0:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
      case 1:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
      case 2:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
      case 3:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
      case 4:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
      case 5:
        Serial.print("right menu: ");
        Serial.println(activeMenuInput);
        break;
    }
  }

  if (activeMenuInput < 0) {
    activeMenuInput = menuItems - 1; //menu looping
  } else if (activeMenuInput > (menuItems - 1)) {
    activeMenuInput = 0;
  }

  for (int i = 0; i < NUM_BUTTONS; i++) {
    if ((buttonStates[i] == 2) && ((millis() - heldTimer) > scrollTime)) { //if a button has been held for enough time
      buttonStates[i] = 0;
      updateDisplayFlag = true;
      //saveState();
      return;
    } else if (buttonStates[i] == 1) { //if a button has been released
      updateDisplayFlag = true;
      return;
    }
  }

  if ((millis() - menuTimer) > 10000 && bigMenu == false) {
    bigMenu = true;
    updateDisplayFlag = true;
  }
}
