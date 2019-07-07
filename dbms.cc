#include <cstdlib>
#include <cstdio>
#include "dbms.hh"

using namespace dbms;

/**
        Constructor for DbTable
        Allocate 5 pieces of album sized memory
        Set rowsUsed and rowsTotal to initial values
*/
DbTable::DbTable() {
        table = (album *)malloc(5*sizeof(album));
        rowsTotal = 5;
        rowsUsed = 0;
}

/**
        Deconstructor for DbTable
        Frees the momory used
*/
DbTable::~DbTable() {
        delete[] table;
}

/**
        Show information for selected row
        If row number is larger than rowsUsed then return false;
*/
bool DbTable::show(unsigned int showRow) {
        if(showRow>=rowsUsed) {
                return false;
        }
        //Display data nicely
        printf("%lu | %s | %d | %s\n",
        table[showRow].id,
        table[showRow].title,
        table[showRow].year,
        table[showRow].artist);
        return true;
}

/**
        Add album to DbTable
        If all the rows are used then allocate momeory for another five
*/
bool DbTable::add(album &toAdd) {
        if(rowsUsed >=rowsTotal) {
                //Add memory for another five entries
                table = (album *)realloc(table,(rowsTotal +5) * sizeof(album));
                if(table == nullptr) {
                        return false;
                }
                rowsTotal = rowsTotal +5;
        }
        //Add album to the table
        table[rowsUsed++] = toAdd;
        return true;
}

/**
        Remove album with matching id from DbTable
        Once the album has been found, move all the data below it up one row

*/
bool DbTable::remove(unsigned long id) {
        bool found = false;
        for(unsigned int i =0; i< rowsUsed;i++) {
                //Check to see if the ids match
                if(table[i].id == id) {
                        found = true;
                }
                //If the id has been found the move up the data from below
                if(found) {
                        table[i] = table[i+1];
                }
        }
        //If id not found then return false;
        if(found == false) {
                return false;
        }
        //If the last five entries are now empty then remove them
        if(found && (rowsTotal - (--rowsUsed) >=5) && (rowsUsed>0)) {
                table = (album *)realloc(table,(rowsTotal -5) * sizeof(album));
                rowsTotal = rowsTotal-5;
        }
        //If the memory realloc doesn't work then return falsel
        if(table == nullptr) {
                return false;
        }
        return true;
}
