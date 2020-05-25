#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
using namespace std;

class DataExtractor {
  private:
    static DataExtractor* dataExtractorInstance;

    int numberOfColumns;
    vector<string> columnTitles;
    vector<double> columnSum;
    vector<int> columnFieldCount;

    // separate comma separated string into a vector of strings 
    vector<string> parser(string input) {
      string build;
      vector<string> parsedInfo;

      for(int i = 0; i <= input.size(); i++) {
        if(i == input.size() or input[i] == ',') {
          parsedInfo.push_back(build);
          build.clear();
        }
        else build += input[i];
      }
      return parsedInfo;
    }

    // extract Data from CSV
    // expect first row with column names
    // other rows with numeric or null values
    void csvReader(string csvName) {
      fstream fileRead;
      fileRead.open(csvName);

      string s;

      getline(fileRead, s);
      columnTitles = parser(s);

      numberOfColumns = columnTitles.size();

      columnSum.resize(numberOfColumns);
      columnFieldCount.resize(numberOfColumns);

      while(getline(fileRead, s)) {
        vector<string> parsedInfo = parser(s);

        for(int i = 0; i < numberOfColumns; i++) {
          if(parsedInfo[i].size()) {
            columnFieldCount[i]++;
            columnSum[i] += stod(parsedInfo[i]);
          }
        }
      }

    }

  public:
    DataExtractor(string csvName) {
      csvReader(csvName);
    }

    static DataExtractor* getInstance(string csvName) {
      if(dataExtractorInstance == nullptr) dataExtractorInstance = new DataExtractor(csvName);
      return dataExtractorInstance;
    } 

    void checkNumberOfColumns(int columnNumber) {
      if(columnNumber < 1 or columnNumber > numberOfColumns) throw invalid_argument("Input not in [1 .. " + to_string(numberOfColumns) + "] range");
    }

    // expect integers from 1 to numberOfColumns
    double showColumnAverage(int columnNumber) {
      checkNumberOfColumns(columnNumber);

      columnNumber--;

      double num = columnSum[columnNumber];
      double dem = columnFieldCount[columnNumber];

      if(!dem) throw invalid_argument("Column doesn't have any info");

      double average = num / dem;

      return average;
    }

    // Created for testing
    void interfaceSimulator() {
      int columnNumber;
      cout << "Inform column number: " << endl;
      cin >> columnNumber;

      checkNumberOfColumns(columnNumber);
      
      double average = showColumnAverage(columnNumber);
      
      columnNumber--;
      string columnTitle = columnTitles[columnNumber];

      cout << "Column name: " << columnTitle << endl;
      cout << fixed << setprecision(2) << "Average: " << average << endl;
    }
};

DataExtractor* DataExtractor::dataExtractorInstance = nullptr;

int main() {
  DataExtractor* test = DataExtractor::getInstance("Taxa de Abandono - Limpa.csv");
  test -> interfaceSimulator();
}
