#include<fstream>
#include<iostream>

using namespace std;

bool isActivated(string path){
  bool is;
  fstream file(path);
  file >> is;
  cout << is << endl;
  return is;
}

int main(){
  string dir = " /sys/bus/platform/drivers/ideapad_acpi/VPC2004:00/conservation_mode";
  string instAC = "sudo sed -i 's/1/0/g' " + dir;
  string instDEC = "sudo sed -i 's/0/1/g' " + dir;
  if (isActivated(dir)){
    cout << '1' << endl;
    system(instAC.c_str());
    system("notify-send 'Conservation Mode' 'OFF' ");
  }
  else if (!isActivated(dir)){
    cout << '2' << endl;
    system(instDEC.c_str());
    system("notify-send 'Conservation Mode' 'ON' ");

  }
  else{
    system("notify-send 'Conservation Mode' 'ERROR' ");
  }
  return 0;
}