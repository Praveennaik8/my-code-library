from ex2 import clear

import random as rd
clear()
def code(str1,cod):
    res = ''
    i=65
    for char in str1:
        if char != ' ':
            res+= chr((ord(char)- cod))
        else:
            res+= chr(331) 
            
        res+= chr(i)
        i+=1
    return res




str1 =str(input("enter your string\n"))

str1 = code(str1,13)
# for i in range(400):
#     print(i,chr(i))
print("ciphertext = ", str1)



