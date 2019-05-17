#Daniel Charua A01017419
import numpy as np


s =  np.array([0.5, 0.288, 0.211]) 
#JOHN, Cleanco, Beach
transition = np.array([[0.7,0.23,0.07],[0.066,0.8,0.134],[0.18,0.32,0.5]])
trans_a = s
for i in range(100000):
    trans_a = np.matmul(trans_a, transition)
print("\n a) Si John si se mantiene arriba del 15% porciento :\n\t", trans_a)
print("\n b)Si le daria el prestama a John ya que se mantiene en equilibro con un 23% + /-.")