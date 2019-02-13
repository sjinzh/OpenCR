/*******************************************************************************
* Copyright 2018 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Darby Lim, Hye-Jong KIM, Ryan Shim, Yong-Ho Na */

#ifndef DEMO_H_
#define DEMO_H_

#include <planar_libs.h>

bool start_demo_flag;
uint8_t motion_cnt[] = {0};
uint8_t sub_motion_cnt[] = {0};

/*****************************************************************************
** Functions used in runDemo()
*****************************************************************************/
/* Draw an Object */
void drawObj(Planar* planar, STRING object, double radius, int num_revolution, double start_angular_position, double move_time)
{
  double draw_arg[3]; 
  draw_arg[0] = radius;                 // Radius (m)
  draw_arg[1] = num_revolution;         // Number of revolution
  draw_arg[2] = start_angular_position; // Starting angular position (rad)
  void* p_draw_arg = &draw_arg;

  planar->makeCustomTrajectory(object, "tool", draw_arg, move_time);
}

/*****************************************************************************
** Start or Stop Demo
*****************************************************************************/
void startDemo()
{
  // Start the demo
  start_demo_flag = true;
}

void stopDemo(Planar *planar)
{
  // Stop the demo
  start_demo_flag = false;

  // Move to the default pose.
  planar->makeTaskTrajectory("tool", math::vector3(0.0, 0.0, 0.0), 2.0);

  // Reset the count variables
  motion_cnt[0] = 0;
  sub_motion_cnt[0] = 0;
}

/*****************************************************************************
** Initialize Demo
*****************************************************************************/
void initDemo()
{
  start_demo_flag = false;
  motion_cnt[0] = 0;
  sub_motion_cnt[0] = 0;
}

/*****************************************************************************
** Run Demo
*****************************************************************************/
void runDemo(Planar *planar)
{
  if(digitalRead(BDPIN_PUSH_SW_1))
  {
    startDemo();
  }
  if(digitalRead(BDPIN_PUSH_SW_2))
  {
    stopDemo(planar);    
  }

  if (planar->getMovingState()) 
  {
    return;
  }
  else 
  {
    if (start_demo_flag)
    {
      switch(motion_cnt[0])
      {
        case 0:
          // planar->makeTaskTrajectory("tool", math::vector3( 0.045, 0.0, 0.0), 1);
          motion_cnt[0] ++; 
        break;
        case 1:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 2:
          // planar->makeTaskTrajectory("tool", math::vector3( 0.0, 0.045, 0.0), 1);
          motion_cnt[0] ++; 
        break;
        case 3:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 4:
          // planar->makeTaskTrajectory("tool", math::vector3(-0.045, 0.0, 0.0), 1);
          motion_cnt[0] ++; 
        break;
        case 5:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 6:
          // planar->makeTaskTrajectory("tool", math::vector3( 0.0,-0.045, 0.0), 1);
          motion_cnt[0] ++; 
        break;
        case 7:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 8:
          // planar->makeTaskTrajectory("tool", math::vector3( 0.045, 0.0, 0.0), 1);
          motion_cnt[0] ++; 
        break;
        case 9:
          planar->sleepTrajectory(0.5);
          motion_cnt[0] ++; 
        break;
        case 10:
          planar->makeTaskTrajectory("tool", math::vector3( 0.045, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 11:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 12:
          planar->makeTaskTrajectory("tool", math::vector3( 0.0,0.045, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 13:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 14:
          planar->makeTaskTrajectory("tool", math::vector3(-0.045, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 15:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 16:
          planar->makeTaskTrajectory("tool", math::vector3( 0.0,-0.045, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 17:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 18:
          planar->makeTaskTrajectory("tool", math::vector3( 0.045, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 19:
          // planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 20:
          drawObj(planar, CUSTOM_TRAJECTORY_CIRCLE, 0.045, 1, 0.0, 0.8);
          motion_cnt[0] ++; 
        break;
        case 21:
          planar->sleepTrajectory(0.05);
          motion_cnt[0] ++; 
        break;
        case 22:
          // planar->makeTaskTrajectory("tool", math::vector3( 0.0, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 23:
          // planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;
        case 24:
          planar->makeTaskTrajectory("tool", math::vector3( 0.04, 0.02, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 25:
          planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;
        case 26:
          planar->makeTaskTrajectory("tool", math::vector3(-0.045, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 27:
          planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;
        case 28:
          planar->makeTaskTrajectory("tool", math::vector3( 0.04, -0.02, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 29:
          planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;    
        case 30:
          planar->makeTaskTrajectory("tool", math::vector3(-0.02, 0.04, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 31:
          planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;    
        case 32:
          planar->makeTaskTrajectory("tool", math::vector3(-0.02,-0.04, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 33:
          planar->sleepTrajectory(0.3);
          motion_cnt[0] ++; 
        break;    
        case 34:
          planar->makeTaskTrajectory("tool", math::vector3( 0.04, 0.02, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
        case 35:
          planar->sleepTrajectory(1);
          motion_cnt[0] ++; 
        break;
        case 36:
          planar->makeTaskTrajectory("tool", math::vector3( 0.0, 0.0, 0.0), 0.08);
          motion_cnt[0] ++; 
        break;
      }
    }
  }
}

#endif // DEMO_H_
