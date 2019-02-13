def cifrarBloque(bloque, llave):
    cifrado=""
    for i in range(0, 4):
        cifrado+=chr(ord(bloque[i]) ^ llave[i])
    return cifrado    

def ECG(mensaje, llaveTexto):
    if len(mensaje)%4!=0:
        for i in range(0, 4-int(len(mensaje)%4)):
            mensaje+="!"
    llave=[]
    for c in llaveTexto:
        llave.append(ord(c))
    cifrado=""    
    for i in range(0, int(len(mensaje)/4)):
        cifrado+=cifrarBloque(mensaje[(i*4):(i*4)+4], llave)
    return cifrado

texto = ECG("este es el mensaje", 'lave')
print(texto)
des= ECG(texto, 'lave')         
print (des)   
