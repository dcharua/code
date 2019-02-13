import socket
from Crypto.Cipher import AES, DES

message = "This is the plan"
aes_key = 'This is a key123'
des_key= b'-8B key-'

s=socket.socket()
s.connect(("localhost", 8000))

#AES
aes = AES.new(aes_key, AES.MODE_CBC, 'This is an IV456')
aes_text = aes.encrypt(message)
print(aes_text)
s.send(aes_text)


#DES
des = DES.new(des_key, DES.MODE_ECB)
des_text = des.encrypt(message)
print(des_text)
s.send(des_text)
