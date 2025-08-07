import os

class SimpleClass:
    system_type = os.name # Static/class variable, same for all objects
    def __init__(self, userId, name) -> None:
        #These are instance variables, unique to each instance
        self.name = name
        self.id = userId

    def __str__(self):
        return "I am " + self.name

if __name__ == '__main__' :
    rks = SimpleClass(1, 'Raj')
    aditi = SimpleClass(2, 'Aditi')

    print(rks, ", ", aditi)

    print('rks: user_id: {} is using {}'.format(rks.id, SimpleClass.system_type))
    print('aditi: user_id: {} is using {}'.format(aditi.id, SimpleClass.system_type))

    print()
    print("Modifying system_type for rks to LINUX using rks object")
    rks.system_type = "LINUX"

    print()
    print("After modifying system_type for rks to LINUX using rks object")
    print('rks: user_id: {} is using {}'.format(rks.id, rks.system_type))
    print('aditi: user_id: {} is using {}'.format(aditi.id, aditi.system_type))

    print()
    print("Modifying system_type to CHROME using the class")
    SimpleClass.system_type = 'CHROME'

    print()
    print("After modifying system_type to CHROME using class")
    print('rks: user_id: {} is using {}'.format(rks.id, rks.system_type))
    print('aditi: user_id: {} is using {}'.format(aditi.id, aditi.system_type))

