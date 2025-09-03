// Package weather provide weather conditions at a given location.
package weather

var (
	// CurrentCondition stores the city location.
	CurrentCondition string

	// CurrentLocation stores the weather condition.
	CurrentLocation string
)

// Forecast returns the condtion of given city.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
