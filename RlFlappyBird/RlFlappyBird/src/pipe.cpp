//
//  pipe.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "pipe.hpp"

Pipe::Pipe(float x, float y, Size size) {
    xPos = x;
    yPos = y;
    vecSize = GetSize(size);
}
