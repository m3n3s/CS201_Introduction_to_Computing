#include "Robots_Modified.h"
#include "MiniFW_Modified.h"
#include <string>
#include "randgen.h"

// MEHMET ENES BATTAL - HW6

void randomMove(Robot & robot)
{
	RandGen direction;
	int d = direction.RandInt(1,4);

	if(d==1)
	{
		robot.TurnFace(east);
		if(!robot.FacingWall())
		{
			robot.Move();
			robot.PickAllThings();
		}
	}

	else if(d==2) 
	{
		robot.TurnFace(west);
		if(!robot.FacingWall())
		{
			robot.Move();
			robot.PickAllThings();
		}
	}

	else if(d==3) 
	{
		robot.TurnFace(north);
		if(!robot.FacingWall())
		{
			robot.Move();
			robot.PickAllThings();
		}
	}

	else if(d==4) 
	{
		robot.TurnFace(south);
		if(!robot.FacingWall())
		{
			robot.Move();
			robot.PickAllThings();
		}
	}
}

string remLives(int l)
{
	string s;
	if (l == 2)
		s = "You have 2 lives left";
	else if (l == 1)
		s = "You have 1 lives left";
	return s;

}

Robot maxMonster(Robot & n1, Robot & n2, Robot & n3)
{
	if((n1.GetBagCount() >= n2.GetBagCount()) && (n1.GetBagCount() >= n3.GetBagCount()))
		return n1;
    else if ((n2.GetBagCount() >= n1.GetBagCount()) && (n2.GetBagCount() >= n3.GetBagCount()))
        return n2;
    else
        return n3;
}

int main()
{
	string nameP;
	GetInput("Enter the name of player: ", nameP);

	string nameM1;
	GetInput("Enter the name of the fisrt monster: ", nameM1);

	string nameM2;
	GetInput("Enter the name of the second monster: ", nameM2);

	string nameM3;
	GetInput("Enter the name of the third monster: ", nameM3);

	for (int i = 0 ; i < 20; )
	{
		RandGen genx, geny;
		int x = genx.RandInt(0,7);
		int y = geny.RandInt(0,7);

		RandGen gen;
		int things = gen.RandInt(1,10);

		if (GetCellCount(x, y) == 0 )
		{
			PutThings(x,y,things);
			i++;
		}
	}

	Robot player(5,2);
	player.SetColor(green);
	player.SetName(nameP);
	
	Robot monster1(0,0);
	monster1.SetColor(red);
	monster1.SetName(nameM1);

	Robot monster2(0,7);
	monster2.SetColor(red);
	monster2.SetName(nameM2);

	Robot monster3(7,7);
	monster3.SetColor(red);
	monster3.SetName(nameM3);

	int prevMonster = 0;
	int lives = 3;

	while(lives > 0 && GetThingCount(0,0,7,7) > 0)
	{
		RandGen gen;
		int m = gen.RandInt(1,3);
		if(m != prevMonster)
		{
			if(m == 1)
			{
				randomMove(monster1);
				prevMonster = 1;
			}
			if(m == 2)
			{
				randomMove(monster2);
				prevMonster = 2;
			}
			if(m == 3)
			{
				randomMove(monster3);
				prevMonster = 3;
			}
		}

		if (IsPressed(keyRightArrow))
		{				
			player.TurnFace(east);
			player.Move();
			player.PickAllThings();
		}
		else if (IsPressed(keyLeftArrow))
		{
			player.TurnFace(west);
			player.Move();
			player.PickAllThings();
		}
		else if (IsPressed(keyUpArrow))
		{
			player.TurnFace(north);
			player.Move();
			player.PickAllThings();
		}
		else if (IsPressed(keyDownArrow))
		{
			player.TurnFace(south);		
			player.Move();
			player.PickAllThings();
		}

		if (!monster1.IsAlive())
			monster1.Resurrect();
		if (!monster2.IsAlive())
			monster2.Resurrect();
		if (!monster3.IsAlive())
			monster3.Resurrect();
		if (!player.IsAlive())
		{
			lives --;
			if (lives != 0)
			{
				ShowMessage(remLives(lives));
				player.Resurrect();
			}
		}
	}

	Robot max = maxMonster(monster1, monster2, monster3);

	if(lives == 0)
		ShowMessage(nameP + " is out of lives, you just lost the game.");
	else if (player.GetBagCount() > max.GetBagCount())
		ShowMessage("Congratulations. " + nameP + " has won the game.");
	else
		ShowMessage("You lost. " + max.GetName() + " has won the game.");

	return 0;
}