#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>


using namespace std;

class arr {
   int* u;
   int length, m;
  void swap(int i, int j) {
       int x = u[i];
       u[i] = u[j];
       u[j] = x;
   }
public:
  arr(int len) {
     u = new int[len];
     m = 0;
     length = len;
  }
  arr& operator<< (int x) {
      if (m==length)
         throw "FULL ARRAY"; 
      u[m] = x;
      m++;
      return *this; 
  }

  int& operator[](int k) {
      if (k<0 || k>=length)
         throw "INVALID INDEX";
      return u[k];
  } 
  void reset() {
      m = 0; 
  }
  int len() {
    return length;
  } 
  int size() {
      return m;      return m;
  }
  string toStr() {
      stringstream ss;
      for (int k=0; k<m; k++)
          ss << u[k] << " ";      
      return ss.str() + "\n";
  }
  void shuffle() {
      int seed = (int) clock();      
      srand(seed);    
      for(int n=m; n>1; n--) {
          int p = rand() % (n-1);
          swap(p, n-1);
      }
      
  }  
  void sortByBubble() {
      if (m<2) 
         return;
      for (int t=m-1; t>0; t--)
          for (int i=0; i<t; i++) 
              if (u[i]>u[i+1]) 
                swap(i, i+1);
  } 

  void selectionSort(){
    for(int i = 0; i < m; i++){
        int k = i;
        for(int j = i; j < m; j++){
            if(u[i] < u[k])
                k = j;
        }
        swap(i,k);

         }
    }
  
  ~arr() {
       delete [] u;
   }
};

int main() {
    arr a(50);
    a << 25 << 10 << 15 << 12 << 31;
    std::cout << "vetor:\n";
    std::cout << a.toStr();
    a.sortByBubble();
    cout << "Sorted:\n";
    std::cout << a.toStr();
    a.shuffle();
    cout << "Shuffled:";
    std::cout << a.toStr();
    a.selectionSort();
    cout << "Selection Sort: \n";
    std::cout << a.toStr();
    a.shuffle();
    

}


 
