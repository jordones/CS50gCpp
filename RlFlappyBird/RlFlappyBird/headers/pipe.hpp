//
//  pipe.hpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#ifndef pipe_hpp
#define pipe_hpp

#include <stdio.h>
#include "raylib.h"

class Pipe {
public:
    enum Size {
        sm,
        md,
        lg
    };
private:
    float xPos, yPos;
    Vector2 vecSize;
    
    Vector2 GetSize(Size size) {
        switch (size) {
            case sm:
                return Vector2 { 75, 200 };
            case md:
                return Vector2 { 90, 250 };
            case lg:
                return Vector2 { 100, 300 };
        }
    }
public:
    Pipe(float x, float y, Size size);
    
    void Draw() {
        DrawRectangle(xPos, yPos, vecSize.x, vecSize.y, GREEN);
    }
};
#endif /* pipe_hpp */
