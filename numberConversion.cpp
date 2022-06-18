#include <iostream>
#include <math.h> 
#include <ctype.h>
using namespace std;

void printAsk(){
    cout << "\n";
    cout << "---------------- \n";
    cout << "What do you have to convert? \n";
    cout << "[1] binary \n";
    cout << "[2] decimal \n";
    cout << "[3] hexadecimal \n";
    cout << "[4] quit \n";
    cout << "---------------- \n";
}

string decimalToHex(int decimal){
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    bool check = true;
    string hexadecimal = "";
        while(check){
            if(decimal % 16 >= 1){
                if(decimal % 16 >= 10){
                    hexadecimal = hex[decimal % 16] + hexadecimal;
                }
                else if(decimal % 16 < 10){
                    hexadecimal = to_string(decimal % 16) + hexadecimal;
                }
                
                decimal = decimal / 16;
            }
            else{
                check = false;
            }
        }

    return hexadecimal;
}

string decimalToBinary(int decimal){
    bool check = true;
    string binary = "";
    
        while(check){
            if(decimal / 2 >= 0 ){
                binary = to_string(decimal % 2) + binary;
                decimal = decimal / 2;
            }
            if(decimal / 2 == 0 & decimal % 2 == 0) check = false;
        }

    return binary;
}

int hexToDecimal(string hexadecimal){
    int current = 0, decimal = 0;
    for(int i = hexadecimal.length() - 1, j = 0; i >= 0; --i, j++){
        current = 0;
        // if character is letter
        if(isalpha(hexadecimal[i])){
            // hex is string so converting to int gives ascii so need to subtrack 55
            current = (int) (hexadecimal[i] - 55) * (pow(16, j));
            decimal = decimal + current;
        }

        else if(isdigit(hexadecimal[i])) {
            // same but subtract 48
            current = (int) (hexadecimal[i] - 48) * pow(16, j);
            decimal = decimal + current;
        }
    }
    return decimal;
}

void binaryTo(int x){
    string binary;
    int convertedInt = 0;
    
    cout << "What is your binary?\n";
    cin >> binary;
    // convert to decimal
    for (int i = binary.length() - 1, j = 0; i >= 0; --i, j++) {
            if(binary[i] == '1'){
                convertedInt = convertedInt + (int) floor(pow(2, j));
            }
        }

    // converts decimal to hexa
    if(x == 2){
        string hexadecimal = decimalToHex(convertedInt);
        cout << "Converted binary to hex: " << hexadecimal << "\n";
        return;
    }

    cout << "Converted binary to decimal: " << convertedInt << "\n";
    
}



void decimalTo(int x){
    int decimal;
    cout << "What is your decimal?\n";
    cin >> decimal;

    // convert decimal to binary
    if(x == 1){
        string binary = decimalToBinary(decimal);
        cout << "Converted decimal to binary: " << binary << "\n";
        return;
    }
    // convert decimal to hexadecimal
    else{
        string hexadecimal = decimalToHex(decimal);
        cout << "Converted decimal to hex: " << hexadecimal << "\n";
        return;
    }
}

void hexadecimalTo(int x){
    string hexadecimal, binary = "";
    cout << "What is your hexadecimal?\n";
    cin >> hexadecimal;
    // converts hex to decimal
    int decimal = hexToDecimal(hexadecimal);
    
    if(x == 1){
        // converts decimal to binary
        binary = decimalToBinary(decimal);
        cout << "Converted hex to binary: " << binary << "\n";
        return;
    }
    // prints our the decimal
    else{
        cout << "Converted hex to decimal: " << decimal << "\n";
        return;
    }
}

int main() {
    cout << "Welcome to my Number converter!\n";
    for(;;){
        printAsk();
        int convertFrom, convertTo;
        cin >> convertFrom; 
        switch(convertFrom){
            case 1:
                while (true){
                    cout << "Binary to decimal or hexadecimal? \n";
                    cout << "[1] decimal \n";
                    cout << "[2] hexadecimal \n";
                    cout << "[3] go back \n";
                    cin >> convertTo;
                    if(convertTo == 1 || convertTo == 2){
                        binaryTo(convertTo);
                        break;
                        }
                    else if(convertTo == 3){
                        break;
                    }
                }
                break;
            case 2:
                while (true){
                    cout << "Decimal to binary or hexadecimal? \n";
                    cout << "[1] binary \n";
                    cout << "[2] hexadecimal \n";
                    cout << "[3] go back \n";
                    cin >> convertTo;
                    if(convertTo == 1 || convertTo == 2){
                        decimalTo(convertTo);
                        break;
                        }
                    else if(convertTo == 3){
                        break;
                    }
                }
                
                break;
            
            case 3:
                while (true){
                    cout << "Hexadecimal to binary or decimal? \n";
                    cout << "[1] binary \n";
                    cout << "[2] decimal \n";
                    cout << "[3] go back \n";
                    cin >> convertTo;
                    if(convertTo == 1 || convertTo == 2){
                        hexadecimalTo(convertTo);
                        break;
                        }
                    else if(convertTo == 3){
                        break;
                    }
                }
                break;
            case 4:
                return -1;
                break;
            default:
                printAsk();
                cin >> convertFrom;
        }
    }
    return 0;
}
