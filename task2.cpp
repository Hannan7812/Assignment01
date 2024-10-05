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