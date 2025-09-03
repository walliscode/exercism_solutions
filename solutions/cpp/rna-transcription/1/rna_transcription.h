#pragma once

#include <string>
#include <unordered_map>
namespace rna_transcription {

static std::unordered_map<char, char> complement_map{
    {'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A', 'U'}};
std::string to_rna(const std::string &dna_sequence);
std::string to_rna(const char &single_letter_sequence);
} // namespace rna_transcription
