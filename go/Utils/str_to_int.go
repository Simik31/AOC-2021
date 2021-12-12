package Utils

import "strconv"

func StrToInt(str string, base int) int {
	return int(StrToInt64(str, base))
}

func StrToInt8(str string, base int) int8 {
	return int8(StrToInt64(str, base))
}

func StrToInt16(str string, base int) int16 {
	return int16(StrToInt64(str, base))
}

func StrToInt32(str string, base int) int32 {
	return int32(StrToInt64(str, base))
}

func StrToInt64(str string, base int) int64 {
	value, err := strconv.ParseInt(str, base, 64)

	if err != nil {
		panic(err)
	}

	return value
}
