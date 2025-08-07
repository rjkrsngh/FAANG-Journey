class Test:
	name = "" #class variable
	_employeeID = None  #leading _ marks a member as private
	__salary = None #__ before a var name is to prevent name conflict

	def __init__(self, name, id, salary):
		self.name = name
		self._employeeID = id
		self.__salary = salary


	def __str__(self):
		return self.name

if __name__ == '__main__':
	t = Test("Raj Kumar", 7469, 1200000)
	print(t.name, t._employeeID, t._Test__salary)

