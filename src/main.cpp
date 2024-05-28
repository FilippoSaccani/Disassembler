#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> getFileBuffer( const string& dir ) { //restituisce un vettore di numeri hex presi dal file in posizione <dir>
    vector<unsigned int> buffer; //buffer da restituire pieno
    ifstream file ( dir , ios_base::in | ios_base::binary );   //apre la lettura del file

    if ( file.is_open() ) { //se il file è aperto correttamente
        unsigned int c;

        while( (c = (unsigned int) file.get()) != EOF ) {  //finché non trova la fine del file
            buffer.push_back( c ); //aggiunge il carattere al buffer
        }

        file.close(); //chiude la lettura del file
    } else {
        cout << "\nFILE NON TROVATO";
    }

    return buffer;
}

int main() {
    cout << "Percorso file (../data/<nome>): ";

    string filePath;
    cin >> filePath;

    vector<unsigned int> buffer = getFileBuffer( filePath );

    stringstream instruction;
    int increment;

    stringstream oneByteData;
    stringstream twoByteData;
    stringstream twoByteAddress;

    int i = 0;
    while ( i < buffer.size() ) {
        instruction.str(string());
        oneByteData.str(string());
        twoByteData.str(string());
        twoByteAddress.str(string());

        oneByteData << "#0x" << hex << setw( 2 ) << setfill( '0' ) << buffer[i+1];
        twoByteData << "#0x" << hex << setw( 2 ) << setfill( '0' ) << buffer[i+2] << setw( 2 ) << setfill( '0' ) << buffer[i+1];
        twoByteAddress << "$" << hex << setw( 2 ) << setfill( '0' ) << buffer[i+2] << setw( 2 ) << setfill( '0' ) << buffer[i+1];

        switch ( buffer[i] ) {
            case 0x00: {
                instruction << "NOP";
                increment = 1;
                break;
            }
            case 0x01: {
                instruction << "LXI B," << twoByteData.str();
                increment = 3;
                break;
            }
            case 0x02: {
                instruction << "STAX B";
                increment = 1;
                break;
            }
            case 0x03: {
                instruction << "INX B";
                increment = 1;
                break;
            }
            case 0x04: {
                instruction << "INR B";
                increment = 1;
                break;
            }
            case 0x05: {
                instruction << "DCR B";
                increment = 1;
                break;
            }
            case 0x06: {
                instruction << "MVI B," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x07: {
                instruction << "RLC";
                increment = 1;
                break;
            }
            case 0x08: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x09: {
                instruction << "DAD B";
                increment = 1;
                break;
            }
            case 0x0a: {
                instruction << "LDAX B";
                increment = 1;
                break;
            }
            case 0x0b: {
                instruction << "DCX B";
                increment = 1;
                break;
            }
            case 0x0c: {
                instruction << "INR C";
                increment = 1;
                break;
            }
            case 0x0d: {
                instruction << "DCR C";
                increment = 1;
                break;
            }
            case 0x0e: {
                instruction << "MVI C," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x0f: {
                instruction << "RRC";
                increment = 1;
                break;
            }
            case 0x10: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x11: {
                instruction << "LXI D," << twoByteData.str();
                increment = 3;
                break;
            }
            case 0x12: {
                instruction << "STAX D";
                increment = 1;
                break;
            }
            case 0x13: {
                instruction << "INX D";
                increment = 1;
                break;
            }
            case 0x14: {
                instruction << "INR D";
                increment = 1;
                break;
            }
            case 0x15: {
                instruction << "DCR D";
                increment = 1;
                break;
            }
            case 0x16: {
                instruction << "MVI D," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x17: {
                instruction << "RAL";
                increment = 1;
                break;
            }
            case 0x18: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x19: {
                instruction << "DAD D";
                increment = 1;
                break;
            }
            case 0x1a: {
                instruction << "LDAX D";
                increment = 1;
                break;
            }
            case 0x1b: {
                instruction << "DCX D";
                increment = 1;
                break;
            }
            case 0x1c: {
                instruction << "INR E";
                increment = 1;
                break;
            }
            case 0x1d: {
                instruction << "DCR E";
                increment = 1;
                break;
            }
            case 0x1e: {
                instruction << "MVI E," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x1f: {
                instruction << "RAR";
                increment = 1;
                break;
            }
            case 0x20: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x21: {
                instruction << "LXI H," << twoByteData.str();
                increment = 3;
                break;
            }
            case 0x22: {
                instruction << "SHLD " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0x23: {
                instruction << "INX H";
                increment = 1;
                break;
            }
            case 0x24: {
                instruction << "INR H";
                increment = 1;
                break;
            }
            case 0x25: {
                instruction << "DCR H";
                increment = 1;
                break;
            }
            case 0x26: {
                instruction << "MVI H," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x27: {
                instruction << "DAA";
                increment = 1;
                break;
            }
            case 0x28: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x29: {
                instruction << "DAD H";
                increment = 1;
                break;
            }
            case 0x2a: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x2b: {
                instruction << "DCX H";
                increment = 1;
                break;
            }
            case 0x2c: {
                instruction << "INR L";
                increment = 1;
                break;
            }
            case 0x2d: {
                instruction << "DCR L";
                increment = 1;
                break;
            }
            case 0x2e: {
                instruction << "MVI L," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x2f: {
                instruction << "CMA";
                increment = 1;
                break;
            }
            case 0x30: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x31: {
                instruction << "LXI SP," << twoByteData.str();
                increment = 3;
                break;
            }
            case 0x32: {
                instruction << "STA " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0x33: {
                instruction << "INX SP";
                increment = 1;
                break;
            }
            case 0x34: {
                instruction << "INR M";
                increment = 1;
                break;
            }
            case 0x35: {
                instruction << "DCR M";
                increment = 1;
                break;
            }
            case 0x36: {
                instruction << "MVI M," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x37: {
                instruction << "STC";
                increment = 1;
                break;
            }
            case 0x38: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0x39: {
                instruction << "DAD SP";
                increment = 1;
                break;
            }
            case 0x3a: {
                instruction << "LDA $" << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0x3b: {
                instruction << "DCX SP";
                increment = 1;
                break;
            }
            case 0x3c: {
                instruction << "INR A";
                increment = 1;
                break;
            }
            case 0x3d: {
                instruction << "DCR A";
                increment = 1;
                break;
            }
            case 0x3e: {
                instruction << "MVI A," << oneByteData.str();
                increment = 2;
                break;
            }
            case 0x3f: {
                instruction << "CMC";
                increment = 1;
                break;
            }
            case 0x40: {
                instruction << "MOV B,B";
                increment = 1;
                break;
            }
            case 0x41: {
                instruction << "MOV B,C";
                increment = 1;
                break;
            }
            case 0x42: {
                instruction << "MOV B,D";
                increment = 1;
                break;
            }
            case 0x43: {
                instruction << "MOV B,E";
                increment = 1;
                break;
            }
            case 0x44: {
                instruction << "MOV B,H";
                increment = 1;
                break;
            }
            case 0x45: {
                instruction << "MOV B,L";
                increment = 1;
                break;
            }
            case 0x46: {
                instruction << "MOV B,M";
                increment = 1;
                break;
            }
            case 0x47: {
                instruction << "MOV B,A";
                increment = 1;
                break;
            }
            case 0x48: {
                instruction << "MOV C,B";
                increment = 1;
                break;
            }
            case 0x49: {
                instruction << "MOV C,C";
                increment = 1;
                break;
            }
            case 0x4a: {
                instruction << "MOV C,D";
                increment = 1;
                break;
            }
            case 0x4b: {
                instruction << "MOV C,E";
                increment = 1;
                break;
            }
            case 0x4c: {
                instruction << "MOV C,H";
                increment = 1;
                break;
            }
            case 0x4d: {
                instruction << "MOV C,L";
                increment = 1;
                break;
            }
            case 0x4e: {
                instruction << "MOV C,M";
                increment = 1;
                break;
            }
            case 0x4f: {
                instruction << "MOV C,A";
                increment = 1;
                break;
            }
            case 0x50: {
                instruction << "MOV D,B";
                increment = 1;
                break;
            }
            case 0x51: {
                instruction << "MOV D,C";
                increment = 1;
                break;
            }
            case 0x52: {
                instruction << "MOV D,D";
                increment = 1;
                break;
            }
            case 0x53: {
                instruction << "MOV D,E";
                increment = 1;
                break;
            }
            case 0x54: {
                instruction << "MOV D,H";
                increment = 1;
                break;
            }
            case 0x55: {
                instruction << "MOV D,L";
                increment = 1;
                break;
            }
            case 0x56: {
                instruction << "MOV D,M";
                increment = 1;
                break;
            }
            case 0x57: {
                instruction << "MOV D,A";
                increment = 1;
                break;
            }
            case 0x58: {
                instruction << "MOV E,B";
                increment = 1;
                break;
            }
            case 0x59: {
                instruction << "MOV E,C";
                increment = 1;
                break;
            }
            case 0x5a: {
                instruction << "MOV E,D";
                increment = 1;
                break;
            }
            case 0x5b: {
                instruction << "MOV E,E";
                increment = 1;
                break;
            }
            case 0x5c: {
                instruction << "MOV E,H";
                increment = 1;
                break;
            }
            case 0x5d: {
                instruction << "MOV E,L";
                increment = 1;
                break;
            }
            case 0x5e: {
                instruction << "MOV E,M";
                increment = 1;
                break;
            }
            case 0x5f: {
                instruction << "MOV E,A";
                increment = 1;
                break;
            }
            case 0x60: {
                instruction << "MOV H,B";
                increment = 1;
                break;
            }
            case 0x61: {
                instruction << "MOV H,C";
                increment = 1;
                break;
            }
            case 0x62: {
                instruction << "MOV H,D";
                increment = 1;
                break;
            }
            case 0x63: {
                instruction << "MOV H,E";
                increment = 1;
                break;
            }
            case 0x64: {
                instruction << "MOV H,H";
                increment = 1;
                break;
            }
            case 0x65: {
                instruction << "MOV H,L";
                increment = 1;
                break;
            }
            case 0x66: {
                instruction << "MOV H,M";
                increment = 1;
                break;
            }
            case 0x67: {
                instruction << "MOV H,A";
                increment = 1;
                break;
            }
            case 0x68: {
                instruction << "MOV L,B";
                increment = 1;
                break;
            }
            case 0x69: {
                instruction << "MOV L,C";
                increment = 1;
                break;
            }
            case 0x6a: {
                instruction << "MOV L,D";
                increment = 1;
                break;
            }
            case 0x6b: {
                instruction << "MOV L,E";
                increment = 1;
                break;
            }
            case 0x6c: {
                instruction << "MOV L,H";
                increment = 1;
                break;
            }
            case 0x6d: {
                instruction << "MOV L,L";
                increment = 1;
                break;
            }
            case 0x6e: {
                instruction << "MOV L,M";
                increment = 1;
                break;
            }
            case 0x6f: {
                instruction << "MOV L,A";
                increment = 1;
                break;
            }
            case 0x70: {
                instruction << "MOV M,B";
                increment = 1;
                break;
            }
            case 0x71: {
                instruction << "MOV M,C";
                increment = 1;
                break;
            }
            case 0x72: {
                instruction << "MOV M,D";
                increment = 1;
                break;
            }
            case 0x73: {
                instruction << "MOV M,E";
                increment = 1;
                break;
            }
            case 0x74: {
                instruction << "MOV M,H";
                increment = 1;
                break;
            }
            case 0x75: {
                instruction << "MOV M,L";
                increment = 1;
                break;
            }
            case 0x76: {
                instruction << "HLT";
                increment = 1;
                break;
            }
            case 0x77: {
                instruction << "MOV M,A";
                increment = 1;
                break;
            }
            case 0x78: {
                instruction << "MOV A,B";
                increment = 1;
                break;
            }
            case 0x79: {
                instruction << "MOV A,C";
                increment = 1;
                break;
            }
            case 0x7a: {
                instruction << "MOV A,D";
                increment = 1;
                break;
            }
            case 0x7b: {
                instruction << "MOV A,E";
                increment = 1;
                break;
            }
            case 0x7c: {
                instruction << "MOV A,H";
                increment = 1;
                break;
            }
            case 0x7d: {
                instruction << "MOV A,L";
                increment = 1;
                break;
            }
            case 0x7e: {
                instruction << "MOV A,M";
                increment = 1;
                break;
            }
            case 0x7f: {
                instruction << "MOV A,A";
                increment = 1;
                break;
            }
            case 0x80: {
                instruction << "ADD B";
                increment = 1;
                break;
            }
            case 0x81: {
                instruction << "ADD C";
                increment = 1;
                break;
            }
            case 0x82: {
                instruction << "ADD D";
                increment = 1;
                break;
            }
            case 0x83: {
                instruction << "ADD E";
                increment = 1;
                break;
            }
            case 0x84: {
                instruction << "ADD H";
                increment = 1;
                break;
            }
            case 0x85: {
                instruction << "ADD L";
                increment = 1;
                break;
            }
            case 0x86: {
                instruction << "ADD M";
                increment = 1;
                break;
            }
            case 0x87: {
                instruction << "ADD A";
                increment = 1;
                break;
            }
            case 0x88: {
                instruction << "ADC B";
                increment = 1;
                break;
            }
            case 0x89: {
                instruction << "ADC C";
                increment = 1;
                break;
            }
            case 0x8a: {
                instruction << "ADC D";
                increment = 1;
                break;
            }
            case 0x8b: {
                instruction << "ADC E";
                increment = 1;
                break;
            }
            case 0x8c: {
                instruction << "ADC H";
                increment = 1;
                break;
            }
            case 0x8d: {
                instruction << "ADC L";
                increment = 1;
                break;
            }
            case 0x8e: {
                instruction << "ADC M";
                increment = 1;
                break;
            }
            case 0x8f: {
                instruction << "ADC A";
                increment = 1;
                break;
            }
            case 0x90: {
                instruction << "SUB B";
                increment = 1;
                break;
            }
            case 0x91: {
                instruction << "SUB C";
                increment = 1;
                break;
            }
            case 0x92: {
                instruction << "SUB D";
                increment = 1;
                break;
            }
            case 0x93: {
                instruction << "SUB E";
                increment = 1;
                break;
            }
            case 0x94: {
                instruction << "SUB H";
                increment = 1;
                break;
            }
            case 0x95: {
                instruction << "SUB L";
                increment = 1;
                break;
            }
            case 0x96: {
                instruction << "SUB M";
                increment = 1;
                break;
            }
            case 0x97: {
                instruction << "SUB A";
                increment = 1;
                break;
            }
            case 0x98: {
                instruction << "SBB B";
                increment = 1;
                break;
            }
            case 0x99: {
                instruction << "SBB C";
                increment = 1;
                break;
            }
            case 0x9a: {
                instruction << "SBB D";
                increment = 1;
                break;
            }
            case 0x9b: {
                instruction << "SBB E";
                increment = 1;
                break;
            }
            case 0x9c: {
                instruction << "SBB H";
                increment = 1;
                break;
            }
            case 0x9d: {
                instruction << "SBB L";
                increment = 1;
                break;
            }
            case 0x9e: {
                instruction << "SBB M";
                increment = 1;
                break;
            }
            case 0x9f: {
                instruction << "SBB A";
                increment = 1;
                break;
            }
            case 0xa0: {
                instruction << "ANA B";
                increment = 1;
                break;
            }
            case 0xa1: {
                instruction << "ANA C";
                increment = 1;
                break;
            }
            case 0xa2: {
                instruction << "ANA D";
                increment = 1;
                break;
            }
            case 0xa3: {
                instruction << "ANA E";
                increment = 1;
                break;
            }
            case 0xa4: {
                instruction << "ANA H";
                increment = 1;
                break;
            }
            case 0xa5: {
                instruction << "ANA L";
                increment = 1;
                break;
            }
            case 0xa6: {
                instruction << "ANA M";
                increment = 1;
                break;
            }
            case 0xa7: {
                instruction << "XRA A";
                increment = 1;
                break;
            }
            case 0xa8: {
                instruction << "XRA B";
                increment = 1;
                break;
            }
            case 0xa9: {
                instruction << "XRA C";
                increment = 1;
                break;
            }
            case 0xaa: {
                instruction << "XRA D";
                increment = 1;
                break;
            }
            case 0xab: {
                instruction << "XRA E";
                increment = 1;
                break;
            }
            case 0xac: {
                instruction << "XRA H";
                increment = 1;
                break;
            }
            case 0xad: {
                instruction << "XRA L";
                increment = 1;
                break;
            }
            case 0xae: {
                instruction << "XRA M";
                increment = 1;
                break;
            }
            case 0xaf: {
                instruction << "ORA A";
                increment = 1;
                break;
            }
            case 0xb0: {
                instruction << "ORA B";
                increment = 1;
                break;
            }
            case 0xb1: {
                instruction << "ORA C";
                increment = 1;
                break;
            }
            case 0xb2: {
                instruction << "ORA D";
                increment = 1;
                break;
            }
            case 0xb3: {
                instruction << "ORA E";
                increment = 1;
                break;
            }
            case 0xb4: {
                instruction << "ORA H";
                increment = 1;
                break;
            }
            case 0xb5: {
                instruction << "ORA L";
                increment = 1;
                break;
            }
            case 0xb6: {
                instruction << "ORA M";
                increment = 1;
                break;
            }
            case 0xb7: {
                instruction << "ORA A";
                increment = 1;
                break;
            }
            case 0xb8: {
                instruction << "CMP B";
                increment = 1;
                break;
            }
            case 0xb9: {
                instruction << "CMP C";
                increment = 1;
                break;
            }
            case 0xba: {
                instruction << "CMP D";
                increment = 1;
                break;
            }
            case 0xbb: {
                instruction << "CMP E";
                increment = 1;
                break;
            }
            case 0xbc: {
                instruction << "CMP H";
                increment = 1;
                break;
            }
            case 0xbd: {
                instruction << "CMP L";
                increment = 1;
                break;
            }
            case 0xbe: {
                instruction << "CMP M";
                increment = 1;
                break;
            }
            case 0xbf: {
                instruction << "CMP A";
                increment = 1;
                break;
            }
            case 0xc0: {
                instruction << "RNZ";
                increment = 1;
                break;
            }
            case 0xc1: {
                instruction << "POP B";
                increment = 1;
                break;
            }
            case 0xc2: {
                instruction << "JNZ " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xc3: {
                instruction << "JMP " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xc4: {
                instruction << "CNZ " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xc5: {
                instruction << "PUSH B";
                increment = 1;
                break;
            }
            case 0xc6: {
                instruction << "ADI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xc7: {
                instruction << "RST 0";
                increment = 1;
                break;
            }
            case 0xc8: {
                instruction << "RZ";
                increment = 1;
                break;
            }
            case 0xc9: {
                instruction << "RET";
                increment = 1;
                break;
            }
            case 0xca: {
                instruction << "JZ " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xcb: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0xcc: {
                instruction << "CZ " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xcd: {
                instruction << "CALL " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xce: {
                instruction << "ACI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xcf: {
                instruction << "RST 1";
                increment = 1;
                break;
            }
            case 0xd0: {
                instruction << "RNC";
                increment = 1;
                break;
            }
            case 0xd1: {
                instruction << "POP D";
                increment = 1;
                break;
            }
            case 0xd2: {
                instruction << "JNC " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xd3: {
                instruction << "OUT " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xd4: {
                instruction << "CNC " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xd5: {
                instruction << "PUSH D";
                increment = 1;
                break;
            }
            case 0xd6: {
                instruction << "SUI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xd7: {
                instruction << "RST 2";
                increment = 1;
                break;
            }
            case 0xd8: {
                instruction << "RC";
                increment = 1;
                break;
            }
            case 0xd9: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0xda: {
                instruction << "JC " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xdb: {
                instruction << "IN " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xdc: {
                instruction << "CC " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xdd: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0xde: {
                instruction << "SBI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xdf: {
                instruction << "RST 3";
                increment = 1;
                break;
            }
            case 0xe0: {
                instruction << "RPO";
                increment = 1;
                break;
            }
            case 0xe1: {
                instruction << "POP H";
                increment = 1;
                break;
            }
            case 0xe2: {
                instruction << "JPO " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xe3: {
                instruction << "XTHL";
                increment = 1;
                break;
            }
            case 0xe4: {
                instruction << "CPO " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xe5: {
                instruction << "PUSH H";
                increment = 1;
                break;
            }
            case 0xe6: {
                instruction << "ANDI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xe7: {
                instruction << "RST 4";
                increment = 1;
                break;
            }
            case 0xe8: {
                instruction << "RPE";
                increment = 1;
                break;
            }
            case 0xe9: {
                instruction << "PCHL";
                increment = 1;
                break;
            }
            case 0xea: {
                instruction << "JPE " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xeb: {
                instruction << "XCHG";
                increment = 1;
                break;
            }
            case 0xec: {
                instruction << "CPE " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xed: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0xee: {
                instruction << "XRI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xef: {
                instruction << "RST 5";
                increment = 1;
                break;
            }
            case 0xf0: {
                instruction << "RP";
                increment = 1;
                break;
            }
            case 0xf1: {
                instruction << "POP PSW";
                increment = 1;
                break;
            }
            case 0xf2: {
                instruction << "JP " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xf3: {
                instruction << "DI";
                increment = 1;
                break;
            }
            case 0xf4: {
                instruction << "CP " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xf5: {
                instruction << "PUSH PSW";
                increment = 1;
                break;
            }
            case 0xf6: {
                instruction << "ORI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xf7: {
                instruction << "RST 6";
                increment = 1;
                break;
            }
            case 0xf8: {
                instruction << "RM";
                increment = 1;
                break;
            }
            case 0xf9: {
                instruction << "SPHL";
                increment = 1;
                break;
            }
            case 0xfa: {
                instruction << "JM " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xfb: {
                instruction << "EI";
                increment = 1;
                break;
            }
            case 0xfc: {
                instruction << "CM " << twoByteAddress.str();
                increment = 3;
                break;
            }
            case 0xfd: {
                instruction << "-";
                increment = 1;
                break;
            }
            case 0xfe: {
                instruction << "CPI " << oneByteData.str();
                increment = 2;
                break;
            }
            case 0xff: {
                instruction << "RST 7";
                increment = 1;
                break;
            }
            default: i++;
        }

        cout << hex << setw( 6 ) << setfill( '0' ) << i << "  " << instruction.str() << endl;
        i += increment;
    }
}
