#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Maze{
public:
  int row;
  int col;
  int *maze;
  int start[2];
  int end[2];
  string path;
  string finalPath;
  Maze(){
    path = "";
    finalPath = "";
  }
  void readFile(istream& in){
    string filename;
    in >> filename;
    int counter = 0, j = 0;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
      while (getline(file , line )){
        if (counter > 2){
          for (int i=0; i < line.length(); i++){
            maze[i + ((row-j-1) * row)] =line[i] -'0';
          }
          j++;
        }
        if (counter == 0){
          istringstream ss(line);
          string token;
          getline(ss,token,' ');
          col = stoi(token);
          getline(ss,token,' ');
          row = stoi(token);
          maze=(int *) malloc(col * row * sizeof(int));
        }
        if (counter == 1){
          istringstream ss(line);
          string token;
          getline(ss,token,' ');
          start[0] = stoi(token);
          getline(ss,token,' ');
          start[1] = stoi(token);
        }
        if (counter == 2){
          istringstream ss(line);
          string token;
          getline(ss,token,' ');
          end[0] = stoi(token);
          getline(ss,token,' ');
          end[1] = stoi(token);
        }
        counter++;
      }
    }
    file.close();
    solveMaze(start[0], start[1]);
  }

  void printMaze(){
    printPath();
    cout << path<<endl;
    for (int i = 0; i < row; i++){
      for (int j = 0; j <col; j++){
        cout<< maze[j + (i * row)];
      }
      cout<<endl;
    }
  }

  bool solveMaze(int c, int r){
    if (c == end[0] && r == end[1]){
        return true;
      }
    else if( maze[c + (r * row)] == 1)
        return false;
    else if(maze[c + (r * row)] == 2)
        return false;
    maze[c + (r * row)] = 2;

    if (c < col-1 && solveMaze(c+1, r)){
        path.append("R");
        return true;
      }
    else if(r > 0 && solveMaze(c, r-1)){
        path.append("D");
        return true;
      }
    else if(c > 0 && solveMaze(c-1, r)){
        path.append("L");
        return true;
      }
    else if(r <row -1  && solveMaze(c, r+1)){
        path.append("U");
        return true;
      }
    return false;
  }
  void printPath(){
    int size = path.length();
    for (int i = size; i >= 0; i--)
      finalPath+=path[i];
    cout<< finalPath;
  }
  ~Maze(){delete(maze);}
};

int main(){
  Maze * m = new Maze();
  m->readFile(cin);
  //m->printMaze();
  m->printPath();
  delete m;
}
