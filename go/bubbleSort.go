package main

import (
	"fmt"
	"math/rand"
	"time"
)

// function to generate random array of numbers from 0 to 29
func randarray() []int {

	rand.Seed(time.Now().Unix())

	arr := rand.Perm(30)

	return arr
}

func bubbleSort(a[] int) {

	for i := 0; i < len(a)-1; i++ {

		for j := 0; j < len(a) - i - 1; j++ {

			if (a[j+1] < a[j]) {

				temp := a[j+1]
				a[j+1] = a[j]
				a[j] = temp
			}
		}
	}
}

func main() {

	array := randarray()

	fmt.Println("\nBefore sort:")
	fmt.Println(array)

	bubbleSort(array) // since I have fixed the size of the random array as 30

	fmt.Println("\nAfter sort:")
	fmt.Println(array)
}