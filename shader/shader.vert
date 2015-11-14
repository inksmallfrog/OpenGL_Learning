#version 130
in vec3 Position;
in vec2 TexCoord;
in vec3 Normal;
in vec3 Material;
in float ReflectPower;

out vec3 originPosition;
out vec2 textureCoord;
out vec3 normal;
out float reflectPower;

uniform mat4 pipelineModel;
uniform mat4 worldModel;

void main(){
     gl_Position = pipelineModel * vec4(Position, 1.0f);
     originPosition = Position;
     textureCoord = TexCoord;
     normal = mat3(worldModel) * Normal;
     reflectPower = ReflectPower;
}
