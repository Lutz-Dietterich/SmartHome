
import paho.mqtt.client as mqtt

def main():
    broker_address = "192.168.178.11"

    # client instanzieren
    client = mqtt.Client("master")

    # verbindung aufbauen
    print("Verbindung zu Broker: " + broker_address)
    client.connect(broker_address)

    # subscribe topic
    print("subscribe topic")
    client.subscribe("house/main")

    # sende nachricht
    print("Sende Nachricht...")
    client.publish("house/main", "Die Zentrale ist online")


if __name__ == '__main__':
    main()


