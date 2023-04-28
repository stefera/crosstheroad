#include <iostream>
#include <deque>
#include <vector>
#include <time.h>

using namespace std;

class cPlayer{
    public:
        int x, y;

    cPlayer(int width) { x = width/2; y=0;}

};


class cGame {
    private:
        bool quit;
    public:
        void Draw(){

        }

        void Input(){
            
        }

        void Logic(){
            
        }

        void Run(){
            while (!quit){
                Input();
                Draw();
                Logic();
                
            
            }
        }


};

int main(){
    return 0;
}
