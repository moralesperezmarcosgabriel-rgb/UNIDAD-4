# include"DHT.h" 

#define DHTPIN 6  // Pin donde esta conectado al DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();

}

void loop(){
  delay (2000); // Espera 2 segundos entre lecturas

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan (t)){
    Serial.println("Error al leer del sensor DHT11");
    return;
  }

  Serial.print(t);
  Serial.print(",");
  Serial.println(h);
}
