#include "Renderer.h"

const float Z = 10.f; // something random for now
const float MAX_VEL = 10.0f; // maximum speed



Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{
	
	// OPENGL SETTINGS 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//triangle = Mesh::GenerateTriangle();
	//triObject = RenderObject(triangle, simpleShader);

	/*

	//MESHES
	cubeMesh =  Mesh::LoadMeshFile("cube.asciimesh");
	points = Mesh::GeneratePoints(50);
	bg = Mesh::GeneratePoints(1);
	tessMesh = Mesh::GenerateQuadPatch();

	//SHADERS
	smileyShader = new Shader("VertSmiley.glsl", "FragSmiley.glsl");
	blendShader = new Shader("basicVertBlend.glsl", "basicFragBlend.glsl");
	perlinShader = new Shader("basicVertPerlin.glsl", "basicFragPerlin.glsl");
	pointShader = new Shader("BasicVert.glsl", "GeometryFrag.glsl", "GeometryShader.glsl");
	tessShader = new Shader("tessVert.glsl", "displaceFrag.glsl", "", "displaceTCS.glsl", "displaceTES.glsl");
	lightShader = new Shader("vertNormals.glsl", "phong.glsl");
	shrinkShader = new Shader("shrinkVert.glsl", "shrinkFrag.glsl");
	tessLightShader = new Shader("cubeLight.glsl", "displaceTCS.glsl", "displaceTES.glsl", "normalGeometry.glsl", "phong.glsl");
	destroyShader = new Shader("DestroyVert.glsl", "GeoDestroyFrag.glsl", "GeoDestroyShader.glsl");
	hairyShader = new Shader("HairyVert.glsl", "HairyFrag.glsl", "HairyShader.glsl");
	tessCubeShader = new Shader("cubeTessVert.glsl", "cubeTessFrag.glsl", "", "cubeTCS.glsl", "cubeTES.glsl");

	if (basicShader->UsingDefaultShader() || smileyShader->UsingDefaultShader() || 
		blendShader->UsingDefaultShader() || perlinShader->UsingDefaultShader() ||
		pointShader->UsingDefaultShader() || tessShader->UsingDefaultShader() ||
		lightShader->UsingDefaultShader() || shrinkShader->UsingDefaultShader() ||
		tessLightShader->UsingDefaultShader() || destroyShader->UsingDefaultShader()
		){
		cout << "Warning: Using default shader! Your shader probably hasn't worked..." << endl;
		cout << "Press any key to continue." << endl;
		std::cin.get();
	}

	// LOAD TEXTURES
	smileyTex = LoadTexture("smiley.png");
	staticTex = LoadTexture("noise.png");
	perlinTex = LoadTexture("perlin.png");
	fireTex = LoadTexture("fire.png");
	skyTex = LoadTexture("sky.png");
	rustTex = LoadTexture("rust.png");
	snowTex = LoadTexture("snow.png");
	treeTex = LoadTexture("tree.png");
	crateTex = LoadTexture("crate.png");

	// CREATE RENDER OBJECT
	smileyObject = RenderObject(cubeMesh, smileyShader, smileyTex);
	smileyObject.SetTexture2(staticTex);
	interpolateObject = RenderObject(cubeMesh, blendShader, smileyTex);
	interpolateObject.SetTexture2(rustTex);
	perlinObject = RenderObject(cubeMesh, perlinShader, perlinTex);
	perlinObject.SetTexture2(perlinTex);
	spritesObject = RenderObject(points, pointShader, treeTex);
	bgObject = RenderObject(bg, pointShader, skyTex);
	tessObject = RenderObject(tessMesh, tessShader, snowTex);
	//tessObject = RenderObject(tessMesh, tessLightShader, snowTex); // tryed to get lighting to work on tesselated surfaces .. failed
	lightObject = RenderObject(cubeMesh, lightShader, fireTex);
	shrinkObject = RenderObject(cubeMesh, shrinkShader, smileyTex);
	destroyObject = RenderObject(cubeMesh, destroyShader, crateTex);
	//hairyObject = RenderObject(cubeMesh, hairyShader, crateTex); // failed - was supposed to generate lines along the normal of all the vectors
	tessCubeObject = RenderObject(cubeMesh, tessCubeShader, crateTex);

	// MODEL MATRIXES
	smileyObject.SetModelMatrix(Matrix4::Translation(Vector3(-3, 0, -10)) * Matrix4::Rotation(90,Vector3(0,1,0)));
	interpolateObject.SetModelMatrix(Matrix4::Translation(Vector3(3, 0, -10)));
	perlinObject.SetModelMatrix(Matrix4::Translation(Vector3(3, 4, -10)));
	spritesObject.SetModelMatrix(Matrix4::Translation(Vector3(-50, -10, -50)));
	tessObject.SetModelMatrix(Matrix4::Translation(Vector3(50, -20, 0)) * Matrix4::Scale(Vector3(100, 100, 100)) * Matrix4::Rotation(90, Vector3(1, 0, 0)));
	lightObject.SetModelMatrix(Matrix4::Translation(Vector3(0, 0, -10)));
	shrinkObject.SetModelMatrix(Matrix4::Translation(Vector3(-3, -3, -10)));
	bgObject.SetModelMatrix(Matrix4::Translation(Vector3(-50, 0, -100)));
	destroyObject.SetModelMatrix(Matrix4::Translation(Vector3(-3, 4, -10)));
	hairyObject.SetModelMatrix(Matrix4::Translation(Vector3(0, 4, -10)));
	tessCubeObject.SetModelMatrix(Matrix4::Translation(Vector3(0, 4, -10)));

	// ADD RENDER OBJECTS
	AddRenderObject(bgObject);			// sky
	AddRenderObject(tessObject);		// groundsw
	AddRenderObject(spritesObject);		// trees
	AddRenderObject(smileyObject);		// multi textured cube
	AddRenderObject(interpolateObject);	// clean / destroyed
	AddRenderObject(perlinObject);		// vanishing cube
	AddRenderObject(shrinkObject);		// shrinking cube
	AddRenderObject(lightObject);		// rotating lit cube
	AddRenderObject(destroyObject);		// exploding cube
	AddRenderObject(hairyObject);		// hairy cube - displays normal vectors as lines
	AddRenderObject(tessCubeObject);	// tesselated cube
	
*/
	modelMatrix = Matrix4::Rotation(90, Vector3(1, 0, 0)) * Matrix4::Scale(Vector3(300, 300, 300));
	viewMatrix = Matrix4::Rotation(90, Vector3(1, 0, 0)) * Matrix4::Rotation(20, Vector3(1, 0, 0)) * Matrix4::Translation(Vector3(0, -30, 20));
	projMatrix = Matrix4::Perspective(1.0f, 1000.0f, (float)width / (float)height, 45.0f);

	// LIGHT SOURCE
	SetShaderLight(Vector3(-4, 0, -8), Vector3(1, 1, 1), 10);

	// SCENE MATRIXES
	SetProjectionMatrix(Matrix4::Perspective(1.0f, 500.0f, 1.33f, 45.0f));
	SetViewMatrix(Matrix4::BuildViewMatrix(Vector3(0, 0, 0), Vector3(0, 0, -10)));
	
	//SHADERS
	basicShader = new Shader("basicVert.glsl", "basicFrag.glsl");

	//MESHES
	triangle = Mesh::GenerateTriangle();
	triFan = Mesh::GenerateTriFan(5.0f, 5.0f, -10.0f, 1.0f);

	//RENDER OBJECTS
	c1 = RenderObject(triangle, basicShader);
	c2 = RenderObject(triangle, basicShader);
	c3 = RenderObject(triangle, basicShader);
	tf1 = RenderObject(triFan, basicShader);

	//TRANSFORMS
	c1.SetModelMatrix(Matrix4::Translation(Vector3(2, 2, -10)));
	c2.SetModelMatrix(Matrix4::Translation(Vector3(3, 3, -20)));
	c3.SetModelMatrix(Matrix4::Translation(Vector3(4, 4, -30)));
	tf1.SetModelMatrix(Matrix4::Translation(Vector3(4, 4, -15)));

	//ENTITIES
	circle1 = new Entity(5, 5, 5, 5, 5, 5, 5, &(c1));
	circle2 = new Entity(5, 5, 5, 5, 5, 5, 5, &(c2));
	circle3 = new Entity(5, 5, 5, 5, 5, 5, 5, &(c3));
	triFan1 = new Entity(5, 5, 5, 5, 5, 5, 5, &(tf1));

	//ADD
	AddEntityObject(circle1);
	AddEntityObject(circle2);
	AddEntityObject(circle3);
	AddEntityObject(triFan1);

	/*
	for (int i = 0; i < 10; ++i){
		triObject = RenderObject(triangle, basicShader);

		triObject.SetModelMatrix(Matrix4::Translation(Vector3(i, 0, -10)));
		vec.push_back(Entity(Renderer::getRandom(5), Renderer::getRandom(5), Renderer::getRandom(Z), Renderer::getRandom(3), Renderer::getRandom(MAX_VEL), Renderer::getRandom(MAX_VEL), Renderer::getRandom(MAX_VEL), &triObject));
	}*/
}

