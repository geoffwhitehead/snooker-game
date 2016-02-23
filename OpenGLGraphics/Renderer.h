#pragma once
#include "../nclgl/OGLRenderer.h"

#include "RenderObject.h"
#include <ctime>
#include <cstdlib>
#include "Entity.h"
#include <vector>

using std::vector;

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	~Renderer(void);

	virtual void	RenderScene();

	virtual void	Render(const RenderObject &o);

	virtual void	UpdateScene(float msec);

	void	AddRenderObject(RenderObject &r) {
		renderObjects.push_back(&r);
	}

	void	AddEntityObject(Entity *e){
		entityObjects.push_back(e);
	}

	static float getRandom(float);

	GLuint LoadTexture(char* filename, bool textureRepeating = true);

	struct Light {
		Vector3 position;
		float radius;
		Vector3 colour;
	};

	void SetShaderLight(Vector3 position, Vector3 colour, float radius){
		currentLight.position = position;
		currentLight.colour = colour;
		currentLight.radius = radius;
	}

	void collisionManager();

protected:
	
	// MANAGERS
	vector<RenderObject*> renderObjects;
	vector<Entity*> entityObjects;

	//MESHES
	Mesh*	triangle;
	Mesh*	cubeMesh;
	Mesh*	points;
	Mesh*   quadMesh;
	Mesh*	tessMesh;
	Mesh*	bgMesh;
	Mesh*	triFanMesh;
	Mesh*	triLoopMesh;

	Shader* simpleShader;
	Shader* basicShader;
	Shader* smileyShader;
	Shader* blendShader;
	Shader* perlinShader;
	Shader* pointShader;
	Shader* tessShader;
	Shader* lightShader;
	Shader* shrinkShader;
	Shader* tessLightShader;
	Shader* destroyShader;
	Shader* hairyShader;
	Shader* tessCubeShader;

	Entity* circle1;
	Entity* circle2;
	Entity* circle3;
	Entity* triFan1;
	Entity* triLoop1;
	Entity* triFan2;
	Entity* triLoop2;
	Entity* triFan3;
	Entity* triLoop3;
	Entity* bg;
	Entity* ground;
	Entity* tableTop;
	Entity* tableRight;
	Entity* tableBottom;
	Entity* tableLeft;


	RenderObject c1;
	RenderObject c2;
	RenderObject c3;
	RenderObject tf1;
	RenderObject tl1;
	RenderObject tf2;
	RenderObject tl2;
	RenderObject tf3;
	RenderObject tl3;

	RenderObject tbl_top;
	RenderObject tbl_right;
	RenderObject tbl_bottom;
	RenderObject tbl_left;


	RenderObject root;			//ROOT
	RenderObject triObject;
	RenderObject smileyObject;
	RenderObject interpolateObject;
	RenderObject perlinObject;
	RenderObject spritesObject;
	RenderObject tessObject;
	RenderObject lightObject;
	RenderObject shrinkObject;
	RenderObject bgObject;
	RenderObject destroyObject;
	RenderObject hairyObject;
	RenderObject tessCubeObject;

	GLuint smileyTex;
	GLuint staticTex;
	GLuint perlinTex;
	GLuint fireTex;
	GLuint skyTex;
	GLuint rustTex;
	GLuint snowTex;
	GLuint treeTex;
	GLuint crateTex;

	float i = 1.0;
	float shrink = 1.0;
	float time = 0.0f;

	void ApplyShaderLight(GLuint program){
		glUniform3fv(glGetUniformLocation(program, "lightColour"), 1, (GLfloat*)&currentLight.colour);
		glUniform3fv(glGetUniformLocation(program, "lightPos"), 1, (GLfloat*)&currentLight.position);
		glUniform1f(glGetUniformLocation(program, "lightRadius"), currentLight.radius);
	}
	Light currentLight;
};

