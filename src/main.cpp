#include "1115command.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
    while (true) {
        Coms line;
        string input;
        int eflag;

        //bonus point
        char hostname[255];
        //currently logged user

        if (gethostname(hostname, sizeof(hostname)) == 0)
            // display the currently logged in user, and the hostname of the machine the user is logged into
            // with the symbol @@ and $ followed
            // cout<<getlogin()<<endl;
            // cout<<hostname<<endl;
            cout<<getlogin()<<"@"<<hostname<<"$ "; 

        // Read in the command line user input
        getline(cin,input);      

        if (input == "") 
            continue;
        
        // Put the command to line
        line.setCmd(input);   
        // do the parsing for the command        
        line.parse();     
        // use the connectors to connect
        // execute the command       
        eflag = line.execute();    

        if (eflag == -1) 
            break;

    }

    return 0;
}
