#pragma config(Sensor, S1, c1, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S2, c2, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3, c3, sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor, motorB, lm, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorC, rm, tmotorEV3_Large, PIDControl, encoder)

#define DIFF 10

int nMotorSpeedSetting = 35, vertex = 0, count = 0, row = 0, val, color, init = 0,
r = 0, c = 0, i, j, f, e, score;

int S[4][5], dt[4][5];


void colorSearchTurn()
{
      setMotorSpeed(lm, 15);
      setMotorSpeed(rm, -15);
      sleep(120);
      setMotorSpeed(lm, 0);
      setMotorSpeed(rm, 0);
      sleep(50);
}

void patchSave()
{
   int i = 0, color = 0;
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);

   color = getColorName(c2);

   if (init == 0 ){
         displayBigTextLine(1, "S[%d][%d] = YELLOW", row , count);
         S[row][count] = 0;
         sleep(1000);
         init++;
   }
   else if (row % 2 == 0){
      if(color == 3){
         displayBigTextLine(1,"S[%d][%d] = GREEN", row, ++count);
         S[row][count] = -5;
         sleep(1000);
      }
      else if (color == 5){
         displayBigTextLine(1, "S[%d][%d] = RED", row, ++count);
         S[row][count] = 5;
         sleep(1000);
      }
      else{
         displayBigTextLine(1, "S[%d][%d] = YELLOW", row , ++count);
         S[row][count] = 0;
         sleep(1000);
      }
   }

   else if(row % 2!= 0){
      if(color == 3){
         displayBigTextLine(1,"S[%d][%d] = GREEN", row, 4-(++count));
         S[row][4-count] = -5;
         sleep(1000);
      }
      else if(color == 5){
         displayBigTextLine(1,"S[%d][%d] = RED", row, 4-(++count));
         S[row][4-count] = 5;
         sleep(1000);
      }
      else{
         displayBigTextLine(1,"S[%d][%d] = YELLOW", row, 4-(++count));
         S[row][4-count] = 0;
         sleep(1000);
      }
   }
   setLEDColor(0);
}

