package utils

func InArrayBool(arr []bool, toFind bool) bool {
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
