#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  int uin;
  while(ifs.eof() == false)
  {
    string line;
    getline(ifs, line);
    istringstream iss(line);
    iss >> uin;
    int ct = 0;
    double don = 0;
    while(iss.eof() == false)
    {
      double n;
      iss >> n;
      don += n;
      ct++;
    }

    if(ct > 1 && don > maxTotalDonation)
    {
      maxTotalDonation = don;
      maxTotalCollector = uin;
    }
  }
    if(maxTotalDonation == 0)
    {
      cout << "No donations." << endl;
      return 0;
    }

  
  // read data
  
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
}
