#include <iostream>
#include <deque>
#include <vector>
#include <time.h>


using namespace std;



class cPlayer{
    public:
        int x, y;

    cPlayer(int width) { x = width/2; y=0;}
    // the player starts in the middle of the road (x), at the top of the screen (y)
};

class cLane{
private:
deque <bool> cars;

public: 
    cLane (int width) 
    {

    for (int i = 0; i < width ; i++){

    cars.push_front(false); //start the game with a blank lane
    }

    }

    void Move(){    
    if(rand() % 4 == 0){
        cars.push_front(true);
    }
    else {
        cars.push_front(false);
        cars.pop_back();
    }
}
bool CheckPos(int pos) 
{return cars[pos];
}
};

class cGame {
    private:
        bool quit;
        int numberOfLanes, width;
        int score;
        cPlayer * player;
        vector <cLane*> map;

    public:
    cGame(int w = 20, int h = 10)
    {
        numberOfLanes = h;
        width = w;
        quit = false;
        player = new cPlayer(width);

        for (int i = 0; i < numberOfLanes; i ++)
        {
        map.push_back(new cLane(width));
        };
    }
        void Draw(){


            for (int a = 0; a < numberOfLanes; a++)
            {
            for (int b = 0; b < width; b++){
                if (map[a]->CheckPos(b)){
                    cout << "#";}
                    else if (player -> x == b && player -> y == a){
                        cout << "V";
                    }
                    else { cout << " ";}
                }
                cout << endl;
            }
            };

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
    srand(time(NULL)); // reseed the random number generator in the lane's move function, for testing purposes.
   cGame game = cGame(30,10);
   game.Run();
    getchar();
    return 0;
};

