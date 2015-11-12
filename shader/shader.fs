#version 130
in vec2 textureCoord;
out vec4 Color;

uniform sampler2D textureSampler;

void main(){
     Color = texture2D(textureSampler, textureCoord.st);
}
