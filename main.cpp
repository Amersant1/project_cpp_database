#include <iostream> 
#include <sqlite3.h> 
#include <sstream>

void dropTables(const std::string& path){
    sqlite3* DB; 
    int exit =0 ;
    char* messaggeError; 
    exit = sqlite3_open(path.c_str(), &DB); 
    std::string textTable = "DROP TABLE IF EXISTS Text;DROP TABLE IF EXISTS Resources;"; 
    exit = sqlite3_exec(DB, textTable.c_str(), NULL, 0, &messaggeError); 
    std::cout << messaggeError << std::endl; 
}
void makeTables(const std::string& path){
    sqlite3* DB; 
    int exit =0 ;
    char* messaggeError; 
    exit = sqlite3_open(path.c_str(), &DB); 
    std::string textTable = "CREATE TABLE IF NOT EXISTS Text("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "title           TEXT    , "
                      "text          TEXT     , "
                      "summary            TEXT     , "
                      "resourceId INT,"
                      "resourcePath            TEXT     ); "
                      ; 
    exit = sqlite3_exec(DB, textTable.c_str(), NULL, 0, &messaggeError); 
    std::cout << messaggeError << std::endl; 
    std::string resourceTable = "CREATE TABLE IF NOT EXISTS Resources("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "type           TEXT    NOT NULL, "
                      "description          TEXT     ); "
                      ; 
     exit = sqlite3_exec(DB, resourceTable.c_str(), NULL, 0, &messaggeError); 
    std::cout << messaggeError << std::endl; 
    sqlite3_close(DB);  
}


bool check_exist(const std::string& path){
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open(path.c_str(), &DB); 
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        sqlite3_close(DB);  
        return (false); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl;
        sqlite3_close(DB);  
        return true;
}


void addStringResource(const std::string& path,const std::string &type, const std::string &description){
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open(path.c_str(), &DB); 
    std::stringstream ss;
    char* messaggeError;
    ss << "INSERT INTO Resources (type, description) VALUES ('" << type << "','" << description << "');";
    exit = sqlite3_exec(DB, ss.str().c_str(), NULL, 0, &messaggeError); 
    
    std::cout << ss.str() << std::endl; 
    sqlite3_close(DB);
}
void addStringText(const std::string& path, const std::string &title, const std::string &text, const std::string summary,int resourceId){
    sqlite3* DB; 
    int exit = 0; 
    // exit = sqlite3_open(path.c_str(), &DB); 
    std::stringstream ss;
    ss << "INSERT INTO Text (title, text, summary, resourceId) VALUES ('" << title <<"','" << text << "','" << summary << "'," << resourceId << ");";
    char* messaggeError;
    std::cout<<ss.str()<<std::endl; 
    exit = sqlite3_exec(DB, ss.str().c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Insert" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Records created Successfully!" << std::endl; 
    sqlite3_close(DB);
}
void fill_with_data(const std::string& path, const std::string& pathToCSVFile){

}
int main(int argc, char** argv) 
{ 
    check_exist("example.db");
    // dropTables("example.db");
    makeTables("example.db");
    addStringText("example.db", "title", "text", "summary", 1);
} 