import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 1234))

HEADERSIZE = 10
new_msg = True

while True:
    fullmsg = ""
    new_msg = True
    while True:
        msg = s.recv(16)
        if new_msg:
            msglen = int(msg[:HEADERSIZE])
            new_msg = False
        print("curr msg : ",msg)
        fullmsg = fullmsg + msg.decode('utf-8')

        if len(fullmsg) - HEADERSIZE  == msglen:
            print(fullmsg[HEADERSIZE:])
            print("Message Received fully")
            break
