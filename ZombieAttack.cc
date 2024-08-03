#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define ZOMBIECOUNT 4

typedef struct point
   {
   int X;
   int Y;
   } point;


int updateZombies(point * zom, point * hum);
int moveZombie(int, int);


int main(int argc, char * argv[])
   {
   point human;
   point zombie[ZOMBIECOUNT] = {{0,25},{10,15},{20,5}, {25,0}};
   
   int i, move = 0, status = -1;

   if (argc < 3) 
      {
      cout << "Must specify the Human X and Y coordinates:  ./ZombieAttack 42 24\n";
      return (-1);
      }
      
   human.X = atoi (argv[1]); // read humanX
   human.Y = atoi (argv[2]); // read humanX
   cout << "The Human's coordinates are: ("<< human.X << ", " << human.Y << ")\n";

   while (status == -1) 
      {

      // update Zombie positions
      status = updateZombies(zombie, &human);

      cout << "Move " << move << " - the zombies are closing in" << endl;
      for (i=0; i < ZOMBIECOUNT; i++)
         cout << "Zombie " << i << " is at " << zombie[i].X << " " << zombie[i].Y << endl;

      move++;
      }
   cout << "Zombies - Yum Yum ... Zombie " << status << " won - Game over\n";
   return (0);
   }


int updateZombies(point * zom, point * hum)
   {
   int i, winner = -1;

   for (i=0; i < ZOMBIECOUNT; i++) 
      {
      zom[i].X = moveZombie(zom[i].X,hum->X);  // update x-coordinate of Zombie i
      zom[i].Y = moveZombie(zom[i].Y,hum->Y);  // update y-coordinate of Zombie i

      // check if Zombie caught human
      if ((zom[i].X == hum->X) && (zom[i].Y == hum->Y)) 
         {
         winner = i;
         break;
         }
      }
   return winner;
   }

// move coordinate of Zombie closer to coordinate of human
// if Zombie x or y axis is at least 10 units from human, close the
// distance by 10 otherwise close the distance by 1
int moveZombie(int z, int h)
{
  int temp, result;

  temp = z - h;
  if (temp >= 10)
    result = z - 10;
  else if (temp > 0)
    result = z - 1;
  else if (temp == 0)
    result = z;
  else if (temp > -10)
    result = z + 1;
  else 
    result = z + 10;

  return result;
}
