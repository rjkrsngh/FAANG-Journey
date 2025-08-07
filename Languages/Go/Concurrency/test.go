package main

import (
	"fmt"
)

func PrintEven(max int, even chan int, evenTurn, oddTurn, done chan bool) {
	defer close(even)
	defer close(oddTurn)

	for num := 0; num <= max; num += 2 {
		<-evenTurn
		even <- num
		oddTurn <- true
	}

	done <- true
}

func PrintOdd(max int, odd chan int, oddTurn, evenTurn, done chan bool) {
	defer close(odd)
	defer close(evenTurn)

	for num := 1; num < max; num += 2 {
		<-oddTurn
		odd <- num
		evenTurn <- true
	}

	done <- true
}

func main() {
	fmt.Println("hello")

	even := make(chan int)
	odd := make(chan int)
	evenTurn := make(chan bool)
	oddTurn := make(chan bool)
	done := make(chan bool)

	max := 20
	go PrintEven(max, even, evenTurn, oddTurn, done)
	go PrintOdd(max, odd, oddTurn, evenTurn, done)

	evenTurn <- true

	for {
		select {
		case val := <-even:
			fmt.Println("Num:", val)
		case val := <-odd:
			fmt.Println("Num:", val)
		case <-done:
			fmt.Println("All done")
			return
		}
	}
}
