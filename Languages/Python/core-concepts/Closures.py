def OuterMethod(name, age):
    def InnerMethod():
        name = 'abc'
        age = 21

        print(name, age)

    return InnerMethod

if __name__ == '__main__':
    NewFunc = OuterMethod('raj', 25)
    NewFunc()