package main

import (
	"errors"
	"fmt"
	"slices"
)

type Stack struct {
	items []int
	count int
}

func (s *Stack) IsEmpty() bool {
	return (s.count == 0)
}

func (s *Stack) push(item int) {
	s.items = append(s.items, item)
	s.count++
}

func (s *Stack) pop() (int, error) {
	if s.count > 0 {
		item := s.items[s.count-1]
		s.items = slices.Delete(s.items, s.count-1, s.count)
		s.count--

		fmt.Println("Deleted", item, "from stack")
		return item, nil
	} else {
		return -1, errors.New("Stack is empty")
	}
}

func (s *Stack) PrintStack() {
	if !s.IsEmpty() {
		fmt.Println("Contents of stack")
		for _, item := range s.items {
			fmt.Println(item)
		}
	}
}

func main() {
	stack := Stack{}
	stack.push(1)
	stack.push(3)
	stack.push(2)

	stack.PrintStack()

	stack.pop()
	stack.push(5)

	stack.PrintStack()
	stack.pop()

	stack.PrintStack()
}
