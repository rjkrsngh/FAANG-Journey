def decorate_message(func):
    print("Entered decorate_message")
    def add_welcome(site_name):
        print("Inside add_welcome")
        res = "welcome to " + func(site_name)
        print("add_welcome\'s task completed")
        return res
    
    print("returning add_welcome")
    return add_welcome

@decorate_message
def site(site_name):
    print("inside site_name")
    return site_name

print(site("rks.com"))


#Decorator with a return value
# def hello_decorator(func):
# 	def inner1(*args, **kwargs):
		
# 		print("before Execution")
		
# 		# getting the returned value
# 		returned_value = func(*args, **kwargs)
# 		print("value returned: ", returned_value)
# 		print("after Execution")
		
# 		# returning the value to the original frame
# 		return returned_value
		
# 	return inner1


# # adding decorator to the function
# @hello_decorator
# def sum_two_numbers(a, b):
# 	print("Inside the function")
# 	return a + b

# a, b = 1, 2

# # getting the value through return of the function
# print("Sum =", sum_two_numbers(a, b))


# Decorator chaining
# def decor1(func):
# 	def inner():
# 		print("Derorator 1")
# 		x = func()
# 		return x * x
# 	return inner

# def decor(func):
# 	def inner():
# 		print("Decorator 2")
# 		x = func()
# 		return 2 * x
# 	return inner

# @decor1
# @decor
# def num():
# 	return 10

# print(num())
