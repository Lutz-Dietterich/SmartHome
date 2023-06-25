import time
import paho.mqtt.client as mqtt


def on_message(client, userdata, message):
    print("EMPFANGEN: " + str(message.payload.decode("utf-8")))


broker = "192.168.178.11"

client = mqtt.Client("receiver")

client.connect(broker)
client.on_message = on_message

client.subscribe("house/main")
client.loop_start()

print("Empfänger gestartet")

time.sleep(60)  # Der Empfänger wird für 60 Sekunden aktiv bleiben und dann stoppen

client.loop_stop()
client.disconnect()
