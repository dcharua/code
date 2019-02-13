import socket
from Crypto.Cipher import AES, DES

aes_key = 'This is a key123'
des_key= b'-8B key '

aes = AES.new(aes_key, AES.MODE_CBC, 'This is an IV456')
des = DES.new(des_key, DES.MODE_ECB)

s=socket.socket()
s.bind(("localhost", 8000))
s.listen()
c, address = s.accept()

with c:
    data=c.recv(1024)
    decipher_text= aes.decrypt(data)
    print(decipher_text)
    data=c.recv(1024)
    decipher_text= des.decrypt(data)
    print(decipher_text)
    c.close()
s.close()