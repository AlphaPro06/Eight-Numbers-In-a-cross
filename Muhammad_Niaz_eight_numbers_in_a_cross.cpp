#include <iostream>
using namespace std;

bool okay(int cross[], int box ){
    static int adj_table[8][5] = {
        {-1},   //box 0
        {0, -1}, // box 1
        {0, 1, -1}, // box 2
        {0, 2, -1}, //box 3
        {1, 2, -1}, //box 4
        {1, 2, 3, 4, -1}, // box 5
        {2, 3, 5, -1}, // box 6
        {4, 5, 6, -1} // box 7
    };
    for (int i = 0; i < box; i++){
        if (cross[i] == cross[box])
        return false;
    }
     for(int i = 0; adj_table[box][i]!=-1; i++){ //For each neighbor of square box,
      if(cross[adj_table[box][i]]+1 == cross[box] || cross[adj_table[box][i]]-1 == cross[box])
        return false;
   }

   return true; 

}

void print (int cross[]){
    static int numSolutions = 1;
    cout << "Solutions # "<< numSolutions << ":" << endl;
    cout << " " << " " << cross[1] << cross[4] << endl;
   cout << " " << cross[0] << cross[2] << cross[5] << cross[7] << endl;
   cout << " " << " " << cross[3] << cross[6] << endl;

   cout << endl;
   numSolutions++;
}

void check_next_value(int cross[], int box) {
   if (box == 8)
      print(cross);
   else for (cross[box] = 1; cross[box] < 9; ++cross[box])
      if (okay(cross, box))
         check_next_value(cross, box+1);
}
int main(){
int cross[8];
   check_next_value(cross, 0);
   return 0;
}