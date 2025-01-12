#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV; 


uniform mat4 MVP;
uniform float SIZE;
uniform vec3 OF;

out vec2 uvCoords;


void main()
{
    vec3 scaled_modelspace = vertexPosition_modelspace*SIZE;
    vec3 translated_modelspace = scaled_modelspace+OF;
    uvCoords = vertexUV;
    // uvCoords = (vertexPosition_modelspace.xy + vec2(1.0)) * 0.5;
    // uvCoords = (translated_modelspace.xy + vec2(1.0)) * 0.5;
    gl_Position = MVP * vec4(translated_modelspace, 1.0);
}