void go()
{
   val = 5;

   if(getColorName(c2) == 4)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else if(getColorName(c2) == 3)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else if(getColorName(c2) == 5)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else
   {
      setMotorSpeed(lm, nMotorSpeedSetting + val);
      setMotorSpeed(rm, nMotorSpeedSetting - val);
   }
   if(row == 1)
   {
      if(getColorName(c1) == 4 && count != 5)
      {
         vertex++;
      }
      else
         vertex = 0;
  }
  else if(row == 3)
  {
     if(getColorName(c1) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
  else if(row == 4)
  {
     if(getColorName(c1) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
  else
  {
     if(getColorName(c3) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
   // Edit motot speed
  if(vertex == 1)
  {
     if(row == 0 || row == 2)
     {
       colorSearchTurn();
       sleep(150);
       setMotorSpeed(lm, 12);
       setMotorSpeed(rm, 10);
       sleep(80);
     }
     else
     {
       colorSearchTurn();
       sleep(150);
       setMotorSpeed(lm, 10);
       setMotorSpeed(rm, 12);
       sleep(80);
     }
     patchSave();
  }
}

void go_nosave()
{
   val = 5;

   if(getColorName(c2) == 4)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else if(getColorName(c2) == 3)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else if(getColorName(c2) == 5)
   {
      setMotorSpeed(lm, nMotorSpeedSetting - val);
      setMotorSpeed(rm, nMotorSpeedSetting + val);
   }
   else
   {
      setMotorSpeed(lm, nMotorSpeedSetting + val);
      setMotorSpeed(rm, nMotorSpeedSetting - val);
   }
   if(row == 1)
   {
      if(getColorName(c1) == 4 && count != 5)
      {
         vertex++;
      }
      else
         vertex = 0;
  }
  else if(row == 3)
  {
     if(getColorName(c1) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
  else if(row == 4)
  {
     if(getColorName(c1) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
  else
  {
     if(getColorName(c3) == 4 && count != 5)
     {
        vertex++;
     }
     else
        vertex = 0;
  }
   // Edit motot speed
  if(vertex == 1)
  {
     if(row == 0 || row == 2)
     {
       colorSearchTurn();
       sleep(150);
       setMotorSpeed(lm, 12);
       setMotorSpeed(rm, 10);
       sleep(80);
     }
     else
     {
       colorSearchTurn();
       sleep(150);
       setMotorSpeed(lm, 10);
       setMotorSpeed(rm, 12);
       sleep(80);
     }
     count += 1;
  }
}

void turnLeft()
{
   setMotorSpeed(lm, 25);
   setMotorSpeed(rm, 25);
   sleep(300);
   while(getColorName(c1) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
      sleep(10);
   }
   while(getColorName(c2) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
   }
   sleep(80);
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);
   sleep(200);
   count = 0;
}

void turnRight()
{
   setMotorSpeed(lm, 25);
   setMotorSpeed(rm, 25);
   sleep(250);
   while(getColorName(c3) > 4)
   {
      setMotorSpeed(lm, nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, -nMotorSpeedSetting * 6 / 10);
      sleep(10);
   }
   while(getColorName(c2) > 4)
   {
      setMotorSpeed(lm, nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, -nMotorSpeedSetting * 6 / 10);
   }
   sleep(80);
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);
   sleep(200);
   count = 0;
}

void turn()
{
   setMotorSpeed(lm, 25);
   setMotorSpeed(rm, 25);
   sleep(300);
   while(getColorName(c1) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
      sleep(10);
   }
   while(getColorName(c2) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
   }
   while(getColorName(c3) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
      sleep(10);
   }
   while(getColorName(c2) > 4)
   {
      setMotorSpeed(lm, -nMotorSpeedSetting * 6 / 10);
      setMotorSpeed(rm, nMotorSpeedSetting * 6 / 10);
   }
   sleep(80);
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);
   sleep(200);
   count = 0;
}

void back()
{
   while(true)
   {
      setMotorSpeed(lm, -20);
      setMotorSpeed(rm, -20);
      if(getColorName(c1) == 4 || getColorName(c3) == 4)
         break;
  }
}

void goUp()
{
    turnRight();
    count = 0;
    while(true)
    {
        go_nosave();
        if (count != 0)
        {
            setMotorSpeed(lm, 10);
            setMotorSpeed(rm, 10);
            sleep(250);
            turnLeft();
            setMotorSpeed(lm, -30);
            setMotorSpeed(rm, -20);
            sleep(200);
            break;
        }
    }
}

void goDown()
{
    turnLeft();
    count = 0;
    while(true)
    {
        go_nosave();
        if (count != 0)
        {
            setMotorSpeed(lm, 10);
            setMotorSpeed(rm, 10);
            sleep(250);
            turnRight();
            break;
        }
    }
}

void goLeft()
{
    count = 0;
    while(true)
    {
        go_nosave();
        if (count != 0)
        {
            break;
        }
    }
    setMotorSpeed(lm, 25);
    setMotorSpeed(rm, 25);
    sleep(200);
}

void goRight()
{
   turnLeft();
   turnLeft();
   count = 0;
   while(true)
   {
      go_nosave();
      if(count != 0)
      {
      setMotorSpeed(lm, 10);
      setMotorSpeed(rm, 10);
      sleep(250);
      turnRight();
      turnRight();
      break;
    }
  }
}

void completeSearch()
{
    while(true)
    {
        go();
        if (count == 4)
        {
            if(row == 3)
            {
                return;
            }

            if (row % 2 == 0)
            {
                setMotorSpeed(lm,35);
                setMotorSpeed(rm,30);
                sleep(200);
                turnRight();
            }

            else
            {
                setMotorSpeed(lm,30);
                setMotorSpeed(rm,35);
                sleep(200);
                turnLeft();
            }

            row++;

            if(row%2 == 0)
            {
                while(getColorName(c1) == 6)
                {
                    go();
                }
                colorSearchTurn();
                      sleep(150);
                     setMotorSpeed(lm, 10);
                      setMotorSpeed(rm, 12);
                      sleep(80);

                count = -1;
                patchSave();

                setMotorSpeed(lm,30);
                setMotorSpeed(rm,35);
                sleep(300);
                turnLeft();
            }

            else
            {
                while(getColorName(c3) == 6)
                {
                    go();
                }
                colorSearchTurn();
                      sleep(150);
                      setMotorSpeed(lm, 10);
                    setMotorSpeed(rm, 12);
                      sleep(80);

                count = -1;
                patchSave();

                setMotorSpeed(lm, 35);
                setMotorSpeed(rm, 30);
                sleep(200);
                turnRight();
            }
            count = 0;
            sleep(200);
        }
    }
}

void printMap()
{
   char map[4][5];
   for(int i = 0; i < 4; i++)
   {
      for(int j = 0; j < 5; j++)
      {
         if(S[i][j] == 0)
         {
           map[i][j] = '+';
         }
         else if(S[i][j] == 5)
         {
           map[i][j] = 'O';
         }
         else if(S[i][j] == -5)
         {
           map[i][j] = 'X';
         }
      }
   }
   for(int p = 0; p < 4; p++)
   {
      for(int q =0; q < 5; q++)
      {
         displayStringAt((q+1)*10, 100-(p+1)*10, "%c",map[p][q]);
      }
   }
   sleep(3000);
}

void printscoreMap()
{
   for(int p = 0; p < 4; p++)
   {
      for(int q =0; q < 5; q++)
      {
         displayStringAt((q+1)*10, 100-(p+1)*10, "%d",dt[p][q]);
      }
   }
   sleep(3000);
}

void printroadMap()
{
   for(int p = 0; p < 4; p++)
   {
      for(int q =0; q < 5; q++)
      {
         displayStringAt((q+1)*10, 100-(p+1)*10, "%d",S[p][q]);
      }
   }
   sleep(3000);
}

void stopMotor()
{
   setMotorSpeed(lm, 0);
   setMotorSpeed(rm, 0);
}

void movePoint_44()
{
   count = 0;
   while(true)
   {
      go_nosave();
      if (count == 4)
      {
         setMotorSpeed(lm, 35);
         setMotorSpeed(rm, 30);
         sleep(100);
         turnLeft();
         setMotorSpeed(lm, -10);
         setMotorSpeed(rm, -10);
         sleep(300);
         turnLeft();
         break;
      }
   }
}

task main()
{
   while(getButtonPress(1) == 0)
   {
      sleep(10);
   }

   completeSearch();
   setMotorSpeed(lm,30);
   setMotorSpeed(rm,30);
   sleep(350);
   turnLeft();
   turnLeft();
   //sleep(1000);

   sleep(2000);

   movePoint_44();
   sleep(300);

   printMap();
   sleep(3000);

    for(f = 0; f <= 4; f++)
    {
      for(e = 0; e<= 3; e++)
       {
          if( e == 0 && f == 0) dt[e][f] = S[e][f];
          else if( f == 0) dt[e][f] = dt[e-1][f] + S[e][f];
          else if( e == 0) dt[e][f] = dt[e][f-1] + S[e][f];
          else
          {
            if( dt[e-1][f] >= dt[e][f-1])
            {
              dt[e][f] = dt[e-1][f] + S[e][f];
            }
            else
              dt[e][f] = dt[e][f-1] + S[e][f];
          }
        }
      }

    printscoreMap();
    sleep(3500);

    e = 3; f = 4;
    while(e != 0 && f != 0)
    {
      if( dt[e-1][f] >= dt[e][f-1])
      {
         S[e][f] = 10;
         e -= 1;
      }
      else
      {
         S[e][f] = 10;
         f -= 1;
      }
    }
    if( e == 0 )
     {
        while(f != 0)
        {
           S[e][f] = 10;
           f -= 1;
        }
    }
    else
    {
       while(e != 0)
       {
          S[e][f] = 10;
          e -= 1;
       }
    }
    S[0][0] = 10;

    printroadMap();
    sleep(3000);

    e = 3; f = 4;
    while(e != 0 && f != 0)
    {
       if(e >= 1 && f >= 1)
       {
          if( S[e-1][f] == 5)
          {
             goUp();
             goDown();
             S[e-1][f] = 0;
             dt[3][4] += 3;
          }
          else if( S[e][f-1] == 5)
          {
             goLeft();
             goRight();
             S[e][f-1] = 0;
             dt[3][4] += 3;
          }
          if( e >= 2 && f >= 2)
          {
             if( S[e-2][f] == 5)
             {
                goUp();
                goUp();
                goDown();
                goDown();
                S[e-2][f] = 0;
                dt[3][4] += 1;
             }
             else if( S[e][f-2] == 5)
             {
                goLeft();
                goLeft();
                turn();
                goLeft();
                goLeft();
                turn();
                back();
                setMotorSpeed(lm, 25);
                setMotorSpeed(rm, 25);
                sleep(300);
                S[e][f-2] = 0;
                dt[3][4] += 1;
             }
          }
       }
      if( S[e-1][f] >= S[e][f-1])
      {
         goUp();
         e -= 1;
         dt[3][4] -= 1;
      }
      else
      {
         goLeft();
         f -= 1;
         dt[3][4] -= 1;
      }
    }
    if( e == 0 )
     {
        while(f != 0)
        {
           goLeft();
           f -= 1;
           dt[3][4] -= 1;
        }
    }
    else
    {
       while(e != 0)
       {
          goUp();
          e -= 1;
          dt[3][4] -= 1;
       }
    }
    playTone(240, 20); sleep(200);
    stopMotor();
    while(getButtonPress(1) == 0) sleep(10);
    displayBigTextLine(1, "Score = %d", dt[3][4]);
    sleep(5000);
}
