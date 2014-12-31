package main

import (
        "fmt"
        "errors"
        "os"
)

const (
	LENGTH = 1000000
)

var (
	NotFound = errors.New("length too low Not found")
)

type DataPirmes struct {
	Data [LENGTH]int8
}

func (this *DataPirmes)InitPrimes() {
	for index := 2; index < LENGTH; index++ {
		if this.Data[index] == 0 {
			for mutil := 2; mutil*index < LENGTH; mutil++ {
				this.Data[mutil*index]++
			}
		}
	}
}

func (this DataPirmes)GetStartNum()(int, error) {
	for i := 2; i+3 < LENGTH; i++ {
		if (this.Data[i] == 4) && (this.Data[i+1] == 4) && (this.Data[i+2] == 4) && (this.Data[i+3] == 4){
			return i, nil
		}
	}
	return 2, NotFound
}

func (this DataPirmes)Factorization(num int) []int{
	factor := []int{}
	index := 2
	for ; num != 1; {
		if this.Data[index] == 0 {
			for ; num%index == 0;  {
				factor = append(factor,index)
				num /= index
			}
		}
		index ++
	}
	return factor
}

func main() {
	s := new(DataPirmes)
	s.InitPrimes()
	start, err := s.GetStartNum()
	if err != nil {
		fmt.Print(err)
		os.Exit(0)
	}
	fmt.Println("Below is this solution ")
	for i := 0; i < 4; i++ {
		fmt.Print(start+i, " : ")
		result := s.Factorization(start+i)
		fmt.Println(result)
	}
}
