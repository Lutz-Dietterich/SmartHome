
import paho.mqtt.client as mqtt

def main():
    broker_address = "192.168.178.11"

    # client instanzieren
    client = mqtt.Client("master")

    # verbindung aufbauen
    client.connect(broker_address)

    # subscribe topic
    client.subscribe("house/main")

    # sende nachricht
    client.publish("house/main", "Die Zentrale ist online")


if __name__ == '__main__':
    main()


