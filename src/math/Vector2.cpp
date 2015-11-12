#include "../../includes/math/Vector2.hpp"

Vector2f::Vector2f() :
    x(0.0f),
    y(0.0f){
}

Vector2f::Vector2f(float _x, float _y) :
    x(_x),
    y(_y){
}

Vector2f::Vector2f(const Vector2f &vector2f) :
    x(vector2f.x),
    y(vector2f.y){
}
