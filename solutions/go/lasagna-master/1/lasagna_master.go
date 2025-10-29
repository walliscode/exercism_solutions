package lasagna

func PreparationTime(layers []string, avg_prep_time int) int {
	prepTime := 0
	time_per_layer := 2
	if avg_prep_time != 0 {
		time_per_layer = avg_prep_time
	}

	prepTime = time_per_layer * len(layers)
	return prepTime
}

func Quantities(layers []string) (noodles int, sauce float64) {
	noodleLayers := 0
	sauceLayers := 0
	for _, layer := range layers {
		if layer == "noodles" {
			noodleLayers++
		} else if layer == "sauce" {
			sauceLayers++
		}

		noodles = 50 * noodleLayers
		sauce = 0.2 * float64(sauceLayers)
	}
	return noodles, sauce
}

func AddSecretIngredient(friendIngredients []string, myIngredients []string) {
	myIngredients[len(myIngredients)-1] = friendIngredients[len(friendIngredients)-1]
}

func ScaleRecipe(quantities []float64, portions int) []float64 {
	scaledQuantities := make([]float64, len(quantities))

	for i, v := range quantities {
		scaledQuantities[i] = v * float64(portions) * 0.5
	}
	return scaledQuantities
}
