#include "rna_transcription.h"
#include <unordered_map>

namespace rna_transcription {

std::string to_rna(const std::string &dna_sequence) {
  std::string complement;

  for (const char &c : dna_sequence) {
    complement.push_back(complement_map[c]);
  }

  return complement;
}

std::string to_rna(const char &single_letter_sequence) {
  std::string complement;

  complement.push_back(complement_map[single_letter_sequence]);

  return complement;
}
} // namespace rna_transcription
