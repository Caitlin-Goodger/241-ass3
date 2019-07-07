#ifndef FILES_DBMS_HH
#define FILES_DBMS_HH

namespace dbms {
        //Struct for album
        struct album {
                unsigned long id;
                char title[100];
                unsigned short year;
                char artist[100];
        };

        class DbTable {
        private:
                album *table;
                unsigned int rowsTotal;
                unsigned int rowsUsed;
        public:
                //Constructor
                DbTable();
                //Deconstructor
                ~DbTable();

                //Get rows used
                unsigned int rows() {
                        return rowsUsed;
                }

                //Get total rows
                unsigned int allocated() {
                        return rowsTotal;
                }

                //Function Prototypes
                bool add(album&);
                bool remove(unsigned long);
                bool show(unsigned int);
        };
}
#endif //FILES_DBMS_HH
