#include <iostream>
#include <string>
#include <cctype>

// Function to evaluate password complexity
int evaluatePassword(const std::string& password) {
    int length = password.length();
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        else if (std::islower(c)) hasLower = true;
        else if (std::isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    return (length >= 8) + hasUpper + hasLower + hasDigit + hasSpecial;
}

// Function to determine password strength
std::string checkPasswordStrength(const std::string& password) {
    switch (evaluatePassword(password)) {
        case 5: return "Strong";
        case 4: return "Normal";
        case 3: return "Moderate";
        default: return "Weak";
    }
}

int main() {
    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;

    std::cout << "Password strength: " << checkPasswordStrength(password) << std::endl;
    return 0;
}
