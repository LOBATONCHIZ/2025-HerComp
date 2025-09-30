#include <print>
#include <string>
#include <vector>

int main() {
    std::string name = "juan";
    int age = 22;
    double height = 1.78;

    // Simple printing
    std::print("Hello, world!\n");

    // Printing variables
    std::print("Name: {}, Age: {}\n", name, age);

    // Formatting floating-point numbers (e.g., scientific)
    std::println("Height: {:.16e} meters", height);

    // Printing a container (like a vector) requires std::format
    std::vector<int> numbers = {10, 20, 30};
    std::println("Numbers: {}\n", numbers);
    std::println("Numbers: {::>05}\n", numbers);

  return 0;
}