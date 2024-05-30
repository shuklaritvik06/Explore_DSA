#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class PrefixConverter {
 public:
  explicit PrefixConverter(const std::vector<int>& prefixFunction);
  [[nodiscard]] std::string convert() const;

 private:
  std::vector<int> prefixFunction;
};

class InputHandler {
 public:
  static std::vector<int> readPrefixFunction();
};

PrefixConverter::PrefixConverter(const std::vector<int>& prefixFunction)
    : prefixFunction(prefixFunction) {}

std::string PrefixConverter::convert() const {
  std::string result;
  std::vector<char> supportiveElements(prefixFunction.size(), '\0');

  if (!prefixFunction.empty()) {
    result += 'a';
    supportiveElements[0] = 'b';
    for (unsigned long i = 1; i < prefixFunction.size(); ++i) {
      int previous = i - 1;
      int predecessor = prefixFunction[i] - 1;
      if (prefixFunction[i] == 0) {
        result += supportiveElements[previous];
      } else {
        result += result[predecessor];
      }
      if (predecessor >= 0) {
        supportiveElements[i] =
            std::max(supportiveElements[predecessor],
                     static_cast<char>(result[predecessor + 1] + 1));
      } else {
        supportiveElements[i] = 'b';
      }
    }
  }
  return result;
}

std::vector<int> InputHandler::readPrefixFunction() {
  std::string inputString;
  std::getline(std::cin, inputString);
  std::istringstream is(inputString);
  return std::vector<int>((std::istream_iterator<int>(is)),
                          std::istream_iterator<int>());
}

int main() {
  std::vector<int> prefixFunction = InputHandler::readPrefixFunction();
  PrefixConverter converter(prefixFunction);
  std::string result = converter.convert();
  std::cout << result << "\n";
  return 0;
}
