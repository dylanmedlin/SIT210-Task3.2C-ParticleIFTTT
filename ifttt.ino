int photoresistor = A5;
int lightValue = 0;
bool isLight = false;

void setup() {
  pinMode(photoresistor, INPUT);
  Particle.variable("lightValue", lightValue);
}

void loop() {
    // read light data
    lightValue = analogRead(photoresistor);
    
    // if in sunlight
    if (lightValue > 40) {
        // if value has changed
        if (isLight == false) {
            isLight = true;
            Particle.publish("isLight", "true");
        }
    // not in sunlight
    } else {
        // if value has changed
        if (isLight == true) {
            isLight = false;
            Particle.publish("isLight", "false");
        }
    }
    
    delay(1000);
}
