#include <string>

namespace log_line {
std::string message(std::string line) {
  // find ":", move pointer 2 places to account for space
  size_t log_message_start(line.find(":") + 2);

  // find end of message
  size_t log_message_end(line.max_size() - 1);

  // get size of message
  size_t log_message_size{log_message_start - log_message_end};

  // return the message
  return line.substr(log_message_start, log_message_size);
}

std::string log_level(std::string line) {
  // find first occurance of "["
  size_t log_level_start{line.find("[") + 1};
  size_t log_level_end{line.find("]")};
  size_t log_level_length{log_level_end - log_level_start};
  // return the log level
  //
  return line.substr(log_level_start, log_level_length);
}

std::string reformat(std::string line) {
  // return the reformatted message
  std::string reformatted_message{message(line) + " " + "(" + log_level(line) +
                                  ")"};
  return reformatted_message;
}
} // namespace log_line
