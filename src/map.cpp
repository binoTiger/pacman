#include "map.h"

using namespace sf;

Map::Map()
{
    map_image.loadFromFile("../images/map.png");
    map_image.createMaskFromColor(Color::White);
    map_texture.loadFromImage(map_image);
    map_sprite.setTexture(map_texture);
}

void Map::drawMap(RenderWindow& window)
{
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            switch (tiles[i][j])
            {
            case 0:
            case 100000:
            case 100001:
            case 100010:
            case 100011:
            case 100100:
            case 100101:
            case 100110:
            case 100111:
            case 101000:
            case 101001:
            case 101010:
            case 101011:
            case 101100:
            case 101101:
            case 101110:
            case 101111:
                map_sprite.setTextureRect(IntRect(0, 0, 30, 30));
                break;

            case 1:
            case 110000:
            case 110001:
            case 110010:
            case 110011:
            case 110100:
            case 110101:
            case 110110:
            case 110111:
            case 111000:
            case 111001:
            case 111010:
            case 111011:
            case 111100:
            case 111101:
            case 111110:
            case 111111:
                map_sprite.setTextureRect(IntRect(330, 0, 30, 30));
                break;

            case 121001:
                map_sprite.setTextureRect(IntRect(330, 30, 30, 30));
                break;

            case 11:
                map_sprite.setTextureRect(IntRect(30, 0, 30, 30));
                break;
            case 12:
                map_sprite.setTextureRect(IntRect(59, 0, -30, 30));
                break;
            case 13:
                map_sprite.setTextureRect(IntRect(60, 0, 30, 30));
                break;
            case 14:
                map_sprite.setTextureRect(IntRect(60, 29, 30, -30));
                break;
            case 15:
                map_sprite.setTextureRect(IntRect(360, 0, 30, 30));
                break;
            case 16:
                map_sprite.setTextureRect(IntRect(390, 0, -30, 30));
                break;

            case 21:
                map_sprite.setTextureRect(IntRect(90, 0, 30, 30));
                break;
            case 22:
                map_sprite.setTextureRect(IntRect(120, 0, -30, 30));
                break;
            case 23:
                map_sprite.setTextureRect(IntRect(120, 0, 30, 30));
                break;
            case 24:
                map_sprite.setTextureRect(IntRect(120, 29, 30, -30));
                break;

            case 31:
                map_sprite.setTextureRect(IntRect(150, 0, 30, 30));
                break;
            case 32:
                map_sprite.setTextureRect(IntRect(179, 0, -29, 30));
                break;
            case 33:
                map_sprite.setTextureRect(IntRect(150, 29, 30, -30));
                break;
            case 34:
                map_sprite.setTextureRect(IntRect(179, 29, -29, -30));
                break;

            case 41:
                map_sprite.setTextureRect(IntRect(180, 0, 30, 30));
                break;
            case 42:
                map_sprite.setTextureRect(IntRect(209, 0, -29, 30));
                break;
            case 43:
                map_sprite.setTextureRect(IntRect(180, 29, 30, -30));
                break;
            case 44:
                map_sprite.setTextureRect(IntRect(209, 29, -29, -30));
                break;

            case 51:
                map_sprite.setTextureRect(IntRect(300, 29, -30, -30));
                break;
            case 52:
                map_sprite.setTextureRect(IntRect(270, 29, 30, -30));
                break;
            case 53:
                map_sprite.setTextureRect(IntRect(300, 0, -30, 30));
                break;
            case 54:
                map_sprite.setTextureRect(IntRect(270, 0, 30, 30));
                break;

            case 61:
                map_sprite.setTextureRect(IntRect(300, 0, 30, 30));
                break;
            case 62:
                map_sprite.setTextureRect(IntRect(330, 0, -30, 30));
                break;
            case 63:
                map_sprite.setTextureRect(IntRect(300, 29, 30, -30));
                break;
            case 64:
                map_sprite.setTextureRect(IntRect(330, 29, -30, -30));
                break;

            case 71:
                map_sprite.setTextureRect(IntRect(210, 0, 30, 30));
                break;
            case 72:
                map_sprite.setTextureRect(IntRect(239, 0, -29, 30));
                break;
            case 73:
                map_sprite.setTextureRect(IntRect(210, 29, 30, -30));
                break;
            case 74:
                map_sprite.setTextureRect(IntRect(239, 29, -29, -30));
                break;
            case 75:
                map_sprite.setTextureRect(IntRect(240, 0, 30, 30));
                break;
            case 76:
                map_sprite.setTextureRect(IntRect(270, 0, -30, 30));
                break;
            }

            map_sprite.setPosition(j * 30 + 540, i * 30);
            window.draw(map_sprite);
        }
    }
}