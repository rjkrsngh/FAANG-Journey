package main

/*Program 1: Using simple routine and channel within same function*/
/******************************************************************/
// func main() {
// 	fmt.Println("Program 1: Using 3 channels and both go routines in 1 function")
// 	odd := make(chan bool)
// 	even := make(chan bool)
// 	stop := make(chan bool)

// 	//Function to print even numbers
// 	go func() {
// 		start := 0

// 		for {
// 			select {
// 			case <-even:
// 				fmt.Println("Num:", start)
// 				start += 2
// 				if start > 10 {
// 					stop <- true
// 				} else {
// 					odd <- true
// 				}
// 			case <-stop:
// 				return
// 			}
// 		}
// 	}()

// 	//Function to print odd numbers
// 	go func() {
// 		start := 1

// 		for {
// 			select {
// 			case <-odd:
// 				fmt.Println("Num:", start)
// 				start += 2
// 				if start > 10 {
// 					stop <- true
// 				} else {
// 					even <- true
// 				}
// 			case <-stop:
// 				return
// 			}
// 		}
// 	}()

// 	defer close(odd)
// 	defer close(even)
// 	defer close(stop)

// 	even <- true

// 	fmt.Println("Done")
// }

/* Program 2: Using 3 Channels and 2 separate functions for even and odd*/
/************************************************************************/
// func PrintEven(max int, even, odd, done chan bool) {
// 	for num := 0; num <= max; num += 2 {
// 		<-even
// 		fmt.Println("Num:", num)
// 		odd <- true
// 	}

// 	done <- true
// }

// func PrintOdd(max int, odd, even chan bool) {
// 	for num := 1; num < max; num += 2 {
// 		<-odd
// 		fmt.Println("Num:", num)
// 		even <- true
// 	}
// 	close(even)
// }

// func main() {
// 	fmt.Println("Program 2: Using 3 Channels and 2 separate functions for even and odd")
// 	fmt.Println()

// 	odd := make(chan bool, 1)
// 	even := make(chan bool, 1)
// 	done := make(chan bool)

// 	max := 100
// 	go PrintEven(max, even, odd, done)
// 	go PrintOdd(max, odd, even)

// 	even <- true

// 	<-done
// }

/*Program 3: Using 2 channels and a WaitGroup*/
/*********************************************/
// func PrintEven(even, odd chan bool, wg *sync.WaitGroup) {
// 	defer wg.Done()

// 	for num := 0; num <= 10; num += 2 {
// 		<-even
// 		fmt.Println("Num:", num)
// 		odd <- true
// 	}
// }

// func PrintOdd(odd, even chan bool, wg *sync.WaitGroup) {
// 	defer wg.Done()

// 	for num := 1; num < 10; num += 2 {
// 		<-odd
// 		fmt.Println("Num:", num)
// 		even <- true
// 	}
// }

// func main() {
// 	fmt.Println("Program 3: Using 2 channels and a WaitGroup")
// 	fmt.Println()

// 	odd := make(chan bool, 1)
// 	even := make(chan bool, 1)

// 	wg := &sync.WaitGroup{}
// 	wg.Add(2)

// 	go PrintEven(even, odd, wg)
// 	go PrintOdd(odd, even, wg)

// 	even <- true
// 	wg.Wait()
// }

/* Program 4: Using Condition variable, mutex and a WaitGroup */
/**************************************************************/
// func PrintEven(isEven *bool, mtx *sync.Mutex, cond *sync.Cond, wg *sync.WaitGroup) {
// 	defer wg.Done()

// 	for num := 0; num <= 20; num += 2 {
// 		mtx.Lock()
// 		if !*isEven {
// 			cond.Wait()
// 		}

// 		fmt.Println("Num:", num)
// 		*isEven = false
// 		cond.Signal()
// 		mtx.Unlock()
// 	}
// }

// func PrintOdd(isEven *bool, mtx *sync.Mutex, cond *sync.Cond, wg *sync.WaitGroup) {
// 	defer wg.Done()

// 	for num := 1; num < 20; num += 2 {
// 		mtx.Lock()
// 		if *isEven {
// 			cond.Wait()
// 		}

// 		fmt.Println("Num:", num)
// 		*isEven = true
// 		cond.Signal()
// 		mtx.Unlock()
// 	}
// }

// func main() {
// 	fmt.Println("Program 4: Using Condition variable, mutex and a WaitGroup")
// 	fmt.Println()

// 	mutex := sync.Mutex{}
// 	condVar := sync.NewCond(&mutex)
// 	wg := &sync.WaitGroup{}
// 	isEven := true

// 	wg.Add(2)

// 	go PrintEven(&isEven, &mutex, condVar, wg)
// 	go PrintOdd(&isEven, &mutex, condVar, wg)

// 	wg.Wait()
// }

/* Program 5: Using multiple channels and receiving values in the main function*/
// func PrintEven(even chan int, isOdd, isEven, done chan bool) {
// 	defer close(even)
// 	for num := 0; num <= 20; num += 2 {
// 		<-isEven
// 		even <- num
// 		isOdd <- true
// 	}

// 	fmt.Println("Signalling done...")
// 	done <- true
// }

// func PrintOdd(odd chan int, isOdd, isEven, done chan bool) {
// 	defer close(odd)
// 	for num := 1; num < 20; num += 2 {
// 		<-isOdd
// 		odd <- num
// 		isEven <- true
// 	}

// 	done <- true
// }

// func main() {
// 	oddTurn := make(chan bool)
// 	evenTurn := make(chan bool)
// 	odd := make(chan int)
// 	even := make(chan int)
// 	done := make(chan bool)

// 	go PrintEven(even, oddTurn, evenTurn, done)
// 	go PrintOdd(odd, oddTurn, evenTurn, done)

// 	evenTurn <- true

// mainloop:
// 	for {
// 		select {
// 		case val, ok := <-even:
// 			if ok {
// 				fmt.Println("Num:", val)
// 			}
// 		case val, ok := <-odd:
// 			if ok {
// 				fmt.Println("Num:", val)
// 			}
// 		case <-done:
// 			fmt.Println("Print complete")
// 			// return
// 			break mainloop
// 		}
// 	}

// 	/* To execute below code:
// 	a. Label the infinite for loop(here mainloop).
// 	b. use break mainloop instead of return. */
// 	fmt.Println("All done finally")
// }
