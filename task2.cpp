#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;

class Node {
public:
    unsigned int data; // Data stored in the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node

    // Constructor to initialize node with integer data
    Node(unsigned int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Constructor to initialize node with string data
    Node(string data) {
        // Check if the string represents a number too large for a 32-bit integer
        if (data.size() == 10){
            if (data[0] == '3' || data[0] == '4' || data[0] == '5' || data[0] == '6' || data[0] == '7' || data[0] == '8' || data[0] == '9') {
                cout << "Number is too large to store in 32 bit long integer" << endl;
                throw invalid_argument("Number is too large to store in 32 bit long integer");
            }
            else if(data[0] == '2'){
                if (data[1] > '1') {
                    cout << "Number is too large to store in 32 bit long integer" << endl;
                    throw invalid_argument("Number is too large to store in 32 bit long integer");
                }
                else if(data[1] == '1'){
                    if (data[2] > '4') {
                        cout << "Number is too large to store in 32 bit long integer" << endl;
                        throw invalid_argument("Number is too large to store in 32 bit long integer");
                    }
                    else if(data[2] == '4'){
                        if (data[3] > '7') {
                            cout << "Number is too large to store in 32 bit long integer" << endl;
                            throw invalid_argument("Number is too large to store in 32 bit long integer");
                        }
                        else if(data[3] == '7'){
                            if (data[4] > '4') {
                                cout << "Number is too large to store in 32 bit long integer" << endl;
                                throw invalid_argument("Number is too large to store in 32 bit long integer");
                            }
                            else if(data[4] == '4'){
                                if (data[5] > '8') {
                                    cout << "Number is too large to store in 32 bit long integer" << endl;
                                    throw invalid_argument("Number is too large to store in 32 bit long integer");
                                }
                                else if(data[5] == '8'){
                                    if (data[6] > '3') {
                                        cout << "Number is too large to store in 32 bit long integer" << endl;
                                        throw invalid_argument("Number is too large to store in 32 bit long integer");
                                    }
                                    else if(data[6] == '3'){
                                        if (data[7] > '6') {
                                            cout << "Number is too large to store in 32 bit long integer" << endl;
                                            throw invalid_argument("Number is too large to store in 32 bit long integer");
                                        }
                                        else if(data[7] == '6'){
                                            if (data[8] > '8') {
                                                cout << "Number is too large to store in 32 bit long integer" << endl;
                                                throw invalid_argument("Number is too large to store in 32 bit long integer");
                                            }
                                            else if(data[8] == '8'){
                                                if (data[9] > '5') {
                                                    cout << "Number is too large to store in 32 bit long integer" << endl;
                                                    throw invalid_argument("Number is too large to store in 32 bit long integer");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        // Convert string to integer and initialize node
        this->data = stoi(data);
        this->next = NULL;
        this->prev = NULL;
    }

    // Method to get the nth digit of the node's data. Required for arithmetic operations
    int getNthDigit(int n) {
        if (n < 0 || n > 8) { // Adjust the valid range
            cout << "Invalid digit number get" << endl;
            throw invalid_argument("N is not in the range of 0-8");
        }
        
        int temp = this->data;
        for (int i = 0; i < n; i++) {
            temp /= 10;
        }
        
        return temp % 10;
    }

    // Method to set the nth digit of the node's data. Required for arithmetic operations
    void setNthDigit(int n, int digit) {
        if (n < 0 || n > 8) { // Adjust the valid range
            cout << "Invalid digit number set" << endl;
            throw invalid_argument("N is not in the range of 0-8");
        }
        
        if (digit < 0 || digit > 9) { // Check valid digit
            cout << "Invalid digit value set" << endl;
            throw invalid_argument("Digit must be between 0 and 9");
        }

        int pow10 = 1; 
        for (int i = 0; i < n; i++) {
            pow10 *= 10;
        }

        int currentDigit = (this->data / pow10) % 10;
        this->data = this->data - currentDigit * pow10 + digit * pow10;
    }

    // Method to get the length of the integer stored in the node
    int getLengthofInt(){
        int temp = this->data;
        int count = 0;
        while (temp > 0){
            temp = temp / 10;
            count++;
        }
        return count;
    }

    // Method to print the node's data
    void printNode() {
        for (int i = 8; i >= 0; i--) {
            cout << getNthDigit(i);
        }
    }
};

class LinkedList {  
public:
    Node* head; // Pointer to the head of the linked list
    Node* tail; // Pointer to the tail of the linked list

    // Default constructor
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    // Constructor to initialize linked list from a string
    LinkedList(string data){
        this->head = NULL;
        this->tail = NULL;
        int n = data.size() - 9;
        int block_size = 9;
        while (1){
            if (n <= 0){
                // Add the remaining part of the string
                this->prependNode(data.substr(0, block_size + n));
                break;
            }
            // Add blocks of 9 characters
            this->prependNode(data.substr(n, block_size));
            n = n - block_size;
        }
    }

    // Overload the < operator to compare two linked lists
    bool operator<(LinkedList* list){
        int n1 = this->get_num_digits();
        int n2 = list->get_num_digits();
        if (n1 < n2){
            return true;
        }
        else if (n1 > n2){
            return false;
        }
        Node* temp1 = this->head;
        Node* temp2 = list->head;
        while (temp1 != NULL && temp2 != NULL){
            if (temp1->data < temp2->data){
                return true;
            }
            else if (temp1->data > temp2->data){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return false;
    }

    // Overload the < operator to compare linked list with an integer
    bool operator<(int n){
        return this->operator<(new LinkedList(to_string(n)));
    }

    // Overload the > operator to compare two linked lists
    bool operator>(LinkedList* list){
        int n1 = this->get_num_digits();
        int n2 = list->get_num_digits();
        if (n1 > n2){
            return true;
        }
        else if (n1 < n2){
            return false;
        }
        Node* temp1 = this->head;
        Node* temp2 = list->head;
        while (temp1 != NULL && temp2 != NULL){
            if (temp1->data > temp2->data){
                return true;
            }
            else if (temp1->data < temp2->data){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return false;
    }

    // Overload the > operator to compare linked list with an integer
    bool operator>(int n){
        return this->operator>(new LinkedList(to_string(n)));
    }

    // Overload the == operator to compare two linked lists
    bool operator==(LinkedList* list){
        int n1 = this->get_num_digits();
        int n2 = list->get_num_digits();
        if (n1 != n2){
            return false;
        }
        Node* temp1 = this->head;
        Node* temp2 = list->head;
        while (temp1 != NULL && temp2 != NULL){
            if (temp1->data != temp2->data){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    // Overload the == operator to compare linked list with an integer
    bool operator==(int n){
        return this->operator==(new LinkedList(to_string(n)));
    }

    // Method to prepend a node with string data
    void prependNode(string data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    // Method to prepend a node with integer data
    void prependNode(unsigned int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    // Method to add a node with integer data at the end
    void addNode(unsigned int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
    }

    // Method to add a node with string data at the end
    void addNode(string data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
    }

    // Method to print the linked list
    void printList() {
        Node* temp = this->head;
        while (temp != NULL) {
            temp->printNode();
            temp = temp->next;
        }
        cout << endl;
    }

    // Method to add another linked list to this linked list
    void add_to_this_linked_list(LinkedList* list){
        Node* temp1 = this->tail;
        Node* temp2 = list->tail;
        int carry = 0;
        while (temp1 != NULL && temp2 != NULL){
            int sum = 0;
            for (int i = 0; i < 9; i++){
                int digit1 = temp1->getNthDigit(i);
                int digit2 = temp2->getNthDigit(i);
                sum = digit1 + digit2 + carry;
                if (sum > 9){
                    carry = 1;
                    sum = sum - 10;
                }
                else{
                    carry = 0;
                }
                temp1->setNthDigit(i, sum);
            }
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        
        // Handle remaining nodes in the second list
        while (temp2 != NULL){
            if (carry){
                this->prependNode(temp2->data + 1);
                carry = 0;
            }
            else{
                this->prependNode(temp2->data);
            }
            this->prependNode(temp2->data);
            temp2 = temp2->prev;
        }
    }

    // Method to get the nth digit of the linked list
    int getNthdigit(int n){
        if (n >= this->get_num_digits()){
            return 0;
        }
        Node* temp = this->tail;
        int loc_within_node = n % 9;
        int node_number = n / 9;
        for (int i = 0; i < node_number; i++){
            temp = temp->prev;
        }
        return temp->getNthDigit(loc_within_node);
    }

    // Method to set the nth digit of the linked list
    void setNthdigit(int n, int digit){
        Node* temp = this->tail;
        int loc_within_node = n % 9;
        int node_number = n / 9;
        for (int i = 0; i < node_number; i++){
            temp = temp->prev;
        }
        temp->setNthDigit(loc_within_node, digit);
    }

    // Method to add two linked lists and return the result
    LinkedList* add_linked_list(LinkedList* list){
        int l1 = this->get_num_digits();
        int l2 = list->get_num_digits();
        int to_ret_len = 0;

        if (l1 > l2){
            to_ret_len = l1;
        }
        else{
            to_ret_len = l2;
        }
        string s(to_ret_len+1, '0');
        LinkedList* to_ret = new LinkedList(s);
        int carry = 0;
        for (int i = 0; i < to_ret->get_num_digits(); i++){
            int dig1 = this->getNthdigit(i);
            int dig2 = list->getNthdigit(i);
            int res = dig1 + dig2 + carry;
            carry = res / 10;
            to_ret->setNthdigit(i, res % 10);
        }
        while (to_ret->head->data == 0){
            to_ret->head = to_ret->head->next;
            delete to_ret->head->prev;
        }
        return to_ret;
    }

    // Method to get the total number of digits in the linked list
    int get_num_digits(){
        int count = 0;
        Node* temp = this->head;
        while (temp != NULL){
            count += 9;
            temp = temp->next;
        }
        return count;
    }

    // Method to subtract one linked list from another and return the result
    LinkedList* subtract(LinkedList* list){
        int l1 = this->get_num_digits();
        int l2 = list->get_num_digits();
        if (l1 < l2){
            cout << "First number is smaller than second number" << endl;
            throw invalid_argument("First number is smaller than second number");
        }
        int to_ret_len = 0;
        if (l1 > l2){
            to_ret_len = l1;
        }
        else{
            to_ret_len = l2;
        }
        string s(to_ret_len, '0');
        LinkedList* to_ret = new LinkedList(s);
        int borrow = 0;
        for (int i = 0; i < to_ret_len; i++){
            int dig1 = this->getNthdigit(i);
            int dig2 = list->getNthdigit(i);
            int res = dig1 - dig2 - borrow;
            if (res < 0){
                borrow = 1;
                res += 10;
            }
            else{
                borrow = 0;
            }
            to_ret->setNthdigit(i, res);
        }
        while (to_ret->head->data == 0 && to_ret->head->next != NULL){
            to_ret->head = to_ret->head->next;
            delete to_ret->head->prev;
        }
        return to_ret;
    }

    // Method to multiply two linked lists and return the result
    LinkedList* multiply(LinkedList* list) {
        int n1 = this->get_num_digits();
        int n2 = list->get_num_digits();
        int totalDigits = n1 + n2;
        
        // Use an array to store results
        int* result = new int[totalDigits]();  // Initialize to 0

        // Convert linked list digits to arrays
        int* num1 = new int[n1];
        int* num2 = new int[n2];
        
        for (int i = 0; i < n1; i++) {
            num1[i] = this->getNthdigit(n1 - i - 1);
        }
        for (int j = 0; j < n2; j++) {
            num2[j] = list->getNthdigit(n2 - j - 1);
        }

        // Multiply
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = num1[i] * num2[j];
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10; // Current digit
                result[i + j] += sum / 10; // Carry
            }
        }

        // Create the final linked list from the result array
        LinkedList* finalResult = new LinkedList();
        bool leadingZero = true; // Flag to skip leading zeros

        for (int i = 0; i < totalDigits; i++) {
            if (result[i] != 0) {
                leadingZero = false; // Found a non-zero digit
            }
            if (!leadingZero) {
                finalResult->appendDigit(result[i]);
            }
        }

        // Cleanup
        delete[] num1;
        delete[] num2;
        delete[] result;

        return finalResult;
    }

    // Static method to divide one linked list by another and return the result
    static LinkedList* divide(LinkedList* dividend, LinkedList* divisor){
        if (dividend->operator==(divisor)){
            return new LinkedList("1");
        }
        if (dividend->operator<(divisor)){
            return new LinkedList("0");
        }
        int l1 = dividend->get_num_digits();
        int l2 = divisor->get_num_digits();
        int to_ret_len;
        if (l1 < l2){
            return new LinkedList("0");
        }
        else{
            to_ret_len = l1;
        }
        string s(to_ret_len, '0');
        LinkedList* result = new LinkedList(s);
        LinkedList* current = new LinkedList();

        for (int i = 0; i < l1; i++){
            current->appendDigit(dividend->getNthdigit(dividend->get_num_digits() - i - 1));
            int x = 0;
            while (current->operator>(divisor) || current->operator==(divisor)){
                current = current->subtract(divisor);
                x++;
            }
            result->setNthdigit(result->get_num_digits() - i - 1, x);
        }

        while (result->head->data == 0){
            result->head = result->head->next;
            delete result->head->prev;
        }

        return result;
    }

    // Static method to find the remainder of one linked list divided by another
    static LinkedList* mod(LinkedList* dividend, LinkedList* divisor){
        if (dividend->operator==(divisor)){
            return new LinkedList("0");  // Remainder is 0 if dividend == divisor
        }
        if (dividend->operator<(divisor)){
            return dividend;  // Remainder is the dividend itself if it's less than the divisor
        }
        LinkedList* a = LinkedList::divide(dividend, divisor);
        LinkedList* b = a->multiply(divisor);
        LinkedList* result = dividend->subtract(b);
        delete a;
        delete b;
        return result;
    }

    static LinkedList* power(LinkedList* base, LinkedList* exp){
        // If exponent is 0, return 1
        if (exp->operator==(0)){
            return new LinkedList("1");
        }
        // If exponent is 1, return base
        if (exp->operator==(1)){
            return base;
        }

        LinkedList* result = new LinkedList("1"); // Initialize result as 1

        // Loop until exponent is greater than 0
        while (exp->operator>(0)){
            // cout << " exp: ";
            // exp->printList();
            // If the least significant digit of exponent is odd
            if (exp->getNthdigit(0) % 2 == 1){
                result = result->multiply(base); // Multiply result by base
            }
            base = base->multiply(base); // Square the base
            exp = LinkedList::divide(exp, new LinkedList("2")); // Divide exponent by 2
        }

        return result; // Return the final result
    }

    void appendDigit(int digit){
        string s(this->get_num_digits() + 1, '0'); // Create a string of zeros with length one more than current number of digits
        LinkedList* temp = new LinkedList(s); // Create a new LinkedList with the string
        temp->setNthdigit(0, digit); // Set the least significant digit to the new digit
        for (int i = 0; i < this->get_num_digits(); i++){
            temp->setNthdigit(i + 1, this->getNthdigit(i)); // Copy existing digits to the new LinkedList
        }
        Node* temp_node = this->head; // Temporary node to traverse the list
        while (this->head != NULL){
            temp_node = this->head->next; // Move to the next node
            delete this->head; // Delete the current node
            this->head = temp_node; // Update head to the next node
        }
        delete temp_node; // Delete the temporary node
        this->head = temp->head; // Update head to the new list's head
        this->tail = temp->tail; // Update tail to the new list's tail

        // Remove leading zeros
        while (this->head->data == 0 && this->head->next != NULL){
            this->head = this->head->next; // Move head to the next node
            delete this->head->prev; // Delete the previous node
        }
    }                
};

bool miller_rabin_primality_test(LinkedList* n) {
    time_t t = time(NULL); // Start timing the function
    if (n->operator==(2) || n->operator==(3)) { // Check if n is 2 or 3
        return true; // 2 and 3 are prime numbers
    }
    if (n->operator<(2) || n->getNthdigit(0) % 2 == 0) { // Check if n is less than 2 or even
        return false; // Numbers less than 2 and even numbers are not prime
    }

    LinkedList* d = n->subtract(new LinkedList("1")); // d = n - 1
    int k = 0; // Initialize k to 0
    while (d->getNthdigit(0) % 2 == 0) { // While d is even
        d = LinkedList::divide(d, new LinkedList("2")); // d = d / 2
        k++; // Increment k
    }
    // cout << "k: " << k << endl;
    // d->printList();

    LinkedList* a =  new LinkedList("2"); // Initialize a to 2
    // cout << "a: ";
    // a->printList();
    LinkedList* x = LinkedList::mod(LinkedList::power(a, d), n); // x = (a^d) % n
    
    if (x->operator==(1) || x->operator==(n->subtract(new LinkedList("1")))) { // Check if x is 1 or n-1
        time_t t2 = time(NULL); // End timing the function
        cout << "Time taken: " << t2 - t << " seconds" << endl; // Print time taken
        return true; // n is probably prime
    }

    for (int i = 0; i < k - 1; i++) { // Repeat k-1 times
        // cout << "i: " << i << endl;
        x = LinkedList::mod(x->multiply(x), n); // x = (x^2) % n
        if (x->operator==(1)) { // Check if x is 1
            time_t t2 = time(NULL); // End timing the function
            cout << "Time taken: " << t2 - t << " seconds" << endl; // Print time taken
            return false; // n is composite
        }
        if (x->operator==(n->subtract(new LinkedList("1")))) { // Check if x is n-1
            time_t t2 = time(NULL); // End timing the function
            cout << "Time taken: " << t2 - t << " seconds" << endl; // Print time taken
            return true; // n is probably prime
        }
    }
    time_t t2 = time(NULL); // End timing the function
    cout << "Time taken: " << t2 - t << " seconds" << endl; // Print time taken
    return false; // n is composite
}

int main() {
    string num_to_check; // Variable to store the number to check
    char cont = 'y'; // Variable to store the user's choice to continue
    while (cont == 'y'){ // Loop until the user chooses to stop
        cout << "Enter the number to check for primality: "; // Prompt the user for input
        getline(cin, num_to_check); // Get the input from the user
        LinkedList* num = new LinkedList(num_to_check); // Create a LinkedList from the input
        if (miller_rabin_primality_test(num)){ // Check if the number is prime
            cout << "Number is prime" << endl; // Print if the number is prime
        }
        else{
            cout << "Number is not prime" << endl; // Print if the number is not prime
        }
        cout << "Do you want to continue? (y/n): "; // Ask the user if they want to continue
        cin >> cont; // Get the user's choice
        cin.ignore(1000, '\n'); // Ignore the newline character left in the input buffer
        cin.clear(); // Clear the input buffer
    }
}