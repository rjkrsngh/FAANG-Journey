class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

class ClassOperatorOverloading:
    def __init__(self, value) -> None:
        self.value = value
    
    #Arithmetic Operator Overloading
    def __add__(self, obj):
        '''This method overloads the + operator'''
        print("Adding 2 complex numbers")
        if isinstance(obj, ClassOperatorOverloading):
            return (self.real + obj.real, self.imag + obj.imag)
        else:
            raise ValueError("obj does not belong to ClassOperatorOverloading")

    def __sub__(self, obj):
        '''This method overloads the - operator'''
        print('Performing subtraction on complex numbers')
        if isinstance(obj, ClassOperatorOverloading):
            return (self.real - obj.real, self.imag - obj.imag)
        else:
            raise ValueError("obj does not belong to ClassOperatorOverloading")

    def __gt__(self, obj):
        '''This method overloads the > operator'''
        pass

    def __lt__(self, obj):
        '''This method overloads the < operator'''
        pass

    def __eq__(self, obj):
        '''This method overloads the == operator'''
        pass

    #Bitwise Operator Overloading
    def __and__(self, obj):
        if isinstance(obj, ClassOperatorOverloading):
            return self.value & obj.value
        
    def __or__(self, obj):
        if isinstance(obj, ClassOperatorOverloading):
            return self.value | obj.value
        
    def __xor__(self, obj):
        if isinstance(obj, ClassOperatorOverloading):
            return self.value ^ obj.value
        
    def __invert__(self, obj):
        if isinstance(obj, ClassOperatorOverloading):
            return ~self.value
        
    def __lshift__(self, numOfBits):
        return self.value << int(numOfBits)
    
    def __rshift__(self, numOfBits):
        return self.value >> int(numOfBits)

if __name__ == '__main__':
    obj1 = Complex(1,2)
    obj2 = Complex(1,2)

    obj3 = obj1 + obj2
    print(obj3)
