#include "CollisionResponse.h"



CollisionResponse::CollisionResponse(CollisionManager* cm){
	this->cm = cm;
}


CollisionResponse::~CollisionResponse()
{
}
void CollisionResponse::destroy() {

}

void CollisionResponse::init() {

}
// collision response is responsible for the logic in sorting the collisions into 
// seperate lists for all the different managers to deal with in their own ways
void CollisionResponse::update(float msec) {

	for (int i = 0; i < cm->collisions_this_frame.size(); i++){
		if (cm->collisions_this_frame[i].first->group == "snooker_balls") {

			// cueball-pocket
			if (cm->collisions_this_frame[i].first->name == "white" && cm->collisions_this_frame[i].second->group == "pocket_plane") {
				cols_cue_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));
			}
			// circle-circle
			else if (cm->collisions_this_frame[i].second->group == "snooker_balls"){
				cols_cue_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
			// circle-cushion
			else if (cm->collisions_this_frame[i].second->group == "cushion_plane") {
				cols_cue_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
			// circle-pocket
			else if (cm->collisions_this_frame[i].second->group == "pocket_plane") {
				cols_cue_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
		}
	}

}