#include <iostream>
#include <string>
#include <cctype>

// Function to check if the password contains uppercase characters
bool containsUpperCase(const std::string& password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains lowercase characters
bool containsLowerCase(const std::string& password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains digits
bool containsDigit(const std::string& password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains special characters
bool containsSpecialChars(const std::string& password) {
    for (char c : password) {
        if (!std::isalnum(c)) {
            return true;
        }
    }
    return false;
}

// Function to check the strength of the password
std::string checkPasswordStrength(const std::string& password) {
    int length = password.length();
    int complexity = 0;

    if (length >= 8) {
        complexity++;
    }
    if (containsUpperCase(password)) {
        complexity++;
    }
    if (containsLowerCase(password)) {
        complexity++;
    }
    if (containsDigit(password)) {
        complexity++;
    }
    if (containsSpecialChars(password)) {
        complexity++;
    }

    if (complexity < 3) {
        return "Weak";
    } else if (complexity == 3) {
        return "Normal";
    } else if (complexity == 4){
        return "Normal";
    } else {
        return "Strong";
    }
}

int main() {
    std::string password;

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::string strength = checkPasswordStrength(password);
    std::cout << "Password strength: " << strength << std::endl;

    return 0;
}
