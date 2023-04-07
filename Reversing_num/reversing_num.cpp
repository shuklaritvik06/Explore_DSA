#include <iostream>

int main() {
  unsigned long long int input_num, output_num = 0;
  std::cin >> input_num;
  for (; input_num != 0; input_num /= 10) {
    output_num = output_num * 10 + input_num % 10;
  }
  std::cout << output_num;

  return 0;
}
