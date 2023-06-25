import time
import paho.mqtt.client as mqtt

broker = "192.168.178.11"

client = mqtt.Client("sender")

client.connect(broker)

client.subscribe("house/main")

print("Sender gestartet")

client.loop_start()  # Hinzugefügter Befehl zum Starten der MQTT-Schleife

while True:
    client.publish("house/main", "Sensor 1 ist online")
    time.sleep(3)
