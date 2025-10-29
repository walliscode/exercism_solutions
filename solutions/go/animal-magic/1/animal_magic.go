package chance

import "math/rand/v2"

// RollADie returns a random int d with 1 <= d <= 20.
func RollADie() int {
	return rand.IntN(20) + 1
}

// GenerateWandEnergy returns a random float64 f with 0.0 <= f < 12.0.
func GenerateWandEnergy() float64 {
	return rand.Float64() * 12.0
}

// ShuffleAnimals returns a slice with all eight animal strings in random order.
func ShuffleAnimals() []string {
	animalNames := []string{"ant", "beaver", "cat", "dog", "elephant", "fox", "giraffe", "hedgehog"}

	rand.Shuffle(len(animalNames), func(i, j int) {
		animalNames[i], animalNames[j] = animalNames[j], animalNames[i]
	})

	return animalNames
}
