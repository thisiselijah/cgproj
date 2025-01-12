#version 330 core

in vec2 uvCoords; // 從頂點著色器傳入
out vec4 FragColor;

uniform sampler2D Texture; // 材質
uniform vec4 color;           // 粒子的基礎顏色

void main()
{
    
    vec4 textureColor = texture(Texture, uvCoords);
    // vec4 textureColor = vec4(uvCoords, 0.0, 1.0);
    FragColor = color*textureColor;
}


// #version 330 core
// // Uniforms
// uniform vec4 color; 
// // Outputs
// out vec4 FragColor; 

// void main() {
//     // 計算最終顏色
//     FragColor = color;

//     // 丟棄完全透明的片段以優化性能
//     if (FragColor.w < 0.1)
//         discard;
// }