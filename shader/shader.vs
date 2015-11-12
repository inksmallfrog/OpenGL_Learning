#version 130
in vec3 Position;
in vec2 texCoord;

out vec2 textureCoord;

uniform mat4 PCWModel;

void main(){
     gl_Position = PCWModel * vec4(Position, 1.0f);
     textureCoord = texCoord;
}
