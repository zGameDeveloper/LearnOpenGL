#version 330 core
in vec3 v_Color;
in vec2 v_TexCoord;

uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	gl_FragColor = texColor * vec4(v_Color, 1.0f);
}