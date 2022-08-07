//
//  pipe.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "pipe.h"

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

Pipe::Pipe(Texture2D texture, int y, Side position) {
    xPos = WINDOW_WIDTH;
    yPos = y;
    image = texture;
    width = texture.width;
    height = texture.height;
    side = position;
}

void Pipe::Render() {
    float yTranslated = side == Top ? yPos + height : yPos;
    float xTranslated = side == Top ? xPos + width : xPos;
    float scale = side == Top ? -1 : 1;
    DrawTextureEx(image, Vector2 { xTranslated, yTranslated }, 0.0f, scale, WHITE);
}
