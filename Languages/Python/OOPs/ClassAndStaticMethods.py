#class Person:
#    '''This class simulates class and static method in python'''
#
#   CLASS METHOD
#   Syntax:
#   @classmethod
#   def method(class, params):
#       '''Class method is available only to class not to instances and can 
#           change the state of a class'''
#       pass
#
#   STATIC METHOD
#   Syntax:
#   @staticmethod
#   def method(params):
#       '''Static method is available only to class not to instances. These methods
#           cannot change the state of a class'''
#       pass

from datetime import date

class Person:
    __birth_year = 0
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def CreateObjectFromBirthYear(ClassName, name, year):
        return ClassName(name, date.today().year - year)

    @staticmethod
    def IsPersonAdult(age):
        return age>=18

if __name__ == '__main__':
    obj1 = Person("abc", 43)
    
    if(obj1.IsPersonAdult(12)):
        print("Person is adult")
    else:
        print("Person is a child")