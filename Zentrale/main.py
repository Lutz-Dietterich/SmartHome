
import time
import paho.mqtt.client as mqtt


def on_message(client, userdata, message):
    print("Nachricht erhalten: " + str(message.payload.decode("utf-8")))
          

def main():
    broker_address = "192.168.178.11"

    # client instanzieren
    client = mqtt.Client("master")
    client.on_message = on_message

    # verbindung aufbauen
    print("Verbindung zu Broker: " + broker_address)
    client.connect(broker_address)
    client.loop_start()

    # subscribe topic
    print("subscribe topic")
    client.subscribe("house/main")

    # sende nachricht
    print("Sende Nachricht...")
    client.publish("house/main", "Die Zentrale ist online")

    # warte auf nachricht
    print("Warte auf Nachricht...")
    time.sleep(4)



    # programm beenden
    print("Programm beenden")
    client.loop_stop()
    client.disconnect()

if __name__ == '__main__':
    main()