float Renderer::getRandom(float x){
	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / x));
	return r2;
}

/// create the gamemanager which will manage entities, pass render objects to the renderer by passing a rendering node. 

Renderer::~Renderer(void)	{
	
	//DELETE MESHES
	delete triangle;
}

void	Renderer::RenderScene() {
	ClearBuffers();
	Render(root);
	/*
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		//Render(*(*i));
	
	}*/
	for (int i = 0; i < entityObjects.size(); i++) {
		Render(*(entityObjects[i]->renderObject));
	}
}

void	Renderer::Render(const RenderObject &o) {

	modelMatrix = o.GetWorldTransform();

	if (o.GetShader() && o.GetMesh()) {
		GLuint program = o.GetShader()->GetShaderProgram();

		glUseProgram(program);

		UpdateShaderMatrices(program);
		ApplyShaderLight(program);	

		// Pass in GLuint for time 
		GLint time = glGetUniformLocation(program, "time");
		glUniform1f(time, o.GetTime());

		Matrix4 rotation = Matrix4(viewMatrix);
		Vector3 invCamPos = viewMatrix.GetPositionVector();
		Vector3 camPos = rotation * -invCamPos; 
		glUniform3fv(glGetUniformLocation(program, "cameraPos"), 1, (GLfloat*)&camPos);

		o.Draw();
	}

	for (vector<RenderObject*>::const_iterator i = o.GetChildren().begin(); i != o.GetChildren().end(); ++i) {
		Render(*(*i));
	}
}

