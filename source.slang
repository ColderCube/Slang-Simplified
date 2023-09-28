int x; // Variable declaration statement

fn add(int a, int b) : int { // Function definition statement
    return a + b;
}

fn multiply(int a, int b) : int; // Function declaration statement

fn multiply(int a, int b) : int { // Function definition statement
    return a * b;
}

int num1 = 10;
int num2 = 5;

if (num1 > num2) { // If statement
    int result = add(num1, num2);
    int product = multiply(num1, num2);
} else {
    int result = add(num2, num1);
    int product = multiply(num2, num1);
}

while (num1 > 0) { // While statement
    num1 = num1 - 1;
}

do { // Do-while statement
    num2 = num2 - 1;
} while (num2 > 0);

bool flag = true && (false || true); // Boolean statement

char grade = 'A';

string message = "Hello, World!";

