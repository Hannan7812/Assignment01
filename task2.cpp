#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;

class Node {
public:
    unsigned int data;
    Node* next;
    Node* prev;

    Node(unsigned int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(string data) {
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
        this->data = stoi(data);
        this->next = NULL;
        this->prev = NULL;
    }

    int getNthDigit(int n) {
        if (n < 0 || n > 8) {
            cout << "Invalid digit number get" << endl;
            throw invalid_argument("N is not in the range of 0-8");
        }
        
        int temp = this->data;
        for (int i = 0; i < n; i++) {
            temp /= 10;
        }
        
        return temp % 10;
    }

    void setNthDigit(int n, int digit) {
        if (n < 0 || n > 8) {
            cout << "Invalid digit number set" << endl;
            throw invalid_argument("N is not in the range of 0-8");
        }
        
        if (digit < 0 || digit > 9) {
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

    int getLengthofInt(){
        int temp = this->data;
        int count = 0;
        while (temp > 0){
            temp = temp / 10;
            count++;
        }
        return count;
    }

    void printNode() {
        for (int i = 8; i >= 0; i--) {
            cout << getNthDigit(i);
        }
    }
};

class LinkedList {  
public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    LinkedList(string data){
        this->head = NULL;
        this->tail = NULL;
        int n = data.size() - 9;
        int block_size = 9;
        while (1){
            if (n <= 0){
                this->prependNode(data.substr(0, block_size + n));
                break;
            }
            this->prependNode(data.substr(n, block_size));
            n = n - block_size;
        }
    }

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

    bool operator<(int n){
        return this->operator<(new LinkedList(to_string(n)));
    }

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

    bool operator>(int n){
        return this->operator>(new LinkedList(to_string(n)));
    }

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

    bool operator==(int n){
        return this->operator==(new LinkedList(to_string(n)));
    }

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

    void printList() {
        Node* temp = this->head;
        while (temp != NULL) {
            temp->printNode();
            temp = temp->next;
        }
        cout << endl;
    }

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

    void setNthdigit(int n, int digit){
        Node* temp = this->tail;
        int loc_within_node = n % 9;
        int node_number = n / 9;
        for (int i = 0; i < node_number; i++){
            temp = temp->prev;
        }
        temp->setNthDigit(loc_within_node, digit);
    }

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

    int get_num_digits(){
        int count = 0;
        Node* temp = this->head;
        while (temp != NULL){
            count += 9;
            temp = temp->next;
        }
        return count;
    }

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
};