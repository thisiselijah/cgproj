#version 330 core

in vec2 uvCoords; 
out vec4 FragColor;

uniform sampler2D Texture; 
uniform vec4 color;          

void main()
{
    
    vec4 textureColor = texture(Texture, uvCoords);
    // vec4 textureColor = vec4(uvCoords, 0.0, 1.0);
    FragColor = color*textureColor;
}
