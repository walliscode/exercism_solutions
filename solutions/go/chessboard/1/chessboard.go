// Package chessboard provides types and functions to work with a chessboard representation.
package chessboard

// File represents a file (column) on a chessboard, containing eight squares.
type File []bool

// Chessboard represents an 8x8 chessboard using a map of files.
type Chessboard map[string]File

// CountInFile returns how many squares are occupied in the chessboard,
// within the given file.
func CountInFile(cb Chessboard, file string) int {
	occupiedCount := 0

	fileOfInterest, ok := cb[file]

	// if file not found return early
	if !ok {
		return 0
	}

	for _, v := range fileOfInterest {
		if v {
			occupiedCount++
		}
	}

	return occupiedCount
}

// CountInRank returns how many squares are occupied in the chessboard,
// within the given rank.
func CountInRank(cb Chessboard, rank int) int {
	if rank < 1 || rank > 8 {
		return 0
	}

	occupiedCount := 0

	for _, file := range cb {
		if file[rank-1] {
			occupiedCount++
		}
	}

	return occupiedCount
}

// CountAll should count how many squares are present in the chessboard.
func CountAll(cb Chessboard) int {
	occupiedCount := 0
	for _, fileOfInterest := range cb {
		occupiedCount += len(fileOfInterest)
	}

	return occupiedCount
}

// CountOccupied returns how many squares are occupied in the chessboard.
func CountOccupied(cb Chessboard) int {
	occupiedCount := 0
	for _, file := range cb {
		for _, v := range file {
			if v {
				occupiedCount++
			}
		}
	}

	return occupiedCount
}
