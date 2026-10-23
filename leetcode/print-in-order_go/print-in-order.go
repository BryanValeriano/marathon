package main

import (
	"fmt"
	"sync"
	"time"
)

type Foo struct {
	c1 chan struct{}
	c2 chan struct{}
}

func NewFoo() *Foo {
	return &Foo{
		c1: make(chan struct{}),
		c2: make(chan struct{}),
	}
}

func (f *Foo) First(printFirst func()) {
	// Do not change this line
	printFirst()
	f.c1 <- struct{}{}
}

func (f *Foo) Second(printSecond func()) {
	/// Do not change this line
	<-f.c1
	printSecond()
	f.c2 <- struct{}{}
}

func (f *Foo) Third(printThird func()) {
	// Do not change this line
	<-f.c2
	printThird()
}

func main() {
	foo := NewFoo()
	var wg sync.WaitGroup
	wg.Add(3)
	go func() {
		defer wg.Done()
		foo.Third(func() { fmt.Println("third") })
	}()
	time.Sleep(1 * time.Microsecond)
	go func() {
		defer wg.Done()
		foo.Second(func() { fmt.Println("second") })
	}()
	time.Sleep(1 * time.Microsecond)
	go func() {
		defer wg.Done()
		foo.First(func() { fmt.Println("first") })
	}()

	wg.Wait()
	fmt.Println("main finish")
}
