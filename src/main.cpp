#include <bits/stdc++.h>
#include "tools/tools.h"
using namespace std;

vector<unsigned int> getFileBuffer( const string& dir ) { //restituisce un vettore di numeri hex presi dal file in posizione <dir>
    vector<unsigned int> buffer; //buffer da restituire pieno
    ifstream file ( dir , ios_base::in | ios_base::binary );   //apre la lettura del file

    if ( file.is_open() ) { //se il file è aperto correttamente
        unsigned int c;

        while( (c = (unsigned int) file.get()) != EOF ) {  //finchè legge un carattere
            buffer.push_back( c ); //aggiunge il carattere al buffer
        }
    }

    return buffer;
}

int main() {
    vector<unsigned int> buffer = getFileBuffer( "../data/input/invaders.h" );

    for (int i = 0; i < buffer.size(); i++) {
        cout << hex << setw( 2 ) << setfill( '0' ) << buffer[i] << " ";
        if ( ( i + 1 ) % 16 == 0 ) cout << endl;
        cout << dec;
    }
}