void	Renderer::UpdateScene(float msec) {

	/*
	//incremenent variables
	i = i + 0.01;
	shrink = shrink - 0.003;
	time += msec;

	//rotate light cube model matrix
	Matrix4 light = lightObject.GetModelMatrix();
	light = light * Matrix4::Rotation(sin(msec)*2, Vector3(0, 1, 0)) * Matrix4::Rotation(sin(msec), Vector3(1,0,0));

	//rotate exploding crate model matrix
	Matrix4 crate = destroyObject.GetModelMatrix();
	crate = crate * Matrix4::Rotation(sin(msec)*2, Vector3(0, 1, 0)) * Matrix4::Rotation(sin(msec), Vector3(1, 0, 1));

	//set the rotated model matrix's 
	lightObject.SetModelMatrix(light);
	destroyObject.SetModelMatrix(crate);

	//set the object variables
	smileyObject.SetTime(sin(i));
	interpolateObject.SetTime(sin(i));
	perlinObject.SetTime(sin(i));
	spritesObject.SetParticleSize(2.0f);
	bgObject.SetParticleSize(200.0f);
	shrinkObject.SetTime(shrink);
	destroyObject.SetParticleSize(2.0f);
	destroyObject.SetTime(i);
	destroyObject.Update(msec);
	*/
	for (vector<RenderObject*>::iterator i = renderObjects.begin(); i != renderObjects.end(); ++i) {
		(*i)->Update(msec);
	}
	for (int i = 0; i < entityObjects.size(); i++) {
		(entityObjects[i]->renderObject->Update(msec));
	}
	// *************** SCENE MOVEMENT / TEXTURE CHANGE ******************
	// enables you to move the camera around the scene with the defined keys
	if (Keyboard::KeyDown(KEY_A)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(-0.1f * 5, 0, 0));
	};

	if (Keyboard::KeyDown(KEY_D)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.1f * 5, 0, 0));
	}
	if (Keyboard::KeyDown(KEY_W)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.1f * 5, 0));
	}
	if (Keyboard::KeyDown(KEY_S)) {
		viewMatrix = viewMatrix * 
			Matrix4::Translation(Vector3(0.0, -0.1f * 5, 0));
	}

	if (Keyboard::KeyDown(KEY_E)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, 0.1 * 5));
	}
	if (Keyboard::KeyDown(KEY_C)) {
		viewMatrix = viewMatrix *
			Matrix4::Translation(Vector3(0.0, 0.0, -0.1 * 5));
	}
}

GLuint Renderer::LoadTexture(char* filename, bool textureRepeating){
	GLuint texture = SOIL_load_OGL_texture(filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
		);

	if (texture == NULL){
		printf("[Texture loader] \"%s\" failed to load!\n", filename);
		return 0;
	}
	else
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureRepeating ? GL_REPEAT : GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureRepeating ? GL_REPEAT : GL_CLAMP);

		glActiveTexture(0);
		return texture;	   
	}					   
}						   