#include<iostream>
#include<vector>
using namespace std;
void clear(){
  cout << "\033[2J\033[1;1H";
}
class ADCET{
public:
string name,ID,Dept,address;
};
class teachers:public ADCET{
public:
teachers(string name,vector<string>&sub,long long salary,vector<char>&div,int ns){
  this-> subjects_of_teacher = sub;
  this->name=name;
  this->salary=salary;
  this->div=div;
  this->no_of_subjects_of_per_teacher=ns;
}
  void set_count(vector<int>total_per_div){
    this->total_per_div=total_per_div;
  }
  vector<int>no_of_students_per_teacher;
  int no_of_subjects_of_per_teacher;
  vector<string> subjects_of_teacher;
  long long salary;
  vector<int>total_per_div;
  vector<char>div;
};
class divisions:public ADCET{
public:
divisions(vector<string>total_sub,vector<int>no_of_stu,int nstu){
  this->subjects=total_sub;
  this->no_of_students=no_of_stu;
  this->strength=nstu;
}
  int strength;
  vector<string>subjects;
  vector<int> no_of_students;
};
int main () {
  int n,nsub,ndiv;
  vector<string>total_sub;
  vector<char>total_div;
  cout<<"Enter total no. of subjects in the ADCET : \n";
  cin>>nsub;
  cin.ignore();
  cout<<"Enter "<<nsub<<" subjects : ";
  for(int i=0;i<nsub;i++){
    string sub;
    cout<<"Sub "<<i+1<<" : ";
    getline(cin,sub);
    total_sub.push_back(sub);
  }
  clear();
  cout<<"Enter how many divisions are in the ADCET : ";
  cin>>ndiv;
  cin.ignore();
  char ch='A';
  for(int i=0;i<ndiv;i++){
    total_div.push_back(ch);
    ch++;
  }
  clear();
  cout<<"Now let's enter data of teachers from ADCET : \n";
  cout<<"How many tecahers are in the ADCET : ";
  cin>>n;
  cin.ignore();
  cout<<"Enter data of "<<n<<" tecahers :\n";
  int ns,nd;
  vector<teachers> teacher;
  for(int i=0;i<n;i++){
    cout<<"Teacher "<<i+1<<" :\n";
    string name;
    char div;
    long long salary;
    cout<<"Name : ";
    getline(cin,name);
    cout<<"Salary : ";
    cin>>salary;
    cout<<"How many subjects does "<<name<<" teach : ";
    cin>>ns;
    cin.ignore();
    vector<string>subj;
    for(int j=0;j<ns;j++){
      cout<<"Subject "<<j+1<<" : ";
      string sub;
      getline(cin,sub);
      subj.push_back(sub);
    }
    cout<<"How many divisions does "<<name<<" teaches : ";
    cin>>nd;
    cin.ignore();
    vector<char>divs;
    for(int j=0;j<nd;j++){
      cout<<"Div "<<j+1<<" : ";
      cin>>div;
      divs.push_back(div);
    }
    teachers newt(name,subj,salary,divs,ns);
    teacher.push_back(newt);
    cin.ignore();
    clear();
  }
  int nstu;
  vector<divisions> division;
  for(int i=0;i<ndiv;i++){
    cout<<"Enter how many students are in the Div : "<<total_div[i]<<endl;
    cin>>nstu;
    int cnt;
    vector<int>no_of_stu;
    for(int j=0;j<nsub;j++){
      cout<<"How mnay students from Div-"<<total_div[i]<<" study "<<total_sub[j]<<" : ";
      cin>>cnt;
      no_of_stu.push_back(cnt);
    }
    divisions d(total_sub,no_of_stu,nstu);
    division.push_back(d);
  }
  clear();
  int cnt2=0;
  for(int i=0;i<n;i++){
    vector<int>totall;
    int no,total=0;
    for(int j=0;j<ndiv;j++){
      if(teacher[i].div[cnt2]==total_div[j]){
        cnt2++;
      for(int k=0;k<teacher[i].no_of_subjects_of_per_teacher;k++){
        for(int l=0;l<nsub;l++){
          if(teacher[i].subjects_of_teacher[k]==division[j].subjects[l]){
            no=division[j].no_of_students[l];
            total+=no;
          }
        }
      }
    }
      totall.push_back(total);
      total=0;
    }
    teacher[i].set_count(totall);
    cnt2=0;
  }
  clear();
  int cnt=0;
  cout<<"Data of "<<n<<" teachers is as follows :\n";
  for(int i=0;i<n;i++){
    cout<<"No of students "<<teacher[i].name<<" has to teach in :"<<endl;
    for(int j=0;j<ndiv;j++){
      if(teacher[i].div[cnt]==total_div[j]){
        cnt++;
      cout<<"Div-"<<teacher[i].div[cnt-1]<<" are : ";
      cout<<teacher[i].total_per_div[j]<<endl;
    }
  }
    cnt=0;
  }
}

