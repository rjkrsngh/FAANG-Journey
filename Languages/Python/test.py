def parent():
    x = "I am from parent"
    def child():
        # print("I am from Child")
        print(x)    
    return child

x = parent()
x()