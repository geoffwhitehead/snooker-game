#include "../engine-base/Camera.h"
#include "../engine-base/GameManager.h"
#include "../nclgl/OGLRenderer.h"
#include "GameInput.h"
#include "../engine-physics/CollisionManager.h"
#include "../engine-audio/AudioManager.h"
#include <iostream>
#include <map>
#include "../_resources/jsoncpp/dist/json/json.h"


#define W_X 1024.0f
#define W_Y 768.0f

std::map<std::string, Mesh*> map_meshes;
std::map<const std::string, GLuint> map_textures;
std::map<std::string, Entity*> map_entities;
std::map<std::string, Shader*> map_shaders;

void main(void) {

	std::string data = "./levels/data.json";
	Json::Value root;   // 'root' will contain the root value after parsing.
	Json::Reader reader;
	ifstream fs(data);
	if (!fs) cout << "Failed to read from path.";
	if (!reader.parse(fs, root)) cout << "Failed to parse.";
	// GAME MANAGER
	GameManager *gm = new GameManager(W_X, W_Y);
	

	//CREATE SUB SYSTEMS
	Camera* camera = new Camera(0.0f, 0.0f, Vector3(0, 0, 400));
	Camera::projMatrix = Matrix4::Perspective(1, 1000, 1024.0f / 768.0f, 45);
	Camera::viewMatrix = camera->BuildViewMatrix();
	CollisionManager* cm = new CollisionManager();
	AudioManager* am = new AudioManager();
	GameInput* gi = new GameInput(gm);

	
	// JSON STUFF
	Json::Value level = root["level"][0];

	//TEXTURES
	for (int i = 0; i < level["textures"].size(); i++)
	{
		string name = level["textures"][i]["name"].asString();
		GLuint tex = gm->LoadTexture(level["textures"][i]["path"].asCString());
		map_textures.insert(pair <string, GLuint>(name, tex));
	}

	//SHADERS
	for (int i = 0; i < level["shaders"].size(); i++)
	{
		Shader* s = new Shader(level["shaders"][i]["vert"].asString(), level["shaders"][i]["frag"].asString());
		map_shaders.insert(pair <string, Shader*>(level["shaders"][i]["name"].asString(), s));
	}

	//MESHES
	for (int i = 0; i < level["meshes"].size(); i++)
	{
		string function = level["meshes"][i]["function"].asString();
		Mesh * m;
		if (function == "GenerateQuad") {
			m = Mesh::GenerateQuad(level["meshes"][i]["x"].asFloat(), level["meshes"][i]["y"].asFloat());
		}
		else if (function == "GenerateTriFan") {
			m = Mesh::GenerateTriFan(level["meshes"][i]["radius"].asFloat(), Vector4(level["meshes"][i]["x"].asFloat(), level["meshes"][i]["y"].asFloat(), level["meshes"][i]["z"].asFloat(), level["meshes"][i]["w"].asFloat()));
		}
		map_meshes.insert(pair<string, Mesh*>(level["meshes"][i]["name"].asString(), m));
	}

	//ENTITIES
	for (int i = 0; i < level["entities"].size(); i++)
	{
		Entity *e = new Entity(level["entities"][i]["name"].asString(),
			Vector3(
				level["entities"][i]["position"][0].asFloat(),
				level["entities"][i]["position"][1].asFloat(),
				level["entities"][i]["position"][2].asFloat()
				),
			Vector3(
				level["entities"][i]["acceleration"][0].asFloat(),
				level["entities"][i]["acceleration"][1].asFloat(),
				level["entities"][i]["acceleration"][2].asFloat()
				),
			Vector3(
				level["entities"][i]["velocity"][0].asFloat(),
				level["entities"][i]["velocity"][1].asFloat(),
				level["entities"][i]["velocity"][2].asFloat()
				),
			map_meshes[level["entities"][i]["mesh"].asString()],
			map_shaders[level["entities"][i]["shader"].asString()],
			map_textures[level["entities"][i]["texture"].asString()]);

		e->setMass(level["entities"][i]["mass"].asFloat());

		if (level["entities"][i]["collidable"].asBool()) {

			if (level["entities"][i]["collision_object"].asString() == "CIRCLE")
				cm->addObject(e, level["entities"][i]["collision_radius"].asFloat());
			if (level["entities"][i]["collision_object"].asString() == "PLANE")
				cm->addObject(e, e->getPhysicsObject()->getPos().Length(), 
					Vector3(
						level["entities"][i]["normal"][0].asFloat(),
						level["entities"][i]["normal"][1].asFloat(),
						level["entities"][i]["normal"][2].asFloat()
						));
		}
		if (level["entities"][i]["parent"].asString() == "")
			map_entities.insert(pair<string, Entity*>(level["entities"][i]["name"].asString(), e));
		else
			map_entities[level["entities"][i]["parent"].asString()]->addChild(e); 
	}

	// register entities
	for (auto iterator = map_entities.begin(); iterator != map_entities.end(); iterator++)
		gm->addEntity(iterator->second);

	//register subsystems
	gm->addSubSystem(camera);
	gm->addSubSystem(cm);
	gm->addSubSystem(am);
	gm->addSubSystem(gi);

	//start
	gm->run();

}