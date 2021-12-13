package Utils

func InArrayBool(arr []bool, toFind bool) bool {
	for index := range arr {
		if arr[index] == toFind {
			return true
		}
	}

	return false
}

func InArrayString(arr []string, toFind string) bool {
	for index := range arr {
		if arr[index] == toFind {
			return true
		}
	}

	return false
}

func InArrayPair(arr []Pair, toFind Pair) bool {
	for index := range arr {
		if arr[index].First == toFind.First && arr[index].Second == toFind.Second {
			return true
		}
	}

	return false
}

func IndexOf(arr []string, toFind string) int {
	for index := range arr {
		if arr[index] == toFind {
			return index
		}
	}

	return -1
}

func RemoveAt(arr []string, index int) []string {
	return append(arr[:index], arr[index+1:]...)
}

func RemoveAtBool(arr []bool, index int) []bool {
	return append(arr[:index], arr[index+1:]...)
}

func RemoveAtArrayBool(arr [][]bool, index int) [][]bool {
	return append(arr[:index], arr[index+1:]...)
}
