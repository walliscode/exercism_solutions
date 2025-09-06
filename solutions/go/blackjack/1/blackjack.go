// Package blackjack provides functions to evaluate and make decisions in a game of blackjack.
package blackjack

// ParseCard returns the integer value of a card following blackjack ruleset.
func ParseCard(card string) int {
	switch card {

	case "ace":
		return 11
	case "two":
		return 2
	case "three":
		return 3
	case "four":
		return 4
	case "five":
		return 5
	case "six":
		return 6
	case "seven":
		return 7
	case "eight":
		return 8
	case "nine":
		return 9
	case "ten", "jack", "queen", "king":
		return 10
	default:
		return 0
	}
}

// FirstTurn returns the decision for the first turn, given two cards of the
// player and one card of the dealer.
func FirstTurn(card1, card2, dealerCard string) string {
	// if a pair of aces is dealt, always split them
	if card1 == "ace" && card2 == "ace" {
		return "P"
	}
	sumCards := ParseCard(card1) + ParseCard(card2)
	if sumCards == 21 {
		if dealerCard == "ace" || ParseCard(dealerCard) == 10 {
			return "S"
		} else {
			return "W"
		}
	}

	if sumCards >= 17 && sumCards <= 20 {
		return "S"
	} else if sumCards >= 12 && sumCards <= 16 {
		if ParseCard(dealerCard) >= 7 {
			return "H"
		} else {
			return "S"
		}
	} else {
		return "H"
	}
}
