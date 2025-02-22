#pragma once

#include <regex>
#include <fstream>
#include <sstream>
#include <vector>

#include "../aer.hpp"
#include "../generator.hpp"

#include "utils.hpp"

struct CSV : FileBase {

  Generator<AER::Event> stream(const int64_t n_events = -1) {
    std::string line;
    std::smatch event_match;
    size_t sum = 0;
    while (std::getline(file_stream, line) && (n_events < 0 || sum < n_events)) {
      std::regex_match(line, event_match, csv_regex);
      co_yield AER::Event{std::stol(event_match[0]), std::stoi(event_match[1]), std::stoi(event_match[2]), std::stoi(event_match[3]) > 0};
      sum++;
    }
    co_return;
  }

  std::tuple<AER::Event *, size_t> read_events(const int64_t n_events = -1) {
    size_t sum = 0;
    Generator<AER::Event> event_stream = stream(n_events);
    std::vector<AER::Event> event_vector;
    for (auto event: event_stream) {
      event_vector.push_back(event);
    }
    return {event_vector.data(), event_vector.size()};
  }
  
  explicit CSV(const std::string &filename) : file_stream(filename), 
    csv_regex("(\\d+),(\\d+),(\\d+),(\\d+)") {}

private:
  std::ifstream file_stream;
  const std::regex csv_regex;

};