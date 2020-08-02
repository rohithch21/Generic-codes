import socket
import time

HEADERSIZE = 10
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((socket.gethostname(),1234))
s.listen(5)

while True:
    clientsocket,addr = s.accept()
    print(f"The connection from {addr} has been established")
    msg = "Welcome to my Server!"
    msg = f"{len(msg):<{HEADERSIZE}}"+msg
    clientsocket.send(bytes(msg,"utf-8"))
    while True:
        time.sleep(3)
        msg = f"The time is {time.time()}"
        msg = f"{len(msg):<{HEADERSIZE}}"+msg
        print(msg)
        clientsocket.send(bytes(msg,"utf-8"))

    # clientsocket.close()


