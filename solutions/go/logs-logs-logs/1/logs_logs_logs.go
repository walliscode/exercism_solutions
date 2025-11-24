// Package logs provides functions to analyze and manipulate log entries.
package logs

import "unicode/utf8"

// Application identifies the application emitting the given log.
func Application(log string) string {
	for _, value := range log {
		switch value {
		case '❗':
			return "recommendation"
		case '🔍':
			return "search"
		case '☀':
			return "weather"
		default:
			continue
		}
	}

	return "default"
}

// Replace replaces all occurrences of old with new, returning the modified log
// to the caller.
func Replace(log string, oldRune, newRune rune) string {
	// declare storage slice for runes
	logAsRunes := []rune{}

	// add each rune to the slice and replace as needed
	for _, value := range log {
		if value == oldRune {
			logAsRunes = append(logAsRunes, newRune)
		} else {
			logAsRunes = append(logAsRunes, value)
		}
	}

	return string(logAsRunes)
}

// WithinLimit determines whether or not the number of characters in log is
// within the limit.
func WithinLimit(log string, limit int) bool {
	return utf8.RuneCountInString(log) <= limit
}
