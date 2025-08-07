#Enums are implemented as classes using enum module
#Each enum item has a name and value associated
#Enums are iterable.
#Enums are compared for 
#   Identity: using 'is' and 'is not'
#   Equality: using == and !=


from enum import Enum

class Color(Enum):
    red = 1
    blue = 2
    green = 3

for color in Color:
    print(color.name, color.value)

#Comparing Enums
if Color.red is Color.blue:
    print('red and blue are same objects')
else:
    print('red and blue are different')
    
if Color.red != Color.blue:
    print('red and blue are not equal')
else:
    print('red and blue are same')