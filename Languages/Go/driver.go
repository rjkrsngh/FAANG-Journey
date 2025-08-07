package main

import (
	"fmt"
	"my-project/test"

	"github.com/enescakir/emoji"
)

type Author struct {
	name       string
	numOfBooks int
}

func (author Author) printAuthor(name string) {
	fmt.Println("Author:", name, ", numOfBooks:", author.numOfBooks)
}

func (author *Author) addBookCount(name string) {
	if author.name == name {
		author.numOfBooks++
	}
}

func printClientDetails(client test.Client) {
	fmt.Println(client.Name, client.Age, client.MemberSince)
}

func main() {
	author := Author{
		name:       "rks",
		numOfBooks: 12,
	}

	author.printAuthor("rks")
	author.addBookCount("rks")
	author.printAuthor("rks")

	client := test.GetClient()
	printClientDetails(client)

	fmt.Println(emoji.SadButRelievedFace)
}
