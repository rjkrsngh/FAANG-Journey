#Types of inheritance supported in python
# 1. Single Inheritance
# 2. Multilevel Inheritance : Inheritance from a class which inherits from some other class
# 3. Multiple Inheritance
# 4. Hierarchial Inheritance:
# 5. Hybrid Inheritance

# Using double underscore before a member variable marks it private and is not inherited by child class.

class Father:
    def __init__(self, name, id, wife_name, child_name):
        self.fname = name
        self.__id = id
        self.__wifeName = wife_name
        self.__childName = child_name

    def display(self):
        print(self.name, self.__id)

    def print_details(self):
        print("Id: {}, name: {}".format(self.__id, self.name))

class Mother:
    def __init__(self, name, id, husband_name, child_name):
        self.mname = name
        self.__id = id
        self.__husbandName = husband_name
        self.__childName = child_name

    def display(self):
        print(self.name, self.__id)

    def print_details(self):
        print("Id: {}, name: {}".format(self.__id, self.name))

class Child(Father, Mother):
    def __init__(self, name, id, fatherName, motherName):
        Father.__init__(self, fatherName, id, motherName, name) # or | super().__init__(name, id)
        Mother.__init__(self, motherName, id, fatherName, name)

        self.name = name
        self.id = id

    def print_details(self):
        print("id: {}, name: {}, fatherName: {}".format(self.id, self.name, self.fname))

if __name__ == '__main__':
    child = Child('raj', 1, "Manoj Prasad Singh", 'Anima Devi')

    child.print_details()