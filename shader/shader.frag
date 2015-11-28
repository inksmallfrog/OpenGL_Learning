#version 130
in vec3 originPosition;
in vec2 textureCoord;
in vec3 normal;
in float reflectPower;
out vec4 Color;

uniform sampler2D textureSampler;
uniform mat4 worldModel;
uniform vec3 cameraPosition;

struct AmbientLight{
  vec3 ambientColor;
};
struct DirectionLight{
  vec3 ambientColor;
  vec3 direction;
  float diffuseIntensity;
};
struct PointLight{
  vec3 ambientColor;
  vec3 position;
  float diffuseIntensity;
  float[3] attenuations;
};
struct SpotLight{
  vec3 ambientColor;
  vec3 direction;
  vec3 position;
  float diffuseIntensity;
  float[3] attenuations;
  float borderCos;
};
uniform PointLight pointLight;

vec3 CalculateDirectionLight(DirectionLight _directionLight);
vec3 CalculateDirection(vec3 ambientColor, vec3 direction, float diffuseIntensity);
vec3 CalculatePointLight(PointLight _pointLight);
vec3 CalculatePoint(vec3 ambientColor, vec3 position, float diffuseIntensity, float[3] attenuations);
vec3 CalculateSpotLight(SpotLight _spotLight);


void main(){
  Color = vec4(vec3(texture2D(textureSampler, textureCoord.st)) * CalculatePointLight(pointLight), 1.0);
}

vec3 CalculateDirectionLight(DirectionLight _directionLight){
  return (CalculateDirection(_directionLight.ambientColor, _directionLight.direction, _directionLight.diffuseIntensity));
}

vec3 CalculatePointLight(PointLight _pointLight){
  return CalculatePoint(_pointLight.ambientColor, _pointLight.position, _pointLight.diffuseIntensity, _pointLight.attenuations);
}

vec3 CalculateDirection(vec3 ambientColor, vec3 direction, float diffuseIntensity){
  float lightFactor = dot(-direction, normal);
  float reflectFactor = 0.0f;
  if(lightFactor < 0){
    lightFactor = 0;
  }
  else{
    lightFactor = lightFactor * diffuseIntensity;
    vec3 reflectLight = normalize(reflect(direction, normal));
    vec3 vectorToCamera = normalize(cameraPosition - originPosition);
    vectorToCamera = mat3(worldModel) * vectorToCamera;
    reflectFactor = dot(reflectLight, vectorToCamera);
    if(reflectFactor > 0.0f && reflectPower != 0.0f){
      reflectFactor = pow(reflectFactor, reflectPower); 
    }
    else{
      reflectFactor = 0.0f;
    }
  }

  return (ambientColor * lightFactor + ambientColor * reflectFactor);
}

vec3 CalculatePoint(vec3 ambientColor, vec3 position, float diffuseIntensity, float[3] attenuations){
  vec3 direction = originPosition - position;
  float lightDistance = length(direction);
  direction = normalize(direction);

  float attenuation = attenuations[0] + attenuations[1] * lightDistance + attenuations[2] * lightDistance * lightDistance;
  
  return CalculateDirection(ambientColor, direction, diffuseIntensity) / attenuation;
}

vec3 CalculateSpotLight(SpotLight _spotLight){
  vec3 relDirection = normalize(originPosition - _spotLight.position);
  float relCos = dot(relDirection, _spotLight.direction);
  float spotFactor = (1.0f - (1.0f - relCos) / (1.0f - _spotLight.borderCos));
  if(spotFactor < 0.0f){
    spotFactor = 0.0f;
  }
  return CalculatePoint(_spotLight.ambientColor, _spotLight.position, _spotLight.diffuseIntensity, _spotLight.attenuations) * spotFactor;
}
