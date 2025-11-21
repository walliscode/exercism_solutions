// Package gross implements a simple gross store inventory and billing system.
package gross

// Units stores the Gross Store unit measurements.
func Units() map[string]int {
	return map[string]int{"quarter_of_a_dozen": 3, "half_of_a_dozen": 6, "dozen": 12, "small_gross": 120, "gross": 144, "great_gross": 1728}
}

// NewBill creates a new bill.
func NewBill() map[string]int {
	return make(map[string]int)
}

// AddItem adds an item to customer bill.
func AddItem(bill, units map[string]int, item, unit string) bool {
	_, unitExists := units[unit]

	// return false if the unit does not exist
	if !unitExists {
		return unitExists
	}

	// add the item to the bill, or update its quantity if it already exists
	value, ok := bill[item]
	if ok {
		bill[item] = value + units[unit]
	} else {
		bill[item] = units[unit]
	}
	return true
}

// RemoveItem removes an item from customer bill.
func RemoveItem(bill, units map[string]int, item, unit string) bool {
	_, unitExists := units[unit]
	if !unitExists {
		return false
	}
	value, itemExists := bill[item]
	if !itemExists {
		return false
	}
	if value < units[unit] {
		return false
	}
	if value == units[unit] {
		delete(bill, item)
	} else {
		bill[item] = value - units[unit]
	}
	return true
}

// GetItem returns the quantity of an item that the customer has in his/her bill.
func GetItem(bill map[string]int, item string) (int, bool) {
	value, ok := bill[item]

	if !ok {
		return 0, false
	}

	return value, true
}
