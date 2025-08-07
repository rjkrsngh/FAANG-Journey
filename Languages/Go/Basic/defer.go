package main

import (
	"fmt"
	"os"
)

// func main() {
// 	defer fmt.Println("Defer 1")
// 	defer fmt.Println("Defer 2")

// 	return
// }

// --> Proof that defer is called after return/panic <--
// --> Observe the sequence of defer statements and the output produced
// func CloseFile(file *os.File) {
// 	fmt.Println("Closing file")
// 	file.Close()
// }

// func main() {
// 	file, err := os.Create("test.txt")
// 	defer fmt.Println("File created")
// 	if err != nil {
// 		return
// 	}

// 	defer CloseFile(file)
// 	fmt.Println("Before return")
// }
